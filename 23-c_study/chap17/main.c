#include <stdio.h>
#include "sum.h"


int main() {
	
#ifdef DEBUG
	printf("degug");
	printf("sum : %d\n",sum(1,2));
#else
	printf("hello");
	printf("sum : %d\n",sum(1,2));
#endif

	return 0;
}	
