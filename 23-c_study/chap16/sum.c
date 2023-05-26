#include "sum.h"



#ifdef RTL2023
int sum(int a, int b) {



	return a+b;
}

#else

int sum(int a, int b) {



	return a*b;
}

#endif
