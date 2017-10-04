# More DP

## Classical DP that you should know off the top of your head
Do before divisionals.
- knapsack
- coin change
- longest increasing subsequence
- ordering matrix multiplication
- edit distance

## Non Classic DP
DP w/:
- bitmasks + subsets
- probabilties + exceptions
- choosing states/eliminating redundant states/better states/fewer states

### Bitmask DP

Example:
Given a 2D grid with a bunch of people
```
^
|           .
|   
|       .
|                   .
|   .           .
| .
|   .    .
---------------------->
```
Minimum weight perfect matching, want to match all dots to a another (to form a pair) such that they are minimal.

DP overlapping problem property: (substructure), if you choose a matching for two points, the problem left over is a subproblem of the origional

n <= 20, hints at subsets since 2^20 = 1048576 ~ 1 million

```
DP[subset] = min weight to match everyone in subset
           = min(
                        0 if subset is empty (base case),
                        min for i, j in subset (dist(i, j) + DP[subset - {i, j}])
               )
The idea is if I match i and j, the answers for everyone else is not affected.
Here trying every permutation works but is slow, try to make subsets out of it to solve all of them with DP.
```

Implementation:
- use an integer to represent a subset, a 1 bit means yes the item is in the subset, 0 means is not (called a bitmask).
Eg:
```
    a b c d e
    0 1 0 1 0
```
Is the subset {b, d}.

- to loop over all subsets, loop over all integers of a certain length, 0 represents the empty set.
```
    for(int subset = 0; subset < (1 << n); subset++) // where n is the length of the bitmask, (1 << n) takes the numner 1 ...00001 and shifts it n bits to the right to make 2^n.
```

#### bitmask operations
- check if bit i is set in the mask: `(mask & (1 << i)) != 0`
- turn on a 1 bit at position i: `mask | (1 << i)`
- flip bit at position i, if it is a 1 turn it into a 0 and vice versa: `mask ^ (1 << i)` xor is the carrot ^ or sometimes a plus with a circle around it
- turn off a bit (set it to 0): `mask & ~(1 << i)` and our mask with all the bits except the one I want to turn off.

```
int match(int subset) {
    if (subset == 0) { return 0; } // means it is empty.
    if (DP[subset] != -1) {  // -1 means not yet done.
        return DP[subset];
    }
    // Evaluate this.
    int best = INFINITY;
    for (int i = 0; i < n; i++) { // For all items in set.
        if (subset & (1 << i)) { // If bit at position i is in our subset. {
            for (int j = i + 1; j < n; j++) {
                // Loop over the bitmask to find the first 1, when you find it break.
                if (subset & (1 << j)) {  // If bit at position j is in our subset.
                    int res = dist(i, j) + match(subset & (~(1 << i)) & (~(1 << j))); // Remove i and j from subset and take the distance + matching everything else.
                    best = min(best, res);
                }

                break; // As soon as we find the first 1, try match that with everything.
            }
        }
    }
    return DB[subset] = best
}

```
### Too many states

Example:
Given two strings `a`, `b` and `a` third string `c`. Can you make the string `c` by taking characters from the start of `a` and `b`.

`a`: abcdefg
`b`: hijkl
`c`: abhijcdek

Can only take from the start.

Obvious DP uses 3d array.
DP[i][j][k] where we have taken `i` chars from `a`, `j` chars form `b` and at position `k` in `c`.

if len of strings are 5000 then the complexity `O(n^3)` which is 125000000000 (125 billion I think).

Add `i` and `j` together to find out where you are up to in `c` so you can save a lot of space to make the complexity `O(n^2)`.

```
DP[i][j] = DP[i + 1][j] if a[i] == C[i + j] or DP[i][j + 1] if b[j] == C[i + j]
```

### Treasure Hunter (reducing state space)
http://codeforces.com/problemset/problem/505/C
You are given a list of islands and money bags. You have to jump `d` places from island one, each consecutive jump just be either `d + 1` or `d - 1` places from your last jump. When you go to an island you get the money there.

Note: You can 't go negative and jump backwards.

Noob solution:
DP[i][j] = max money I can make form island i and i just jumped j.
DP[i][j] = max (
    DP[i + (j + 1)][j + 1],
    DP[i + (j - 1)][j - 1]
)

There are 30,000 islands. The naive DP is 30,000^2 states.

If `d` is large, then only a very few states will be touched.
If `d` is small then in the worst case it will start at 1, then we can jump 1 then 2 then 3 ..... which will be around sqrt(30000) to jump to 30,000 places. `d` won't be increased by more than a few hundred.


We can make `j` the distance from `d` instead of the jump distance. Making `j` the difference in jump location and `d` we can use less space (`d` is bounded to around high 200s).

```
DP[i][j] = max money from island i where I just jumped d + j // Note j can be negative now so need to implement an offset like adding 300 to everything.

DP[i][j] = max(
    DP[i + (d + j + 1)][j + 1],
    DP[i + (d + j - 1)][j - 1]
)
```
Instead of having states where we can have all the possible distances, we store the difference from d as it is bounded at a few hundred to minimize our state space.

### Probability/Expectation
Maximise/find value of something.
- often adding up possibilities/averaging possible outcomes, also optimizing something.

Example: VCPC 2016 A.

Darcy's friend will come out of door A or door B at any second, not sure which.
There are possibilities for each at a given time (won't exceed 1).
`k` seconds to walk from 1 gate to the other.

DP[t][gate] = max probability to see friend if i'm at 'gate' at time t.
DP[t][gate] = 0 if t > n
```
DP[t][gate] = (
        a<sub>t</sub> if gate == 'A',
        b<sub>t</sub> if gate == 'B'
) + max (
        DP[t + 1][gate] // stay at same gate
        DP[t + k][other gate]
)
```
### Haggling with a witcher (Probability/Expectation)
Divisionals 2016 problem H.

NPC who chooses a price (gold pieces) at random, and a threshold t.
You offer a price, if you are at most his threshold then you can take the offer or restart the game and ask him again (his number will be the same because the game is saved).

S (time) <= 10,000 ms
talking takes 100 ms
restarting takes 100 ms
if you run out of time you get 0
L, R <= 80

DP states:
- no points having `S` as 10,000 ms as part of our states as things you can do take 100 ms, divided by 100 so `S = 100`.
- if we offer `P` dollars, if he accepts then we know `t` must be between `[P, r]`
- if he rejects then `t` must be between `[l, P]`

DP[L][R][S] = Max expected value we can get if `t is in [L, R]` and we have 100 x S milliseconds left.

base case: S <= 0 then out of time. can make $0, return 0.
```
Q: What is the probability that if t is in [L, R] what is p <= t?

DP[L][R][S] = 0 if S <= 0
Pr(Accept) = ((R - P + 1) / (R - L + 1)
Pr(Reject) = ((P - L) / (R - L + 1))

DP[L][R][S] = max [value of P is from L to R // Try all values of P from L to R.] (
        (R - P + 1) / (R - L + 1) max(P, DP[P][R][S-2]) // Pr(Accept)
        + (P - L) / (R - L + 1) DP[L][P - 1][S - 1] // Pr(Reject)
)
```
`O(R^3 * T)`
