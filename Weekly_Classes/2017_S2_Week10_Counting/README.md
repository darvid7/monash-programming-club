# Counting things
Permutations: Shuffling where order matters
Combinations: Choose objects

Permutations: `n! = n * (n - 1) * (n - 2) * .... * 2 * 1`
Easily overflows a 64 bit integer

Combinations: (n choose k) = n! / (k!  * (n - k)!)

In contests, instead of computing exact number, compute it mod something.

Remember: `x % m` is the remainder when you divide `x` by `m`, between `0` and `m-1`.

## Operations with mods:
- `(x + y) % m == ((x % m) + (y % m)) % m` you can take the mod of each one making them small, add them up then take a mod on the outside
- `(x - y) % m == ((x % m) - (y % m)) % m`
- `(x * y) % m == ((x % m) * (y % m) % m)`

Note: in C++/Java `x % m` is in the `set {-(m - 1), -(m - 2), .., -1, 0, 1, .., m - 1}`
To make negative values positive add `m` to them.
note that if x is positive then the output will always be negative.
So `((x % m) + m) % m` is in the `set {0, 1, .., m - 1}`

## Factorials.
```cpp
// Compute n! % m.
int fact(int n, int m) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % m;
    }
    return ans;
}
```
Most of the time instead of a function call factorials make an array.

```cpp
fact[i] = (fact[i - 1] * i) % m;
```

## Combinations.
We can't use the operations with mods to calculate combinations yet as we can't divide.

```
Pascal's triangle. Each item is the value of the above 1 value or two values.
    1
   11
  121
 1331
14641
Gives (n choose k).
```
Note: There is 1 way to choose 0 objects and 1 way to choose n objects from n things.

```
int choose[N][N];
for (int 0 = 1; i < N; i++) {
    choose[i][0] = 1;
    choose[i][i] = 1;
    for (int j = 1; j < i; j++) {
        // if we want mod m do this line instead.
        // choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % m;
        choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
}
O(n^2), can do about 10000.
```
## Questions
- How many binary strings have n 1's and m 0's?
`(n + m choose n) == (n + m choose m)`
- How many ways cat I split up k cats between l people?
Look up `stars and bars` aka selection without replacement.
1. make a binary string of size `k + l - 1`
2. allocate some `1s` and `0s` to this

`0 1 1 0 1 0 0 0 0`
`<-<-<---<-------`
here:
- person 1 gets 1 cat (1 zero b/w start and first 1)
- person 2 gets 0 cats (0 zeros b/w first and second 1)
- person 3 gets 1 cat (1 zero b/w second and third 1)
- person 4 gets 4 cats (4 zeros b/w third and forth 1)

(k + l - 1) / (l - 1)
cats as dividers

## Division

If you want `a/b` do `a * b'` where `b' * b = 1`. This is the Multiplicative Inverse.
Note: `b' sometimes written as b^(-1)`
```
7/5 mod 12
y:   0 1  2 3 4 5
5*y: 0 5 10 3 8 1

11/3 (mod 14) = 11 * 5 (mod 14) = 55 (mod 14) = 13 (mod 13)

7/4 (mod 12)
y:      0 1 2 3 4 5 6 7 8 9 10 11
4 * y:  0 4 8 0 4 8 0 4 8 0 4   
```
// look up extended gcd.
```ext_gcd(a, b): // code binder
    returns:
        s t and g
        g has to be 1 otherwise there is no inverse

Compute multi inverse of x mod m = ext_gcd(x, m)
```    
If `m` is prime, `x'` always exists (`x=/=0`)

in contents output mod
- `1,00,00,007`
- `1,00,00,009`
- `1,00,00,097`
are primes.

## Now we can compute n choose k.
```
(n choose k) = n!/(k!*(n-k)!) = (n!)  * (k!)' * ((n - k)!)'
```
