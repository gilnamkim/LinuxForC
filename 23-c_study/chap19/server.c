#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// 기본제공 헤더파일은 < >, 직접 만든 헤더파일은  " "로 정의

#define CLNT_MAX 10
#define BUFFSIZE 200


int g_clnt_socks[CLNT_MAX];
int g_clnt_count = 0;

pthread_mutex_t g_mutex;

void send_all_clnt(char * msg, int my_sock) {
	pthread_mutex_lock(&g_mutex);
	for(int i = 0; i < g_clnt_count; i++) {
		if(g_clnt_socks[i] != my_sock) {
			write(g_clnt_socks[i], msg, strlen(msg)+1);
		}
	}
	pthread_mutex_unlock(&g_mutex);
}

void * clnt_connection(void * arg) {
	
	int clnt_sock = (int)arg;
	int str_len = 0;
	char msg[BUFFSIZE];
	int i;
	
	while(1) {
		str_len = read(clnt_sock, msg, sizeof(msg));
		if(str_len == -1) {
			printf("client [%d] close\n",clnt_sock);
			break;
		}
		send_all_clnt(msg,clnt_sock);
		printf("%s\n",msg);
	}
	
	pthread_mutex_lock(&g_mutex);
	
	for(int i = 0; i < g_clnt_count; i++) {
		if(clnt_sock == g_clnt_socks[i]) {
			for(; i <g_clnt_count-1; i++) {	
				g_clnt_socks[i] = g_clnt_socks[i+1];
				break;
			}
		}
	}
			
	pthread_mutex_unlock(&g_mutex);	
	close(clnt_sock);
	pthread_exit(0);
	return NULL;
}





int main(int argc, char ** argv) {

	int serv_sock;
	int clnt_sock;

	pthread_t t_thread;
	
	struct sockaddr_in serv_addr;

	struct sockaddr_in clnt_addr;
	int clnt_addr_size;

	pthread_mutex_init(&g_mutex,NULL);

	// 파라미터 PF_INET : 2로 define한 변수입니다. IPv4를 사용하겠습니다.
	// IPv4의 IP고갈을 걱정하여 IPv6를 만들었지만?
	// IPv6는 공유기의 등장으로 사용할 목적이 사라졌습니다.
	// 파라미터 SOCK_STREAM : TCP통신을 사용하겠습니다.
	// 파라미터 0 : 프로토콜이 TCP입니다 IPPROTO_TCP로도 사용할 수 있습니다.
	serv_sock = socket(PF_INET,SOCK_STREAM,0);
	
	// 주소관련 설정은 PF대신 AF를 사용...변수값은 동일합니다.
	serv_addr.sin_family = AF_INET;

	// INADDR_ANY : 지금 내 IP주소를 사용하겠습니다
	// htonl : host to network long : 호스트방식의 오더를 네트워크방식으로 32비트로 바꿔주겠습니다
	// 엔디안 : 데이터를 저장하는 순서에 따라 리틀엔디안, 빅엔디안으로 구분, 운영체제에 따라 다릅니다.
	// 네트워크 오더는 무조건 빅엔디안으로 통일합니다.
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	// port설정
	// htons는 short형식 
	serv_addr.sin_port = htons(7889);
	

	if(bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
		printf("bind error\n");	
	}	
	
	// listen 상태의 클라이언트의 숫자를 제한
	if(listen(serv_sock,5) == -1) {
		printf("listen error\n");
	}
	
	
	// 소켓의 2종류
	// 서버 소켓 : 내부작업 후 listen상태
	// 클라이언트 소켓 : 클라이언트 1명당 소캣생성
	//
	char buff[200];
	int recv_len = 0;
	while(1) {	
		clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
		pthread_mutex_lock(&g_mutex);
		g_clnt_socks[g_clnt_count++] = clnt_sock;
		pthread_mutex_unlock(&g_mutex);

		pthread_create(&t_thread, NULL, clnt_connection, (void *)clnt_sock);
	}
	return 0;
}
