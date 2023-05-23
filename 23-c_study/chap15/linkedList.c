#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	int num;
	char name[20];
	struct data * next;
	
}data;

data * g_head = NULL;
data * g_tail = NULL;

data *find(int num) {
	if(g_head == NULL) {
		printf("no data...\n");
		return NULL;
	}
	data *temp = g_head;
	while(temp){
		if(temp->num == num){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}


void printAll() {
	if(g_head == NULL) {
		printf("no data...\n");
		return;
	}
	data *temp = g_head;
	printf("===================================================\n");
	while(temp->next) {
		printf("num : %d\n",temp->num);	
		printf("name : %s\n",temp->name);	
		printf("===================================================\n");
		temp = temp->next;	
	}
	printf("num : %d\n",temp->num);	
	printf("name : %s\n",temp->name);	
	printf("===================================================\n");	

}

int insert(int num, char * name) {

	data * node = malloc(sizeof(data));

    	node -> next = NULL;
	node -> num = num;
	if(name != NULL) {
		strcpy(node->name, name);
	}
	
	if(g_head == NULL) {
		g_head = node;
		g_tail = node;
		return 1;
	} else {
		data *temp = g_head;
		while(temp->next) {
			temp = temp->next;
		}
		temp->next = node;
		g_tail = node;
		return 1;
	}
	return 0;
}

data *pop() {
	if(g_head == NULL){
		return NULL;
	}
	data *node = g_head;

	if(g_head->next != NULL){
		g_head = g_head->next;
	}else{
		g_head = NULL;
		g_tail = NULL;
	}
	
	return node;

}

data *stack_pop() {
	
	if(g_head == NULL) {
		return NULL;
	}
	
	data *node = g_tail; 

	data *temp = g_head;
	data *before = NULL;

	while(temp->next) {
		before = temp;
		temp = temp->next;
	}
	
	g_tail = before;
	if(before != NULL) {
		before->next = NULL;
	}

	if(g_tail == NULL) {
		g_head = NULL;
	}

	return node;

}

int main() {
	char name[20] = "";
	for(int i = 0; i < 10; i++) {
		sprintf(name,"test %d",i);
		insert(i,name);
	}	
	printAll();

	/*for(int i = 0; i < 10; i++) {
	data * node1 = stack_pop();
	printf("pop num : %d\n",node1 -> num);
	printf("pop name : %s\n",node1 -> name);
	free(node1);
	}
	printAll();*/

	for(int i = 0; i < 10; i++) {
	data * node1 = pop();
	printf("pop num : %d\n",node1 -> num);
	printf("pop name : %s\n",node1 -> name);
	free(node1);
	}
	printAll();

	/*data *node = find(7);
	if(node != NULL){
		printf("find num : %d\n",node -> num);
		printf("find name : %s\n",node -> name);

	}else{
		printf("error\n");
	}*/

	return 0;
}
