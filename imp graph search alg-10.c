#include <stdio.h>

int graph[10][10];      // adjacency matrix
int visited[10];
int queue[10];
int front = -1, rear = -1;

// BFS Queue Functions
void enqueue(int x) {
    if (rear == 9) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Depth First Search
void DFS(int vertex, int n) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}

// Breadth First Search
void BFS(int start, int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int vertex = dequeue();
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int start;

    printf("Enter start vertex for DFS: ");
    scanf("%d", &start);
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start, n);

    printf("\nEnter start vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start, n);

    return 0;
}
