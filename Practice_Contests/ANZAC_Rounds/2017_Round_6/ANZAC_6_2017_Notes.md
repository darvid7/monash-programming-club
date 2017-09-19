# ANZAC 6 2017

## E

.isSorted()

Stories can be funnier when it is easy.

The question is pretty much is the array sorted.

## A

`sqrt(10^16)` = `10^8`, can do in O(n).

some number `n = a * b`. For sake of argument say `a > b`.
this means that `b <= sqrt(n)`.

Try all possible values of `b` from `2` to `sqrt(n)`.

## C

state space is `100^2`,

## H

Destroy either 1 building or 1 floor for all buildings.

Greedy solution works.

Sort first.

Try all:
1. destroy first floor or all buildings
2. destroy buildings individually
3. count number of shots fire
Note: computation to destroy first floor and then work out the number of buildings left should be O(1).
Keep going

May as well delete all floors at once, then the building second.

Destroy 0 floors = need to destroy n buildings.
Try destroy 1 floor, work out the number of buildings you are left with = n - buildings with 1 floor.

Another way is to delete highest building and then look at the building with the max height left, then you are left with h operations to get rid of remaining buildings.

## K

2D grid with `(x, y)` coords.

Graph problem.

Distances
```
         .
         |
         y
.___x____|
```
- Euclidian point to point
- Manhattan x + y
- Inf-Norm max(x, y)

## D

Turn it into a graph problem, check for cycles.

Can be done with topological sort (if fails then it doesn't work).

Dfs works as well.

## I

`factor_huge()` code binder, returns list of factors. But it sometimes gives 1's.

## M

Dijkstra like question handling blocked edges (direct parent).

Can use a 3D array to keep track of bad edges.

(?)
Make it as you go

## B

Dictionary 300, 000 words.

Find how many words, what is the longest word and score.

Can't use same tile in a single word, but can do use it for multiple words.

For each word found, is it in my dictionary.

Try every possible path will TLE. Try paths of lengths <= 8. Need to use backtracking. What is the current string I have built, what is in my trie. Trie lookup is O(1).

Prune while going through, paths that are not a prefix of anything in the dict is useless.

Use a prefix trie to check this. Prefix trie will prune search space.

16 chose 8, can choose order you do it in.

Complexity: 16 chose 8 * 8! * log(300, 000) = 2 * 10^9 = 2 billion.

If using a balanced bst i.e. map in c++, with a trie = 16 choose 8 * 8!

Need backtracking, remember to undo your statechanges.

## G

For each sprinkler mark the circle area.

For each sprinkler, look at points in it. m * r^2 = 200, 000, 000.

Look at bounding square of 2r and check if the point is in the circle.

Store things in a 10000 * 10000 grid.

Keep in integers, do distance^2 things.

## F

Try everything, similar to B in that search space will decrease.

## J

DP problem.

options = [ti, ei] where t is time at i and e is best guess at i.

input can be parsed as a prefix trie of words.

```
Sample 2:

         root
       /       \
    when        what
     |             |
    do             do
    |              |
    we             we
    |              |
    send          want -----
    |            /          \
ans: code   ans: accepted    it
                             |
                          ans: now    

at each node, it has probability pr1 which is the probability you go down that edge.
pr2 is if you go down that edge and guess right away. this is the max answer at that subtree divided by the total number of answers.

pr1 = pr go down this path.
pr2 = max(#ans)/#leaves
pr1 * pr2 = expected value

expected_value = max(guess_right_now, listen_a_bit_more)

guess_right_now = p2 probability
listen_a_bit_more = hear the next word = sum(probability of going to word i * it's expected value)
```

DP approach: 2D table, DP[t][node] where t is the time we have left and node is where we are in the tree.
```
max(
        p2 + DP[t-1][0],
        sum( prob(wi) * DP[t - 1][wi] )
    )
```
Note: if using a tree, might need to make it into a trie which is compressed.

## L

A bunch of math.
