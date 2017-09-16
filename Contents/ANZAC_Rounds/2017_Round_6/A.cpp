#include <bits/stdc++.h>

using namespace std;

typedef __int128 big;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi check = {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

vi val = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
ll expmod(big a, big b, big m) {
  big res=1%m; a %= m;
  for (; b; b/=2) {if (b&1) res=res*a%m;  a=a*a%m;}
  return res;
}
bool is_prime(ll n) {
  if (n < 2) return false;
  ll s = __builtin_ctzll(n-1), d = (n-1) >> s;
  for (int v : val) {
    if (v >= n) break;
    ll x = expmod(v, d, n);
    if (x == 1 || x == n-1) continue;
    for (ll r = 1; r < s; r++) if ((x = ((big(x)*x) % n)) == n-1) goto nextPr;
    return false;
    nextPr:;
  }
  return true;
}


int main() {
  string s;
  ll N = 0, newN = 0, count = 1;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    N += count * (s[s.size()-i-1]-'0');
    if (check[s[i]-'0'] == -1) {
      cout << "no" << endl;
      return 0;
    }
    else newN += count * check[s[i]-'0'];
    count *= 10;
  }
  if (is_prime(N) && is_prime(newN)) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}
