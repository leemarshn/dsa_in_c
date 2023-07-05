//
// Created by leen on 7/5/23.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void list_insert(struct Node** head, int x, int i) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;

    if (i == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    for (int count = 0; count < i - 1; count++) {
        if (current == NULL) {
            printf("Invalid position\n");
            return;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Utility function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create the head node of the linked list
    struct Node* head = NULL;

    // Insert elements into the linked list
    list_insert(&head, 1, 0);
    list_insert(&head, 23, 1);
    list_insert(&head, 17, 2);
    list_insert(&head, 4, 3);
    list_insert(&head, -5, 4);
    list_insert(&head, 100, 5);

    // Print the linked list
    printList(head);

    return 0;
}

