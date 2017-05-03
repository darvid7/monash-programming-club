# Dynamic Programming

Technique: solve complex problems by breaking it down into recurring simpler subproblems

Typically asked in:

- Optimization
- Counting number of solutions

## Fibonacci

1, 1, 2, 3, 5, 8, ... n

F(n) = F(n-1) + F(n-2)

def F(n):
	if (n <= 2) return 1
	return F(n-1) + F(n-2)

O(2^n)

### Recursive Fib Recursion Tree


```
								F(6)	
				F(5)							F(4)
		F(4) 			F(3)			F(3) 			F(2)
	F(3)  	F(2) 	F(2) 	F(1) 	F(2)	 F(1)
F(2) 	F(1)
```

Binary tree shape, branching factor = 2.
Complexity: 2^n

~ N levels
~ So upper bound of: 2^n nodes

Remember: Max number of nodes for a binary tree of height h = 2^(h + 1) - 1

### Using memoization

O(n) 

- values not recomputed every
- can retrieve values in O(1)

when analyzing complexity look at number of states, number of states grow with in linear way

Note: DP can't be used on questions with cycles. For DP you need it to be a DAG (directed acyclic graph)

## Longest increasing subsequence

Given an array of integers, find the longest increasing subsequence where a subsequence is just a in order subset of the array.

A = [1, 3, 2, 5, 4, 6]

Answer = 1, 2, 4, 6

### Naive Approach = 2^n * n or 2^n

### O(n^2) DP approach

- go in reverse order
f(i) = length of Longest Increasing Subsequence (LIS) begining from i

idx: 0  1  2  3  4  5 
	[1, 2, 2, 5, 4, 6]

start at index 5
1. LIS at index 5 is 1 as can just take itself
2. LIS at index 4 is 1 + 1, first 1 from 4 itself and because 4 < 6, you can extend the sequence by 1.
When checking if can extend, loop forward and pick max of all items > than current.

Cut down computation of subsets, get to 1 number.

O(n^2) as O(n) to loop backwards * O(n) to check forwards (at each time you loop backwards)

### O(n * log n) DP approach

For every iteration, do a binary search, cut array into half.

```
Given all LIS of length k, f(k) is the min element at position k (last element in LIS).

f(k) = a table, at index i it stores 

k =  1  2  3  4  5  7

idx: 0  1  2  3  4  5  
A = [1, 3, 2, 5, 4, 6]
f =  1, ~, ~, ~, ~, ~ 
f =  1, 2, ~, ~, ~, ~

l(i) means options for a increasing subsequence of length i
l(1): (1), (3), (2), (5)
l(2): (1, 3), (1, 2), (1, 5), (2, 5), (3, 5)
l(3): (1, 2, 5), (1, 3, 5)
```

#### The binary search part (Lower/Upper bound binary search)

F(k) is sorted (from F(0) -> F(k))

2 ways to do it.

1. find the first element not greater than target element you are trying to place. Lower bound binary search.

2. find first element greater than target element. Upper bound binary search.

### Coin Changing

Given a list of denominations [1, 2, 5, 20]

Target value: 24

Give minimum number of coins.

#### Naive approach

Greedy doesn't work (if no 1 denomination you're stuffed), need to backtrack (is computationally intensive).

#### DP Approach: O(n * k)

n = size of target

k = len of array of denominations

Try everything.

For 24, try take each coin away [1, 2, 5, 17, 20]

24 - 1 = 23
..
24 - 20 = 4

Trying each coin brings us down to a lower state.

Eg: target = 10

coins = [1, 2, 5, 17, 20]
index == target value: 	0	1	2	3	4	5	6	7	8	9	10
options:			
0: take 0
1: take 1
2: take 1 + 1 or take 2
...
once all options calculated, take smallest value

f(i)					0	1	1	2	2	1	2	..............

## Knapsack

Each item can only be taken once

w: weight you can carry

v: value of item

Eg: w = 4

items
weight:	1	2	2	3 
value: 	2	3	4	6

#### Greedy approach (doesn't always work)

ration of weight/value works well.

TODO: this

#### DP Approach
	weight
	0 	1	2	3	4
0					at 4
1		+3		take first item, w-=1, v+= 2		
2
3		
4

Take represents our state space

O(n * w) for number of state spaces, at each stage do a constant operation to check if should take = O(w * n)

DP table stores max value you can take.

Recording soln --> store in another 2d table.
Return location of max of original table that corresponds with items taken in other table (I think).

#### NP-ness

NP-Complete: 
P: Polynomial time, bound of n log n is P
subclass of P is NP
NP = Non-deterministic Polynomial: 
EXP = exponential time: 

Don't know relationship b/w P and NP.

What we know is, given a solution to a NP problem, we can check if it is a solution in P time.

But coming up with a NP solution is hard.

NP hard: problems where if you can find a P solution, you have proven P = NP
current solution is O(n * w) = 

Width of table = number of items you can store = weight

to make it order of n, need to do it based on number of items you can take.

if weight is 100000000, table will be size 100000000 even for only have 2 items to take.

### Traveling Salesman

Want to visit every city and arrive back at your starting city.

What is the minimum distance you need to take.

Edges (paths) are weighted.

Naive solution: n! = try everything = all permutations

#### DP solution

At any city, what you care about is what city you are at and what cities you still need to visit.

At each stage, try find what is the next city I should visit.

(city, subset of cities visited)
(n * 2^n) * n = O(n^2 * 2^n)

Key insight: you can represent your states pace as the cities you have not visited and try them.

### Algo Complexity limits

n!: n <= 10

