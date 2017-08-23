# Shortest paths

## Terminology

- V: vertices/nodes
- E: edges
- n = # vertices
- m = $ edges

## Assumptions:

- no loops
- no multiple edges
- connected

## DFS vs BFS

| DFS | BFS |
| ---- | ---- |
| Easier to code | Slow in practice |
| Uses recursion, computer stack is faster than any queue | Uses a queue of sorts, not as fast as computer's recursion stack |
| Explores as deep as possible | Explores nodes closest first by level |
| No information about distance | Can find shortest path
|`O(n + m)`|`O(n + m)`|

## BFS

`O(n + m)`: best possible as need to look at each edge once and each vertex once to ensure you have seen the entire graph.

Note: in the connected case you can not care about n as for a graph with n nodes, it will have at max n - 1 edge. So processing all edges will process all nodes so `O(m)`.

```
BFS(adj_list, src):
  bool visited[n] = {0};

  int dist[n] = {-1};
  queue q; // If you use stack instead of queue, you will have DFS.

  dist[src] = 0;
  q.push(src);
  visited[src] = true;

  while (!q.empty()) {
    t = q.front();  // What is the first thing in the queue.
    // From docs:  void pop()
    q.pop(); // pop it off, pop does not return a value.

    for each u in adj[t] {
      if (visited[u]) {
        continue;
      }
      dist[u] = dist[t] + 1; // + 1 for 1 level deeper.
      visited[u] = true;
      q.push(u);
    }
  }
  return dist;
```

## BFS vs Bellaman Ford vs Dijkstra vs Floyd Warshall

| BFS | Dijkstra | Bellman-Ford | Floyd Warshall |
| --- | --- | --- | --- |
| un-weighted | weighted (non -negative) | negative, positive and zero | negative, positive and zero |
| `O(n + m)`, if connected `O(m)` | `O((m + n ) * log (m))`, if connected `O((m + m) * log (n)) = O(m log (m))` | `O( n * m )` which is a lot worse than m + n | `O(n^3)` |

Dijkstra is Bellman-Ford, but in Dijkstra you are relaxing edges in a very particular order (closest first). In Bellman-Ford you relax edges at random.

## DJ ikstra's Algorithm

Similar to BFS but for weighted graphs.

Use a priority queue of (distance, vertex) instead of a queue.

```
DJ_ikstra(adj_list, src):
  bool visited[n] = {0};

  int dist[n] = {-1};
  priority_queue pq; // If you use stack instead of queue, you will have DFS.

  dist[src] = 0;
  pq.push(0, src);

  while (!pq.empty()) {
    (d, t) = pq.top();  // What is the first thing in the queue.
    pq.pop(); // pop it off, pop does not return a value.

    // -1 means we haven't seen it yet.
    if (d >= dist[t] && dist[t] != -1) {
      // current distance is > than distance we know, no point doing this.
      continue;
    }

    for each u in adj[t] {

      if (dist[u] != -1 && dist[t] + w[u, t] >= dist[u]) {
        continue;
      }

      dist[u] = dist[t] + 1; // + 1 for 1 level deeper.
      visited[u] = true;
      pq.push(dist[u], u);
    }
  }
  return dist;
```
`O((n + m) * log (m) ) = O( log edges * (edges + nodes))`

## Fords of Bellman

1. Set everything to positive infinity to say there is no path from src to target

2. Distance array holds shortest path possible using at least i edges.

3. Do things n - 1 times, then do it one more time. At the end go through graph again, if anything changes there is a negative cycle.

Detect what vertices belong in a negative cycle/are affected in a negative cycle. Run it 2n times and check for what changes.

```
bellman_ford(V, E, src):
  dist = [ inf, inf, inf, in, inf, inf]
  dist[src] = 0
  for i from 1 to 2n:
    for each edge (u, v): // in each iteration, relax edge (u, v)
      if dist[u] + w(u, v) < dist[v]:
        dist[v] = dist[u] + w(v, u)
        change[v] = i // last time each array entry was changed
  if changed[v] <= n - 1:
    dist[v] is right
  else:
    dist[v] is part of/influenced by a negative cycle and dist[v] is negative infinity.
```

## Floyd Warshall

Gives shortest path from any vertex to any other.

```
A[i][j] is the weight of the edge from i to j
dist[i][j] is the distance between i and j.

dist[i][i] = 0 // Can get to ourselves from ourselves in instance time.

dist[i][j] = infinity

for k from 1 to n:
  for i from 1 to n:
    for j from 1 to n:
      if (dist[i][j] > dist[i][k] + dist[k][j]):
        dist[i][j] = dist[i][k] + dist[k][j]
```

`dist array` will be correct unless there is a negative cycle, `if dist[i][i] is negtive`. Look along the diagonal for each node to itself, if negative then you have a negative cycle.
