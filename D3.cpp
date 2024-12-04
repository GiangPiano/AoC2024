#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s; getline(cin, s);
    cout << s << endl;
    regex pattern("mul\\((\\d+)\\,(\\d+)\\)");
    smatch match;

    long long ans = 0;
    while (regex_search(s, match, pattern)) {
        // cout << match[1] << " " << match[2] << endl;
        ans += stoll(match[1]) * stoll(match[2]);
        // cout << match[1] << endl;
        s = match.suffix().str();
    }
    cout << ans;
}

void solve2() {
    string s; getline(cin, s);
    // cout << s << endl;
    regex pattern("mul\\((\\d+)\\,(\\d+)\\)|do\\(\\)|don't\\(\\)");
    regex mul("mul\\((\\d+)\\,(\\d+)\\)");
    smatch match;

    regex_iterator<string::iterator> rit(s.begin(), s.end(), pattern);
    regex_iterator<string::iterator> rend;
    long long ans = 0;
    bool enable = true;
    for (auto it = rit; it != rend; ++it) {
        if ((*it).str() == "do()") {
            enable = true;
            continue;
        } else if ((*it).str() == "don't()") {
            enable = false;
            continue;
        } else if (enable == true) {
            auto match = (*it).str();
            smatch num;
            regex_search(match, num, mul);
            cout << match << ' ' << num[1] << " " << num[2] << endl;
            ans += stoll(num[1]) * stoll(num[2]);
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D3.inp", "r", stdin);
    // freopen("D3.out", "w", stdout);
    while (t--) {
        solve2();
    }

    return 0;
}