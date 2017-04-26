# Fenwick Tree (a.k.a binary index tree) - max sum in range

Use when things change in the array.
If things don't change build a cumulative sum array.

- bit manipulation techniques
- binary increases in digits faster than decimal (more digits, dec 9 = 1001 = 4 digits) 
- idea: can take off bits and get to 0

10 | 1010
8  | 1000
0  | 0000

Fenwick Tree goal (ft): Able to do sum over arrays (sum within array indices) and update them.

Fenwick Tree is 1 indexed, so plus 1 for everything at the end.

Eg: 

Array of numbers, know sum of a range of numbers in that array.

For each number in array, theses is a ft value.

ft stores:		---------------------------14
ft stores:		------------2				
ft stores:		
ft stores:		----1			----7			----3
ft stores:		0       0       3       2       1
arr:			0	1	0	1	3	4	3	2	2	1
index:			1	2	3	4	5	6	7	8	9	10


------num is the sum (sum = num) over everything under '-'

for sum = 14 at index 8
8 = 1000 in binary, taking off least sig '1' = 0000 so draw '-' until 0th index. But since it is 1 indexed, if it is 0, draw '-' until 1 (shouldn't happen).

0 is a dummy value.

Usage:

sum of number in range [1, 7].

1. start at number you are summing from = 7, go to index 7, get value 3.
	7 in binary = 111
2. Take least sig 1 = 110 = 6 in decimal, go to index 6 and get value 7.
	6 in binary = 110
3. Take least sig 1 = 100 = 4 in decimal, go to in dex 4, get value 2.
	4 in binary = 100
4. Take least sig 1 = 000 = 0 in decimal + 1 - index 1 take value 0. 

Add numbers 3 + 7 + 2 = 12

If range [4, 7]

Do same process for [0, lower_bound - 1]

1. start at 3, in bin = 11, go index 3 and take value  0
2. start at bin 10 = 2, go to index 2 and take value 1.
3. start at bin 00 = 0 + 1, take value 1 at index 1, done.

minus [0, 3] from [0, 7] = 11 = [4, 7]

Complexity: O(log n)
Construct complexity: O(n log n)

Any number has log(n) bits, worst case process all bits = O(log n)

21312341 in binary is 1010001010011001101010101, has 25 bits.

log base 2 of 21312341 is 24.345186

-2 & 2 = 2

1111111111111111111111111111111111111111111111111111111111111110  | -2 in binary (2's complement)
0000000000000000000000000000000000000000000000000000000000000010  | 2 in binary
AND both = 0000...000010 = 2

Note: All computers use 2's complement

Twos complement:
1. flip all bits
2. add 1

Eg:
1. 0010 = 1101
2. 1101 + 1 = 1110
Twos complement of 2 is 1110, two is 0010
And together = 0010 = 2

# Segment Tree - min number in range

- given a range, give the minimum number in this range.
- naive, do a loop = O(n)
- segment tree can handle updates

Start at top segment, covers the whole range. Get min.
Half and make sub segments, find min and keep halving.

segment:	----------------------------------------1
segment:	------------------------2  -------------1
segment: 	--------2   --------5      -----1   ----2
segment:	----2  -4   ----7  -5	----1  -9 -7  -2
segment:    -5  -2     -7  -8      -3  -1  
numbers: 	5	2	4	7	8	5	3	1	9	7	2
index:		0	1	2	3	4	5	6	7	8	9 	10

Complexity: O(log n)
- only traverse further down when there is a segment that is inside and outside the range.
- only log n segments that cross over as log many levels
- log many levels as halving each time
- get to 0 in log number of steps
- any layer apart from top most, as soon as you split into 2 branches, 1 of the 2 branches will quit on the next step (range is fully contained).

Construct Complexity: O(n)

Look at:
- log n things on your path
- log n things you go down, check and decide you don't want that and go back up

Updates:
- update node and every ancestor

Storing segments.
For any binary tree, can set the root node to be index 1 in an array. Make left child 2 and right child 3. Keep counting left to right to fill out indexes.

Where in (n)i n = number and i = index in array.

			   (0)1
		(2)2		 (3)2
	(2)4	(5)5   (0)6	 (1)7

Children are your index * 2 and your index * 2 + 1

## Segment Tree with Range Updates

eg: Set entire range of x to y = 1.

Updating individually is log n per element = len(range to update) * log n, slow for many range updates.




# Sparse Tables - answers range minimum query, but can't update.

log n segments
do for all numbers
n log n total segments
						________________________________1
						________________2
						____2
						_4
numbers: 		5	2	4	2	8	5	3	1	9	7	2

https://www.quora.com/What-is-a-sparse-table-data-structure-and-how-does-it-work

Gives query in O(1) constant time

In contest it is easier to code a sparse table
- O(1) and O(log n) is ~ around the same for contests

Note: if you negate -2^31 you get the same thing back (-2^32)

# DP: Palindromes

string: aababaaab

A palindrome is a string thats the same forwards and backwards i.e. abba, ana, hannah

For every letter, how far can you go to the left and the right so that it is still a palindrome.

DP: Calculates whats the longest possible palindrome at any center.

O(n^2) keep going until you find 2 letters that don't match = longest palindrome.

String with all a's eg: aaaaaaa, keep going until hitting boundaries. Naive O(n^2)

Start at left, work your way right.

Deal with odd len first.

DP: What is longest palindrome with this as our center.

A[i] is the longest palindrome centered at i.
- look one to left, one to right, if same keep going

		<- <- i -> -> 

## Naive Algorithm O(n^2)

For A[0], centered at 0, nothing to our left, answer = 1

## Better O(n)

[.., L, .., i-1, i, .., R, ..]

- if working along string up to location i
- lets say at i-1, found a palindrome that is centered at i-1 which spans L to R 
- if the palindrome exists at i-1, then i must be equal to i-2

if take L to R and flip, palindrome stays the same, reflects over.

[ a0 a1 a2 a3 a4 a5 a6 ] a7

same as

a6 a5 a4 a3 a2 a1 a0

Look at the guy before us that has the farthest end point.

1. use reflection where possible
2. use naive algorithm when cant

R will always move to the right, if R doesn't move does 1 simple look up.

R moves a linear amount of time, Look ups can be done R times = O(n)

http://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/

O(n-k) amount of work for first big palindrome, then never do work as use reflection, after that will only do extra work to make it O(n)

Loop over n elements, each of them being a center

O(n+n) = O(2n)


