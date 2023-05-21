#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct human{
	int num;
	char name[20];
	
	//.linkedList를 구현하려면 추가
	human * nest;

}human;

int g_h_total = 0;


void add_h(human *h_num) {  // human h_num[]을 파라미터로 넘겨도 괜찮다
	
	// 파라미터로 human h_num[]을 받을 경우
	(h_num + g_h_total) -> num = (g_h_total + 1) *2;
	sprintf((h_num+g_h_total++) ->name, "test %d",g_h_total+1);
	
//	h_num[g_h_total].num = (g_h_total + 1) * 2;
//	sprintf(h_num[g_h_total++].name,"test %d",g_h_total+1);

}

void print_all(human *h_num) {
	int i = 0;

	while(h_num[i].num) {
		printf("====================================\n");
		printf(" num[%d] : %d\n",i, h_num[i].num);
		printf("name[%d] : %s\n",i, h_num[i].name);
		i++;
		if(i >= MAX){
			break;
		}
	}
}


int main() {
	// human이라는 구조체 MAX만큼 생성
	human h_num[MAX];

	for(int i = 0; i < MAX; i++) {
		add_h(h_num);
	}

	// 구조체의 배열도 시작번지의 주소를 가지고 있다
	print_all(h_num);

	return 0;
}
