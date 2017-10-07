#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// NOTE: std::distance is a thing, don't use it as a variable name http://www.cplusplus.com/reference/iterator/distance/
vi dist(205, 0);
vvi adjacency_list(205);
map<string, int> node_id_map;

bool dfs(int n, int depth) {
    // Do I need a visited array?.
    dist[n] = depth;
    for (int adj: adjacency_list[n]) {
        dfs(adj, depth + 1);
    }
    return true;
}

int main() {
    int N; cin >> N;
    int node_id = 1;
    // Note: cin >> type string reads until first whitespce.
    for (int i = 0; i < N; i++) {
        string user_a, reposted, user_b;
        cin >> user_a >> reposted >> user_b;

        // Change strings to lowercase, won't do anything for digits.
        for (int c = 0; c < user_a.size(); c++) { user_a[c] = tolower(user_a[c]); }
        for (int c = 0; c < user_b.size(); c++) { user_b[c] = tolower(user_b[c]); }

        if (node_id_map.find(user_a) == node_id_map.end()) {  // Not in map.
            node_id_map[user_a] = node_id;
            node_id++;
        }

        if (node_id_map.find(user_b) == node_id_map.end()) {
            node_id_map[user_b] = node_id;
            node_id++;
        }

        // Users can't be the same.
        adjacency_list[node_id_map[user_b]].push_back(node_id_map[user_a]);
    }
    dfs(node_id_map["polycarp"], 1);
    int max_value = 0;
    for (int i = 1; i < node_id; i++) {
        if (dist[i] > max_value) { max_value = dist[i]; }
    }
    cout << max_value << endl;
}
