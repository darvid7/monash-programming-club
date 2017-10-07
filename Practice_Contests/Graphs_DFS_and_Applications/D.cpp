#include <bits/stdc++.h>

using namespace std;

int NOT_SEEN = -1;
int VISITED = 1;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi visited(100005 -1);
vi colours(100005, -1);
vvi adjacency_list(100005);

// Note: DON'T ASSUME GRAPH IS CONNECTED. 2 wrong anwers because I started my DFS
// from node 1 assuming it will explore the entire graph.
// But when the only edge is between node 3 and 2 then it will not find how to
// create the two vertex covers and output -1.

// Variation of two coluring.
bool vertex_cover(int n, int colour) {
    visited[n] = VISITED;
    colours[n] = colour;
    for (int adj: adjacency_list[n]) {
        if (colours[adj] != NOT_SEEN) {
            if (colours[adj] == colour) { return false; }  // Bad two colouring breaks vertex cover.
            continue;
        }
        if (visited[adj] != VISITED) {
            bool can_cover = vertex_cover(adj, colour ^ 1); // colour ^ 1 flips bit, colour either 0 or 1.
            if (can_cover == false) { return false; }
        } else { // Should never happen.
            // cerr << "adj: " << adj << " already visited, how?" << endl;
        }
    }
    return true;
}

int main() {
    int N, M; cin >> N >> M;
    // No self loops, no multiple edges.
    for (int m = 0; m < M; m++) {
        int u, v; cin >> u >> v;
        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u);
    }
    // Need to do a for loop to handle if the graph is not connected.
    for (int n = 1; n <= N; n++) {
        if (visited[n] == VISITED) { continue; }
        // Run for every disconnected component of the graph, if connected will be visisted previously.
        bool can_colour = vertex_cover(n, 1);
        if (can_colour == false) { cout << -1 << endl; return 0; }
    }

    vi group_0;
    vi group_1;
    for (int i = 1; i <= N; i++) {
        if (colours[i] == 0) {
            group_0.push_back(i);
        } else if (colours[i] == 1) {
            group_1.push_back(i);
        } else { // Should not happen.
            // cerr << "colour val: " << colours[i] << " for node: " << i << endl;
        }
    }
    if (!(((int) group_0.size() >= 1) and ((int) group_1.size() >= 1))) { cout << -1 << endl; return 0; }

    cout << group_0.size() << endl;
    for (int i = 0; i < (int) group_0.size(); i++) {
        cout << group_0[i] << ((i == (group_0.size() - 1)) ? "": " ");
    }
    cout << endl;

    cout << group_1.size() << endl;
    for (int i = 0; i < (int) group_1.size(); i++) {
        cout << group_1[i] << ((i == (group_1.size() -1) ? "": " "));
    }
    cout << endl;
}
