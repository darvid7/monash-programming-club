#include <bits/stdc++.h>

//  g++ -std=c++11 -Wall file.cpp -o F
using namespace std;

typedef vector<int> vi;

int main() {
	int S; // S is random number in memory, be careful with this.
//	int num[S]; // Don't use arrays like this, num[S] is undefined C++ won't let you do this g++ will convert this to somything else, use fectors. Pass vectors with & so pass by refernce otherwise will copy every time,
	cin >> S; vi num(S); 

	for(int i = 0; i < S; i++) {
		cin >> num[i]; 
	}
	sort(num.begin(), num.end()); // takes num without () is a pointer to start of array, + 5 is 5 later.
	int c = 0;
	int min_s = num[0];
	int max_s = num[S - 1];
	for(int i = 1; i < S - 1; i++) {
		if (num[i] > min_s and num[i] < max_s) {
			c++;		
		}
	}
	cout << c << endl;
	return 0;

}
