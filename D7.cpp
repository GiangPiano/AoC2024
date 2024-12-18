#include<bits/stdc++.h>
#define int long long
using namespace std;

long long sum = 0;
vector<long long> tenth = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
bool test(int a, map<int, vector<int>> &list, int id) {
    if (id == list[a].size()) return sum == a;

    int oldsum = sum;

    sum += list[a][id];
    if (test(a, list, id + 1)) return true;
    sum = oldsum;
    
    if (list[a][id] != 0) {
        sum *= list[a][id];
        if (test(a, list, id + 1)) return true;
        sum = oldsum;
    }

    sum = sum * *upper_bound(tenth.begin(), tenth.end(), list[a][id]) + list[a][id];
    if (test(a, list, id + 1)) return true;
    sum = oldsum;
    
    return false;
}

void solve() {
    string s; 
    int res = 0;
    while (getline(cin, s)) {
        if (s == "end") break;
        stringstream ss(s);
        string a1;
        ss >> a1;
        long long a = stoll(a1.substr(0, a1.size() - 1));
        map<int, vector<int>> list;
        string b1;
        while (ss >> b1) {
            int b = stoi(b1);
            list[a].push_back(b);
        }
        sum = list[a][0];
        res += a * test(a, list, 1);
        cout << '\n';

        cout << a << ": ";
        for (auto i: list[a]) {
            cout << i << ", ";
        }
        cout << endl;
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("D7.inp", "r", stdin);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
