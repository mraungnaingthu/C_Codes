#include <stdio.h>
#include <stdbool.h>
#define MaxSize 100

typedef struct {
    int arr[MaxSize];
    int top;
} Stack;

//Function to initialize the stack
void init(Stack *s) {
    s->top = -1;
}

//Function to check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

//Function to check if the stack is full
bool isFull(Stack *s) {
    return s->top == MaxSize - 1;
}

//Function to push an element into the stack
void push(Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack is full\n");
        return;
    }
    s->arr[++s->top] = data;
}

//Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

//Function to get the top element of the stack
int top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    printf("The top element in the stack is %d\n", top(&s));

   printf("The popped element is ");

   for (int i = 0; i < 5; i++) {
       printf("%d ", pop(&s));
   }
    printf("\n");

   
    return 0;
}