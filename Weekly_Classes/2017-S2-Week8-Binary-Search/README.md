# Binary Search

## Boring Binary Search

the bounds `lo` and `hi` just mean the answer is in here somehwere.

```
lo = 0, hi = n - 1;
while (lo != hi) {
    mid = (lo + hi) / 2;
    if (array[mid] = target) {
        return true;
    }
    else if (array[mid] < target) {
        // Look at right.
        lo = mid + 1;
    } else {
        // Look to left.
        hi = mid - 1;
    }
    return array[lo] == target;
}
```

## Lower bound problem

Given a sorted list `S[0..n-1]` and `x`, find the first element `S[i]` such that `S[i] >= x`.

```
The dots represent stuff in the array.

Top half is S[i] >= x
                .
              .
            .
x -------.----------------
      .
   .
.
Bottom half is S[i] < x
```

The approach is to make `lo` and `hi` more significant.
Make `lo` point to an element that is in the less than half and `hi` point to an element in the greater or equal half.
Make these two pointers converge.

### Invariants

- S[lo] < x
- S[hi] >= x

This always holds apart from edge cases where everything is less than/greater than.

To move the bounds, make sure it still upholds the invariant.

```
lo = -1, hi = n; // hi changed from n - 1, lo changed from 0.
while(lo != hi) {
    mid = (lo + hi) / 2;
    // Note: We care about the boundary so we don't -1 or +1 like above.
    if (S[mid] >= x) {
        hi = mid;
    } else {
        lo = mid;
    }

    // Sometimes you want to return lo which is the first item that is less than x.
    return hi; // Index of first item in the bigger or equal half.
    // If everything is larger, will return n.
    // If everything is smaller, will return -1.
    // Returns 0 on an empty array.
}
```

To handle edge cases:
- can check edge cases first
- can also change the bound of hi to n. This means if it isn't in the sequence  

## Upper bound problem.

Same as above but change `>=` to `>` in code and invariants.

## Application of upper & lower bounds.

Note: For no occurrences will both point to 0.

### Number of numbers in array.

Given an array of integers, how many 5's are there?

Naive: For loop O(N)

Better: Do a `binary_search_upper_bound(5) - binary_search_lower_bound(5)`

### Count numbers in range [a, b].

`binary_search_upper_bound(a) - binary_search_lower_bound(b)`

### Binary search on continuous function.

#### Square root of x
Compute the square root of x (without `.sqrt()`)

graph: Imagine it looks like the log function.
```
|        stuff here is > sqrt(x)
|
|        _________________________
2 >>>>>>.>>>>>>>>>>>>>>>>>>>>>>>>>>>
|  ---/
| /      stuff here is <= sqrt(x)
|/_____________________________
```

```
lo = 1, hi = x + epsilon; // epsilon to make sure hi and lo are different, if asking sqrt(1) then oth will point to 1.

we want y >= sqrt(q) so can change this to y^2 >= x.
```

Trick for assigning `hi`, look at problem statement and pick the upper bound number + 1.

```
lo = 1, hi = 1;
while(hi * hi <= x) {
    hi *= 2;

    while (hi - lo > epsilon) {
        mid = (hi + lo) / 2;
        if (mid * mid <= x) { // <-line
            lo = mid;
        } else {
            hi = mid;
        }
    }
return lo;  // lo is everything <= to x so return that.
}
```

## C++ library built in.

Call using `upper_bound(vector.begin(), vector.end(), 5)` for vectors.
- `lower_bound(it1, it2, x)` returns iterator to first `a<sub>i</sub> >= x`, end iterator if all `a<sub>i<sub> < x`
- `upper_bound(it1, it2, x)` "  "  "  "  "  "  "  "  "  "  "  "  "  "
- `equal_range(it1, it2, x)` returns left_it , right_it such that [left_it, right_it) = x
    ```
    v = {1,2,4,5,6,6,6,7,5,4};
    equal_range(v.begin(), v.end(), 6) => {v.begin()+4, v.begin()+7};
    ```
- `binary_search(it1, it2, x)` return true/false. Does [it1, it2) contain `x`
- `partition_point(it1, it2, f)` give it function `f` as function to use as invariant, will tell you when your invariant breaks. Returns iterator to first element such that `f(x)` is `false`. `f` replaces the line `<-line` (ln 130) in the code above.

