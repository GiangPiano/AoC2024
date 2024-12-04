#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void check(int i, int j, vector<string> &s) {
    // left
    if (i - 3 >= 0) {
        if (s[i - 1][j] == 'M' && s[i - 2][j] == 'A' && s[i - 3][j] == 'S') {
            cnt++;
        }
    }
    // right
    if (i + 3 < s.size()) {
        if (s[i + 1][j] == 'M' && s[i + 2][j] == 'A' && s[i + 3][j] == 'S') {
            cnt++;
        }
    }
    // up
    if (j - 3 >= 0) {
        if (s[i][j - 1] == 'M' && s[i][j - 2] == 'A' && s[i][j - 3] == 'S') {
            cnt++;
        }
    }
    // down
    if (j + 3 < s[i].size()) {
        if (s[i][j + 1] == 'M' && s[i][j + 2] == 'A' && s[i][j + 3] == 'S') {
            cnt++;
        }
    }
    // left-up
    if (i - 3 >= 0 && j - 3 >= 0) {
        if (s[i - 1][j - 1] == 'M' && s[i - 2][j - 2] == 'A' && s[i - 3][j - 3] == 'S') {
            cnt++;
        }
    }
    // right-up
    if (i + 3 < s.size() && j - 3 >= 0) {
        if (s[i + 1][j - 1] == 'M' && s[i + 2][j - 2] == 'A' && s[i + 3][j - 3] == 'S') {
            cnt++;
        }
    }
    // left-down
    if (i - 3 >= 0 && j + 3 < s[i].size()) {
        if (s[i - 1][j + 1] == 'M' && s[i - 2][j + 2] == 'A' && s[i - 3][j + 3] == 'S') {
            cnt++;
        }
    }
    // right-down
    if (i + 3 < s.size() && j + 3 < s[i].size()) {
        if (s[i + 1][j + 1] == 'M' && s[i + 2][j + 2] == 'A' && s[i + 3][j + 3] == 'S') {
            cnt++;
        }
    }
}

void solve() {
    string str;
    vector<string> s;
    while (getline(cin, str)) {
        s.push_back(str);
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] == 'X') {
                check(i, j, s);
            }
        }
    }
    cout << cnt;
}

void check2(int i, int j, vector<string> &s) {
    if (i - 1 >= 0 && j - 1 >= 0 && i + 1 < s.size() && j + 1 < s[i].size()) {
        if (s[i - 1][j - 1] == 'M' && s[i - 1][j + 1] == 'M' && s[i + 1][j - 1] == 'S' && s[i + 1][j + 1] == 'S') {
            cnt++;
        }
        else if (s[i - 1][j - 1] == 'S' && s[i - 1][j + 1] == 'S' && s[i + 1][j - 1] == 'M' && s[i + 1][j + 1] == 'M') {
            cnt++;
        }
        else if (s[i - 1][j - 1] == 'M' && s[i - 1][j + 1] == 'S' && s[i + 1][j - 1] == 'M' && s[i + 1][j + 1] == 'S') {
            cnt++;
        }
        else if (s[i - 1][j - 1] == 'S' && s[i - 1][j + 1] == 'M' && s[i + 1][j - 1] == 'S' && s[i + 1][j + 1] == 'M') {
            cnt++;
        }
    }
}

void solve2() {
    string str;
    vector<string> s;
    while (getline(cin, str)) {
        s.push_back(str);
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] == 'A') {
                check2(i, j, s);
                // cout << 1;
            }
        }
    }
    cout << cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("D4.inp", "r", stdin);
    // cin >> t;
    while (t--) {
        // solve();
        solve2();
    }

    return 0;
}
