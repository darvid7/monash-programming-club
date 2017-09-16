#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int UNVISITED = -1;
int VISITED = 1;

vvi adjList(105);
vi visited(105, UNVISITED);

bool euclidean(pair<ll, ll> c1, pair<ll, ll> c2) {
	ll x1 = c1.first, y1 = c1.second, x2 = c2.first, y2 = c2.second;
	ll dist = abs(x1-x2) + abs(y1-y2);
	return dist <= 1000;
}

void dfs(int u) {
	visited[u] = VISITED;
	for (int v : adjList[u]) {
		if (visited[v] == UNVISITED) {
			dfs(v);
		}
	}
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i=0;i<N+2;i++) {
			adjList[i].clear();
		}
		for (int i=0;i<N+2;i++) {
			visited[i] = UNVISITED;
		}
		vector<pair<ll, ll>> coords(N+2);
		for (int i=0;i<N+2;i++) {
			ll x,y; cin >> x >> y;
			coords[i] = {x,y};			
		}
		for (int i=0;i<N+1;i++) {
			for (int j=i+1;j<N+2;j++) {
				if (euclidean(coords[i], coords[j])) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
		}
		dfs(0);
		if (visited[N+1] == VISITED) cout << "happy";
		else cout << "sad";
		cout << endl;
	}
	return 0;
}
