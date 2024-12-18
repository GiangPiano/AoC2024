#include<bits/stdc++.h>
using namespace std;

vector<string> grid;
int width, height;
int direction = 4;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int distS[1000][1000][4];
int distE1[1000][1000][4];
int distE2[1000][1000][4];
bool visited[1000][1000][4];

struct Node {
    int x, y, dir, distS;
    Node(int x, int y, int dir, int distS) : x(x), y(y), dir(dir), distS(distS) {}
    bool operator >(const Node &other) const {
        return distS > other.distS;
    }
};

map<tuple<int, int, int>, tuple<int, int,int>> traceS;
map<tuple<int, int, int>, tuple<int, int,int>> traceE1;
map<tuple<int, int, int>, tuple<int, int,int>> traceE2;

void dijkstra(int startX, int startY, int direction, map<tuple<int, int, int>, tuple<int, int,int>>& trace, int (&dist)[1000][1000][4]) {
    memset(visited, false, sizeof(visited));
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[startX][startY][direction] = 0;
    pq.push({startX, startY, direction, dist[startX][startY][direction]});
    // int dir = 0;

    while (!pq.empty()) {   
        Node u = pq.top();
        visited[u.x][u.y][u.dir] = true;
        // cout << u.x << ' ' << u.y << ' ' << u.dir << ' ' << u.distS << '\n';
        pq.pop();
        if (grid[u.x + dx[u.dir]][u.y + dy[u.dir]] != '#' && !visited[u.x + dx[u.dir]][u.y + dy[u.dir]][u.dir]) {
            if (dist[u.x + dx[u.dir]][u.y + dy[u.dir]][u.dir] > dist[u.x][u.y][u.dir] + 1) {
                dist[u.x + dx[u.dir]][u.y + dy[u.dir]][u.dir] = dist[u.x][u.y][u.dir] + 1;
                pq.push({u.x + dx[u.dir], u.y + dy[u.dir], u.dir, dist[u.x + dx[u.dir]][u.y + dy[u.dir]][u.dir]});
                trace[{u.x + dx[u.dir], u.y + dy[u.dir], u.dir}] = {u.x, u.y, u.dir};
            }
        }
        for (int i = 0; i < 4; i++) {
            if (i != u.dir && i != (u.dir + 2) % 4) {
                if (grid[u.x + dx[i]][u.y + dy[i]] != '#' && !visited[u.x + dx[i]][u.y + dy[i]][i]) {
                    dist[u.x][u.y][i] = dist[u.x][u.y][u.dir] + 1000;
                    pq.push({u.x, u.y, i, dist[u.x][u.y][i]});
                    trace[{u.x, u.y, i}] = {u.x, u.y, u.dir};
                }
            }
        }
    }
}

void solve() {
    string s;
    while (getline(cin, s)) {
        grid.push_back(s);
    }

    width = grid[0].size();
    height = grid.size();

    int startX, startY, endX, endY;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            if (grid[i][j] == 'E') {
                endX = i;
                endY = j;
            }
        }
    }

    memset(distS, 0x3f, sizeof(distS));
    memset(distE1, 0x3f, sizeof(distE1));
    memset(distE2, 0x3f, sizeof(distE2));

    dijkstra(startX, startY, 0, traceS, distS);
    dijkstra(endX, endY, 3, traceE1, distE1);
    dijkstra(endX, endY, 2, traceE2, distE2);

    
    int best = min({distS[endX][endY][0], distS[endX][endY][1], distS[endX][endY][2], distS[endX][endY][3]});
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] != '#') {
                for (int dir = 0; dir < 4; dir++) {
                     if (distS[i][j][dir] + distE1[i][j][(dir + 2) % 4] == best) {
                        tuple<int, int, int> u = {i, j, dir};
                        u = traceS[u];
                        while ((get<0>(u) != startX || get<1>(u) != startY) && get<0>(u) != 0 && get<1>(u) != 0) {
                            grid[get<0>(u)][get<1>(u)] = 'O';
                            u = traceS[u];
                        }
                        u = {i, j, (dir + 2) % 4};
                        u = traceE1[u];
                        while ((get<0>(u) != endX || get<1>(u) != endY) && get<0>(u) != 0 && get<1>(u) != 0) {
                            grid[get<0>(u)][get<1>(u)] = 'O';
                            u = traceE1[u];
                        }
                    }
                    if (distS[i][j][dir] + distE2[i][j][(dir + 2) % 4] == best) {
                        tuple<int, int, int> u = {i, j, dir};
                        u = traceS[u];
                        while ((get<0>(u) != startX || get<1>(u) != startY) && get<0>(u) != 0 && get<1>(u) != 0) {
                            grid[get<0>(u)][get<1>(u)] = 'O';
                            u = traceS[u];
                        }
                        u = {i, j, (dir + 2) % 4};
                        u = traceE2[u];
                        while ((get<0>(u) != endX || get<1>(u) != endY) && get<0>(u) != 0 && get<1>(u) != 0) {
                            grid[get<0>(u)][get<1>(u)] = 'O';
                            u = traceE2[u];
                        }
                    }
                }
            }
        }
    }    
    int cnt = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] != '#' && grid[i][j] != '.') cnt++;
        }
    }
    for (int i = 0; i < height; i++) {
        cout << grid[i] << '\n';
    }
    cout << cnt << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D16.inp", "r", stdin);
    freopen("D16.out", "w", stdout);
    while (t--) {
        solve();
    }

    return 0;
}