#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

vi weights, values;
int N, W1, W2;

ll rec(int i, int W1, int W2, vector<vector<vector<ll>>> &memo) {
	if (W1 < 0 || W2 < 0) return LLONG_MIN/2;
	if (i == N) return 0;
	if (memo[i][W1][W2] != -1) return memo[i][W1][W2];
	ll tryD1Take = values[i] + rec(i+1, W1-weights[i], W2, memo);
	ll tryD2Take = max(tryD1Take, values[i] +  rec(i+1, W1, W2-weights[i], memo));
	ll tryNoTake = max(tryD2Take, rec(i+1, W1, W2, memo));
	memo[i][W1][W2] = tryNoTake;
	return tryNoTake;
}


void solve() {
	cin >> N >> W1 >> W2;
	weights.resize(N); values.resize(N);
	for (int i=0;i<N;i++) cin >> weights[i];
	for (int i=0;i<N;i++) cin >> values[i];
	vector<vector<vector<ll>>> memo(N, vector<vector<ll>>(W1+5, vector<ll>(W2+5,-1)));
	cout << rec(0,W1,W2,memo) << endl;
}


int main() {
	int P; cin >> P;
	for (int i=1;i<=P;i++) {
		cout << "Problem " << i << ": ";
		solve();
	}
	return 0;
}
