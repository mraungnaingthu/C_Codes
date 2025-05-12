#include <stdio.h>
#include <stdbool.h>
#define MaxSize 100

typedef struct {
    int arr[MaxSize];
    int front, rear;
} Queue;

//Function to initialize the queue
void init(Queue *q) {
    q->front = -1;
    q->rear = 0;
}

//Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return (q->front == q->rear - 1);
}

//Function to check if the queue is full
bool isFull(Queue *q) {
    return q->rear == MaxSize;
}

//Function to add an element to the queue
void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear] = data;
    q->rear++;
}

//Function to remove an element from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->arr[q->front];
}

//Function to get the front element of the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front + 1];
}

//Function to get the rear element of the queue
int rear(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->rear - 1];
}

//Function to print the queue
void print(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front + 1; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}


int main() {

    Queue q;

    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("The front element of the queue is %d\n", peek(&q));
    printf("The rear element of the queue is %d\n", rear(&q));
    printf("The queue is ");
    print(&q);

    int dequeuedElement = dequeue(&q);
    if (dequeuedElement != -1) {
        printf("Dequeued element is %d\n", dequeuedElement);
    }
    printf("The front element of the queue is %d\n", peek(&q));

    printf("The queue is ");
    print(&q);



    return 0;
}