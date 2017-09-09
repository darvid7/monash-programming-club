VISITED = 1
UNVISITED = 2

def dfs(u):
    dfs_num[u] = VISITED
    if u == T:
        return True
    for v in adjList[u]:
        if dfs_num[v] == UNVISITED:
            if dfs(v):
                return True
    return False

N, T = [int(x) for x in input().split()]

adjList = []
for i in range(N+5):
    adjList.append([])
dfs_num = [UNVISITED]*(N+5)


a = [int(x) for x in input().split()]

for i in range(1, N):
    adjList[i].append(i+a[i-1])

if dfs(1):
    print("YES")
else:
    print("NO")

print(dfs_num)
