#include <bits/stdc++.h>

using namespace std;

int check(string input) {
  if (input.size() == 1) return 1;
  else {
    for (int i = 1; i < input.size(); i++) {
      int f = input[i], n = input[i-1];
      int tmp = f - n;
      if (tmp < 0) tmp += 7;
      if (tmp != 2 && tmp != 4 && tmp != 6) {
	// cout << (char)f << " " << (char)n << " " << tmp << endl;
	return 0;
      }
    }
    return 1;
  }
}

int main() {
  string input;
  cin >> input;
  while (input != "#") {
    if (check(input) == 1) {
      cout << "That music is beautiful." << endl;
    }
    else {
      cout << "Ouch! That hurts my ears." << endl;
    }
    cin >> input;
  }
  
  return 0;
}
