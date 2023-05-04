#include <stdio.h>

int main() {
	
	// 비트연산
	//
	// 2진수 8비트값 출력기
	// 
	char a = 12;
	
	char printVal = 0;

	printf("12의 2진수 표현법은?    ");

	for(int i = 7; i >= 0; i--) {
		printVal = a & (1 << i);
		printVal >>= i;
		printf("%d ", printVal);
	}

	printf("\n");
	
	// 0000 1100에서 0000 1000으로 바꿔보자
	
	a = a & (~(1<<2));
	
	printf("0000 1000으로 바꿔보면? ");

	for(int i = 7; i >= 0; i--) {
		printVal = a & (1 << i);
		printVal >>= i;
		printf("%d ", printVal);
	}

	printf("\n");


	return 0;

}
