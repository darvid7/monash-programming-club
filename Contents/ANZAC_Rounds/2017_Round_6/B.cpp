#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

set<string> validWords, foundWords;
string longestWord;
vector<string> board(4);

int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};
int points[9] = {0,0,0,1,1,2,3,5,11};

int rowColToNum(int r, int c) {
	return 4*r + c;
}

pii numToRowCol(int n) {
	int row = n/4;
	int col = n%4;
	return {row,col};
}

int setBm(int b, int i) {
	return (b | (1<<i));
}

int isOn(int b, int i) {
	return b & (1<<i) != 0;
}

ll rec(int i, int j, int b, string cur) {
	if ((int)cur.size() >8) return 0;
	if (i < 0 || i >= 4 || j < 0 || j >= 4) return 0;
	if (isOn(b, rowColToNum(i,j))) {
		return 0;
	}
	b = setBm(b, rowColToNum(i,j));
	cur += board[i][j];
	ll ans = 0;

	auto it = validWords.lower_bound(cur);
	if (it == validWords.end()) return 0;
	string match = *it;


	for (int k=0;k<min((int)cur.size(), (int)match.size());k++) {

	  if (cur[k] != match[k]) return 0;
	}
	if (cur.size() == match.size()) {
		if (foundWords.count(cur) == 0) {
			foundWords.insert(cur);
			ans += points[(int)cur.size()];
			if (cur.size() > longestWord.size()) {
				longestWord = cur;
			} else if (cur.size() == longestWord.size()) {
				longestWord = (cur < longestWord ? cur : longestWord);
			}
		}
	}

	// string can still work
	for (int k=0;k<8;k++) {
		int row,col;
		row = i+dr[k];
		col = j+dc[k];
		ans += rec(row, col, b, cur);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i=0;i<N;i++) {
		string s; cin >> s;
		validWords.insert(s);
	}

	int B; cin >> B;
	while (B--) {
		for (int i=0;i<4;i++) cin >> board[i];
		foundWords.clear();
		longestWord = "";

		ll ans = 0;
		for (int i=0;i<4;i++) {
			for (int j=0;j<4;j++) {
				int id = rowColToNum(i,j);
				ans += rec(i,j, 0, "");
			}
		}
		cout << ans << " " << longestWord << " " << foundWords.size() << endl;
	}	
	return 0;
}
