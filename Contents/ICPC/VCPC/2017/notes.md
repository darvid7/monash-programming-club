# VCPC 2017 post competition notes.

In order of assumed difficulty.

## F. Floor Plan

Many solutions.

1. lay out seats A1-A6 ...
2. assign people to practice contests
3. shift everyone 7 seats across (7 seats in a lab)

## I. Interesting Signs

Greedy doesn't work, easy to find a counter examples

AABACCA

If your greedy approach taking AA at the start then you will be stuck at BACCA.

Trying everything can lead to time limit/stack overflow/recursion limit.

Eg:

AAAAA......AAABA....AAAAA

There are many many many many ways to process this string, exponential number of ways.

Key thing: Don't repeat yourself, use a memoization table (DP).

DP[l][r] = True if can take everything in range l, r.

## B. Beginner's Training

n = 100
k = 100
10,000

Try all starting points by looping thought all students. Move window over to next student. Pick max.

n^2 * k ^2 = 10,000^2 operations = 100,000,000

To make faster:

Can make faster doing a binary search n^2 * k * log(k) but not needed.

Sweep line: n^2 * k

Sweep order stats: n * k * log (n) using a fenwick tree, segment tree, avl tree etc that maintains a sorted ordering.

## C. Chessboard Chaos

Game theory question.

Arbitrarily big chess board.

Moves:
- down x squares
- diagonally left x squares
- left x squares

Who wins if they both plays perfectly.

Winning: When your opponent can't make any more moves (the person who moves it into the bottom left corner).

Game theory terminology:
- N position: N stands for next, means next move can force win.
- P position: P stands for previous, means a previous move forced a win.

You want to move into a P position.

Question is asking, is this an N position?

P positions: (1, 1), (3, 2), (2, 3)

If you can move to a P position, you are an N position.

N positions:
- Left diagonals that can move onto any P position.
- Rows that can move onto any P positions.
- Column that can move onto any P positions.

```
P positions can only be found on the diagonals. You can just jump along diagonals to find all P positions

| n |  n | p |
| | |  n | n | n | n | n | n
| | |  n | n | n | n | p | n ......
| | |------------------------------
| | | p  | n | n | n ..............
| | | -----------------------------
| v |  n | p | n ..................
|----------------------------------
| p |  <==== n positions ======== |
|__________________________________
```

Can precompute P positions and brute force it.

Some fibonacci magic to compute in O(1) time `fi * m fi^2` where fi is the golden ratio

## E. Environmental Concern IV

Fibonacci like sequence, compute sum(i, d) ai mod m, try minimize.

Where
- d is up to 10^18
- m is up to 10000

So you can't just try sum it.

To calculate the nth fib number fast can use this magic http://fusharblog.com/solving-linear-recurrence-for-programming-contest/


### Fib numbers

| i | ai | sum to up ai |
|---|---|----|
| 0 | 0 | 0  |
| 1 | 1 | 1  |
| 2 | 1 | 2  |
| 3 | 2 | 4  |
| 4 | 3 | 7  |
| 5 | 5 | 12 |
| 6 | 8 | 20 |

### Numbers in the problem

| i | ai | sum to up ai |
|---|---|----|
| 0 | 0 | 0  |
| 1 | 2 | 2  |
| 2 | 4 | 6  |
| 4 | 10 | 12  |
| 5 | 16 | 22  |


`sum(i, n) ai = a sub(n + 2) - a sub 2`

Now it is pretty much compute the nth + 2 fib number.

To compete the nth fib number for large n can plug it into a matrix.

| Nicely | formatted | matrix | multiplication | =] |
| --- | --- | ---| ---|
| a<sub>i + 1</sub>|  = | 1   1 | *  | a<sub>i</sub>|
| a<sub>i</sub>|   | 1   0 |    | a<sub>i-1</sub>|

Use fast exponentiation.

To compute a^1000,000,000 = (a^500,000,000)^2

Exponentiation by squaring.

So to get the value it is log(d).

Need to do modding as you go in the fast exponentiation. If you mod as you go then the very worse you can get is the mod^2.

Try all values of m.

O( (R - L) * log (d))

log(10^18) ~ 63

## K. Kreative Konstruction

If you disconnect an edge and the graph is still connected, nothing is achieved.

We only want to consider edges that will disconnect the graph (or bridges).

A bridge is an edge that if taken out, will disconnect the graph.

Approaches:
- n^2 for taking each edge and checking. n is up to 200,000 so you can't do n^2.

- at max n-1 bridges (will form a tree), so can't just try the bridges.

- bridges form a tree of clumps of stuff that are connected, don't want to compute how many vertices in the connected components many times, just do it once.

Use DP. Count how many vertices in each subtree.

`S * (N - S)` is the value of inconvenience.

Two edge connected component tree.

Compute:
- bridges in linear time O(n) dfs, maintain two stats
    - when did I first see this node
    - whats the lowest number node I can see
    - if you can see something smaller you are in a cycle and you are not a bridge.
- do dp to count the number of components in each component (this can be done in the above dfs, how many nodes did I see before backtracking and crossing the bridge).
- look up for each bridge what does the mode dmg.

## G. Guardians of the Galaxy

Given a bunch of points on a plane.

Asked where should we put another point such that the distance to any other point is the smallest possible.

Minimum enclosing circle problem.

For all points to be enclosed, the circle with the max radius will enclose all points.

Find smallest circle that encloses every point.

Read up: https://en.wikipedia.org/wiki/Smallest-circle_problem

## Stuff above this seems doable, stuff below is like :fearful: :cry: :sob: :scream:
## J. Juggling Errands

250 * 250 grid of points (250^2 nodes)

up to 100,000 queries.

A BFS is around 5 * 250^2 = 325,000

100,000 queries = 31,250,000,000

Exploit path over lap.
- lots of paths will probably go through he center of the grid


Divide grid into two quarters along the horizontal and vertical.

Do 500 BFS's, then we have the shortest path for any query that crosses the boundary.

Can divide and conquer this approach and recurse down.

Draw a diagram for this.

Linear number of BFS's, log number of recursions going down.

Mixture of BFS, divide and conquer, recursion.

Having every time and adding up is at worse the geometric series which is at worst double of the work in the first time.

## D. Dice

Want
```
pr(roll(a, b) element of [L, R])

= # of ways to roll in [L, R] / # of rolls

# of rolls = A * B
```

| ways to roll | sum | rolls |
|---|---|---|
| 1 | 1 | (1, 1) |
| 2 | 3 | (1, 2), (2, 1) |
| 1 | A + B | (A, B) |
| 2 | A + B - 1 | (A, B-1), (A-1, B) |

At most there are A ways of rolling something,

Once you can compute the pr of stuff, you can't just try all pairs of dice as 100,000 of them.

Given a1 find b that maximises this probability.

Plot graph thingy (uni modal, single peak) and then do a ternary search [<- learn this].

note: need to sore die.
