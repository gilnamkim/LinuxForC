#include <stdio.h>

int main() {
	
	// 삼항연산자 (if문을 대신할 수 있다)
	// ?:
	//
	// 비트연산자
	//  | & << >>
	//
	// 크기연산자
	// sizeof();
	//
	// 연산자 우선순위
	// 소괄호()를 사용하여 제 3자가 봐도 알아보기 편하게 해주는게 좋다
	// 버그를 방지하기 위해 명확히 표현해준다.
	
	// 논리연산자
	// 0이 아니면 무조건 참이다.
	// 0이면 거짓
	
	int a = 3;
	int b = 7;
	int c = 6;
	int d = 0;

	printf("%d\n", a || b);
	printf("%d\n", a && b);
	printf("%d\n", a && d);

	return 0;
}
