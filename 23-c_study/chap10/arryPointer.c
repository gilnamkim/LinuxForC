#include <stdio.h>
#define MAX 5

int swap(int *pa);

int main() {
	
	int a[MAX] = {0,1,2,3,4};

	printf("a[3] = %d\n", a[3]);
	swap(a);
	
	printf("a[0] = %d\n", a[0]);
	printf("a[1] = %d\n", a[1]);
	printf("a[2] = %d\n", a[2]);
	printf("a[3] = %d\n", a[3]);
	printf("a[4] = %d\n", a[4]);

	return 0;
}

int swap(int *pa) {
	*(pa + 3) = 99;

	return 1;
}
