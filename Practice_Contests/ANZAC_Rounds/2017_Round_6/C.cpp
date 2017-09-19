#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

// Top down recursive dp call.
// cpu_num_left is the number of CPUs left.
// merchant_num is the merchant you are currently at.
// This will find the maximum value you can possibly get with cpu_num_left number of CPUs left at this merchant.
int dp_recursive_call(int cpu_num_left, int merchant_num, vvi& matrix, vvi& dp_table, int M) {
    // cerr << "dp call - merchant: "  << merchant_num << ", cpu: " << cpu_num_left << endl;

    if (merchant_num == M) {
        return 0;
    }

    if (cpu_num_left == 0) {
        // cerr << "in here" << endl;
        dp_table[merchant_num][cpu_num_left] = 0;
        return 0;
    }

    if (dp_table[merchant_num][cpu_num_left] != -1) {
        return dp_table[merchant_num][cpu_num_left];
    }

    int max_val = 0;
    for (int c = 0; c <= cpu_num_left; c++) {
        max_val = max(
            max_val, dp_recursive_call(cpu_num_left - c, merchant_num + 1, matrix, dp_table, M) + matrix[merchant_num][c]
        );
    }
    // cerr << "set value in table: [" << merchant_num << "][" << cpu_num_left << "] = " << max_val << endl;
    dp_table[merchant_num][cpu_num_left] = max_val;
    return max_val;
}

int main() {
    int C, M; cin >> C >> M;
    vvi matrix(M, vi(C + 1)); //
    vvi dp_table(M, vi(C + 1, -1));
    for (int i = 0; i < M; i++) {
        for (int c = 1; c <= C; c++) {
            cin >> matrix[i][c];
        }
    }

    int max_value = dp_recursive_call(C, 0, matrix, dp_table, M);
    cout << max_value << endl;

    // for(vi v: dp_table) {
    //     for(int n: v) {
    //         cerr << n << " ";
    //     }
    //     cerr << endl;
    // }
    return 0;
}

