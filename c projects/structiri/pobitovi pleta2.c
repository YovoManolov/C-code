#include <stdio.h>

int main () {
	struct b_type {
		int g: 2;
		int f: 2;
		int m: 3;
		
	}bvar1;
	
	bvar1.g = 2;
	bvar1.f = 0;
	bvar1.m = -1;
	
	printf(" %d %d %d ", bvar1.g, bvar1.f, bvar1.m);
	return 0;
}
