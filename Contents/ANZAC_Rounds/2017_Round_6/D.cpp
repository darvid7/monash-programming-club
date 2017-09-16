#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int UNVISITED = -1;
int EXPLORED = 0;
int VISITED = 1;

vvi adjList(1e5+5);
vi visited(1e5+5, UNVISITED);
vi dfs_parent(1e5+5, 0);

bool dfs(int u) {
	visited[u] = EXPLORED;
	for (int v : adjList[u]) {
		if (visited[v] == UNVISITED) {
			dfs_parent[v] =u;
			if (!dfs(v)) return false;
		} else if (visited[v] == EXPLORED) {
				return false;
		}
	}
	visited[u] = VISITED;
	return true;
}

int main() {
	int N; cin >> N;
	map<string, int> nameId;
	int id = 0;

	for (int i=0;i<N;i++) {
		string n1,n2; char c; cin >> n1 >> c >> n2;
		if (!nameId.count(n1)) nameId[n1] = id++;
		if (!nameId.count(n2)) nameId[n2] = id++;
		if (c == '>') {
			adjList[nameId[n1]].push_back(nameId[n2]);	
		} else {
			adjList[nameId[n2]].push_back(nameId[n1]);				
		}
	}

	for (int i=0;i<id;i++) {
		if (visited[i] == UNVISITED) {
			if (!dfs(i)) {
				cout << "impossible" << endl;
				return 0;
			}
		}
	}
	cout << "possible" << endl;
	return 0;
}
