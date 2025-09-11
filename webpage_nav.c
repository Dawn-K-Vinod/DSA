
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    char URL[20];
    struct node *prev, *next;
} *head, *tail, *newnode, *current;

void visit_new_page() {
    
    if (current != tail && current != NULL) {
        while (tail != current) {
            tail = tail->prev;
            free(tail->next);
            tail->next = NULL;
        }
    }

    newnode = (struct node*) malloc (sizeof(struct node));
    printf("Enter the URL: ");
    scanf(" %19[^\n]", newnode->URL);

    if (current == NULL) head = tail = current = newnode;
    else {
        newnode->prev = current;
        newnode->next = NULL;
        current->next = newnode;
        current = tail = newnode;
    }
}

void go_back() {
    if (current == NULL || current->prev == NULL) printf("Can't Go Back\n");
    else {
        current = current->prev;
        printf("Moved back\n");
    }
}
void go_forward() {
    if (current == NULL || current->next == NULL) printf("Can't Go forward\n");
    else {
        current = current->next;
        printf("Moved forward\n");
    }
}
void display() {
    if (current == NULL) {
        printf("No page visited yet!");
        return;
    }
    printf("The current wepage: %s\n", current->URL);
}



int main() {
    head = tail = newnode = current = NULL;

    int choice = 0;
    int done = false;
    while (!done) {
        printf("\n>> DLL Operations Menu <<\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visit_new_page(); break;
            case 2:
                go_back(); break;
            case 3:
                go_forward(); break;
            case 4:
                display(); break;
            case 5:
                done = true; break;
            default:
                printf("Invalid choice"); 
        }
    }
    return 0;
}
