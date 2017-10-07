#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef vector<pil> vp;
typedef vector<vp> vvp;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int VISITED = 1;
int UNVISITED = -3;
ll INF = -1;  // Note: 1e9 == 10^9
int IMPOSSIBLE = -2;

vvp adjacency_list(5005);
// [s][n] stores the min time it takes to get visit s showplaces from node n.
vvll memo_table(5005, vll(5005, UNVISITED));
vvpii path_table(5005, vpii(5005, {-2, -2}));

int N, M;
ll T;

ll dfs(int n, int s) {
    // cout << "n: " << n << ", s: " << s << endl;

    if (s < 0) {
        // memo_table[s][n] = -1; out of bounds.
        return -1;
    }

    if (memo_table[s][n] != UNVISITED) {
        return memo_table[s][n];
    }
    if (s == 0 and n != N) {
        memo_table[s][n] = -1;
        return -1;
    }
    // Base cases.
    if (n == N) {  // At goal node.
        if (s != 0) {
            // s > 0.
            memo_table[s][n] = -1;
            return -1;
        }
        // cerr << "Goal n: " << n << ", s: " << s << ", N: " << N << endl;
        path_table[s][n] = {-1, -1}; // This is the end of the path.
        memo_table[s][n] = 0;
        return 0; // Time it takes to get to node.
    }

    ll min_time = -1;

    for(pil p: adjacency_list[n]) {
        int next_node = p.first;
        ll next_time = p.second;
        ll attempt = dfs(next_node, s - 1);
        if (attempt == -1) {
            continue;
        }
        // We got an answer.
        attempt += next_time;
        if (min_time == -1) {
            // Update the best answer.
            min_time = attempt;
            memo_table[s][n] = min_time;
            // Update the best path.
            path_table[s][n] = {s - 1, next_node}; // Exporing this next gave us the best answer so far.

        } else {
            if (attempt < min_time) {
                // Update the best answer.
                min_time = attempt;
                memo_table[s][n] = min_time;
                // Update the best path.
                path_table[s][n] = {s - 1, next_node}; // Exporing this next gave us the best answer so far.
            }
        }
    }

    if (min_time == -1) {
        // No edge works from here.
        memo_table[s][n] = -1;
    }
    return min_time;
}

void print_stuff(ll best_time) {
    // Remember things are 1 indexed but we use row 0 for needing to visit 0 showplaces for a potential goal node.
    // Print memo_table.
    // cout << "memo_table" << endl;
    // for (int i = 0; i <= N; i++) {
    //     vll v = memo_table[i];
    //     for (int j = 0; j <= N; j++) {
    //         cout << v[j] << " ";
    //     }
    //     cout << endl;
    // }

    // Print paths_table.
    // cout << "path_table" << endl;
    // for (int i = 0; i <= N; i++) {
    //     vpii v = path_table[i];
    //     for (int j = 0; j <= N; j++) {
    //         cout << "{" << v[j].first << ", " << v[j].second << "} ";
    //     }
    //     cout << endl;
    // }

    int path_row = -1;
    int path_col = 1;
    // Traverse path_table and memo_table to print path.
    for (int row = 0; row <= N; row++) { // Loop through col 1 until found the best time.
        if (memo_table[row][1] == best_time) {
            path_row = row;
            break;
        }
    }

    if (path_row == -1) {
        cout << "WTF" << endl;
    }

    pii p = path_table[path_row][path_col];
    pii goal = {-1, -1};
    while (p != goal) {
        cout << path_col << " ";
        path_row = p.first;
        path_col = p.second;
        p = path_table[path_row][path_col];
    }
    cout << path_col << endl;

}

int main() {
    cin >> N >> M >> T;
    for (int i = 0; i < M; i++) {
        int v, u;
        ll t;
        cin >> u >> v >> t;
        adjacency_list[u].push_back({v, t});
    }

    for (int n = N; n >= 2; n--) {
        ll t = dfs(1, n - 1); // At show 1 we have seen 1 show.
        if (t == -1) {
            continue;
        }
        if (t <= T) {
            cout << n << endl;
            // cout << t << endl;
            // Print out the path.
            print_stuff(t);
            break;
        }
    }

    return 0;
}
