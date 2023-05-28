#include <stdio.h>




// 리눅스는 전부 파일화(스트림)한다
int main(){
	
	FILE * fd;

	char ch;
	
	// 파일 쓰기모드
	fd = fopen("a.txt","a");
	if(fd == NULL) {
		printf("file open error!\n");
	} else {
		printf("success\n");
	}

	fprintf(fd,"한글도 가능합니다!\n");



	// 파일 읽기모드
	fd = fopen("a.txt","r");
	if(fd == NULL) {
		printf("file open error!\n");
	} else {
		printf("success\n");
	}
	
	while(1) {
		ch = getc(fd);
		if(ch == EOF) {
			break;
		}
		putchar(ch);
	}
	
	fclose(fd);

	return 0;
}
