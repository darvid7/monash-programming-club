#include <bits/stdc++.h>

using namespace std;

int main() {
	int DAYS, PAGES_PER_BOOK;
	cin >> DAYS >> PAGES_PER_BOOK;

	int books_used = 1;
	int pages_left = PAGES_PER_BOOK;
	for(int i = 0; i < DAYS; i++) {

		int pages_for_day;
		cin >> pages_for_day;

		if (pages_left - pages_for_day < 0) {
			// Need another book for today.
			books_used++;
			pages_left = PAGES_PER_BOOK;

		} else if (pages_left - pages_for_day == 0) {
			// We can use the book today, tmr won't have anything though.		
		}
		
		pages_left -= pages_for_day;		
		// cout << "pages left: " << pages_left << endl;
		
	}
	cout << books_used << endl;
}
