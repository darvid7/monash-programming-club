#include <bits/stdc++.h>

using namespace std;

// Note: this solution passes but it isn't the best.
// I modelled the problem as a DAG where we traverse from children to roots (managers).
// This means that when I try to find the longest chain I will repeat computations if two or more children
// have the same manager (on the same path).
// The better way to do this is to model it as a DAG from root (managers) to children and run a normal DFS with a visited array.
typedef vector<int> vi;

int VISITED = 1, UNVISITED = -1;
vi employees(2005);

// superior(A, B) A is B's superior if
// - A is immediate maanger of B
// - B has an immediate manager C such that superior(A, C)
int superior(int A, int B) { }

int dfs(int n, int depth) {
    int next_node_index = employees[n]; // n's manager.
    if (next_node_index == -1) { return depth + 1; }
    return dfs(next_node_index, depth + 1);
}

int main() {
    int N; cin >> N;
    // 1 or 0 immediate manager.
    // No cycle.
    for (int i = 1; i <= N; i++) {
        cin >> employees[i]; // Denotes immediate maanger for ith employee.
    }

    int max_val = 0;
    for (int n = 1; n <= N; n++) {

        max_val = max(dfs(n, 0), max_val);
    }

    cout << max_val << endl;

    // Divide N employees into groups.
    // Must use all employees.
    // In any group must not have superior(A, B).
    // Output min number of groups.
    return 0;
}
