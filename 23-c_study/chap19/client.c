#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFSIZE 100
#define NAMESIZE 20

int StoHEX(char fi, char sc);

char message[BUFFSIZE];


int main(int argc, char **argv) {
	
	int sock;
	struct sockaddr_in serv_addr;


	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1) {
		printf("socket error");
	} else {
		printf("socket ok");
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(7889);
	
	if(connect(sock, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) == -1) {
		printf("connect error");
	} else {
		printf("connect success");
	}

	unsigned char msg[100] = {0x01,1,2,2,34,5,1,5,123,5,2,3,45,1,0x0c};


	while(1) {
		
		printf("send : \n");

		write(sock,msg,15);
		sleep(1);
		
	}
	close(sock);



	return 0;
}
