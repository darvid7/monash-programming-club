#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	int min_so_far = 1000001;

	for (int i = 0; i < N; i++) {
		int newest_price;
		cin >> newest_price;
		if (newest_price < min_so_far) {
			min_so_far = newest_price;
		}
		cout << min_so_far << " \n"[i==N-1];
		min_so_far++;
	
	}
}
