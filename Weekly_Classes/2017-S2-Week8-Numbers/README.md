# Prime numbers.

A prime number is a number that can only be divided by 1 and itself.

Note: 1 is not a prime.

## Some terminology.

### Prime Power

a number `p<sup>k</sup>` where `p` is a prime and `k >= 1`

      2^1      2^3 3^3
      v        v   v
2, 3, 4, 5, 6, 8,  9, 11, ....

### Composite numbers
Non prime numbers

## Important Theorem

### Fundamental Theorem of Arithmetic

> fundamental theorem of arithmetic, also called the unique factorization theorem or the unique-prime-factorization theorem, states that every integer greater than 1 either is prime itself or is the product of prime numbers, and that this product is unique, up to the order of the factors

Factorization is unique

`12 = 2^3 * 3`

There is only 1 way to write each number as a factor of primes.

Any number `n` can be expressed as

n = p<sub>1</sub><sup>alpha1</sup> * p<sub>2</sub><sup>alpha2</sup> * p<sub>2</sub><sup>alpha2</sup> .. p<sub>k</sub><sup>alphak</sup>

This means that `m` is a divisor if and only if beta<sub>i</sub> <= alpha<sub>i</sub>

`n = p1^a1 * p2^a2 ... pk^ak`

`m = p1^b1 * p2^b2 ... pk^bk`

For example:

`n = 2^4 * 3^6 * 7^12 * 11^4`

`m = 2^3 * 3^7 * 7^4 * 11^2`

Does `m` divide `n`?

`n/m = (2^4 * 3^6 * 7^12 * 11^4)/(2^3 * 3^7 * 7^4 * 11^2) = (2 * 7^8 * 11^2)/3`

Looking at exponents, there are k + 1 choices for each of them.
For each alpha i .. alpha k there are k + 1 choices.

The number of divisors of n = product(alpha i + 1)

### Prime Number Theorem

`Pi(n) = The number of primes <= X is approximately (~) X/log base e (X)`

A table showing the number of primes for number `n`

n | Pi(n) |
--- | --- |
10 | 4 |
100 | 25 |

`Pi(n) is approx n/log base e (n)`

### How to find primes.

Question: Is `n` prime?

```
// Silly solution O(n).
for i from 2 to n - 1:
    if n % i == 0:
        return false
return true
```

Slight optimization: `n = a * b` for some `n` that is not a prime and `a =/= 1, b =/= 1`, `a <= b`

This tells us that `a <= sqrt(n)` as if `a > sqrt(n)` the number just be `> n` as `b >= a >= sqrt(n)`.

So loop until `sqrt(n)`.

```
// Silly solution O(sqrt(n)).
for i from 2 to sqrt(n):
    if n % i == 0:
        return false
return true
```

Problem with this approach: if `n = 25` we know  `sqrt(25) = 5`. But on a computer this might be hard to represent.
It could be
- 5.000000001
- 4.999999999
- 5.0

If the value isn't exact then bad things will happen, it might say 25 is a prime number.

Write this instead to get rid of rounding errors.

```
// Silly solution O(sqrt(n)).
for i from 2 to a*a <= n:
    if n % i == 0:
        return false
return true
```

### Perfect square

`if (n == (int) (sqrt(n)) * (int) (sqrt(n)))` is mathematically correct.

But the `sqrt()` function might return `4.99999999` and `4.99999999 * 4.99999999` is not 25.
The correct way to do this is check around the square root of n.

```
for (int sqrt(n - 2); i < sqrt(n + 2); i++) {
    if (i * i == n) { return true; }
}
return false;
```

### Miller Rebine (idk spelling)
Will find all prime numbers for all 64 bit integers, won't work after that.

### Sieve of Eratosthenes: Multiple isPrime() queries

http://hbmeyer.de/eratclass.htm

basic idea:
- start at beginning
- rule out all multiples of numbers

So start at 2, 2 is prime, go through every multiple of 2 and mark it as not prime.

When you get to a certain number it will stop, this is because the range is up to 400 and last number left is `397, sqrt(397) = 19.9`.

```
is_prime[n] = {1, 1, 1, ..., 1} // 1 is true.
is_prime[1] = false;

for (i = 2; i * i < n; i++) {
    if (is_prime[i]) {
        for(j = 2; i * j <= n; j++) { // here
            is_prime[i * j] = false;
        }
    }
}
```

