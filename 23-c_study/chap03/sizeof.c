#include <stdio.h>

int main() {
	
	int a;
	a = 8;

	printf("a의 값 %d size : %d\n", a, sizeof(a));
	// 임베디드를 포함한 다양한 시스템에 따라 변하는 int외 다양한 형의 
	// 크가를 알고 싶을 때 sizeof라는 함수를 사용합니다.
	
	// const int a = 3;  a=3; << 못바꿈
	//
	// #define a 3;  전처리기가 3으로 바꾸고 컴파일

	//입력이 됩니다
	return 0;
}
