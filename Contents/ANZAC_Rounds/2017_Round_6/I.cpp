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

ll F(ll x, ll n, ll c) {
	x = big(x)*x%n-c; 
	return (x < 0 ? x + n : x); 
}

ll pollardRho(ll n) {
	ll i,c,b,x,y,z,g;
	for (g=0,c=3;g%n==0;c++)
		for (g=b=x=y=z=1;g == 1;b*=2,g=__gcd(z,n),z=1,y=x)
			for (i=0;i<b;i++) {
				x=F(x,n,c);
				z=(big)z * abs(x-y)%n;
			}
	return g;
}

ll factor_huge(ll n) {
	ll ans = 1, tmp = n;
	for (ll i=2;i*i*i <= n;++i) {
		ll c = 0;
		if (tmp%i == 0) {
			while (tmp%i==0) {
				c++;
				tmp/=i;
			}
			ans *= (c+1);
			//cerr << i << " " << c << endl;
		}
	}
	if (tmp == 1) return ans;
	if (ll(sqrt(tmp))*ll(sqrt(tmp)) == tmp) {
		ans *= 3;
		//cerr << "sqrt " << sqrt(tmp) << " " << 2 << endl;
		return ans;
	}
	if (is_prime(tmp)) {
		ans *= 2;
		//cerr << "prime" << n << " " << 1 << endl;
		return ans;
	}
	ll q = pollardRho(tmp);
	//cerr << "pollar" << endl;
	//cerr << q << " " << 1 << endl;
	//cerr << tmp/q << " " << 1 << endl;
	ans *= 2;ans *= 2;
	return ans;
}

int main() {
	ll N; cin >> N;
	if (N==1) cout << 1 << endl;
	else cout << factor_huge(N) << endl;
  return 0;
}
