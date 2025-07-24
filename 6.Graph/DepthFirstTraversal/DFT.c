#include <stdio.h>
#include <stdbool.h>

#define V 5

void DFS(int graph[V][V], int start) {
    bool visited[V] = { false };
    int stack[V];
    int top = -1;

    stack[++top] = start;

    while (top != -1) {
        int v = stack[top--];

        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = true;
        }

        // Push neighbors in reverse order to mimic the C++ rbegin->rend
        for (int i = V - 1; i >= 0; i--) {
            if (graph[v][i] && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0, 0}, // 0->1,2
        {0, 0, 1, 0, 0}, // 1->2
        {1, 0, 0, 1, 0}, // 2->0,3
        {0, 0, 0, 1, 0}, // 3->3
        {0, 0, 0, 0, 0}  // 4 no edges
    };

    printf("Depth First Traversal starting from vertex 2:\n");
    DFS(graph, 2);

    return 0;
}
