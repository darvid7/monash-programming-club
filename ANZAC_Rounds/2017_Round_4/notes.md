# Do later:

## Problem L
(bfs, 1 path, dfs identical as bfs, need to consider the force path)

## Problem M (easy problem in world finals 2 years ago).

Solve recursively, check roots are the same and their children.

Trees can have subtrees of them selves of children.

Different number of children = not equal.

```
bool same(u, v) {
  if |c[u]| != |c[v]|
    return false
}

# Can set things to true in advance as in the for loop it will do the actual check.
# DP approach.
# if DP[u][v]: return true
# DP[u][v] = true

# Disjoint set approach.
# UnionFind(N+M)
# if connected(u, v)
#   merge(u, v)

for i = 1 to |c[u]|
  if (!same(c[u][i], c[v][i]))
    return false
return true
```

will solve the case where trees are not repeating

|c[u]| used to count num children?

Add in some DP to check if we have seen trees.

With DP it is still slow.

To fix use a disjoint set to do a union find to see if things are connected.

Due to transitivity if u = v, v = w then u = w.

This speed up means we don't need to try all pairs, as long as we try a few we can find out things.

### Sample input 3
```
input:
3 1
2 1 1
2 2 2
2 0 0  
2 0 0

first tree:
              (0)
          /         \
       (1)            (1)
      /   \           /  \
    (2)    (2)      (2)   (2)
    / \    / \     / \    / \
  (0) (0) (0) (0) (0) (0)(0) (0)  

second tree:
      (0)
      / \
    (0) (0)

(0)'s recurse on

They are the same as we just care about what the tree looks like not the actual
numbers.
```

## Problem N

Complexity: ~ O(n^2 log n)

1. Find shortest path
2. For each segment in shortest path
3.    Remove that and find the new shortest path
4.    Add that back in
5. Return the shortest shortest path of the new shortest paths

For the next best thing type problems: Find best thing, remove a piece of the
solution and try find the solution again.

## Problem O

Given a sequence, and left and right endpoints, find out the number of disjoint combinations
that add to k.

Disjoint means if the sequence is: 2 3 5 3 then you can't pair 2 and 3 together twice to make 5,
but if it isL 2 3 5 2 3 you can as there are two 2's.


Naive solution.

```
input: 2 3 5 3
i     : 0 1 2 3 4 5
arr[i]: 0 0 1 2 0 1

for char in input:
  increment arr[char idx]

match them up as you go to make k.
```
### Better Approach: Mo's Algorithm

Do queries not in the order they are given

1. Bucketize with ranges 0 to root n, root n to 2 root n (rounded up) by left endpoint.
2. In each bucket, sort intervals by right endpoint.
3. Do the stuff below for each bucket

```
k = 5
index    : 0 1 2 3 4 5 6 7 8
input seq: 2 3 5 3 4 2 3 1 2'

i     : 0 1 2 3 4 5
arr[i]: 0 1 2 3 1 1


eg: in a Bucket
(2, 4) <- do naive solution, matches = 0
(4, 5) <- expand in both directions naively, matches = 0
(1, 7) <- extend right endpoint from 5 to 7, add in 2, matches = 1
       <- extend left endpoint to 1, add in 2, 3, 5, matches = 2
(2, 9) <- extend right endpoint to 9 (index 8), matches = 3
       <- restrict the left endpoint to start from 2nd index, remove a two in arr[i], reduce matches by 1, matches = 2

so answer will be 0, 0, 2, 2 for above intervals.

The right endpoint is increasingly increasing meaning the right endpoint is moved at most N times.
The left endpoint can only move up/down by root N (due to bucket ranges).

right: O(n)
left: O(Q * root n) where Q is number of queries in this bucket.

Now unsort them to output answer in right order.

Total complexity: root n * O(each bin) = O(Q * root n + n * root n)
Each bin: O(n) + O(n) + O(Qi * root n)
        initial   right   per query
```
Note: in problems you don't actually code root n, find root n of the max input size and go from there.
In trivial cases it will do everything in one bucket, but in big test cases it will perform well.
