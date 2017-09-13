#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int dR[4] = {-1,0,1,0};
int dC[4] = {0,1,0,-1};
int R,C;

vector<string> grid;
vvi visited(1005, vi(1005,0));
vvi dist(1005, vi(1005,-1));
vector<vector<pii>> parent(1005, vector<pii>(1005, {-1,-1}));

vector<pii> A;

bool canGo(int x, int y) {
	if (x < 0 || x >= R || y < 0 || y >= C) return false;

<<<<<<< HEAD
bool can_move(int row, int col, int max_row, int max_col) {
	if (row >= 0 and row < max_row and col >= 0 and col < max_col) {
		if (implicit_graph[row][col].second == '#') {
			return false;
		}
		return true;
	}
	return true;
}

bool bfs(n_coords start, int max_row, int max_col) {
	queue<n_coords> q;
	q.push(start);
	
	while(!q.empty()) {
		n_coords cur_n = q.front();
		q.pop();
		
		int cur_node_id = cur_n.first;
		pair<int, int> cur = cur_n.second;  // Current coords.
		
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
<<<<<<< Updated upstream
=======
	return can_reach;
=======
	if (grid[x][y] == '#') return false;
>>>>>>> Stashed changes
	return true;
}

pair<bool, int> dfs(int curI, int curJ) {
	visited[curI][curJ] = true;

	pair<bool, int> ans;
	if (grid[curI][curJ] == 'A') {
		return {true, 0};
	}
	if (grid[curI][curJ] == 'O') ans.second = 1;
	for (int i=0;i<4;i++) {
		int nextI,nextJ; nextI = curI+dR[i]; nextJ = curJ+dC[i];
		if (canGo(nextI, nextJ) && !visited[nextI][nextJ]) {
			auto result = dfs(nextI, nextJ);
			ans.first |= result.first;
			ans.second += result.second;
		}
	}
	return ans;
}

void dijkstra(int startI, int startJ) {
	priority_queue<pair<ll,pii>, vector<pair<ll,pii>>, greater<pair<ll,pii>>> q;
	dist[startI][startJ] = 0;
	q.push({ 0, {startI,startJ} });

	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		ll d = cur.first;
		pii coords = cur.second;
		int curI, curJ; curI = coords.first; curJ = coords.second;
		if (d > dist[curI][curJ]) continue;
		// if we are at the other A, stop
		if (grid[curI][curJ] == 'A') return;

		for (int i=0;i<4;i++) {
			int nextI, nextJ; nextI = curI+dR[i]; nextJ = curJ+dC[i];
			if (canGo(nextI, nextJ)) {
				ll costToGo = ((grid[nextI][nextJ] == 'O') ? 2000 : 1);
				if (dist[nextI][nextJ] == -1 ||
						d + costToGo < dist[nextI][nextJ]) {
						parent[nextI][nextJ] = {curI,curJ};
						dist[nextI][nextJ] = dist[curI][curJ] + costToGo;
						q.push({ d+costToGo, {nextI,nextJ} });
					}
			}
		}
	}
>>>>>>> 4b1eca76b2197f8b8864c76cda256e00d9ce0c9c
}

int solve() {
	cin >> R >> C;
<<<<<<< Updated upstream
	
=======
<<<<<<< HEAD

>>>>>>> Stashed changes
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
		}
	}
	cout << "read everything" << endl;
	
	// Find shortest path using bfs.
	n_coords first_alpha_atom = alpha_atoms[0];
	bfs(first_alpha_atom, R, C);
	
	cout << "printing alpha atoms " << endl;
	for(int i = 0; i < (int) alpha_atoms.size(); i++) {
		int id =  alpha_atoms[i].first;
		pair<int, int> coords = alpha_atoms[i].second;
		cout << "id:  " << id << "w/ coords r: " << coords.first << ", c: " << coords.second << endl;
	}
	cout << "o atoms: " << can_see_deterium_atoms << endl;	
	cout << "Printing parents " << endl;
	for(int i = 0; i < (int) parents.size(); i++) {
		pair<int, int> parent = parents[i];
		cout << "node: " << i << " has parent (r: " << parent.first << ", c:" << parent.second << ")" << endl;
	}

	

<<<<<<< Updated upstream
	
	
=======



=======
	grid.resize(R);
	for (int i=0;i<R;i++) {
		cin >> grid[i];
	}

	for (int i=0;i<R;i++) {
		for (int j=0;j<C;j++) {
			if (grid[i][j] == 'A') A.push_back({i,j});
		}
	}

	// change first A to a #
	grid[A[0].first][A[0].second] = '#';

	// try dijkstra from up right, down, left
	int bestAns = 1e9;
	for (int i=0;i<4;i++) {
		int startI,startJ; startI = A[0].first + dR[i]; startJ = A[0].second + dC[i];
		if (canGo(startI,startJ)) {
			// clear memory
			for (int i=0;i<1005;i++) {
				for(int j=0;j<1005;j++) {
					visited[i][j] = 0;
					dist[i][j] = -1;
					parent[i][j] = {-1,-1};
				}
			}
			// check if we can reach destination and get count of all Os
			pair<bool, int> ans = dfs(startI, startJ);
			bool canReach = ans.first;
			int totalOs = ans.second;

			if (!canReach) continue;

			dijkstra(startI, startJ);
			if (dist[A[1].first][A[1].second] == -1) continue;

			pii cur = A[1]; int noOfOsInPath = 0;
			while (cur.first != -1 && cur.second != -1) {
				if (grid[cur.first][cur.second] == 'O') noOfOsInPath++;
				cur = parent[cur.first][cur.second];
			}

			// printf("%d %d\n", totalOs, noOfOsInPath);

			if (noOfOsInPath % 2 == 0) {
				bestAns = min(bestAns,noOfOsInPath/2 + 1);
			} else {
				if (totalOs >= noOfOsInPath+1) {
					bestAns = min(bestAns,(noOfOsInPath+1)/2 + 1);
				}
			}
		}
	}

	if (bestAns == 1e9) return -1;
	return bestAns;
}

int main() {
	cout <<  solve() << endl;
>>>>>>> 4b1eca76b2197f8b8864c76cda256e00d9ce0c9c
>>>>>>> Stashed changes
	return 0;
} 
