#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1) {
        printf("Queue underflow\n");
        return -1;
    } else {
        vertex = queue[front++];
        if (front > rear) front = rear = -1;
        return vertex;
    }
}

int isEmpty() {
    return front == -1;
}

void bfs(int startVertex, int n) {
    int i;
    enqueue(startVertex);
    visited[startVertex] = 1;
    printf("BFS Traversal: ");
    
    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
        for (i = 0; i < n; i++) {
            //if in the adj matrix,vertex is available and it is not visited
            //then enqueue and make visited[i]=1 
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j, startVertex;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);
    
    bfs(startVertex, n);
    
    return 0;
}
