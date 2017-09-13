#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int colour[2005];
int memo[2005][2005];
vector<pii> dpData;
vvi adjList(200005);

pii dfs(int u, int c) {
    pii result = {0, 0};
    colour[u] = c;
    int curCol;
    if (c == 1) {
        result.first += 1;
        curCol = 2;
    }
    else {
        result.second += 1;
        curCol = 1;
    }

    for (auto&v : adjList[u]) {
        if (!colour[v]) {
            pii tmp = dfs(v, curCol);
            result.first += tmp.first;
            result.second += tmp.second;
        }
        else if (colour[v] == c) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    int a = min(result.first, result.second), b = max(result.first, result.second);
    return {a, b};
}


int main() {
    int L, R, N, C;
    cin >> L >> R >> N >> C;

    if (N > L+R) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < C; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dpData.push_back({0, 0});

    for (int i = 0; i < N; i++) {
        for (auto& u : adjList[i]) {
            if (!colour[i]) {
                dpData.push_back(dfs(u, 1));
            }
        }
    }

    int sum = 0, check = 0;
    for (pii p : dpData) {
        sum += p.first;
        check += p.second - p.first;
    }

    int newL = L-sum, newR = R-sum;
    int tmp = max(newL, newR);

    memo[0][0] = 1;
    for (int i = 1; i < dpData.size(); i++) {
        pii p = dpData[i];
        int num = p.second-p.first;
        for (int j = 0; j <= tmp; j++) {
            if (j-num > 0) {
                if (memo[i-1][j-num]) memo[i][j] = 1;
            }
            else if (j-num == 0) memo[i][j] = 1;
            if (memo[i-1][j]) memo[i][j] = 1;
        }
    }

    // for (int i = 0; i < dpData.size(); i++) {
    //     for (int j = 0; j <= tmp; j++) {
    //         cout << memo[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i <= tmp; i++) {
        if (memo[dpData.size()-1][i]) {
            int remaining = check - i;
            if (min(i, remaining) <= min(newL, newR) && max(i, remaining) <= tmp) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}
