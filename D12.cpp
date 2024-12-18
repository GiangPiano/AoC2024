#include<bits/stdc++.h>
using namespace std;

vector<string> grid;

map<char, int> area;
map<char, int> side;
bool visited[500][500];
vector<vector<bool>> island(500, vector<bool>(500, 0));

void propagate(int i, int j) {
    if (visited[i][j]) return;
    visited[i][j] = 1;
    island[i][j] = 1;
    area[grid[i][j]]++;

    if (i > 0 && grid[i][j] == grid[i - 1][j]) propagate(i - 1, j);
    if (i < grid.size() - 1 && grid[i][j] == grid[i + 1][j]) propagate(i + 1, j);
    if (j > 0 && grid[i][j] == grid[i][j - 1])propagate(i, j - 1);
    if (j < grid[0].size() - 1 && grid[i][j] == grid[i][j + 1]) propagate(i, j + 1);
}

void solve() {
    string s;
    int sum = 0;
    grid.push_back(string(200, ' '));
    while (getline(cin, s)) {
        s = " " + s + " ";
        grid.push_back(s);
    }
    grid.push_back(string(200, ' '));
    for (string s : grid) {
        cout << s << endl;
    }

    
    for (int i = 1; i < grid.size() - 1; i++) {
        for (int j = 1; j < grid[1].size() - 1; j++) {
            if (!visited[i][j]) {
                island = vector<vector<bool>>(500, vector<bool>(500, 0));
                propagate(i, j);
                for (int k = 1; k < grid.size() - 1; k++) {
                    for (int l = 1; l < grid[1].size() - 1; l++) {
                        if (island[k][l] && !island[k - 1][l]) side[grid[i][j]]++;
                        while (island[k][l] && !island[k - 1][l]) l++;
                    }
                }
                for (int k = 1; k < grid.size() - 1; k++) {
                    for (int l = 1; l < grid[1].size() - 1; l++) {
                        if (island[k][l] && !island[k + 1][l]) side[grid[i][j]]++;
                        while (island[k][l] && !island[k + 1][l]) l++;
                    }
                }
                for (int l = 1; l < grid[1].size() - 1; l++) {
                    for (int k = 1; k < grid.size() - 1; k++) {
                        if (island[k][l] && !island[k][l + 1]) side[grid[i][j]]++;
                        while (island[k][l] && !island[k][l + 1]) k++;
                    }
                }
                for (int l = 1; l < grid[1].size() - 1; l++) {
                    for (int k = 1; k < grid.size() - 1; k++) {
                        if (island[k][l] && !island[k][l - 1]) side[grid[i][j]]++;
                        while (island[k][l] && !island[k][l - 1]) k++;
                    }
                }
                sum += area[grid[i][j]] * side[grid[i][j]];
                area[grid[i][j]] = 0;
                side[grid[i][j]] = 0;
            }
        }
    }
    cout << sum << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D12.inp", "r", stdin);
    while (t--) {
        solve();
    }

    return 0;
}

