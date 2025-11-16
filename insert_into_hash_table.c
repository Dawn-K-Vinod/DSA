#include <stdio.h>
#include <stdlib.h>

struct cell {
    int value;
    struct cell *next;
};

struct cell *createNewCell(int value) {
    struct cell *newCell = (struct cell*) malloc(sizeof(struct cell));
    newCell->value = value;
    newCell->next = NULL;
    return newCell;
}

// normal hash function ``k mod h``
int hash(int k, int t_size) {return k % t_size;}

void displayHashTable(struct cell* table[], int size) {
    struct cell *temp;
    for (int i = 0; i < size; i++) {
        temp = table[i];
        printf("%d | ", i);
        while(temp) {
            printf("[%4d] --> ", temp->value);
            temp = temp->next;
        }
        if (!temp) {
            printf("[NULL]");
        }
        printf("\n");
    }
}

int main() {
    // here i used separate chaining method
    int tableSize = 10, n;
    struct cell* hashTable[tableSize];
    for (int i = 0; i < tableSize; i++) hashTable[i] = NULL;
    
    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);
    if (n<=0) { printf("Exiting the program..."); return 0;}
    
    int index, key;
    struct cell *newCell, *temp;
    for (int i = 0; i < n; i++) {
        printf("Enter key-%d: ", i+1); scanf("%d", &key);
        newCell = createNewCell(key);

        index = hash(key, tableSize);
        temp = hashTable[index];
        if (temp) {
            while (temp->next) temp = temp->next;
            temp->next = newCell;
        }
        else {
            hashTable[index] = newCell;
        }
    }
    printf("Successfully inserted all given keys into the hash table.\n");
    displayHashTable(hashTable, tableSize);
    printf("\nLoad factor: %.2f\n", (float) n/tableSize);
    return 0;
}
