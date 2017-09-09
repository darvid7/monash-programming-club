#include <bits/stdc++.h>

//  g++ -std=c++11 -Wall file.cpp -o F
using namespace std;


int main() {
	int k,a , b;

	cin >> k;
	cin >> a;
	cin >> b;
	if ((a < k and b%k != 0) or (b < k and a%k != 0)) {
		cout << -1 << endl;	
		return 0;
	}
	int a_max_sets = a/k;
	int b_max_sets = b/k;
		
	cout << a_max_sets + b_max_sets << endl;

}
