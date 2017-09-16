#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vvi;
typedef vector<vector<pair<int, char> > > vvpic;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef pair<int, pair<int, int> > n_coords; // First int is node id, 2nd pair is (r, c) coords.



vvpic implicit_graph; // Holds graph along with node id.

vector<pair<int, int> > parents;
vector<int> visited;
int can_see_deterium_atoms = 0;

bool can_move(int row, int col, int max_row, int max_col) {
	if (row >= 0 and row < max_row and col >= 0 and col < max_col) {
		if (implicit_graph[row][col].second == '#') {
			return false;
		}
		return true;
	}
	return false;
}

bool bfs(n_coords start, int max_row, int max_col, n_coords goal) {
	bool can_reach = false;

	cerr << "bfs start: (" << start.second.first << ", " << start.second.second  << ")" << endl;
	queue<n_coords> q;
	q.push(start);
	while(!q.empty()) {
		n_coords cur_n = q.front();
		q.pop();

		int cur_node_id = cur_n.first;

		if (goal.first == cur_node_id) {
			can_reach = true;
		}

		pair<int, int> cur = cur_n.second;  // Current coords.

		cerr << "bfs current node: id: " << cur_node_id << " w/ coords: (" << cur.first << ", " << cur.second << ")" << endl;

		if (visited[cur_node_id] == 1) {
			continue;
		}
		visited[cur_node_id] = 1;

		// Process edges.
		if (can_move(cur.first - 1, cur.second, max_row, max_col)) {
			// Move down.
			int next_node_id = implicit_graph[cur.first - 1][cur.second].first;
			parents[next_node_id] = cur;
			q.push({next_node_id, {cur.first - 1, cur.second}});
			if (implicit_graph[cur.first - 1][cur.second].second == 'O') {
				can_see_deterium_atoms++;
			}
		}

		if (can_move(cur.first + 1, cur.second, max_row, max_col)) {
			// Move up.
			int next_node_id = implicit_graph[cur.first + 1][cur.second].first;
			parents[next_node_id] = cur;
			q.push({next_node_id, {cur.first + 1, cur.second}});
			if (implicit_graph[cur.first + 1][cur.second].second == 'O') {
				can_see_deterium_atoms++;
			}
		}

		if (can_move(cur.first, cur.second + 1, max_row, max_col)) {
			// Move right.
			int next_node_id = implicit_graph[cur.first][cur.second + 1].first;
			parents[next_node_id] = cur;
			q.push({next_node_id, {cur.first, cur.second + 1}});
			if (implicit_graph[cur.first][cur.second + 1].second == 'O') {
				can_see_deterium_atoms++;
			}
		}

		if (can_move(cur.first, cur.second - 1, max_row, max_col)) {
			// Move left.
			int next_node_id = implicit_graph[cur.first][cur.second - 1].first;
			parents[next_node_id] = cur;
			q.push({next_node_id, {cur.first, cur.second - 1}});
			if (implicit_graph[cur.first][cur.second - 1].second == 'O') {
				can_see_deterium_atoms++;
			}
		}
	}
	return can_reach;
}

int main() {
	int R, C;
	cin >> R >> C;
}



	parents.resize(R * C);
	visited.resize(R * C);
	implicit_graph.resize(R);

	vector<n_coords> alpha_atoms;
	vector<n_coords> deterium_atoms;

	int node_id = 0;

	for(int r = 0; r < R; r++) {
		string s;
		cin >> s;
		for(int c = 0; c < (int) s.size(); c++) {
			char ch = s[c];
			implicit_graph[r].push_back({node_id, ch});

			if (ch == 'O') {
				deterium_atoms.push_back({node_id, {r, c}});
			} else if (ch == 'A') {
				alpha_atoms.push_back({node_id, {r, c}});
			}
			node_id++;

		}
	}
	cerr << "read everything" << endl;

	// Find shortest path using bfs.
	n_coords first_alpha_atom = alpha_atoms[0];
	if (!bfs(first_alpha_atom, R, C, alpha_atoms[1])) {
		// Return can't reach goal.
		cout << "-1" << endl;
		return 0;
	}

	// Construst shortest path from alpha_atoms[1] to alpha_atoms[0].
	int current_id = alpha_atoms[1].first;
	int goal_id = alpha_atoms[0].first;
	vector<int> shortest_path_ids;

	while(true) {
		if (current_id == goal_id) {
			break;
		}
		shortest_path_ids.push_back(current_id);
		pair<int, int> parent_of_current = parents[current_id];
		int id_of_parent_of_current = implicit_graph[parent_of_current.first][parent_of_current.second].first;


	}


	// TODO: no path.

	cerr << "printing alpha atoms " << endl;
	for(int i = 0; i < (int) alpha_atoms.size(); i++) {
		int id =  alpha_atoms[i].first;
		pair<int, int> coords = alpha_atoms[i].second;
		cerr << "id:  " << id << " w/ coords r: " << coords.first << ", c: " << coords.second << endl;
	}
	cerr << "o atoms: " << can_see_deterium_atoms << endl;
	cerr << "Printing parents " << endl;
	for(int i = 0; i < (int) parents.size(); i++) {
		pair<int, int> parent = parents[i];
		cerr << "node: " << i << " has parent (r: " << parent.first << ", c:" << parent.second << ")" << endl;
	}






	return 0;
}
