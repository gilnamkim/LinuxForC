#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;
pthread_mutex_t mutex;

void * thread1(void * arg) {
	
	printf("arg : %d\n",(int)arg);

	while(1) {
		
		pthread_mutex_lock(&mutex);
		printf("thread%d a[%d]\n",(int)arg,++a);
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
	return NULL;
}





int main() {
	
	pthread_t s_thread[2];
	int id1 = 77;
	int id2 = 88;
	
	pthread_mutex_init(&mutex,NULL);

	// 쓰레드 생성
	pthread_create(&s_thread[0], NULL, thread1,(void *)id1);
	pthread_create(&s_thread[1], NULL, thread1,(void *)id2);

	while(1) {
		
		printf("main loop\n");
		sleep(1);
		
	}

//	pthread_join(s_thread[0], NULL);
//	pthread_join(s_thread[1], NULL);

}
