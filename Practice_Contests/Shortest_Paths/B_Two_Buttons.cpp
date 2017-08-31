// TODO: Use this on linux:
#include <bits/stdc++.h>
// Use below on osx:
// #include "../stdc++.h"
// To compile: $ g++ -std=c++11 -Wall file.cpp -o F
using namespace std;


typedef long long ll;

// Represent state space as a graph search problem.

ll n, m;
int seen_states[20005] = {0}; // Array of size 10^4 initalized to 0.

int main() {
    cin >> n; // Start state.
    cin >> m; // Target state.

    queue<pair<ll, int>> states; // Queue of <values, times> button has been pushed.

    states.push({n, 0});
    seen_states[n] = 1;

    // BFS: explore each level, add to queue. Will find it in min number of steps.
    while (!states.empty()) {
        pair<ll, int> current = states.front();
        states.pop();

        if (current.first == m) { // Found the target.
            cout << current.second << endl;
            return 0;
        }

        // Red button is multiply by 2.
        // No point multiplying by 2 if the current number is already >= m.
        if (!(current.first >= m)) {
            // Don't go to new state if we already have/had it in our queue (seen it already).
            if (current.first * 2 <= 20000) {
                // Need to check that mult by 2 won't go out of bounds.
                // Bounds from 0....20000, as at max we might need to for what ever reason multiply 10^4 by 2.
                if (seen_states[current.first * 2] == 0) {
                    states.push({current.first * 2, current.second + 1});
                    seen_states[current.first * 2] = 1;
                }
            } // Else if multiply by 2 will go out of bounds.
        }

        // Blue button is minus 1.
        // If current number is < 1 then we have a problem, but should never happen.
        if (current.first > 1) {
            // Don't go to new state if we already have/had it in our queue (seen it already).
            if (seen_states[current.first - 1] == 0) {
                states.push({current.first - 1, current.second + 1});
                seen_states[current.first - 1] = 1;
            }
        } else {
            // Value is <= 1, don't minus 1.
            // cout << "WTF current value is 1" << endl;
        }

    }
    cout << "I didn\'t find anything..impossible!" << endl;
    return 0;
}
