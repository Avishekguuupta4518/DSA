#include <stdio.h>
#include <stdlib.h>

// Disjoint Set structure
typedef struct {
    int *parent;
    int *rank;
    int size;
} DisjointSet;

// Initialize Disjoint Set
DisjointSet* createDisjointSet(int n) {
    DisjointSet* ds = malloc(sizeof(DisjointSet));
    ds->size = n;
    ds->parent = malloc(n * sizeof(int));
    ds->rank = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

// Find with path compression
int find(DisjointSet* ds, int node) {
    if (ds->parent[node] != node)
        ds->parent[node] = find(ds, ds->parent[node]);
    return ds->parent[node];
}

// Union by rank
void unionSets(DisjointSet* ds, int u, int v) {
    int rootU = find(ds, u);
    int rootV = find(ds, v);

    if (rootU != rootV) {
        if (ds->rank[rootU] > ds->rank[rootV]) {
            ds->parent[rootV] = rootU;
        } else if (ds->rank[rootU] < ds->rank[rootV]) {
            ds->parent[rootU] = rootV;
        } else {
            ds->parent[rootV] = rootU;
            ds->rank[rootU]++;
        }
    }
}

// Edge structure
typedef struct {
    int u, v, weight;
} Edge;

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal’s algorithm
void kruskal(int vertices, Edge edges[], int edgeCount) {
    // Sort edges by weight
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    DisjointSet* ds = createDisjointSet(vertices);

    int mstCost = 0;
    Edge mst[edgeCount];  // To store MST edges
    int mstSize = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(ds, u) != find(ds, v)) {
            unionSets(ds, u, v);
            mst[mstSize++] = edges[i];
            mstCost += edges[i].weight;
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 0; i < mstSize; i++) {
        printf("%d - %d \t%d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    printf("Total Cost of MST: %d\n", mstCost);

    // Cleanup
    free(ds->parent);
    free(ds->rank);
    free(ds);
}

int main() {
    int vertices = 5;
    Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    kruskal(vertices, edges, edgeCount);

    return 0;
}
