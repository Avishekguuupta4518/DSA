# Warshall's Algorithm (Floyd-Warshall Algorithm) Explained

## Introduction
Warshall's Algorithm, also known as the **Floyd-Warshall Algorithm**, is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph. It works efficiently for graphs with **positive or negative weights** but **no negative weight cycles**.

## Algorithm Explanation
The algorithm maintains a distance matrix `dist[][]`, where `dist[i][j]` represents the shortest distance from vertex `i` to vertex `j`. It iteratively updates this matrix considering intermediate nodes step by step.

### Steps:
1. **Initialize** the distance matrix with the given graph's adjacency matrix.
2. **Iterate over each node** as an intermediate node `k`.
3. **Update all pairs `(i, j)`** using the relation:
   
   \[
   dist[i][j] = \min(dist[i][j], dist[i][k] + dist[k][j])
   \]
   
4. **Repeat for all nodes** until the matrix contains shortest distances between all pairs.

## Code Explanation
```python
INF = float('inf')

def floyd_warshall(graph):
    # Number of vertices in the graph
    n = len(graph)
    
    # Distance matrix initialization
    dist = [[graph[i][j] for j in range(n)] for i in range(n)]
    
    # Applying Warshall's algorithm
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
    return dist

# Example Usage
graph = [
    [0, 3, INF, 5],
    [2, 0, INF, 4],
    [INF, 1, 0, INF],
    [INF, INF, 2, 0]
]

shortest_paths = floyd_warshall(graph)
for row in shortest_paths:
    print(row)
```

## Visualization
### **Initial Graph Representation**
Assume the following adjacency matrix representation:
```
    0    3    ∞    5
    2    0    ∞    4
    ∞    1    0    ∞
    ∞    ∞    2    0
```
Where **∞ (INF)** represents no direct path.

### **Step-by-Step Iteration**
- The algorithm iteratively updates paths using all nodes as intermediates.
- Example: If there is a path `1 → 3` through `2` that is shorter than `1 → 3` directly, it updates `dist[1][3]`.

### **Final Shortest Path Matrix**
```
    0    3    7    5
    2    0    6    4
    3    1    0    5
    5    3    2    0
```

## Complexity Analysis
- The algorithm runs in **O(V³)** time complexity, where `V` is the number of vertices.
- It uses **O(V²)** space for storing distances.

## Applications
- Finding shortest paths in road networks
- Network routing optimization
- Social network analysis
- Robotics and AI pathfinding

### Conclusion
The **Floyd-Warshall Algorithm** is a powerful approach for computing shortest paths in a graph efficiently. It is simple yet effective for dense graphs and applications requiring shortest path analysis.