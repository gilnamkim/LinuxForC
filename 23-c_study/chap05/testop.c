#include <stdio.h>

int main() {
	
	// 삼항연산자	
	// 참은 0이 아니면 참이다.
	// ?앞의 조건에 따라 (참):(거짓)의 결과가 출력된다.
	

	int a = 3;
	int b = 2;
	int c = a < b;

	(c) ? printf("참\n") : printf("거짓\n");

	printf("결과: %d\n", c);

	return 1;

}

