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
