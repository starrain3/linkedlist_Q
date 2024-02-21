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

void push(Queue *Q, int value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	if(empty(Q)) {
		Q->head = newNode;
		Q->tail = newNode;
	}
	else {
		Q->head->next = newNode;
		Q->head = 	Q->head->next;
	}
}

int front(Queue *Q) {
	if(empty(Q)) {
		return 0;
	}
	return Q->head->value;
}

void pop(Queue *Q) {
	if(empty(Q)) {
		return;
	}
	Node* temp = Q->tail;
	Q->tail = Q->tail->next;
	free(temp);
}

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
