#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end (for completeness, using void and double pointer)
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node is the head
        return;
    }
    
    // Connect new node to the existing list
    struct Node* last = (*head)->prev; // Last node (points to head in circular list)
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

// Function to delete a node from the list
void deleteNode(struct Node** head, struct Node* del) {
    if (*head == NULL || del == NULL) {
        return;
    }

    if (*head == del) {
        *head = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list: ");
    printList(head);

    insertAfter(head->next, 6);
    printf("After inserting 6 after 2: ");
    printList(head);

    deleteNode(&head, head->next);
    printf("After deleting 2: ");
    printList(head);

    return 0;
}