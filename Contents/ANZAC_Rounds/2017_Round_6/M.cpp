#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<ll, int, int> tp;

int UNVISITED = -1;
int VISITED = 1;

vvi adjList(105);
vi cost(105);
vector<vector<vector<bool>>> badEdge(105, vector<vector<bool>>(105, vector<bool>(105, false)));
vector<vector<ll>> dist(105, vector<ll>(105,-1));

void dijkstra(int u) {
	priority_queue<tp, vector<tp>, greater<tp>> pq;
	pq.push(make_tuple(0,1,0));
	dist[u][0] = 0;
	while (!pq.empty()) {
		tp cur = pq.top(); pq.pop();
		ll d = get<0>(cur); 
		int u, p; 
		u = get<1>(cur); p = get<2>(cur);
		if (d > dist[u][p]) continue;
		for (int v : adjList[u]) {
			if (badEdge[u][v][p]) continue;
			if (dist[v][u] == -1 || d + cost[u] < dist[v][u]) {
				dist[v][u] = d + cost[u];
				pq.push(make_tuple(d+cost[u],v,u));
			}
		}
	}
}

int main() {
	int N; cin >> N;
	for (int i=1;i<=N;i++) {
		int E,T; cin >> E >> T;
		cost[i] = T;
		for (int e=0;e<E;e++) {
			int S,X; cin >> S >> X;
			adjList[i].push_back(X);
			for (int s=0;s<S;s++) {
				int badParent; cin >> badParent;
				badEdge[i][X][badParent] = true;
			}
		}
	}

	dijkstra(1);

	ll ans = -1;
	for (ll d : dist[N]) {
		if (d == -1) continue;
		if (ans == -1 || d < ans) {
			ans = d;
		}
	}

	if (ans == -1) {
		cout << "impossible" << endl;
	} else {
		cout << ans + cost[N] << endl;
	}
	
	return 0;
}
