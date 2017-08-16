# Graphs

Given a graph
```
A -- B  E -- F    H
|    |          /   \
C    D        G      Z
```
Common questions:
- mutual groups of friends (connected components problem)
- within a group of friends, what is the largest degree of separation (longest chain you need to traverse, what is the longest shortest path)
- are there any important nodes that if removed, things will become disconnected
- distance between places (nodes are cities, edges are paths, shortest path)
- DAG can chain nodes and use them to represent pre-requisties, can use this to work out orderings (topological sort)


## Terminology

  - A graph G is a pair V, E: G = (V, E) where V are vertices, E are edges.
  - Edges can be weighted and/or directed.
  - edge(u, v) is the edge between vertex u and v
  - weight(u, v) is the weight of the edge between u and v
  - n = # vertices
  - m = # edges

## Representation
```
        2
w=2  /    \ w 5
    1       3
```
1. Adjacency Matrix
```
  1| 0  1  0
  2| 1  0  1
  3| 0  1  0
    _ _ _ _ _
    1   2  3
```
If weighted, edge representation depends on the problem:
- can put weights instead of 1 or 0 to represent an edge.
- might need to represent no edge with not 0 (also might be negative weights)
- infinity is a good idea (sometimes).
- can always make 2 matrices 1 that represents weight, 1 for if the edge exists (extra space, O(1) look up)

Memory: `O(n^2)`

2. Adjacency Lists (usually preferred, bad for deletions)
```
1 :[2]
2: [1, 3]
3: [2]
```
- Better than Adjacency matrix when the Graph is sparse (not many edges), store only edges we actually have.
- List of lists, for each vertex list the vertices it is connected to.
- Uses a lot less memory.

For weighted graphs, store a pair of (vertex, weight)
```
1 :[(2, 2)]
2: [(1, 2), (3, 5)]
3: [(2, 5)]
```
Memory: `O(M)`

If the graph contains every possible edge, it will use as much memory as an adjacency matrix.

Slow to delete (needs to iterate through all edges), but we hardly need to delete.

3. Balanced BST (set in C++, TreeSet in Java, good when lots of deletions)
- looping over edges is slower
- insert new edges little slower
- fast deletion

4. Edge list (only use this for Kruskals MST, rarely used)
- 1 use case for this: Kruskals minimum spanning tree
- Fast to insert new edges
- Really really bad for deleting edges

## Traversal

### Depth first search
1. start from some node
2. move to an adjacent node

- most commonly using recursion

```
function dfs(u)
  visited[u] = true  # assume visibility of this array.
  for each edge(u, v) adjacent to u:
    if not visited[v]
      dfs(v)
```
## Problems

### Connected components

Connected components are mutually connected subgraphs.

Given an undirected, unweighted graph, find the maximal connected subgraphs.

Strategy: Use a DFS (can use BFS as well, DFS is easier to code)
- DFS from some vertex
- all visited vertices are one connected components
- find a non visited vertex, repeat, this will find all connected components

Assume we are using an adjacency list.
```
function connected_components(G):
  comp_num = array[1..N] # Holds component number for each vertex.
  visited = array[1..N] # Don't really need this, can just use component number array.
  current_num = 0  # Found 0 connected components when starting.
  for each vertex u=1 to N:
    if not visited[u]:
        dfs(u) # Will go through a new component and mark that node with the component number.

function dfs(u, number): # u is vertex, number is number of current component.
  visited[u] = true
  comp_num[u] = number
  for each edge(u, v) adj to u:
    if not visited[v]:
      dfs(v, number)
```

Note: this is also called flood fill.

### Two Colouring

Can we colour a graph with just two colours such that no node is adjacent to a node of the same colour.
