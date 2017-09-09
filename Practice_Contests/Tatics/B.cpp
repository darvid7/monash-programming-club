#include <bits/stdc++.h>

//  g++ -std=c++11 -Wall file.cpp -o F
using namespace std;

typedef vector<int> vi;
typedef long long ll;

ll sum_to_n(ll v) {
	// sum to n gives the sum of values up to n inclusive.
	// eg: sum to 5 = 1 + 2 + 3 + 4
	return ((v + 1) * v)/2;
}

int main() {
	int S; // S is random number in memory, be careful with this.
//	int num[S]; // Don't use arrays like this, num[S] is undefined C++ won't let you do this g++ will convert this to somything else, use fectors. Pass vectors with & so pass by refernce otherwise will copy every time,
	cin >> S; vi num(S); 

	for(int i = 0; i < S; i++) {
		cin >> num[i]; 
	}
	// 2 * 10^5 = 10^10, int's can only hold 10^9. 
	
	// minmax_element() finds smallest and greatest element in range [first, last).
	// min_element(first, last, val to match) finds smallest element in range [first, last).
	// max_element(first, last, val to match) finds greatest element in range [first, last).
	// a = [1, 2] .end() is after 2.	
	ll min_el = *min_element(num.begin(), num.end());
	ll max_el = *max_element(num.begin(), num.end());
	
	ll num_min_el;
	num_min_el = count(num.begin(), num.end(), min_el); 
	ll num_max_el;
	num_max_el = count(num.begin(), num.end(), max_el);

	if (max_el != min_el) {
		cout << max_el - min_el << " " << num_min_el * num_max_el << endl;	
	} else {
		// get sum to n - 1.
		cout << max_el - min_el << " " << sum_to_n(num_min_el - 1) << endl;	
	}

	return 0;

}
