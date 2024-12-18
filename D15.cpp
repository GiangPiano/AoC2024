#include<bits/stdc++.h>
#include <windows.h>

using namespace std;
#define int long long

vector<string> oldgrid;
vector<string> grid;
int X, Y;
int width, height;

void up(int x, int y) {
    queue<pair<int, int>> q;
    if (grid[x - 1][y] == '.') {
        grid[x - 1][y] = '@';
        grid[x][y] = '.';
        X = x - 1;
        return;
    }
    q.push({x, y});
    vector<pair<int, int>> obstacles;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int tmpx = p.first, tmpy = p.second;
        if (grid[tmpx - 1][tmpy] == '[') {
            obstacles.push_back({tmpx - 1, tmpy});
            q.push({tmpx - 1, tmpy});
        }
        if (grid[tmpx - 1][tmpy - 1] == '[') {
            obstacles.push_back({tmpx - 1, tmpy - 1});
            q.push({tmpx - 1, tmpy - 1});
        }
        if (grid[tmpx - 1][tmpy + 1] == '[' && grid[tmpx][tmpy] != '@') {
            obstacles.push_back({tmpx - 1, tmpy + 1});
            q.push({tmpx - 1, tmpy + 1});
        }
        if (grid[tmpx - 1][tmpy] == '#' || (grid[tmpx - 1][tmpy + 1] == '#' && grid[tmpx][tmpy] != '@')) return;
    }
    for (pair<int, int> p : obstacles) {
        grid[p.first][p.second] = '.';
        grid[p.first][p.second + 1] = '.';
    }
    for (pair<int, int> p : obstacles) {
        grid[p.first - 1][p.second] = '[';
        grid[p.first - 1][p.second + 1] = ']';
    }
    grid[x][y] = '.';
    grid[x - 1][y] = '@';
    X = x - 1;
    obstacles.clear();
}

void down(int x, int y) {
    queue<pair<int, int>> q;
    if (grid[x + 1][y] == '.') {
        grid[x + 1][y] = '@';
        grid[x][y] = '.';
        X = x + 1;
        return;
    }
    q.push({x, y});
    vector<pair<int, int>> obstacles;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int tmpx = p.first, tmpy = p.second;
        if (grid[tmpx + 1][tmpy] == '[') {
            obstacles.push_back({tmpx + 1, tmpy});
            q.push({tmpx + 1, tmpy});
        }
        if (grid[tmpx + 1][tmpy - 1] == '[') {
            obstacles.push_back({tmpx + 1, tmpy - 1});
            q.push({tmpx + 1, tmpy - 1});
        }
        if (grid[tmpx + 1][tmpy + 1] == '[' && grid[tmpx][tmpy] != '@') {
            obstacles.push_back({tmpx + 1, tmpy + 1});
            q.push({tmpx + 1, tmpy + 1});
        }
        if (grid[tmpx + 1][tmpy] == '#' || (grid[tmpx + 1][tmpy + 1] == '#' && grid[tmpx][tmpy] != '@')) return;
    }
    for (pair<int, int> p : obstacles) {
        grid[p.first][p.second] = '.';
        grid[p.first][p.second + 1] = '.';
    }
    for (pair<int, int> p : obstacles) {
        grid[p.first + 1][p.second] = '[';
        grid[p.first + 1][p.second + 1] = ']';
    }
    grid[x][y] = '.';
    grid[x + 1][y] = '@';
    X = x + 1;
    obstacles.clear();
}

void left(int x, int y) {
    int tmpx = x, tmpy = y;
    vector<pair<int, int>> obstacles;
    while (grid[tmpx][tmpy] != '.') {
        tmpy--;
        if (grid[tmpx][tmpy] == '[') {
            obstacles.push_back({tmpx, tmpy});
        }
        if (grid[tmpx][tmpy] == '#') return;
    }
    for (pair<int, int> p : obstacles) {
        grid[p.first][p.second - 1] = '[';
        grid[p.first][p.second] = ']';
    }
    grid[x][y] = '.';
    grid[x][y - 1] = '@';
    Y = y - 1;
    obstacles.clear();
}

void right(int x, int y) {
    int tmpx = x, tmpy = y;
    vector<pair<int, int>> obstacles;
    while (grid[tmpx][tmpy] != '.') {
        tmpy++;
        if (grid[tmpx][tmpy] == '[') {
            obstacles.push_back({tmpx, tmpy});
        }
        if (grid[tmpx][tmpy] == '#') return;
    }
    for (pair<int, int> p : obstacles) {
        grid[p.first][p.second + 1] = '[';
        grid[p.first][p.second + 2] = ']';
    }
    grid[x][y] = '.';
    grid[x][y + 1] = '@';
    Y = y + 1;
    obstacles.clear();
}

void solve() {
    string s;
    while (getline(cin, s) && s != "") {
        oldgrid.push_back(s);
    }
    for (int i = 0; i < oldgrid.size(); i++) {
        grid.push_back(string(3 * oldgrid[0].size(), ' '));
    }
    width = oldgrid[0].size();
    height = oldgrid.size();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (oldgrid[i][j] == '#') {
                grid[i][2 * j] = '#';
                grid[i][2 * j + 1] = '#';
            }
            else if (oldgrid[i][j] == '@') {
                X = i;
                Y = 2 * j;
                grid[X][Y] = '@';
                grid[X][Y + 1] = '.';
            }
            else if (oldgrid[i][j] == 'O') {
                grid[i][2 * j] = '[';
                grid[i][2 * j + 1] = ']';
            }
            else {
                grid[i][2 * j] = '.';
                grid[i][2 * j + 1] = '.';
            }
        }
    }
    width = 2 * width;
    int cnt = 0;
    while (getline(cin, s)) {
        if (s == "") break;
        for (char c : s) {
            if (c == '^') {
                up(X, Y);
            } else if (c == 'v') {
                down(X, Y);
            } else if (c == '<') {
                left(X, Y);
            } else if (c == '>') {
                right(X, Y);
            }
            // cout << cnt++ << '\n';
            //     cout << c << '\n';
            // for (int i = 0; i < height; i++) {
            //     for (int j = 0; j < width; j++) {
            //         cout << grid[i][j];
            //     }
            //     cout << '\n';
            // }
            // Sleep(1000);
            // system("CLS");
        }
    }
    int res = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // cout << grid[i][j];
            if (grid[i][j] == '[') {
                res += 100 * i + j;
            }
        }
        // cout << '\n';
    }
    cout << res << '\n';
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D15.inp", "r", stdin);
    freopen("D15.out", "w", stdout);
    while (t--) {
        solve();
    }

    return 0;
}
