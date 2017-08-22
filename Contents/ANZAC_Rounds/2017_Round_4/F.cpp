#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> pn(n);
  vector<int> ps(n);
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    pn[i] = name;
    ps[i] = i + 1;
  }
  int seatCount = n;
  int r;
  cin >> r;
  for (int k = 0; k < r; k++) {
    int s, m;
    cin >> s >> m;
    
    for (int i = 0; i < ps.size(); i++) {
      // cout << pn[i] << ": " << endl;
      // for (int i = 0; i < ps.size(); i++) {
      // 	cout << ps[i];
      // }
      // cout << endl;
      
      if (ps[i] != -1) {
	int ns = ps[i] + m;
	ns = ns % seatCount;
	if (ns == 0) ns = seatCount;
	ps[i] = ns;
	
	if (ps[i] == s) {
	  cout << pn[i] << " has been eliminated." << endl;
	  ps[i] = -1;
	}
	else if (ps[i] > s) {
	  ps[i] -= 1;
	}
      }
    }
    seatCount -= 1;

    // for (int i = 0; i < ps.size(); i++) {
    //   cout << ps[i];
    // }
    // cout << endl;
  }
  if (seatCount == 1) {
    string winner;
    for (int i = 0; i < n; i++) {
      if (ps[i] != -1) winner = pn[i];
    }
    cout << winner << " has won." << endl;
  }
  else {
    cout << "Players left are";
    for (int i = 0; i < n; i++) {
      if (ps[i] != -1) cout << " " << pn[i];
    }
    cout << "." << endl;
  }
  return 0;
}
