#include<bits/stdc++.h>
using namespace std;

vector<string> v;
int startcol = 0, startrow = 0;
int cnt = 0;


void run(int x, int y) {
    pair<int, int> dir[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
    vector<vector<int>> direction(v.size(), vector<int>(v[0].size(), -1));
    int j = 0;
    pair<int, int> p = make_pair(startrow, startcol);
    map<pair<int, int>, int> timevisit;
    timevisit[p] = 1;
    for (int i = 0; i < 20000; i++) {
        if (direction[p.first][p.second] == j && timevisit[p] > 1) {
            cnt++;
            // cout << x << ' ' << y << endl;
            break;
        }
        if (v[p.first][p.second] != '#') {
            direction[p.first][p.second] = j;
            timevisit[p]++;
        }
        if (p.first + dir[j].first >= v.size() || p.first + dir[j].first < 0 || p.second + dir[j].second >= v[0].size() || p.second + dir[j].second < 0) {
            break;
        }
        while (v[p.first + dir[j].first][p.second + dir[j].second] == '#') {
            j = (j + 1) % 4;
        }
        p.first += dir[j].first;
        p.second += dir[j].second;
    }
}

void check() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (i == startrow && j == startcol || v[i][j] == '#')
                continue;
            v[i][j] = '#';
            run(i, j);
            v[i][j] = '.';
        }
    }
}

void solve() {
    string s;
    while (getline(cin, s)) {
        if (s.empty()) {
            break;
        }
        v.push_back(s);
    }


    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == '^') {
                startrow = i;
                startcol = j;
                v[i][j] = '.';
            }
        }
    }    
    check();

    cout << cnt << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("D6.inp", "r", stdin);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}