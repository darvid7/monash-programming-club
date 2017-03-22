//C++

#include <bits/stdc++.h>
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
            filled++;
            num_busses++;
        }

    }
    cout << num_busses << "\n";
}
