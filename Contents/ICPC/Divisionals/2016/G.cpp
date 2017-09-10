#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

int grass[11][11];

int main() {
  int k;
  cin >> k;
  vvi weeks(k+1);
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < 6; j++) {
      int tmp;
      cin >> tmp;
      weeks[i].push_back(tmp);
    }
  }

  int day = 1;
  for (int i = k; i >= 1; i--) {

    // DEBUG
    // cerr << day << ": " << endl;
    // for (int i = 1; i <= 10; i++) {
    //   for (int j = 1; j <= 10; j++) {
    //     cout << grass[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    //DEBUG

    for (int j = 0; j < 6; j++) {
      // cout << "j: " << weeks[i][j] << endl;
      if (j < 3) {
	int r = weeks[i][j];
	for (int column = 1; column <= 10; column++) {
	  if (!grass[r][column]) grass[r][column] = day;
	}
      }
      else {
	int c = weeks[i][j];
	for (int row = 1; row <= 10; row++) {
	  if (!grass[row][c]) grass[row][c] = day;
	}
      }
    }
    day += 1;
  }

  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      if (!grass[i][j]) cout << day << " \n"[j==10];
      else cout << grass[i][j] << " \n"[j==10];
    }
  }

  return 0;
}
