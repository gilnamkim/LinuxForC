#include <stdio.h>
#include <stdlib.h>
#define MAX 200

int g_h_total = 0;


void add_h(int *h_num) {
	h_num[g_h_total++] = (g_h_total+1) * 2;
}


void print_all(int *h_num) {

	int i = 0;
	while(*(h_num+i)) {
		printf(" [%d] : %d\n",i , *(h_num+i));
		i++;
		if(i >= MAX) {
			break;
		}
	}

}

// 배열을 늘릴 수가 없다!
int main() {
	
//	stack공간에 배열설정
//	int h_num[MAX] = {0,};
//
//
	int * h_num;
	
// malloc은 다양한 형태의 포인터를 지원히기 위해 void *를 사용
// 	heap공간에 배열설정
	h_num = (int *)malloc(sizeof(int)*MAX);

	* h_num = 4;
	

	printf("%d\n",*h_num);
//	for(int i = 0; i < MAX; i++) {	
//		add_h(h_num);
//	}
//
//	print_all(h_num);	

	return 0;
}
