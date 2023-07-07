//
// Created by leen on 7/5/23.
//

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void list_insert(struct Node** head, int x) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
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
    list_insert(&head, 1);
    list_insert(&head, 4);

    list_insert(&head, 23);
    list_insert(&head, 17);
    list_insert(&head, -5);
    list_insert(&head, 100);

    // Print the linked list
    printList(head);

    return 0;
}

