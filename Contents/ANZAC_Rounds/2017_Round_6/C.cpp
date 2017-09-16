#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi table(105, vi(105));
vvi memo(105, vi(105,-1));

int C, M;

ll rec(int mId, int remC) {
	if (mId == M) return 0;
	if (remC == 0) return 0;
	if (memo[mId][remC] != -1) return memo[mId][remC];
	
	// try sell to this guy
	ll bestAns = 0;
	for (int i=0;i<=remC;i++) {
		bestAns = max(bestAns, table[mId][i] + rec(mId+1, remC-i));		
	}

	memo[mId][remC] = bestAns;

	return bestAns;
}

int main() {
	cin >> C >> M;
	for (int i=0;i<M;i++) {
		for (int j=1;j<=C;j++) {
			cin >> table[i][j];
		}
	}

	cout << rec(0,C) << endl;
	return 0;
}
