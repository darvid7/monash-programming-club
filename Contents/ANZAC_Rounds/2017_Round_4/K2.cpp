#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005] = {0};
vector<int> weights, values;

int max3(int a, int b, int c) {
  return max(a, max(b, c));
}

void solve() {
  int N, W1, W2;
  cin >> N >> W1 >> W2;
  for (int i=0;i<1005;i++) for(int j=0;j<1005;j++) dp[i][j]=0;
  weights.resize(N); values.resize(N);
  for (int i = 0; i < N; i++) cin >> weights[i];
  for (int i = 0; i < N; i++) cin >> values[i];
  
  for (int i = 0; i < N; i++) {
    int weight = weights[i], value = values[i];
    for (int s1 = W1; s1 >= 0; s1--) {
      for (int s2 = W2; s2 >= 0; s2--) {
	if (s1 >= weight && s2 >= weight) {
	  dp[s1][s2] = max3(dp[s1][s2], dp[s1-weight][s2]+value, dp[s1][s2-weight]+value);
	}
	else if (s1 >= weight) {
	  dp[s1][s2] = max(dp[s1][s2], dp[s1-weight][s2]+value);
	}
	else if (s2 >= weight) {
	  dp[s1][s2] = max(dp[s1][s2], dp[s1][s2-weight]+value);
	}
      }
    }
  }

  int result = 0;
  for (int i = 0; i <= W1; i++) {
    for (int j = 0; j <= W2; j++) {
      if (dp[i][j] > result) result = dp[i][j];
    }
  }

  cout << result << endl;
}

int main() {
  int P;
  cin >> P;
  for (int i = 0; i < P; i++) {
    cout << "Problem " << i+1 << ": ";
    solve();
  }
  return 0;
}
