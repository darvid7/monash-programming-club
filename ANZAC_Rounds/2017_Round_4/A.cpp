#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    string answer = "Seems OK";
    cin >> a >> b >> c;
    if (a + b + c != 180) answer = "Check";
    cout << a << " " << b << " " << c << " " << answer << endl;
  }
  return 0;
}
