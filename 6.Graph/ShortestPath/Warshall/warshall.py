import math

W = [
    [0, 10, math.inf, 5, math.inf],
    [math.inf, 0, 1, 2, math.inf],
    [math.inf, math.inf, 0, math.inf, 4],
    [math.inf, 3, 9, 0, 2],
    [7, math.inf, 6, math.inf, 0]
]

def FW(W):
    n = len(W)
    D = dict()
    D[0] = W
    for k in range(n):
        D[k+1] = D[k]
        for i in range(n):
            for j in range(n):
                D[k+1][i][j] = min(
                    D[k][i][j], D[k][i][k] + D[k][k][j]
                )
    print(D[k+1])            
    
FW(W)    
