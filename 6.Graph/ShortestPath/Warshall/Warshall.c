#include <stdio.h>
#include <limits.h>

#define V 4

void printMatrix(int dist[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize distance matrix same as input graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Run Floyd-Warshall
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Check if vertex k is on the shortest path from i to j
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printMatrix(dist);
}

int main() {
    int INF = INT_MAX;
    int graph[V][V] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floydWarshall(graph);

    return 0;
}
