# Graph Theory

- undirected (bi directional)

- directed 

- weighted

- unweighted

- disconnected

loops called a cycle

- cyclic graph (has a cycle)

- degree = how many edges are connected to a node/vertex

note: node with loop to itself is counted as 2 degree

Real world, using a set/dict for an Adjacency list is probs smart but for contests assume they force it to become the worst case O(n) lookup so iterating over an array is fastest.

## Adjacency lists are ideal for comps

- weighted graph, store (connecting_node, weight) tuples

- directed graph, store index of node connecting, undirected do same but both ways)

## Searching Adjacency lists

### Depth First Search

Idea: start at node, do processing, explore neighbors (lexicographical order) as far as possible (skip if seen, start form next node if no where to go)

Application:

- cycle finding, doing DFS on any vertex and we run into a seen node, there is a cycle.

- disconnected graphs, do DFS, if any vertex was not seen = graph is disconnected.

Depth = Stack

#### Easy DFS

dfs(node):
	if node is seen: return
	process stuff here
	set not as seen
	for each adj_node connected to node:
		if adj_node is seen: continue
		else: dfs(adj_node)

This uses the call stack and pops stuff instead of using a stack in memory as a variable like a queue in BFS. Computer stack (used by recursive fun) is faster than in memory stack.

To set as seen can create a new array of size num_nodes and init to all False, when reaching a node set it to True, do this instead of a class.

### Breadth First Search

Idea: check all nodes on 1 level, once done go to the next level deeper.

Note: DFS vs BFS, if both recursive DFS is faster, if iterative both same speeds. DFS is used more because easier to implement.

Application:

- find distance (steps to get to a node), good if distance is universal

Breadth = Queue

### Dijkstra

- makes sense on weighted graphs (non negative)

- continues on shortest path

Finds distance from start node to very other node (gives shortest path to all of them)

Can use an array of distances and update that rather than a node class with .dist.

Uses a Priority Queue

PQ in C++ prioirty_Queue<(int, int)> pq_nam

this compares the first int (being the weight) and then the next int (being the vertex index) and orders based off that.







