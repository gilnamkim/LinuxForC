#include <stdio.h>
#include <string.h>


// 구조체는 하나의 자료형과 비슷합니다
// 구조체는 JAVA의 클래스와 유사합니다
//struct student{
//	
//	int s_id;
//	char name[20];
//	char a; // 크기가 4바이트인 이유는 접근하는 속도의 효율성?.


//};

// 이렇게 축약할 수 있습니다.

typedef struct student{
	int s_id;
	char name[20];
}std;

void std_func(std *st);

// typedef는 해당 타입을 다른 타입으로 부를 수 있습니다.
typedef struct student std; // 구조체의 크기를 줄일 수 있습니다.



int main() {
	
	// 구조체(학생 1을) 정의
	std st1;
		
	std_func(&st1);


	printf("s_id : %d\n",st1.s_id);
	printf("name : %s\n",st1.name);
	
	printf("st1 : %ld\n",st1);
	printf("st1 : %ld\n",&st1);

	char a[20];
	

	printf("a : %ld\n",a);
	printf("&a : %ld\n",&a);
	printf("&a[0] : %ld\n",&a[0]);

	return 0;
}	

void std_func(std *st){
	st->s_id = 10;
	strcpy(st->name, "gilnami");

	
	printf("s_id : %d\n",st->s_id);
	printf("name : %s\n",st->name);
}
