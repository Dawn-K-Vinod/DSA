
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
} *newnode, *head, *tail, *temp, *nextnode;

int count = 0;
void create_newnode() {
    newnode = (struct node*) malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    count++;
}

void insert_at_front() {
    create_newnode();
    if (head == NULL) head = tail = newnode;
    else {
        newnode->next = head;
        head = newnode;
    }
}
void insert_at_end() {
    create_newnode();
    if (head == NULL) head = tail = newnode;
    else {
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_position() {
    int pos;
    printf("Enter the position to insert (1-%d): ", count-1);
    scanf("%d", &pos);
    
    create_newnode();
    if (head == NULL) head = tail = newnode;
    else {
        temp = head;
        int i = 1;
        while(i < pos-1) {
            temp = temp->next; i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete_from_front() {
    temp = head;
    head = head->next;
    free(temp);
}
void delete_from_end() {
    temp = head;
    while (temp->next != tail) temp = temp->next;
    temp->next = NULL;
    free(tail);
    tail = temp;
}
void delete_from_position() {
    int pos;
    printf("Enter the position to delete (1-%d): ", count-1);
    scanf("%d", &pos);

    temp = head;
    int i = 1;
    while(i < pos-1) {
        temp = temp->next; i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}


int main() {
    newnode = head = tail = temp = nextnode = NULL;
    int choice, pos;
    bool done = 0;
    while(!done) {
        printf(">> Singly Linked List Operation Menu <<\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");        
        printf("3. Insert at position\n");        
        printf("4. Delete from front\n");        
        printf("5. Delete from end\n");        
        printf("6. Delete from position\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_at_front(); break;
            case 2:
                insert_at_end(); break;
            case 3:
                insert_at_position(); break;
            case 4:
                delete_from_front(); break;
            case 5:
                delete_from_end(); break;
            case 6:
                delete_from_position(); break;
            case 7:
                done = true; break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}