Note that up to `// here` in the above code, if we are looking at `i = 17` then `2 * 17` has already been knocked off when `i = 2` so the next optimization is to start the inner loop at `j = i`.

```
is_prime[n] = {1, 1, 1, ..., 1} // 1 is true.
is_prime[1] = false;

for (i = 2; i * i < n; i++) {
    if (is_prime[i]) {
        for(j = i; i * j <= n; j++) { // here
            is_prime[i * j] = false;
        }
    }
}
```

More optimization, do this instead of inner loop.
```
for(k=i*i; k<=n; k+=i) {
    is_prime[k]=false
}
```

`O(n log(log n))`

#### Complexity analysis

i | 2 | 3 | 4 | 5 |
--- | --- | --- | --- | --- |
Inner for loop | n/2 | n/3 | n/4 | n/5|

for any iteration of the inner for loop only `n/i` amount of work has to be done.

This summation is almost `log (n)` so complexity is `O( n log(n))`

Note: The outer `n` is taken from the summation of `n/i`, n is taken outside.

### Factor a number
```
factor(12) = {2} union factor(12/2 = 6)
           = {2} union ({2} union factor(6/2 = 3))
           = {2} union ({2} union ({3} union factor(3/3 = 1)))
           = {2} union {2} union {3} union {empty set}
find the number in {} to be the smallest prime factor of the number we are up to.
```


```
for i from 2 to n-1:
    if n % i == 0:
        while n % i == 0:
            n = n/i
            "i is a prime factor"
if n != 1: "n is a prime factor"
```

the above function will return `{2, 2, 2}` for g(8).

This is the naive approach, copy pasta good is prime checking function `O(sqrt(n))` in.

Best solution.

1. Do Sieve of Eratosthenes
2. Prime factorization of me is my smallest prime factor and factor(n/smallest_prime_factor)

```
f(n):
    while n > 1:
        "factor[n] is a prime factor"
        n = n / factor[n]
```

Complexity:
`O(n log(log(n))) +  O (log n)` here LHS < RHS
Worst case = n=2^k

Complexity is `O(log n)`

## In code binder

### Miller - Rabin (prime tester)

consider it as O(log n)
works for number < 64 bits

### Pollard - Rho (finds a factor, might not work on squares)

You give it number N and it will find some factor of that number.

Given n return a such that n = a * b

Does not work in all cases.

Probabilistic, works for values where a =/= b.

eg: with 25 might not find 5 as a prime factor. 5 * 5 = 25.

Will work on n = 6 as 6 = 3 * 2.

Might not work on squares.

### Factor Huge (factors any number up to 10^24)

Complexity is `O( cube_root(n))`

### How do I know if Miller Rabin will work.


`n = a * b * c` given `a <= b <= c`

```
for a from 2 to cube_root(n):
    check if n % a == 0    
```

so if b is p^2 we can handle it ourselves, otherwise b is p * q and Miller Rabin can handle it.

## Greatest Common Divisor

`gcd(p1^a1 * p2^a2 ... * pk^ak)`

Find GCD given prime factors.

`= p1^min(a1, b2) * p2^min(a2, b2) .... * pk^min(a2, b2)`

## Lowest Common Multiple

`lcm(p1^a1 * p2^a2 ... * pk^ak)`

Find LCM given prime factors.

`= p1^max(a1, b2) * p2^max(a2, b2) .... * pk^max(a2, b2)`

## Not sure what this is
`gcd(p1^a1 * p2^a2 ... * pk^ak) * lcm(p1^a1 * p2^a2 ... * pk^ak)`

`= p1^min(a1, b1) * p1^max(a1, b1) * ... * pk^min(ak, bk) * pk^max(ak, bk)`
`= p1^(a1 + b1) * ... * pk^(ak + bk)`
`= n * m` which is the product of those two numbers.

### Extended Euclidean Algorithm.

Given `a`, `b` return `s`, `t` such that `a * s + b * t = gcd(a, b)`

Theorem: if `a * x + b * y` is positive then it is a multiple of `gcd(a, b)`

This is `O(log n)` proof to do with fib numbers. Try it later.
