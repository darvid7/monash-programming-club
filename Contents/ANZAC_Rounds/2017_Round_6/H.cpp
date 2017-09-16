#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi h;

int main() {
  int n;  cin >> n;
  for (int i = 0; i < n; i++) {
    int tmp;  cin >> tmp;
    h.push_back(tmp);
  }

  sort(h.begin(), h.end());

  int result = min(n, h[n-1]);
  for (int i = 1; i < n; i++) {
    result = min(result, i+min(h[n-1-i], n-i));
  }

  cout << result << endl;
  return 0;
}
