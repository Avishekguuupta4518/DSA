# Prim's Algorithm Explained

## Introduction
Prim's Algorithm is a **greedy algorithm** used to find the **Minimum Spanning Tree (MST)** of a weighted, connected, and undirected graph. The MST is a subset of edges that connects all vertices with the minimum possible total edge weight and without any cycles.

## Algorithm Explanation
The algorithm works as follows:
1. **Initialize**: Choose an arbitrary starting vertex and mark it as selected.
2. **Find the Minimum Edge**: Select the edge with the lowest weight that connects a selected vertex to an unselected vertex.
3. **Include the Selected Edge** in MST and mark the new vertex as selected.
4. **Repeat** the process until all vertices are included in the MST.

## Code Implementation
```python
import sys

def prims_algorithm(graph):
    num_vertices = len(graph)
    selected = [False] * num_vertices  # Track selected vertices
    min_edge = [sys.maxsize] * num_vertices  # Store minimum edge weight
    parent = [-1] * num_vertices  # Store parent of each vertex in MST

    min_edge[0] = 0  # Start from vertex 0

    for _ in range(num_vertices):
        # Find the vertex with the minimum edge weight that is not yet included in MST
        min_weight = sys.maxsize
        u = -1

        for v in range(num_vertices):
            if not selected[v] and min_edge[v] < min_weight:
                min_weight = min_edge[v]
                u = v

        selected[u] = True  # Include the vertex in MST

        # Update minimum edge weights for adjacent vertices
        for v in range(num_vertices):
            if graph[u][v] and not selected[v] and graph[u][v] < min_edge[v]:
                min_edge[v] = graph[u][v]
                parent[v] = u

    # Print MST
    print("Edge \tWeight")
    for i in range(1, num_vertices):
        print(f"{parent[i]} - {i} \t{graph[i][parent[i]]}")

# Example graph represented as an adjacency matrix
graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

prims_algorithm(graph)
```

## Visualization
### **Graph Representation**
Consider the following adjacency matrix representation of the graph:
```
    0    2    ∞    6    ∞
    2    0    3    8    5
    ∞    3    0    ∞    7
    6    8    ∞    0    9
    ∞    5    7    9    0
```
Where **∞ (INF)** represents no direct edge.

### **Step-by-Step Execution**
1. Start with **vertex 0** and mark it as selected.
2. Find the smallest edge connected to the selected vertices and expand MST.
3. Continue until all vertices are included in MST.

### **Minimum Spanning Tree (MST) Output**
```
Edge    Weight
0 - 1   2
1 - 2   3
1 - 4   5
0 - 3   6
```

## Complexity Analysis
- **Time Complexity**: **O(V²)** (Using adjacency matrix representation)
- **Space Complexity**: **O(V²)** (For storing the graph)

## Applications
- Network Design (LAN, electrical grids, road networks)
- Clustering in Machine Learning
- Image segmentation in Computer Vision

### Conclusion
Prim’s Algorithm is an efficient and intuitive approach to finding a Minimum Spanning Tree (MST) using a greedy strategy. It is best suited for dense graphs where an adjacency matrix representation is feasible.