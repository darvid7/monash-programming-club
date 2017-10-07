#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pair<int, ll> > vp;
typedef vector<vp> vvp;


int VISITED = 1;
int UNVISITED = -1;
ll INF = 1e9 + 10;  // 1e9 == 10^9
int IMPOSSIBLE = -1;

int RETURN_GOT_TO_N = 1;
int RETURN_RAN_OUT_OF_STOPS = 2;
int RETURN_IMPOSSIBLE = 3;

// nodes 1 .. n.
// Some connected by one-directional roads.
// No cyclic routes.
// Guaranteed at least 1 route from city 1 to n.
// This means awe are dealing with a connected graph where there exists a path from 1 to n.
// Want to maximize number of nodes visited with constraint T.

vvp adjacency_list(5005);
vvll matrix(5005, vll(5005, INF));
int N;

void update_time_in_matrix(int n, int s, ll time_so_far) {
    if (matrix[s][n] > time_so_far) {
        matrix[s][n] = time_so_far;
    }
}

int dfs(int n, int s, ll time_so_far) { // n = node, s = showplaces, T = time.
    cerr << "n: " << n << ", s: " << s << endl;
    if (s == 0 and n != N) {
        return RETURN_RAN_OUT_OF_STOPS;
    }
    if (s <= 0) {
        cerr << "WRONG OR GOT TO N n: " << n << ", s: " << s << endl;
    }
    if (n == N) {
        if (s != 1) {
            matrix[s][n] = IMPOSSIBLE;
            return RETURN_RAN_OUT_OF_STOPS;
        }

        update_time_in_matrix(n, s, time_so_far);

        return RETURN_GOT_TO_N;
    }
    int something_reached_n = RETURN_IMPOSSIBLE;

    for (pair<int, int> p : adjacency_list[n]) {
        int v = p.first;
        ll t = p.second;
        if (matrix[s - 1][v] == IMPOSSIBLE) {
            matrix[s][n] = IMPOSSIBLE;
            continue;
        }
        if (matrix[s - 1][v] == INF) { // Visit it.
            int local_reached_n = RETURN_IMPOSSIBLE;
            local_reached_n = dfs(v, s - 1, time_so_far + t);
            if (local_reached_n != RETURN_GOT_TO_N) {
                // No point exploring this ever again because it never got to N.
                matrix[s][n] = IMPOSSIBLE;
            } else if (local_reached_n == RETURN_GOT_TO_N) {
                something_reached_n = RETURN_GOT_TO_N;

                update_time_in_matrix(n, s, time_so_far);
            }
        } else {
            // Previously visited.
            update_time_in_matrix(n, s, time_so_far);
            something_reached_n = RETURN_GOT_TO_N;
            if ((time_so_far + t) < matrix[s - 1][v]) {
                // Revisit with shorter time.
                dfs(v, s - 1, time_so_far + t);
            }
        }
    }
    return something_reached_n;
}

int main() {
    int M, T; cin >> N >> M >> T;

    for (int m = 0; m < M; m++) {
        ll t;
        int u, v;
        cin >> u >> v >> t;
        // Store edges as pair {v, t}
        adjacency_list[u].push_back({v, t});
    }

    for (int i = 1; i < N; i++) {
        cerr << "node: " << i << endl;
        vector<pair<int, ll> > v = adjacency_list[i];
        for (int j = 0; j < (int) v.size(); j++) {
            cerr << v[j].first << " ";
        }
        cerr << endl;
    }

    // dfs(1, 4, 0);
    for (int s = N; s >= 0; s--) {
        cerr << "CHECK FOR s == " << s << endl;
        dfs(1, s, 0);
    }

    for (int i = 1; i <= N; i++) {
        vll v = matrix[i];
        for (int j = 1; j <= N; j++) {
            if (v[j] == 1e9 + 10) {
                cerr << "-" << " ";
            } else {
                cerr << v[j] << " ";
            }
        }
        cerr << endl;
    }
    // int max_shows = visited[N];
    // int node = N;
    // vi path;
    // while(node != -1) {
    //     path.push_back(node);
    //     node = parents[node];
    // }
    // cout << max_shows << endl;
    // for (int i = (int) path.size() - 1; i >= 0; i--) {
    //     cout << path[i] << " ";
    // }
    // cout << endl;
    return 0;
}
