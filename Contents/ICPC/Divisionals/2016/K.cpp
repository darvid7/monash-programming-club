#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;

vector<vi> board(9, vi(9));
vector<vector<bool>> visited(9, vector<bool>(9, false));
vector<vector<vector<pii>>> adjList(9, vector<vector<pii>>(9));

pii dfs(int i, int j, set<int> &appeared) {
	visited[i][j] = true;
	pii ans = {board[i][j],1};
	appeared.insert(board[i][j]);
	for (pii neighbour : adjList[i][j]) {
		int nextI,nextJ; nextI=neighbour.first; nextJ =neighbour.second;
		if (!visited[nextI][nextJ]) {
			pii result = dfs(nextI, nextJ, appeared);
			ans.first += result.first;
			ans.second += result.second;
		}
	}
	return ans;
}

bool solve() {

	vector<string> lines(19);
	for (int i=0;i<19;i++) {
		getline(cin, lines[i]);
	}

	for (int i=1;i<=17;i+=2) {
		for (int j=2;j<=35;j+=4) {
			int row, col; row = i/2; col = (j-2)/4;
			board[row][col] = lines[i][j] - '0';
		}
	}

	// find edge between i,j and i+1,j
	for (int i=0;i<8;i++) {
		int row = i*2+2;
		for (int j=0;j<9;j++) {
			int col = j*4+2;
			if (lines[row][col] == ' '){
				adjList[i][j].push_back({i+1,j});
				adjList[i+1][j].push_back({i,j});
			}
		}
	}

	// find edge between i,j and i+1,j
	for (int i=0;i<9;i++) {
		int row = i*2+1;
		for (int j=0;j<8;j++) {
			int col = (j+1)*4;
			if (lines[row][col] == ' '){
				adjList[i][j].push_back({i,j+1});
				adjList[i][j+1].push_back({i,j});
			}
		}
	}
	// check row valid
	for (vi nums : board) {
		set<int> appeared;
		for (int num : nums) appeared.insert(num);
		if (appeared.size() != 9) {
			return false;
		}
	}
	
	// check col valid
	for (int j=0;j<9;j++) {
		set<int> appeared;
		for (int i=0;i<9;i++) {
			appeared.insert(board[i][j]);
		}
		if (appeared.size() != 9) {
			return false;
		}
	}
	// check grid valid
	for (int row=0;row<=6;row+=3) {
		for (int col=0;col<=6;col+=3) {
			set<int> appeared;
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++) {
					appeared.insert(board[row+i][col+j]);
				}
			}
			if (appeared.size() != 9) {
				return false;
			}
		}
	}

	// check cage
	int i,j,sum;
	while (cin >> i >> j >> sum) {
		i--;j--;
		for (int a=0;a<9;a++){
			for (int b=0;b<9;b++) visited[a][b] = false;
		}
		set<int> appeared;
		pii result = dfs(i,j, appeared);
		if (!(result.first == sum && result.second == (int)appeared.size())) {
			return false;
		}
	}
	return true;
}

int main() {
	if (!solve()){
		cout << "Not";
	}
	cout << "OK" << endl;
	return 0;
}
