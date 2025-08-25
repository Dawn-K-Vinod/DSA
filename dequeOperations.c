/*
C Program to demonstrate deque operations using array
*/

#include <stdio.h>

int MAX_SIZE;
int FRONT = -1, REAR = -1;

void insert_front(int q[]) {
    if (FRONT == 0) { printf("Queue is full. Cannot insert at front.\n"); return;}
    
    int value;
    printf("Enter the value to insert at front: ");
    scanf("%d", &value);

    if (FRONT == -1) { FRONT = 0; REAR = 0;} 
    else if (FRONT > 0) FRONT--; 
    q[FRONT] = value;
    printf("Inserted %d at front.\n", value);
}

void insert_rear(int q[]) {
    if (REAR == MAX_SIZE-1) { printf("Queue is full. Cannot insert at rear.\n"); return;}
    
    int value;
    printf("Enter the value to insert at rear: ");
    scanf("%d", &value);

    if (FRONT == -1) { FRONT = 0; REAR = 0;} 
    else REAR++; 
    q[REAR] = value;
    printf("Inserted %d at rear.\n", value);
}

void delete_front(int q[]) {
    if (FRONT==-1) { printf("Queue is empty. Cannot delete from front.\n"); return;}
    
    int value = q[FRONT];
    FRONT++;
    if (FRONT > REAR) FRONT = REAR = -1;
    printf("Deleted %d from front.\n", value);
}

void delete_rear(int q[]) {
    if (REAR==-1) { printf("Queue is empty. Cannot delete from rear.\n"); return;}
    
    int value = q[REAR];
    REAR--;
    if (FRONT > REAR) FRONT = REAR = -1;
    printf("Deleted %d from rear.\n", value);
}

void display(int q[]) {
    if (FRONT==-1) {
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

    printf("Enter the maximum size of the DE-queue: ");
    scanf("%d", &MAX_SIZE);
    int queue[MAX_SIZE];
    
    int exit= 0;
    int choice;
    while (!exit) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display DE-queue\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_front(queue);
                break;
            case 2:
                insert_rear(queue);
                break;
            case 3:
                delete_front(queue);
                break;
            case 4:
                delete_rear(queue);
                break;
            case 5:
                display(queue);
                break;
            case 6:
                exit = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;

}
