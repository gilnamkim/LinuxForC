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

void * rcv(void * arg) {

	int sock = (int)arg;
	char buff[500];
	int len;
	while(1) {
		len = read(sock, buff, sizeof(buff));

		if(len == -1) {
			printf("sock close\n");
			break;
		}
		printf("%s",buff);
	}
	pthread_exit(0);
	return NULL;

}



int main(int argc, char **argv) {
	
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t rcv_thread;
	void* thread_result;

	char id[100];

	if(argc < 2) {
		printf("you have to enter ID\n");
		return 0;

	}
	strcpy(id,argv[1]);
	printf("id : %s\n", id);


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
	
	pthread_create(&rcv_thread, NULL, rcv, (void *)sock);

	char chat[100];
	char msg[1000];
	
	

	while(1) {		
		gets(chat);
		sprintf(msg,"[%s] : %s\n", id, chat);
		printf("send : %s\n",msg);
		write(sock,msg,strlen(msg)+1);
		sleep(1);
		
	}
	printf("while end\n");
	close(sock);
	return 0;
}
