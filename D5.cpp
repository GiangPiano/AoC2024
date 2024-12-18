#include<bits/stdc++.h>
using namespace std;

vector<int> lists[105];

bool cmp(int &a, int &b) {
    return find(lists[a].begin(), lists[a].end(), b) != lists[a].end();
}

void solve() {
    string s;
    while (std::getline(std::cin, s) && !s.empty()) {
        // cout << s << endl;
        int a = 0, b = 0, i;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == '|') break;
            a = a * 10 + s[i] - '0';
        }
        for (i++; i < s.length(); i++) {
            b = b * 10 + s[i] - '0';
        }
        lists[a].push_back(b);
    }

    // for (int i = 0; i < 105; i++) {
    //     if (list[i].size() == 0) continue;
    //     cout << i << ": ";
    //     for (int j = 0; j < list[i].size(); j++) {
    //         cout << list[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    string line;
    int res = 0;
    while (std::getline(std::cin, line) && !line.empty()) {
        vector<int> a;
        bool flag = false;
        while (line.find(',') != string::npos) {
            a.push_back(stoi(line.substr(0, line.find(','))));
            line = line.substr(line.find(',') + 1);
        }
        a.push_back(stoi(line));
        // for (int i = 0; i < a.size(); i++) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        map<int, int> id;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < lists[a[i]].size(); j++) {
                if (id.find(lists[a[i]][j]) != id.end()) {
                    flag = true;
                    break;
                }
            }
            id[a[i]] = i;
        }
        if (flag) {
            sort(a.begin(), a.end(), cmp);
            // cout << a[a.size() / 2] << endl;
            res += a[a.size() / 2];
        }
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D5.inp", "r", stdin);
    while (t--) {
        time_t start = clock();

        solve();
        time_t end = clock();
        cerr << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    }

    return 0;
}
