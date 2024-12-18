#include<bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> grid;
    string s;
    map<char, vector<pair<int, int>>> coords;
    while (cin >> s) {
        grid.push_back(string(s.size(), '.'));
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '.')
                coords[s[i]].push_back({grid.size() - 1, i});
    }
    int res = 0;
    for (auto &v : coords) {
        // cout << v.first << ' ' << v.second.size() << endl;
        for (int i = 0; i < v.second.size(); i++) {
            for (int j = i + 1; j < v.second.size(); j++) {
                // cout << v.first << ": " << v.second[i].first << " " << v.second[i].second << " " << v.second[j].first << " " << v.second[j].second << endl;
                pair<int, int> gap = {v.second[j].first - v.second[i].first, v.second[j].second - v.second[i].second};
                cout << gap.first << " " << gap.second << endl;
                pair<int, int> cur = v.second[j];
                while (cur.first - gap.first >= 0 && cur.first - gap.first < grid.size() && cur.second - gap.second >= 0 && cur.second - gap.second < grid[0].size()) {
                    cur.first -= gap.first;
                    cur.second -= gap.second;
                    if (grid[cur.first][cur.second] != '#') {
                        grid[cur.first][cur.second] = '#';
                        res++;
                    }
                }

                cur = v.second[i];
                while (cur.first + gap.first >= 0 && cur.first + gap.first < grid.size() && cur.second + gap.second >= 0 && cur.second + gap.second < grid[0].size()) {
                    cur.first += gap.first;
                    cur.second += gap.second;
                    if (grid[cur.first][cur.second] != '#') {
                        grid[cur.first][cur.second] = '#';
                        res++;
                    }
                }
            }
        }
    }
    cout << res << endl;

    for (auto &s : grid) {
        cout << s << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D8.inp", "r", stdin);
    while (t--) {
        solve();
    }

    return 0;
}
