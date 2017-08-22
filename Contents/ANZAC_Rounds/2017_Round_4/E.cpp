#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int N;

int sumHorBits(vvi &bytes, int i) {
	int ans = 0;
	for (int j = 0;j<8;j++) {
		ans += bytes[i][j];
	}
	return ans;
} 

int sumVerBits(vvi &bytes, int j) {
	int ans = 0;
	for (int i =0; i<N+1;i++) {
		ans += bytes[i][j];
	}
	return ans;
} 

int main() {
	cin >> N;
	vvi bytes(N+1, vi(8));
	for (int i=0;i<N+1;i++) {
		for (int j=0;j<8;j++) {
			cin >> bytes[i][j];
		}
	}
	vi freqEvenOdd(2,0), recentIEvenOdd(2,0), recentJEvenOdd(2,0);
	bool isEven;
	for (int i=0;i<N;i++) {
		int nBits = sumHorBits(bytes, i);
		freqEvenOdd[nBits%2]++;
		recentIEvenOdd[nBits%2] = i;
	}
	isEven = (freqEvenOdd[0] > 1);
	for (int j=0;j<8;j++) {
		int nBits = sumVerBits(bytes, j);
		recentJEvenOdd[nBits%2] = j;
	}

	cout << ((isEven) ? "Even" : "Odd") << endl;
	if (isEven) {
		printf("Byte %d is broken\n", recentIEvenOdd[1]+1);
		printf("Bit %d is broken\n", recentJEvenOdd[1]+1);
	} else {
		printf("Byte %d is broken\n", recentIEvenOdd[0]+1);
		printf("Bit %d is broken\n", recentJEvenOdd[0]+1);
	}

	return 0;
}
