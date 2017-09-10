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

	if (grid[x][y] == '#') return false;
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
}

int solve() {
	cin >> R >> C;
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
	return 0;
}
