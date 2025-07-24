#include <stdio.h>
#include <stdbool.h>

#define V 4

void BFS(int graph[V][V], int start) {
    bool visited[V] = { false };
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front != rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        for (int i = 0; i < V; i++) {
            if (graph[curr][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0},  // 0 -> 1, 2
        {0, 0, 1, 0},  // 1 -> 2
        {1, 0, 0, 1},  // 2 -> 0, 3
        {0, 0, 0, 1}   // 3 -> 3 (self loop)
    };

    printf("BFS starting from vertex 2:\n");
    BFS(graph, 2);

    return 0;
}
