#include <stdio.h>

int isGood();
int isBad();

int main() {
	
	// c언어에서 참거짓을 구분하는것은
	// 참은 0이 아니면 모두 참
	// 0이면 거짓
	//
	// 참일 확률이 가장 높아보이는 것을 가장 상위에 두는것이 보기 좋다

	int a = 0;

	if(isGood()){           // 리턴값이 1이므로 if문 내부를 실행한다
		a = 1;
	}

	if(isBad()){            // 리턴값이 0이므로 if문 내부를 실행하지 않는다
		a = 2;
	}
	
	
	printf("결과: %d\n", a);

	return 0;


}

int isGood(){
	return 1;
}

int isBad() {
	return 0;
}