/*
Where M is the number of merchants and C is the number of CPUs.

Mercahnt purchase prices are as follows:

           CPUs sold
mercahnt: 1  2  3  4  5
1         1  4  10 1  1
2         1  1  8  1  1
3         1  1  9  1  1

For the sameple case where M = 3, C = 5 the state space is as follows:

Where the tuple (value, cpu_num_left, cpu_num_sold, merchant_num) represents
the current value of selling cpu_num_sold CPUs to mercahnt merchant_num.

        Merchant 1             Merchant 2              Merchant 3

                                                  /-- (0, 5, 0, 3)
                                                 /--- (1, 4, 1, 3)
                                                /---- (1, 3, 2, 3)
                           |-- (0, 5, 0, 2)---------- (9, 2, 3, 3)
                           |                   \----- (1, 1, 4, 3)
                           |                    \---- (1, 1, 0, 3)
                           |
                           |                    /---- (1, 4, 0, 3)
                           |                  /------ (2, 3, 1, 3)
                           |-- (1, 4, 1, 2)---------- (2, 2, 2, 3)
                           |                 \------- (10, 1, 3, 3)
                           |                  \------ (2, 0, 4, 3)
                           |
                           |                  /------ (1, 3, 0, 3)
                           |                 /------- (2, 2, 1, 3)
                           --- (1, 3, 2, 2)---------- (2, 1, 2, 3)
                           |                 \------- (10, 0, 3, 3)
                           |
                           /                   /------ (8, 2, 0, 3)
    |-------- (0, 5, 0, 1) ----- (8, 2, 3, 2) -------- (9, 1, 1, 3)
    |                      \                   \------ (9, 0, 2, 3)
    |                      |
    |                      |                   /------ (1, 1, 0, 3)
    |                      |--- (1, 1, 4, 2) --------- (2, 0, 1, 3)
    |                      |
    |                      |--- (1, 0, 5, 2) --------- x
    |
    |                                           /----- (1, 4, 0, 3)
    |                                          /------ (2, 3, 1, 3)
    |                       |-- (1, 4, 0, 2) --------- (2, 2, 2, 3)
    \                       |                  \------ (10, 1, 3, 3)
    |                       |                   \----- (2, 0, 4, 3)
    |                       |
    |                       |                   /----- (2, 3, 0, 3)
    |                       |                  /------ (3, 2, 1, 3)
    |                       |--- (2, 3, 1, 2) -------- (3, 1, 2, 3)
    |                       |                  \------ (11, 0, 3, 3)
    |                       |
    |                      /                  /------- (2, 2, 0, 3)
    |---------(1, 4, 1, 1) ----- (2, 2, 2, 2) --------- (3, 1, 1, 3)
    |                      \                  \------- (3, 0, 2, 3)
    |                      |
    |                      |                  /------- (9, 1, 0, 3)
    |                      |--- (9, 1, 3, 2) --------- (10, 0, 1, 3)
    |                      |
    |                      |--- (2, 0, 4, 2) --------- x
    |
    /                                         /------- (4, 3, 0, 3)
root                                        /--------- (5, 2, 1, 3)
    \                      |---(4, 3, 0, 2) ---------- (5, 1, 2, 3)
    |                      |                \--------- (13, 0, 3, 3)  [max]
    |                      |
    |                      |                  /------- (5, 2, 0, 3)
    |                      |--- (5, 2, 1, 2) --------- (6, 1, 1, 3)
    |                      |                 \-------- (6, 2, 0, 3)
    |                      |
    |                      /                  /------- (5, 1, 0, 3)
    |-------- (4, 3, 2, 1) ----- (5, 1, 2, 2) -------- (6, 0, 1, 3)
    |                     \
    |                     |---- (12, 0, 3, 2) -------- x
    |
    |                                          /------ (10, 2, 0, 3)
    |                       |-- (10, 2, 0, 2) -------- (11, 1, 1, 3)
    |                       |                 \------- (11, 0, 2, 3)
    |                       |
    |                       /                  /------ (11, 1, 0, 3)
    |-------- (10, 2, 3, 1) ---- (11, 1, 1, 2) -------- (12, 0, 1, 3)
    |                      \
    |                      |--- (11, 0, 2, 2) -------- x
    |
    |                                        /-------- (1, 1, 0, 3)
    |                      |--- (1, 1, 0, 2) --------- (2, 0, 1, 3)
    |                      /
    |-------- (1, 1, 4, 1) ----- (2, 0, 1, 2) --------- x
    |
    |-------- (1, 0, 5, 1) ---------------------------- x

56 states over all.

Note that this state tree is very specific and is hard to generalize to a DP problem.
We want to find the subproblem by breaking it down into smaller problems with the properties:
- what we do next doesn't depend on how we got to our current state.
- problem has optimal substructure: optimal solution can be constructed from optimal solution of subproblems.
- problem has overlapping subproblems: problem can be broken down into subproblem that are reused a lot.

From the state tree we can see that we get to the state:

(x, x, 1, 2) several times where we sell 1 CPU to merchant 2.
likewise we get to the state (x, 1, x, 2) several times where we have 1 CPU left
after visiting merchant 2.

To reduce our state space lets disregard the values as we want to maximize this and don't care what the
actual operations are to do so.

We want to memoize repeated computations, so we need to structure our algorithm
so we can easily take advantages of repeated states.

Taking the tuple (CPUs left, merchant_num) as our state we can compute
the maximum value for each configuration of the number of CPUs left at each merchant.
This is repeated often as we eventually want to know what the maximum value we
can get with 2 CPUs left at merchant 3 when we sell 3 to merchant 1 and 1 to merchant 2.
Likewise when we sell 2 to merchant 1 and 2 to merchant 2.
So using (CPU_left, merchant_num) is a good state tuple.

This results in the follow state tree:

      Merchant 1         Merchant 2        Merchant 3

                     |------ (0, 2) ------- (0, 3)
                     |
                     |                /---- (0, 3) r
                     |------- (1, 2) ------ (1, 3)
                     |
                     |                /---- (0, 3) r
                     |------- (2, 2) ------ (1, 3) r
                     |                \---- (2, 3)
                     |
                     |                 /---- (0, 3) r
                     /                /----- (1, 3) r
        |---- (5, 1) --------- (3, 2) ------ (2, 3) r
        |            \               \------ (3, 3)
        |            |
        |            |                 /---- (0, 3) r
        |            |                /----- (1, 3) r
        |            |------- (4, 2) ------- (2, 3) r
        |            |               \------ (3, 3) r
        |            |               |------ (4, 3)
        |            |
        |            |
        |            |                /----- (0, 3) r
        |            |               /------ (1, 3) r
        |            | ------ (5, 2) ------- (2, 3) r
       /                             \------ (3, 3) r
   root                              |------ (4, 3) r
       \                             |------ (5, 3)
Note: All these below states will never happen as you will never go to merchant 1 with less items than C.
        |            |------- (0, 2) r
        |            /------- (1, 2) r
        |---- (4, 1) --------- (2, 2) r
        |            \------- (3, 2) r
        |            |------- (4, 2) r
        |
        |            |------- (0, 2) r
        |            /------- (1, 2) r
        |---- (3, 1) --------- (2, 2) r
        |            \------- (3, 2) r
        |
        |            /------- (0, 2) r
        |---- (2, 1) --------- (1, 2) r
        |            \------- (2, 2) r
        |
        |            /------- (0, 2) r
        |---- (1, 1) --------- (1, 2) r
        |
        |---- (0, 1)

You can see that at the 3rd merchant there are 6 unique states.
At the 2nd merchant there are 6 unique states.
At the 1st merchant there are 6 unique states.

So the total number of states is the states at merchant 1 * states at merchant 2 * states at merchant 3 = 18.
The state space has been reduced to M * ( C + 1) = 18.

This is now doable as a DP as C <= 100 & M <= 100.

So we want to fill to fill to fill out a DP table that we can use to look up
the best value we can get with a number of CPUs left over.

CPUs left * Merchants.
[
    [x, x, x, x, x, x],
    [x, y, x, x, x, x],
    [x, x, x, x, x, x]
]

y represents the max value we can get with 1 CPU at merchant 2, will also consider posiblities in merchant 3.
*/
