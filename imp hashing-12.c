#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Initialize table with -1
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert key
void insert(int key) {
    int index = hash(key);

    // Linear probing
    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            printf("%d inserted at index %d\n", key, newIndex);
            return;
        }
    }
    printf("Hash table full!\n");
}

// Search key
void search(int key) {
    int index = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == key) {
            printf("%d found at index %d\n", key, newIndex);
            return;
        }
        if (hashTable[newIndex] == -1)
            break;
    }
    printf("%d not found\n", key);
}

// Display table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("Index %d --> %d\n", i, hashTable[i]);
}

int main() {
    int choice, key;

    init();

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
