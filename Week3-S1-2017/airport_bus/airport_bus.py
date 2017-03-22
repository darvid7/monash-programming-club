"""
@author: David Lei
@since: 15/03/2017
@modified: 

N people
T1, T2, T3, ..., Tn # times people arrive
buses with capacity C
need to get a bus within K units of time
how many busses do we need?

N up to 100 000

To solve:
1. sort times people arrive --> group people into busses

if person waits > K units of time, they become angry.

First bust must arrive K units after the first person arrives (T1 + k)
- leads to the most amount of ppl being eligible to get on the bus w/ keeping the first person happy

2. put as many ppl on bus until capacity exceeded or first person gets angry
"""

"""
5 3 5
1
2
3
6
12

A: 3
"""

N, C, K = [int(x) for x in input().split()]
TIMES = []
for _ in range(N):
    TIMES.append(int(input()))
TIMES.sort()

busses = 0
## Don't have weird edge cases like this.

i = 0
while (i <= len(TIMES) - 1):
    gotta_go = TIMES[i] + K
    capacity = 1
    i += 1
    while (i < N and capacity < C and TIMES[i] <= gotta_go):
        i += 1
        capacity += 1
    busses += 1
print(busses)
"""
first_arrive_time = TIMES[index]
index += 1
next_leave_time = TIMES[index]

while (served <= N):
    max_leave_time = first_arrive_time + K
    capacity = C
    while (capacity < C and next_leave_time <= max_leave_time and index <= N):
        index += 1
        capacity += 1
        served += 1
        next_leave_time = TIMES[index]
    busses += 1
    first_arrive_time = next_leave_time
print(busses)
"""




"""
//C++

#include <bits/stdc++.h> // means give me all the libs, so don't need to write a bunch of incldues.
// bits is a cpp thing, not a g++ thing
using namespace std;

// vector in C++ is sstandard array based container.

int main() {
    int N, C, K;
    cin >> N >> C >> K;

    vector<int> T(N); // vector called T of size N.*[]:

    // auto&, auto finds type by default, & means i want to modifiy what is in this container, not copies.
    // emiting the & does a loop over a copy of everything meaning you cant read in.
    for (auto& x: T) cin >> x; // for each element in my array, cin read stuff into here.

    sort(T.begin(), T.end()); // sorts things in C++, sort from begining of T to end. begin() and end() are iterators.

    int num_busses = 0;

    for (int i=0; i<N; i++) {
        int leave_time = T[i] + k
        int filled = 0; // no people on bus
        while (i < N && filled < C && T[i] <= leave_time) {
            i ++
            filled++;
        }
        num_busses++;


    }
    cout << num_busses << "\n";
}

"""

## Unix diff tool diff <f1> <f2>