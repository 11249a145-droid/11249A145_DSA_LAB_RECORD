#include <stdio.h>

// Function declarations
void display(int arr[], int n);
void insert(int arr[], int *n, int pos, int value);
void delete(int arr[], int *n, int pos);
int search(int arr[], int n, int key);

int main() {
    int arr[100], n, choice, pos, value, key, result;

    // Input array size and elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n=== ARRAY OPERATIONS MENU ===\n");
        printf("1. Display array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(arr, &n, pos, value);
                break;
            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &key);
                result = search(arr, n, key);
                if (result == -1)
                    printf("Element not found.\n");
                else
                    printf("Element found at position %d.\n", result + 1);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the array
void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a position
void insert(int arr[], int *n, int pos, int value) {
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    (*n)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element from a position
void delete(int arr[], int *n, int pos) {
    if (pos < 1 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element deleted successfully.\n");
}

// Function to search for an element (Linear Search)
int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

