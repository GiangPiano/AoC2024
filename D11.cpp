#include<bits/stdc++.h>
#define int long long
using namespace std;

int res = 0;
map<pair<int, int>, int> dp;

int process(int n, int t) {
    int res = 0;
    string s = to_string(n);
    if (dp.find({n, t}) != dp.end()) {
        return dp[{n, t}];
    }
    if (t == 0) res = 1;
    else if (n == 0) res = process(1, t - 1);
    else if (s.size() % 2 != 0) res = process(n * 2024, t - 1);
    else if (s.size() % 2 == 0) {
        string s = to_string(n);
        cout << s << ' ';
        int left = stoi(s.substr(0, s.size() / 2));
        int right = stoi(s.substr(s.size()/2, s.size() / 2));
        cout << left << ' ' << right << endl;
        res = process(left, t - 1) + process(right, t - 1);
    }
    dp[{n, t}] = res;
    return res;
}

void solve() {
    string s; 
    getline(cin, s);
    stringstream ss(s);
    vector<int> a;
    while (ss >> s) {
        // cout << s << ' ';
        a.push_back(stoi(s));
    }
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += process(a[i], 75);
    }
    cout << sum << endl;
} 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D11.inp", "r", stdin);
    while (t--) {
        solve();
    }

    return 0;
}