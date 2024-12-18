#include<bits/stdc++.h>
using namespace std;

vector<string> grid;
int cnt = 0;

void dfs(int i, int j, char c, vector<vector<bool>>& visited) {
    cout << i << ' ' << j << endl;
    if (visited[i][j]) return;
    if (grid[i][j] != char(c + 1)) return;
    if (grid[i][j] == '9') {
        // visited[i][j] = true;
        cout << "end at " << i << " " << j << endl;
        cnt++;
        return;
    }
    if (i < grid.size() - 1) dfs(i + 1, j, grid[i][j], visited);
    if (i > 0) dfs(i - 1, j, grid[i][j], visited);
    if (j < grid[0].size()) dfs(i, j + 1, grid[i][j], visited);
    if (j > 0) dfs(i, j - 1, grid[i][j], visited);
}

void solve() {
    string s;
    while (getline(cin, s)) {
        grid.push_back(s);
    }
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
        cout << grid[i] << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0') {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                cout << "start at " << i << " " << j << endl;
                dfs(i, j, char('0' - 1), visited);
            }
        }
    }
    cout << cnt;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D10.inp", "r", stdin);
    while (t--) {
        solve();
    }

    return 0;
}
