# Week 4

## Primes
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
		for (int j=i*i; j<= 1000000; j+=1) {
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
