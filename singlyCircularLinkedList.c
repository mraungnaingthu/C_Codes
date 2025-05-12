#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;  
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to insert at a given position
void insertAtPosition(struct Node **head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; temp != *head && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == *head) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node by value ( I do not understand this function)
void deleteNode(struct Node **head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    while (temp->data != key && temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    if (temp->data != key) {
        printf("Element not found\n");
        return;
    }
    if (temp == *head) {
        if (temp->next == *head) {
            *head = NULL;
        } else {
            struct Node *last = *head;
            while (last->next != *head) {
                last = last->next;
            }
            *head = temp->next;
            last->next = *head;
        }
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to search for a node by value
int search(struct Node *head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return -1;
    }
    struct Node *temp = head;
    int position = 0;
    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    return -1;
}

// Function to print the list
void print(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function to test the implementation
int main() {
    struct Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtPosition(&head, 50, 2);
    print(head);
    deleteNode(&head, 20);
    print(head);
    printf("Element found at position: %d\n", search(head, 30));
    return 0;
}