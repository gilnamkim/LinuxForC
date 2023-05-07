#include <stdio.h>

int function1(int a, int b) {
	return a+b;
}

int function2(int a, int b, int c) {
	return a-b-c;
}

int main() {
	
	printf("%d\n",function1(1,2));  

	printf("%d\n",function2(10,4,1));

	return 0;
}
