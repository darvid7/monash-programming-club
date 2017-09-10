#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// -1 means don't look at it, 0 is a colour, 1 is a colour, -2 means don't need to colour.
vi nodes(2000, -1); // vector<int>(size, default int value).

vvi adjlist(2000);

bool two_colouring(int n, int colour) {
	if (nodes[n] > -1) {
		// Already coloured.
		return true;		
	}
	
	nodes[n] = colour;
	// vector.size() returns size_t which is unsigned int.
	for(int adj_i = 0; adj_i < (int) adjlist[n].size(); adj_i++) {
		int adj_n = adjlist[n][adj_i];
		if (nodes[adj_n] == colour) {
			cout << "node: " << n << " and " << adj_n << " have same colour " << colour << endl;
			return false;		
		}
		if (nodes[adj_n] == -1) {
			cout << "WTF " << endl;		
		}

		bool can_colour = two_colouring(adj_n, colour ^ 1);
		if (can_colour == false) {
			return false;		
		}
	}
	return true;
}


int main() {
	int L, R, N, C;
	cin >> L >> R >> N >> C;

	// Make graph.
	for(int c = 0; c < C; c++) {
		int x, y;
		cin >> x >> y;
		adjlist[x].push_back(y);
		adjlist[y].push_back(x);	
	}
	for(int i = 0; i < N; i++) {
		nodes[i] = -2;	
	}

	for(int n = 0; n < N; n++) {
		bool can_colour = two_colouring(n, 1);
		if (can_colour == false) {
			cout << "NO here, idx: " << n << endl;
			return 0;		
		}
	}
	
	cout << "HERE ARE MY NODES" << endl;
	
	for(int idx = 0; idx < N; idx++) {
		cout << "index: " << idx << " has colour " << nodes[idx] << endl;
	}
	
	// Can avoid conflitcs, check capacity.
	int colour_1 = 0;
	int colour_0 = 0;
	int colour_less = 0;
	
	colour_1 = count(nodes.begin(), nodes.end(), 1);
	colour_0 = count(nodes.begin(), nodes.end(), 0);
	colour_less = count(nodes.begin(), nodes.end(), -2);
	
	cout << "colour 0: " << colour_0 << endl;
	cout << "colour 1: " << colour_1 << endl;
	cout << "colourless: " << colour_less << endl;

	int left_remaining; 
	int right_remaining; 
	
	// Try put colour 0 in L.
	left_remaining = L - colour_0;
	right_remaining = R - colour_1;
	if (left_remaining >= 0 and right_remaining >= 0) {
		int left_over = left_remaining + right_remaining;
		if (left_over >= colour_less) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}

	// Try out colour 1 in L.
	left_remaining = L - colour_1;
	right_remaining = R - colour_0;
	if (left_remaining >= 0 and right_remaining >= 0) {
		int left_over = left_remaining + right_remaining;
		if (left_over >= colour_less) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}

	cout << "NO" << endl;
	return 0;
}
