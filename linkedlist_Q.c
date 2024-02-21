#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
	int value;
	struct node* next;
}Node;

typedef struct queue{
	Node *head;
	Node *tail;
}Queue;

// Initialize an empty queue
void initQueue(Queue *Q) {
    Q->head = NULL;
    Q->tail = NULL;
}

//check if the queue is empty or not
bool empty(Queue *Q) {
    if (Q->head != NULL) {
        return false;
    }
    return true;
}

//push a new node into queue
void push(Queue *Q, int value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if(empty(Q)) {
		Q->head = newNode;
		Q->tail = newNode;
	}
	else {
		Q->tail->next = newNode;
		Q->tail = Q->tail->next;
	}
}

//print out the first value in the queue
int front(Queue *Q) {
	if(empty(Q)) {
		return 0;
	}
	return Q->head->value;
}

//pop a node out of the queue
void pop(Queue *Q) {
	if(empty(Q)) {
		return;
	}
	Node* temp = Q->head;
	Q->head = Q->head->next;
	free(temp);
}

//print out the last value in the queue
int back(Queue *Q) {
	if(empty(Q)) {
		return 0;
	}
	return Q->tail->value;
}

int main() {
    Queue myQ;
    initQueue(&myQ);
    printf("empty() return %s\n", empty(&myQ)?"true":"false");
    push(&myQ, 5);
    push(&myQ, 4);
    push(&myQ, 3);
    push(&myQ, 2);
    printf("front() return %d\n", front(&myQ));
    printf("back() return %d\n", back(&myQ));
    pop(&myQ);
    printf("front() return %d\n", front(&myQ));
    printf("back() return %d\n", back(&myQ));

    return 0;
}
