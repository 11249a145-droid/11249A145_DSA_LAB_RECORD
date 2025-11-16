
#include <stdio.h>
#define SIZE 100  // maximum size of the queue

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to insert an element (Enqueue)
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
    } else {
        if (front == -1)  // first element
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}

// Function to delete an element (Dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("=== QUEUE IMPLEMENTATION IN C ===\n");

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
