# TODO: read up on this stuff until it makes sense.

# Pattern Matching

- Does string A exist in string B

- Try every position and check strings are equal = n^2

# KNP

- worst case linear time O(n)

- approach: Matched a particular prefix properly, use this.

T = ABCDAB|AB|CDABCDABCE

P = ABCD|AB|D<-

upon reaching D and seeing the first partial match doesn't match. We can start from the next occurrence of AB knowing that a particular prefix is the same -> saves time, don't repeat work.


We are not looking anywhere in T twice.

Have 2 pointers, when a miss match occurs move a pointer backwards.

# Suffix Array

faster version = prefix doubling O(n) time suffix array

Makes use of obvious fact about string comparison.

2 strings of length N each, complexity =  O(n), loop through all strings.

that is the bottle neck of doing a suffix array manually


### Prefix doubling

1. Sort characters of string in order (sort substrings of length 1)

banana = $ a a a b n n

N(log(N))^2 

Can make this N log (N) if you use radix/bucket sort
