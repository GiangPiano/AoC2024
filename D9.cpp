#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    getline(cin, s);
    map<int, int> cnt;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        cnt[i] = s[i] - '0';
    }

    vector<int> a;
    int j = n - 1;
    if (j % 2 != 0) j--;
    for (int i = 0; i < n && i <= j; i++) {
        if (i % 2 == 0)
            while (cnt[i]--)
                a.push_back(i / 2);
        else
            while (cnt[i]--) {
                a.push_back(j / 2);
                cnt[j]--;
                if (cnt[j] <= 0) {
                    j -= 2;
                }
            }
    }
    long long res = 0;

    for (int i = 0; i < a.size(); i++) {
        if (i > 0 && a[i] == 0 && a[i - 1] > 0) break;
        // cout << a[i];
        res += a[i] * i;
    }
    cout << res << endl;
}


struct interval {
    int l, r, id;

    bool operator<(const interval& other) const {
        if (l != other.l)
            return l < other.l;
        if (r != other.r)
            return r < other.r;
        return id < other.id;
    }
};

struct num {
    int id, start, size;

    bool operator<(const num& other) const {
        if (start != other.start)
            return start < other.start;
        return size < other.size;
    }
};

void solve2() {
    string s;
    getline(cin, s);
    int n = s.size();
    int cur = 0;

    vector<interval> a;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            interval x = {cur, cur + s[i] - '0' - 1, i / 2};
            a.push_back(x);
        }
        cur += s[i] - '0';
    }
    set<interval> st;
    for (auto x : a) st.insert(x);
    for (auto x : st)
        cout << x.id << ": " << x.l << " " << x.r << endl;
    auto it = st.end();
    it--;
    // it--;
    while (it != st.begin()) {
        for (auto left = st.begin(); left != st.end(); left++) {
            auto right = left;
            right++;
            if (right == st.end() || right == it) break;
            if (right->l - left->r > it->r - it->l + 1) {
                interval x = {left->r + 1, left->r + 1 + it->r - it->l, it->id};
                st.insert(x);
                st.erase(it);
                break;
            }
        }
        it--;
    }
    long long res = 0;
    for (auto x : st) {
        cout << x.id << ": " << x.l << " " << x.r << endl;
        for (int i = x.l; i <= x.r; i++) {
            res += i * x.id;
        }
    }

    cout << res << endl;
}

void solve3() {
    string s;
    getline(cin, s);
    int n = s.size();
    int cur = 0;

    vector<num> a;
    map<int, int> gap;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            num x = {i / 2, cur, s[i] - '0'};
            a.push_back(x);
        }
        else {
            gap[cur] = s[i] - '0';
        }
        cur += s[i] - '0';
    }

    for (int i = a.size() - 1; i >= 0; i--) {
        for (auto x : gap) {
            if (x.first > a[i].start) break;
            if (x.second >= a[i].size) {
                a[i].start = x.first;
                gap.erase(x.first);
                gap[x.first + a[i].size] = x.second - a[i].size;
                break;
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = a[i].start; j < a[i].start + a[i].size; j++) {
            res += j * a[i].id;
        }
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D9.inp", "r", stdin);
    while (t--) {
        // solve();
        // solve2();
        solve3();
    }

    return 0;
}