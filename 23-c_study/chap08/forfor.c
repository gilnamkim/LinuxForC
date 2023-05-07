#include <stdio.h>

int main() {

	// 2중 for문 만들기(구구단)
	//
	for(int i = 1; i < 21; i++) {

		printf("[%d 단]\n",i);
		for(int j = 1; j < 10; j++) {
			printf("%d * %d = %d\n", i , j , i*j);
		}
		printf("\n");
	}
	return 0;
}


