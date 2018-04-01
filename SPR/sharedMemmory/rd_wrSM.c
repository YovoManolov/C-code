#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>

void* create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;
  // The buffer will be shared (meaning 
  //other processes can access it), but
  // anonymous (meaning third-party processes
  // cannot obtain an address for it),
  // so only this process and its children 
  //will be able to use it:
  int visibility = MAP_ANONYMOUS | MAP_SHARED;

  // The remaining parameters to `mmap()`
  // are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, 0, 0);
}

int main(){
	char* parent_message = "hello";
	char* child_message = "goodbye";

	void* shmem = create_shared_memory(128);

	memcpy(shmem, parent_message, sizeof(parent_message));
	//process id of the child is returned in the parent and 0 is
	//returned in the child
	int pid = fork();

	if(pid == 0){
		printf("Child read: %s\n", (char*)shmem);
		memcpy(shmem,child_message,sizeof(child_message));
		printf("Child wrote: %s\n",(char*)shmem);

	}else{
		printf("Parent read: %s\n",(char*)shmem);
		sleep(1);
		printf("After 1s, parent read : %s\n", (char*)shmem);
	}
}

