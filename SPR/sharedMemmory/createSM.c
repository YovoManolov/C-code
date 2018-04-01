#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

void* create_shared_memmory(size_t size){
	//our memmory buffer will be readable and writeable 
	int protection = PROT_READ| PROT_WRITE;
	// The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
	int visability = MAP_ANONYMOUS | MAP_SHARED;
    
    return mmap(NULL, size, protection, visability, 0, 0);

}