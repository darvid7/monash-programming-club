# Week 4

## Primes

why is it O(n*log(log(n)))
number of primes < n is around n/loge(n)

first prime is 2, cross off all multiples of 2: 2, 4, 6, 8, ..1000000 // complexity is roughly 10000000/2 as crossing off every 2nd number
second prime is 3, cross off all multiples of 3: 3, 6, 9, 12, ...1000000 // complexity is roughly 1000000/3
..
..
nth prime is n, cross off all multiples of n: 2n, 3n, ..1000000 // complexity is roughly 1000000/n

complexity is how many numbers we cross off

1000000/2 + 1000000/3 + .. + 1000000/n // note 1 mill = 1

= n(1/2 + 1/3 + .. + 1//n)


```
x     x   x   x x
1 2 3 4 5 6 7 8 9
x     x     x  x  x     x
10 11 12 13 14 15 16 17 18

19 20

How to tell what are primes

start at 1, 1 is not a prime
then @ 2, check for all numbers, if divisor by 2 is not a prime,
do same for 3, if divisor cross off

naive algorithm
- slight speed up, cross off a number, cross off its square

// c++ code, need algo library.

bool isprime[1000001]; // array of booleans that say is number prime, go up to a million.

fill(isprime, isprime+1000001, true)
ifprime[0] = false;
isprime[1] = false;

// O(n  * log(log(n)))
// not many primes, will go fast, for bigger primes, because multiles will get to 1 million very quickly.

for (int i=2; i*i<=1000000; i++) {
	if (isprime[i]) {
		for (int j=2*i; j<= 1000000; j+=1) { // get all primes and do stuff
			isprime[j]=false;
		}
	}
}
```

## Greatest common divisor

Eclid's Algorithm

2 numbers 24, 32

GCD --> list out all divisors

24: 1, 2, 3, 4, 6. 8. 12. 24
32: 1, 2, 4, 8, 16, 32


largest divisor that appears in both list = 8

one way is to list out powers of 2

24 = 2^3 * 3^(1)
32 = 2^5 * 3^(0)

gcd = 2^min(3,5) * 3^min(1, 0)

	= 2^(3) * 3^(0) = 8 * 1 = 8 :)

gcd(32, 24) = gcd(24, 32 % 24) // remainder when 32 div 24 = 8


gcd(m,n) = | gcd(n m%n), n =/= 0
		   | m, n=0

can do this as a recursive fn, g++ has this built in


O(log(min(m,n))) // runs in log time, is fast is good.

to use in c++
__gcd

##

Say you want to know 7^some_really_big_number % 11
7^100000 % 11

approach 1:
- work out number, calculate remainder, but this will have many digits and take 5eva to calculate

approach 2:
- take remainder as you go, remainder will stay < 11, more doable

do intermediate steps, won't get bigger because you are moding each time.

use index law
7^100000 = (7^500000)^2 // half exponent, square, takes less time
7^500000 = (7^250000)^2 ...
...
7^1 = 7
7^0 = 1

base cases:
- can't halve exponent if exponent is odd.

eg:
7^11 = 7^5)^2 * 7 // do integer division and floor it, make it 1 less than what it is then mult by 7 so 7^10 * 7 = 7^11

a^b = | (a^(b/2))^2, b is even
	  | (a^(b//2))^2 * a, b is odd
and base cases

// pesudo code
// O(log(exponent))
// can be done for anything that needs to be multiplied i.e.a  matrix^something
int power(int base, int exponent, int mod) {

	if (exponent == 0) { // base case.
		return 1;
	}

	//if (exponent == 1) { // base case.
 	//		return base;
	//}

	int res = power(base, exponent/2);
	res = res * res; // square it
	res = res % mod; // take mod at each incremental step

	if (exponent % 2 == 1) { // Odd case
		res *= base; // multiply by base again.
	}
}
//
if question asks you to print something mod 11, make sure u print the positive version.

>>> 5 - 7 % 11
-2
>>> (5 - 7) % 11
9

cpp is not nice like python.
// fast fibs

| fn   | =  |1 1|^n-1 * |1|
| fn-1 |    |0 1|		|0|


// inverse fns

a / b = a * inverse(b) = a * b^-1

b * b^-1 = 1 // multiplicative identity

7 * x = 1

naive way = try all numbers

7 * 1 = 7
7 * 2 = 14 % 11 = 3
7 * 3 = 10 % 11 = 10
..
7 * 8 = 56 % 11 = 1 // inverse of 7 is 8

so

5/7 = 5 * 7^-1
	= 5 * 8 // inverse of 7 is 8 based on above
	= 40 % 11
	= 7

division doesn't mean anything, it is multiplication by the inverse.
when you want division in the form of the answer mod a number use this.

## Finding the inverse.

2^-1 mod 24


2 * x = 1

no number to solve this

for inverse to exist need gcd = 1, gcd(24, 2) = 2 =/= 1 so 2 doesn;t have an inverse

can modify gcd algo to fine numbers am + bm = gcd

if you want the last digit of 7^1000000
7^10000000 % 10 will give you that.

a = b'
b =  a' - b'[m/n floored]
