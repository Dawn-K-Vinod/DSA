#include <stdio.h>
#include <stdlib.h>
int MAX_SIZE;

struct memory {
    int size;
    int startAddr;
    int isFree;
    struct memory *prev;
    struct memory *next;
};

struct memory *createBlock(int size, int addr, int isFree) {
    struct memory *newnode = (struct memory*) malloc(sizeof(struct memory));
    newnode->size = size;
    newnode->startAddr = addr;
    newnode->isFree = isFree;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void displayAll(struct memory *temp);

struct memory *allocateProcess(struct memory *head, int size, int choice) {
    struct memory *temp = head, *selected = NULL;
    
    if (choice == 1) { // first fit
        while (temp) {
            if (size <= temp->size && temp->isFree == 1) { selected = temp; break; }
            temp = temp->next;
        }
    }
    else if (choice == 2 || choice == 3) { //best fit & worst fit combined
        int var = (choice==2) ? MAX_SIZE+1 : -1;
        while (temp) {
            if ((temp->isFree) && (size <= temp->size) && ((choice==2) ? temp->size <= var : temp->size >= var)) {
                var = temp->size;
                selected = temp;
            }
            temp = temp->next;
        }
    }

    if (!selected) {
        printf("There are no unallocated memory for a process of size %d.\n", size); 
        return head;
    }
    struct memory *newBlock = createBlock(size, selected->startAddr, 0);
    newBlock->prev = selected->prev;
    newBlock->next = selected;
    newBlock->isFree = 0;
    if (selected->prev) selected->prev->next = newBlock;
    selected->prev = newBlock;
    
    selected->startAddr += size;
    selected->size -= size;

    if (selected == head) { head = selected->prev; }
    if (selected->size == 0) {
        struct memory *z = selected;
        if (z->prev) z->prev->next = z->next;
        if (z->next) z->next->prev = z->prev;
        free(z);
    }
    printf("Successfully Allocated the process of size %d.\n", size);
    displayAll(head);
    return head;
}

void garbageCollector(struct memory *temp) {
    struct memory *toDelete;
    while (temp && temp->next) {
        if (temp->isFree && temp->next->isFree) {
            temp->size += temp->next->size;
            toDelete = temp->next;
            temp->next = temp->next->next;
            if (temp->next) temp->next->prev = temp;
            free(toDelete);
        }
        else {
            temp = temp->next;
        }
    }
}

void displayAll(struct memory *temp) {
    while (temp) {
        printf("%s %d-%d (sz=%d)] <-> ", 
            temp->isFree ? "[Free:" : "[Alloc:", temp->startAddr, temp->startAddr + temp->size - 1, temp->size);
        temp = temp->next;
    }
    printf("NULL\n");
}
void display_freeOrAllocatedBlocks(struct memory *temp, int isFree) {
    while (temp) {
        if (temp->isFree == isFree) {
            printf("%s %d-%d (sz=%d)] <-> ", 
                temp->isFree ? "[Free:" : "[Alloc:", temp->startAddr, temp->startAddr + temp->size - 1, temp->size);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeProcess(struct memory *head, int addr) {
    struct memory *temp = head;
    while (temp && temp->startAddr!=addr) temp = temp->next;
    if (!temp) { printf("No block starts at %d.\n", addr); return; }
    if (temp->isFree) { printf("Block at %d is already free.\n", addr); return; }
    temp->isFree = 1;
    garbageCollector(head);
    displayAll(head);
}

int main() {
    int n, size, address=0;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &n);
    struct memory *newBlock=NULL, *temp=NULL, *head;

    for (int i=0; i<n; i++) {
        printf("Enter the size of block-%d: ",i+1);
        scanf("%d", &size);
        temp = newBlock;
        newBlock = createBlock(size, address, 1);
        address += size;
        if (temp) {
            newBlock->prev = temp;
            temp->next = newBlock;
        } else temp = newBlock;
    }
    while (temp && temp->prev) temp = temp->prev; 
    head = temp;
    displayAll(head);
    MAX_SIZE = address;
    int choice;

    while (1) {
        printf("\n--Menu--\n");
        printf("1. Allocate a process\n");
        printf("2. Free/deallocate a process\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
        case 1:
            printf("Enter the size of process: "); scanf("%d", &size);
            if(size<=0) { printf("Size of a process must be greater than 0."); break;}

            printf("Choose allocation method: 1-FirstFit, 2-BestFit, 3-WorstFit: "); scanf("%d", &choice);
            if (!(choice >= 1 && choice <=3)) { printf("Invalid entry! Try Again.\n"); break; }
            head = allocateProcess(head, size, choice);
            break;
        case 2:
            display_freeOrAllocatedBlocks(head, 0);
            printf("Enter the address to free that process: ");
            scanf("%d", &address);
            freeProcess(head, address);
            break;
        case 3:
            printf("Exited the program.\n"); return 0;
            break;
        default:
            printf("Invalid entry! Try Again.\n"); 
            break;
        }
    }    
    return 0;
}
