#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

char getComplement(char c) {
	if (c == '|') return '-';
	else if (c == '-') return '|';
	else if (c == '/') return '\\';
	else return '/';
}

pii getNewForce(pii force, char c) {
	if (c == '|') {
		if (force.first == 1 || force.second == 0)
			return make_pair(1, 0);
		else
			return make_pair(-1, 0);
	}
	else if (c == '-') {
		if (force.first == 0 || force.second == 1)
			return make_pair(0, 1);
		else
			return make_pair(0, -1);
	}
	else if (c == '/') {
		if (force.first == 1 || force.second == 1)
			return make_pair(1, 1);
		else
			return make_pair(-1, -1);
	}
	else {
		if (force.first == -1 || force.second == 1)
			return make_pair(-1, 1);
		else
			return make_pair(1, -1);
	}	
}

void solve(int N, int S, int Fx, int Fy) {
	map<pii, char> board;
	int startx, starty;
	
	for (int i=0;i<N;i++) {
		int x,y; char c;
		cin >> x >> y >> c;
		board[make_pair(x,y)] = c;
		if (i==S) {
			startx = x; starty = y;
		}
	}

	queue<pii> q;
	q.push(make_pair(startx,starty));
	pii force = make_pair(Fx,Fy);
int n = 0;
	while (!q.empty()) {
		pii curPos = q.front(); q.pop();

		char curC = board[curPos];
		board[make_pair(curPos.first, curPos.second)] = 'X';
		n++;
		pii nextPos = make_pair(curPos.first + force.first, curPos.second + force.second);
		if (board.count(nextPos) && board[nextPos] != 'X' && board[nextPos] != getComplement(curC)) {
			q.push(nextPos);
			force = getNewForce(force, board[nextPos]);
		}
	}
	cout << n << endl;
}


int main() {
	int N, S, Fx, Fy;
	while (cin >> N >> S >> Fx >> Fy, N || S || Fx || Fy) {
		solve(N, S, Fx, Fy);
	}
	return 0;
}
