#include <bits/stdc++.h>

using namespace std;

int int_num(int num) {
  int count = 0, tmp = num, ans = 0, something = 1;
  while (tmp != 0) {
    count += 1;
    something *= 10;
    tmp /= 10;
  }

  if (count == 1) {
    return 4*num;
  }

  // cout << count << endl;
  int init = 1;
  for (int i = 1; i < count; i++) {
    init *= 10;
    ans += (init - init/10)*i;
  }
  ans += (num - (something/10) + 1) * count + (2+count)*num;
  // cout << num << ": " << ans << endl;
  return ans;
}

int main() {
  int n, t;  cin >> n >> t;

  int start = (t+n-1)/n;
  for (int i = start; i <= t; i++) {
    if (t + int_num(i) > i*n) continue;
    else {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  // cout << int_num(101) << endl;
  // cout << int_num(417) << endl;
  

  return 0;
}