If you are doing this on a set/map (which is a tree in C++), they will have their own methods i.e. `myset.lower_bound(stuff)`.

## Interesting Applications

### Bipartite Graph MiniMax Matching

Given a bipartite graph with edge weights

```
()-2-()
  \3
    \
()-2-()
 \   /
  4 1
  / \
()-2-()
```

What is the minimum maximum weight I can get in a perfect matching.

Out of all the matchings I want the minimum max weight.

Possible matchings.
1. max weight = 4
```
()-2-()
()   ()
 \   /
  4 1
  / \
()   ()
```
2. max weight = 2
```
()-2-()
()-2-()
()-2-()
```

Can't try all matches because there are too many.

Idea: if can find a matching with max weight `W`, then you don't need to bother finding a weight bigger than `W`.
Becomes question: Is there a perfect matching with `weight <= w`.
Solution: Remove edges with weight more than `w` and do regular bipartite matching algo.

if `f(w) = true` there exists a matching with `weight <= W`.
```
// Invariants.
f(lo) = false // Want lo to point to the false region.
f(hi) = true


lo = 0, hi = max_weight;
while(lo != hi -1) {
    mmid = (lo + hi) / 2;
    if (f(mid) = false) { // Just need to implement `f()` to remove edge and run bipartite matching.
        lo = mid;
    } else {
        hi = midl
    }
return hi
}
```

### Nanobots - Distributed Code Jam 2017 Round 2 E.


Question: Given a grid covered with rectangles from the origin what is the total area.
The only way you can get information is by querying a cell.
Grid is 10^12 * 10^12, 10^5 rectangles.

The rectangles can been seen as a stair case.
```
10^12
|
|---
|   |
|   |
|   ------------
|              |
|xxxxxxxxxxxxxxx----------
|_____stuff here__________|_____ 10^12
```

Can't do it the dumb way querying every cell, TLE.

Solution to small problem.

1. Start at (0, 0)
2. Binary search to find the right end of the first rectangle to get the first point.
3. Binary search up to find how high it goes.
4. Repeat for each rectangle.

Note: Doing steps 1-3 once will allow us to see that the rectangle `stuff here` is in our area.

O(N log(10^12))

For the large input (Distributed).
- 10^7 rectangles.
- you get 100 processors
- need to divide and conquer the problem up into different segment and give them all to a processors.
- need to do this smart so 1 processor is not stuck with all the rectangles.

### Binary Search in Geometry - Fatman

There is a man in a shopping isle. He wants to get from the start to the end.
The dots infinitely small points things in his way that he can't pass.
What is the maximum radius of the Fatman such that he can get from the start to end.
```
----------------------------
^   .
|            .
|       .            .
m ------------------->
|   .       .
|   .           .
v
----------------------------
```

Idea: If `r` fits, then so do smaller `r`. If `r` doesn't fid then neither does bigger `r`. This is monotonic.

```
// Invariants
f(lo) = true;
f(hi) = false;

lo = 0; // infinitely thin man will always work.
hi = isle_size/2 + epsilon // A man with radius size of isle/2 + something small can't get through.

while (hi - lo > epsilon) {
    mid = (lo + hi) / 2;
    if (f(mid) == true) {
        lo = mid;
    } else {
        hi = mid;
    }
return lo;
}
```

So now just need to do the geometry part.

#### Implementation of f
A trick with geometry is to transform the problem such that:
- the man is infinitely thin.
- the dots now have radius r.
- shrink the wall in by r.

So we fatten the objects instead of the man.

Turn into a graph connectivity problem. If two objects are touching they are adjacent. Want to know if the two walls are touching each other.

If the walls are connected then there is no path through.

```
----------------------------
^   (.)
|           (.)
|      (.)             (.)
m ------------------->
|   (.)       (.)
|   (.)           (.)
v
----------------------------
```

If walls are connected i.e.


```
----------------------------
^     |                     |
|   ( . )      |          ( . )
|     |      ( . )          |. this is blocked
|             ||        |    |
|           ( . )     ( . )( . )
m             |         |    |
|                      |          
|                    ( . )
v                      |
----------------------------
```

### Intuition for binary search
- minimize or maximize something -> should think is it binary searchable.
- is it monotonic -> if some number works, does any smaller number work? If some number works, does any bigger number work?
- floating point answers, hint that there is no right answer, small error or margin hinting that the answer is approximate and might be binary searchable.
