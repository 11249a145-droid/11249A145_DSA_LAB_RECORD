#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insertBegin(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
    printf("%d inserted at beginning\n", value);
}

// Insert at end
void insertEnd(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        printf("%d inserted at end\n", value);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    printf("%d inserted at end\n", value);
}

// Delete from beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("%d deleted from beginning\n", temp->data);

    head = head->next;
    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    printf("%d deleted from end\n", temp->data);

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;   // list had only 1 node

    free(temp);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertBegin(20);
    insertBegin(10);
    insertEnd(30);
    insertEnd(40);

    display();

    deleteBegin();
    deleteEnd();

    display();

    return 0;
}
