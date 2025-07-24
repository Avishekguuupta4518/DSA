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
