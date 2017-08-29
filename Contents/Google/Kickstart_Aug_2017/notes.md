# Google Kickstart Aug 2017 notes

## A

At each state either
- type 1 char
- copy from clip board (300 options)
- look for substrings to copy (300 options)

No point to copy something before, type then paste it later, no point copying for the future.

Every time you copy, you want to paste.

DP approach to try everything.

Looping left to right, when the index is low, the number of strings possible on our clipboard is also low.

O(300^5) is too slow, O(300^4) will work.

KMP + modify

For each substring we need two pieces of information.
- left and right endpoint, have we seen these strings before.
- keep track of left most right endpoint.
- keep information in a map.

n^2 states, map calls n log n (in c++ or n worst case in python).

Every substring has a number associated, so can compare substrings every easily.

For each substring, where is the left most place it exists.

Nice trick: start at the end and see what the longest we can find is.

Main idea
- DP where we are up to, how far we have built
- contents of clip board

300 (space) * 300^2 (time)

Big dp give away: is the start stuff independent to what I need to do to finish the stuff?

Dp[len] = min # of operations to complete the string from position len
1. pre process to get a map of <string, int> of substrings storing where you first saw them
2. Do a dp for each possible option, try everything.
  - can either type, try copy and paste (and build up substring fro there)


O(300) space for map of substrings.
O(300^2) for trying to place 300 substrings in all 300 places.

# B

Large data set number of sticks upper bound <= 5000.

This tells you try every pair.
5000^2 ~ 1 Million which is doable to try every pair.
Don't go above 1000 squared.

Try all pairs of bottom and top.

eg: where t is the top and b is the bottom.

  t -----
b ----------

side_len > (b-t)/2

if equal means that the structure is flat which is invalid.

All possible side lengths = [(B-T)/2, max(input_set)], only integer lengths.

1. sort lengths
2. preprocess so we can have efficient queries for pairs
- start from the back to make a frequency map (not a vanilla freq map count, but a record of how many pairs after this suffix)

```
Store for each suffix, how many pairs are in that suffix.

ans = 0
map<int, int> freq
loop over index, x (backwards):
  ans += freq[x]
  freq[x]++
  suffix_sum[index] = ans
```

If you have 20 z values and you take one z value away, you have gotten rid of 19 potential pairs as that one z can be matched to any of the other 19 z's.

so go to freq[T] - 1


# C

All spheres have to be connected so at any point at any sphere you can walk to any other point in any of the 3 spheres.

First idea: minimum, floating point number, is monotonic --> think binary search

Minimization problems: makes you think of binary search.

Output number to x decimal places: makes you think of binary search you are approaching but not computing.

Try this radius, too big too small from binary search.

1D is trivial, think about 2D next before 3D.
