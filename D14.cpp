#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    vector<pair<int, int>> p;
    vector<pair<int, int>> v;
    
    pair<int, int> P;
    pair<int, int> V;
    while (scanf("p=%d,%d v=%d,%d\n", &P.first, &P.second, &V.first, &V.second) != -1) {
        p.push_back(P);
        v.push_back(V);
    }
    int cnt[4] = {0, 0, 0, 0};
    const int width = 101;
    const int height = 103;
    for (int j = 0; j < 10000; ++j) {
        int grid[height][width] = {};
        cout << j << '\n';
        for (int i = 0; i < p.size(); ++i) {
            p[i].first = (p[i].first + v[i].first % width + width) % width;
            p[i].second = (p[i].second + v[i].second % height + height) % height;
            grid[p[i].second][p[i].first]++;
        }
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] > 0) {
                    cout << "#";
                } else {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
    // int res = 1;
    // for (int i = 0; i < 4; ++i) {
    //     res *= cnt[i];
    //     cout << cnt[i] << " ";
    // }
    // cout << '\n' << res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D14.inp", "r", stdin);
    freopen("D14.out", "w", stdout);
    while (t--) {
        solve();
    }

    return 0;
}

