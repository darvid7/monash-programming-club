#include <bits/stdc++.h>

using namespace std;

int main() {
	string team1, team2;
	getline(cin, team1); getline(cin, team2);
	int S; cin >> S;
	string strokes; cin >> strokes;
	vector<int> scores(2,0);
	bool isWon = false;
	for (int i=0;i<S;i++) {
		char c = strokes[i];
		if (c == 'H') {
			scores[i%2]++;
		} else if (c == 'D') {
			scores[i%2]+=2;
		} else if (c == 'O') {
			scores[(i+1)%2]++;
		}
		scores[0] = min(7, scores[0]); scores[1] = min(7, scores[1]);
		if (scores[0] == 7 || scores[1] == 7) {
			isWon = true;
			break;
		}
	}
	if (isWon) {
	  cout << team1 << " " << scores[0] << " " << team2 << " " << scores[1] << ". " << ((scores[0] == 7) ? team1 : team2) << " has won." << endl;
	} else {
		if (scores[0] == scores[1]) {
	  cout << team1 << " " << scores[0] << " " << team2 << " " << scores[1] << ". All square." << endl;
		} else {
		  cout << team1 << " " << scores[0] << " " << team2 << " " << scores[1] << ". " << ((scores[0] > scores[1]) ? team1 : team2) << " is winning." << endl;
		}		
	}
	return 0;
}
