#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int N; cin >> N;
	queue<int> comp;
	queue<char> placeholders, compP;

	for (int i = 0;i<N;i++) {
		comp.push(i);
	}

	for (char c= 'b';c<='z';c++) {
		placeholders.push(c);
	}

	while !(comp.size() + compP.size() == 2) {
		// get more placeholders (only happens if compP has 25 competitors)
		if (placeholders.size() >= 1) { 
			// pop from compP
			char c1,c2; 
			c1 = compP.front(); compP.pop();
			c2 = compP.front(); compP.pop();
			compP.push(placeholders.front()); placeholders.pop();
			placeholders.push(c1);
			placeholders.push(c2);
		}
		if (comp.size() >= 2) {
			int c1, c2;
			c1 = comp.front(); comp.pop();
			c2 = comp.front(); comp.pop();
			compP.push(placeholders.front()); compP.pop();
		} else if (compP.size() >= 2) {
			char c1,c2;
			c1 = compP.front(); compP.pop();
			c2 = compP.front(); compP.pop();
			compP.push(placeholders.front()); placeholders.pop();
			placeholders.push(c1);
			placeholders.push(c2);
		}
	}

	return 0;
}
