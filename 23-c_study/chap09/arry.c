#include <stdio.h>

#define MAX 10

int main() {
	
	// 배열?
	// 자료의 주소를 한곳에 모아놓는다
	// arry[0]의 주소가 배열의 주소입니다 그리고 간격은 자료형에 따라 달라집니다
	//
	int arryA[MAX];

	for(int i = 0; i < MAX; i++) {
		arryA[i] = i;
	}

	for(int i = 0; i < MAX; i++) {
		printf("arryA[%d]= %d\n", i , arryA[i]);			
	}
	
	int a = arryA;

	printf("arryA의 주소값: %d\n", a);
	
	int b = 2;
	printf("b : %d\n", b); // int형 b를 출력
	int *pb; // pb라는 int형 포인터를 선언
	pb = &b; // pb는 b의 주소입니다
	printf("&pb : %u\n", &pb); // pb의 개인주소값입니다.
	printf("pb : %u\n", pb); // pb는 b의 주소값을 가지고 있습니다
	printf("&b : %u\n", &b); // b의 주소값이랑 같습니다
	*pb = 4; // pb의 주소값을 따라 4를 넣어주세요
	printf("*pb : %u\n",*pb); // pb의 주소값을 따라 값을 가져오면?
	printf("b : %d\n",b); // b에 들어있는 값과 같습니다

	return 1;
}
