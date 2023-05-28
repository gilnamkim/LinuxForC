#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


FILE *fd;
FILE *fd2;
//int fd;

int main() {
	
	// 표준입출력
	printf("hi\n");


	// fopen은 다음과 같이 작동합니다
	fd = fopen("a.txt","a");

	// open의 리턴값은 int
	// 0 : 표준입력/키보드
	// 1 : 표준출력/콘솔
	// 2 : 에러출력/콘솔
	// 3 : 파일출력
/*	fd = open("a.txt",O_WRONLY | O_APPEND);
	printf("fd : %d\n",fd);
	write(fd,"good!!!\n",8);
	close(fd);*/

	fprintf(fd,"hello\n");
	printf("fd : %d\n",fd->_fileno);

	fd2 = fopen("b.txt","a+");

	fprintf(fd,"hello\n");
	printf("fd2 : %d\n",fd2->_fileno);

//	write(3,"hihi\n",3);

	fclose(fd);
	return 0;
}
