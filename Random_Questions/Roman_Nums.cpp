#include <bits/stdc++.h>

using namespace std;

int main() {
    const string roman_characters[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int numbers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int target; cin >> target;
    string result = "";
    int index = 0;
    while(target != 0) {
        if (target - numbers[index] >= 0) {
            target -= numbers[index];
            result += roman_characters[index];
        } else {
            index++;
            if (index >= 13) {
                cout << "WTF" << endl;
                return 0;
            }
        }
    }
    cout << result << endl;
}
