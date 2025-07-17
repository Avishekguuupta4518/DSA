# Kruskal's Algorithm Explained

## Introduction
Kruskal’s Algorithm is a **greedy algorithm** used to find the **Minimum Spanning Tree (MST)** of a weighted, connected, and undirected graph. It works by selecting the smallest edges first while ensuring no cycles are formed.

## Algorithm Explanation
The algorithm follows these steps:
1. **Sort all edges** in ascending order based on weight.
2. **Initialize a Disjoint Set** to keep track of connected components.
3. **Iterate through sorted edges** and add the smallest edge to the MST if it doesn’t form a cycle.
4. **Repeat** until all vertices are included in the MST.

## Code Implementation
```python
class DisjointSet:
    """Disjoint Set (Union-Find) with path compression and union by rank."""
    
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, node):
        """Finds the root of the set with path compression."""
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])  # Path compression
        return self.parent[node]

    def union(self, u, v):
        """Performs union by rank."""
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def kruskal_algorithm(vertices, edges):
    """Implements Kruskal’s algorithm to find the Minimum Spanning Tree (MST)."""
    
    # Step 1: Sort edges by weight
    edges.sort(key=lambda edge: edge[2])  # Sort by weight (third element)

    # Step 2: Initialize Disjoint Set for cycle detection
    ds = DisjointSet(vertices)
    
    mst = []  # Stores MST edges
    mst_cost = 0  # Total weight of MST

    # Step 3: Iterate through sorted edges and pick the smallest non-cyclic edge
    for u, v, weight in edges:
        if ds.find(u) != ds.find(v):  # If adding edge doesn't form a cycle
            ds.union(u, v)
            mst.append((u, v, weight))
            mst_cost += weight

    # Step 4: Print MST
    print("Edge \tWeight")
    for u, v, weight in mst:
        print(f"{u} - {v} \t{weight}")

    print("Total Cost of MST:", mst_cost)

# Example Graph (Edge List Representation)
vertices = 5
edges = [
    (0, 1, 2),
    (0, 3, 6),
    (1, 2, 3),
    (1, 3, 8),
    (1, 4, 5),
    (2, 4, 7),
    (3, 4, 9)
]

kruskal_algorithm(vertices, edges)
```

## Visualization
### **Graph Representation**
Consider the following weighted graph:
```
     (0)---2---(1)---3---(2)
      |         |         |
      6         8         7
      |         |         |
     (3)---9---(4)---5---(1)
```
Where each number represents the weight of the edge.

### **Step-by-Step Execution**
1. **Sort edges by weight**: [(0,1,2), (1,2,3), (1,4,5), (0,3,6), (2,4,7), (1,3,8), (3,4,9)]
2. **Iterate through edges** and add them to MST if they don’t form a cycle.
3. **Final MST Edges**:
   ```
   0 - 1   2
   1 - 2   3
   1 - 4   5
   0 - 3   6
   ```

### **Minimum Spanning Tree (MST) Output**
```
Edge    Weight
0 - 1   2
1 - 2   3
1 - 4   5
0 - 3   6
Total Cost of MST: 16
```

## Complexity Analysis
- **Sorting edges** takes **O(E log E)**.
- **Union-Find operations** run in nearly **O(1)** using path compression.
- **Overall complexity**: **O(E log V)**, making Kruskal’s algorithm efficient for sparse graphs.

## Applications
- Network Design (Communication, Electrical Grids, Transportation)
- Clustering in Machine Learning
- Image segmentation in Computer Vision

### Conclusion
Kruskal’s Algorithm efficiently finds the Minimum Spanning Tree (MST) using a greedy approach. It is particularly useful for sparse graphs where sorting edges is computationally feasible.