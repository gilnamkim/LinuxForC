#include <stdio.h>

int main() {
	
	// 0은 거짓 그 외에는 모두 참
	
	int a = 10;

	while(a) {
		a--;
		printf("a : %d\n",a);
	}

	return 0;
}
