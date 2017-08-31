# Max flow applications

Flow networks are directed graphs w/ capacity on edges.
How much stuff can you push from S (source) to T (target).

Residual graph is an edge backwards.

## Variations of Max flow

NEVER EVER ERVER MODIFY YOUR ALGORITHM (Ford-Fulkerson)

Modify the graph instead

### Vertex capacities

Add an edge for each vertex with capacity so
```
(A) -w-> (B) -w-> (C)

if (B) has a capacity, transform it to

(A) -w-> (B1) -b-> (B2) -w-> (C)

Where b is the capacity of (B)
```

### Bipartite matching

Two sets where edges only exist from one to another.

```
Edges only between node set A and B, never within a single set.
Edges only from A to B.

    | Set   |--> | Set   |
S-->| of    |--> | of    | -> T (all nodes have an edge to Target)
    | nodes |\   | nodes |
    | A     | \_>| B     |
S is source node with edges to all other nodes in A with capacity 1.    
```

Give each edge a capacity of 1, total number of edges = max flow.

### Assignment Problem (Generalised bipartite matching)

Bipartite matching but instead of 1 you may want multiple of things.


Eg VCPC 2016 question.
For a contest, you have a set of problems, a set of categories and a set of
difficulties. Can model this as a bunch of bipartite matching with the
number of the type of questions as capacities.

### Minimum Cut

Minimum cost to remove some edges so that we can't get to S anymore.
Cost is usually the sum of max flow of the removed edges.

max flow <= min cut

### Min Cut Max Flow Theorem

min cut = max flow

### Edge-disjoint paths

Given a network flow graph.

Assign 1 capacity to each edge.

Do a max flow, the max at the target is the number of disjoint edge paths.

To get the path, do a dfs from S, for each edge encountered make capacity 0.

Do number of disjoint edge paths times to get all paths.

If you want only two paths extend T with another node T' and give the edge in between a capacity of 2.

### Vertex-disjoint paths

Do vertex splitting by adding an edge b/w each vertex and splitting the vertex into two. Do edge-disjoint paths algorithm.

### Implementing
