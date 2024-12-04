#include<bits/stdc++.h>
using namespace std;


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("D1.inp", "r", stdin);
    int t = 1;
    // cin >> t;
    vector<int> a;
    map<int, int> cnt;
    int x, y;
    while (cin >> x >> y) {
        a.push_back(x);
        cnt[y]++;
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        // cout << cnt[y];
        ans += a[i] * cnt[a[i]];
    }
    cout << ans;

    return 0;
}
