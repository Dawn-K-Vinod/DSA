/*
A menu driven program to implement a queue using an array.
This program allows users to perform various queue operations such as enqueue, dequeue, and display the queue.
*/

#include <stdio.h>
#include <stdbool.h>
int MAX_SIZE;
int FRONT = -1, REAR = -1;

bool isFull() {
    if (REAR == MAX_SIZE - 1) return true;
    return false;
}

bool isEmpty() {
    if (FRONT == -1 || FRONT > REAR) return true;
    return false;
}

void enqueue(int q[]) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n"); 
        return;
    }
    int value;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);
    if (FRONT == -1) FRONT = 0;
    q[++REAR] = value;
}

void dequeue(int q[]) {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued value: %d\n", q[FRONT]);
    if (FRONT == REAR) {FRONT = -1; REAR = -1;} 
    else FRONT++;
}

void display(int q[]) {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: [");
    for (int i = FRONT; i <= REAR; i++) {
        printf("%d ", q[i]);
    }
    printf("]\n");
}


int main() {

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &MAX_SIZE);
    int queue[MAX_SIZE];
    
    bool exit= false;
    int choice;
    while (!exit) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(queue);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;

}
