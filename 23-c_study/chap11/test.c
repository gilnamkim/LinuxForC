#include <stdio.h>



void swap(int *a , int *b) {
	
	int c;
	c = *a;  // a를 참조한 값을 c에 넣는다
	*a = *b;
	*b = c;
}

void test() {

	printf("func test\n");
}

void test2() {

	printf("func test2\n");
}	


int main() {
		
	void (*fp)(); // 함수도 포인터 주소입니다.

	fp = test;
	fp();
	printf("test의 주소는 : %d\n",test);

	fp = test2;
	fp();
	printf("test2의 주소는 : %d\n",test2);


	return 0;
}
