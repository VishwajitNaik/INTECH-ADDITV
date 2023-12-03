#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to find the kth to the last element of a linked list
struct Node* kthToLast(struct Node* head, int k) {
    if (head == NULL || k <= 0) {
        return NULL;
    }

    struct Node *s = head, *s1 = head;
    int i = 1;

    // Move s1 k nodes ahead
    while (s1->next != NULL && i < k) {
        i++;
        s1 = s1->next;
    }

    // If k is greater than the length of the linked list
    if (i < k) {
        return NULL;
    }

    // Move s and s1 until s1 reaches the end
    while (s1->next != NULL) {
        s1 = s1->next;
        s = s->next;
    }

    return s;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    return;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test the functions
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Linked List: ");
    printList(head);

    int k = 3;
    struct Node* kthNode = kthToLast(head, k);

    if (kthNode != NULL) {
        printf("The %dth to the last element is: %d\n", k, kthNode->data);
    } else {
        printf("Invalid value of k\n");
    }

    return 0;
}
