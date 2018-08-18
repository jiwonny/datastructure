#include <stdio.h>

#define MAX_VERTICES 10
#define FALSE 0
#define TRUE 1
#define MAX_QUEUE_SIZE 100

short int visited[MAX_VERTICES];
short int visited2[MAX_VERTICES];
typedef struct queue *queuePointer;
typedef struct queue {
	int vertex;
	queuePointer link;
};
queuePointer graph[MAX_VERTICES];
queuePointer front, rear;

void addq(int v) {//program 4.7-list
	queuePointer temp;
	temp = (queuePointer)malloc(sizeof(*temp));

	temp->vertex = v;
	temp->link = NULL;
	if (front)
		rear->link = temp;
	else
		front = temp;

	rear = temp;
}

int deleteq() {
	queuePointer temp = front;
	int ver;
	if (!temp) {
		printf("queue empty");
		return;
	}
	ver = temp->vertex;
	front = temp->link;
	return ver;

}

void bfs(int v) {
	queuePointer w2;
	printf("%5d", v);
	visited2[v] = TRUE;
	addq(v);//정점의 노드 큐에 저장.
	while (front) {
		v = deleteq();//
		for (w2 = graph[v]; w2; w2 = w2->link) {
			if (!visited2[w2->vertex]) {
				printf("%5d", w2->vertex);
				addq(w2->vertex);
				visited2[w2->vertex] = TRUE;
			}
		}
	}

}

void dfs(int v) {
	queuePointer w;

	visited[v] = TRUE;
	printf("%5d", v);

	for (w = graph[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs(w->vertex); //순환(스택)
}

int main(void) {
	int idx;
	queuePointer temp1, temp2, temp3,temp4;
	for (idx = 0; idx < MAX_VERTICES; idx++) {
		graph[idx] = (queuePointer)malloc(sizeof(*graph[idx]));
	}

	for (idx = 0; idx < 8; idx++) {
		graph[idx]->vertex = idx;
	}

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));

	graph[0]->link = temp1;
	temp1->vertex = 1;
	temp1->link = temp2;
	temp2->vertex = 2;
	temp2->link = NULL;

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));
	temp3 = (queuePointer)malloc(sizeof(*temp3));

	graph[1]->link = temp1;
	temp1->vertex = 0;
	temp1->link = temp2;
	temp2->vertex = 3;
	temp2->link = temp3;
	temp3->vertex = 4;
	temp3->link = NULL;

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));
	temp3 = (queuePointer)malloc(sizeof(*temp3));

	graph[2]->link = temp1;
	temp1->vertex = 0;
	temp1->link = temp2;
	temp2->vertex = 5;
	temp2->link = temp3;
	temp3->vertex = 6;
	temp3->link = NULL;

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));

	graph[3]->link = temp1;
	temp1->vertex = 1;
	temp1->link = temp2;
	temp2->vertex = 7;
	temp2->link = NULL;

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));

	graph[4]->link = temp1;
	temp1->vertex = 1;
	temp1->link = temp2;
	temp2->vertex = 7;
	temp2->link = NULL;

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));

	graph[5]->link = temp1;
	temp1->vertex = 2;
	temp1->link = temp2;
	temp2->vertex = 7;
	temp2->link = NULL;

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));

	graph[6]->link = temp1;
	temp1->vertex = 2;
	temp1->link = temp2;
	temp2->vertex = 7;
	temp2->link = NULL;

	temp1 = (queuePointer)malloc(sizeof(*temp1));
	temp2 = (queuePointer)malloc(sizeof(*temp2));
	temp3= (queuePointer)malloc(sizeof(*temp3));
	temp4 = (queuePointer)malloc(sizeof(*temp4));

	graph[7]->link = temp1;
	temp1->vertex = 3;
	temp1->link = temp2;
	temp2->vertex = 4;
	temp2->link = temp3;
	temp3->vertex = 5;
	temp3->link = temp4;
	temp4->vertex = 6;
	temp4->link = NULL;


	printf("깊이우선탐색 dfs :\n");
	dfs(0);
	printf("\n너비우선탐색 bfs :\n");
	bfs(0);
	printf("\n");
	return 0;
}