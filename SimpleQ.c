#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void enQueue(int);
void deQueue();
void display();

int queue[SIZE];
int front = -1, rear = -1;

int main() {
    int value, choice;
    while (1) {
        printf("\n\n***** MENU *****\n");
        printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong selection!!! Try again!!!\n");
        }
    }
    return 0;
}

void enQueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("\nQueue is Full!!! Insertion is not possible!!!\n");
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = value;
        printf("\nInsertion success!!!\n");
    }  else {
        rear++;
        queue[rear] = value;
        printf("\nInsertion success!!!\n");
    }
}

void deQueue() {
    if (front == -1) {
        printf("\nQueue is Empty!!! Deletion is not possible!!!\n");
    } else if (front == rear) {
        printf("\nDeleted : %d\n", queue[front]);
        front = rear = -1;
    }  else {
        printf("\nDeleted : %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty!!!\n");
    } else {
        int i;
        printf("\nQueue elements are:\n");
        if (rear >= front) {
            for (i = front; i <= rear; i++) {
                printf("%d\t", queue[i]);
            }
        } else {
            for (i = front; i < SIZE; i++) {
                printf("%d\t", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d\t", queue[i]);
            }
        }
        printf("\n");
    }
}
