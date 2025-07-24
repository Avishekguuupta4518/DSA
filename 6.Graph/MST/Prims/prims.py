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
