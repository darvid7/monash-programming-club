#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int N; cin >> N;
	vi a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((a[j] - a[i]) < 0) {
				cout << "no" << endl;
				return 0;
			}		
		}	
	} 
	cout << "yes" << endl;
	return 0;
}
