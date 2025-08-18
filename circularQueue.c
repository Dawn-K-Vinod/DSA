/*
A menu driven program that performs circular queue operation using array.
Opeartion: enqueue, dequeue
other funtion: display
*/


#include <stdio.h>
#include <stdbool.h>

int MAX_SIZE;
int FRONT=-1, REAR=-1;

bool isFull() {
    if ((REAR+1)%MAX_SIZE == FRONT) return true;
    return false;
}
bool isEmpty() {
    if (FRONT == -1) return true;
    return false;
}

void enqueue(int cq[]) {
    if (isFull()) {
        printf("The queue is full. Enqueue operation cannot be done!\n");
        return;
    }
    REAR = (REAR+1)%MAX_SIZE;
    printf("Enter the value to be enqueued: ");
    scanf("%d", &cq[REAR]);
    if (FRONT==-1) FRONT=0;
}

void dequeue(int cq[]) {
    if (isEmpty()) {
        printf("The queue is empty. Dequeue operation cannot be done!\n");
        return;
    }
    printf("The dequeued value: %d\n", cq[FRONT]);
    if (FRONT==REAR) {
        FRONT = -1; REAR = -1;
        return;
    }
    FRONT = (FRONT+1)%MAX_SIZE;
}

void display(int cq[]) {
    if (isEmpty()) {
        printf("The Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue Elements:\n[");
    int i = FRONT;
    do {
        printf("%d ",cq[i]);
        i = (i+1)%MAX_SIZE;
    } while (i != (REAR+1)%MAX_SIZE);
    printf("]\n");
}


int main() {
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &MAX_SIZE);

    int cq[MAX_SIZE];
    bool exit = false;
    int choice;

    while (!exit) {   
        printf("\n**Circular Queue Operations Menu**\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enqueue(cq); break;
            case 2:
                dequeue(cq); break;
            case 3:
                display(cq); break;
            case 4:
                exit = true; break;
            default:
                printf("Invalid choice!");
        }       
    }
    return 0;
}