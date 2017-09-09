#include <bits/stdc++.h>

//  g++ -std=c++11 -Wall file.cpp -o F
using namespace std;


int main() {
	int N, M;
	cin >> N >> M;
	int flag = 0;	
	for(int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			// Is even.
			cout << string(M, '#') << endl;	
		} else {
			// string(N, char) will create a string of chars of size N.
			if (flag == 0) { 
				flag = 1; 
				cout << string(M - 1, '.') << "#" << endl;
			} else {
				flag = 0;
				cout << "#" << string(M - 1, '.') << endl;
			}
		}
	}
	return 0;
}
