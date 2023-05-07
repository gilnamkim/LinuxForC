#include <stdio.h>

int main() {

	int a;
	int *pa;
	int **ppa;
	
	a = 3;

	printf("a의 값 : %d\n",a);
	printf("a의 주소 : %u\n",&a);

	pa = &a;

	printf("pa의 값 : %u(a의 주소)\n",pa);
	printf("pa의 주소 : %u\n",&pa);
	printf("*pa의 값 : %d(a의 주소에 담긴 값)\n",*pa);

	*pa = 5;
	
	printf("*pa의 값 : %d(a의 주소에 담긴 값)\n",*pa);

	ppa = &pa;
	
	printf("ppa의 값 : %u(pa의 주소)\n",ppa);
	printf("ppa의 주소 : %u\n",&ppa);
	printf("**ppa의 값 : %d(a의 주소에 담긴 값)\n",**ppa);

	**ppa = 10;

	printf("**ppa의 값 : %d(a의 주소에 담긴 값)\n",**ppa);
	


	// 포인터는 메모리값
	// 이 컴퓨터는 64비트입니다.
	// 한번에 메모리주소를 읽어와야하는데 그 한계가 64비트(8바이트)까지 입니다.
	// 그래서 메모리주소를 다루는 포인터는 자료형에 상관없이 8바이트 입니다.
	// 자료형은 왜 붙일까? 
	// 변수가 시작되는 주소값에서 얼마만큼의 크기를 읽어올지 알려주기 위한 용도입니다.
	//
	int *b;
	char *c;
	float *f;
	double *d;
	short *s;

	printf("%d\n",sizeof(b));
	printf("%d\n",sizeof(c));
	printf("%d\n",sizeof(f));
	printf("%d\n",sizeof(d));
	printf("%d\n",sizeof(s));
	
	
	return 0;
}
