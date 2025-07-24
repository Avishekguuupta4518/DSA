#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

// Function to find vertex with minimum distance from unvisited set
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print shortest path from source to j using predecessor array
void printPath(int predecessor[], int j) {
    if (predecessor[j] == -1) {
        printf("%c", 'A' + j);
        return;
    }
    printPath(predecessor, predecessor[j]);
    printf("->%c", 'A' + j);
}

// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];           // shortest distance from src to i
    bool visited[V];       // visited vertices
    int predecessor[V];    // to reconstruct path

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        predecessor[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break; // all reachable vertices visited
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            // If not visited, there's an edge, and new distance is shorter
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                predecessor[v] = u;
            }
        }
    }

    // Print results
    printf("Vertex\tDistance from %c\tPath\n", 'A' + src);
    for (int i = 0; i < V; i++) {
        printf("%c -> %c \t %d \t\t ", 'A' + src, 'A' + i, dist[i]);
        if (dist[i] == INT_MAX) {
            printf("No path\n");
        } else {
            printPath(predecessor, i);
            printf("\n");
        }
    }
}

int main() {
    int graph[V][V] = {
        // A  B  C  D  E
        { 0, 3, 1, 0, 0 }, // A
        { 3, 0, 7, 5, 1 }, // B
        { 1, 7, 0, 2, 0 }, // C
        { 0, 5, 2, 0, 7 }, // D
        { 0, 1, 0, 7, 0 }  // E
    };

    int start = 0; // 'A'
    dijkstra(graph, start);

    return 0;
}
