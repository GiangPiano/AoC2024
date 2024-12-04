#include<bits/stdc++.h>
using namespace std;

bool isSafeReport(const vector<int>& report) {
    bool increasing = true, decreasing = true;
    for (size_t i = 1; i < report.size(); ++i) {
        int diff = abs(report[i] - report[i - 1]);
        if (diff < 1 || diff > 3) return false; // Difference not in range [1, 3]
        if (report[i] > report[i - 1]) decreasing = false;
        if (report[i] < report[i - 1]) increasing = false;
    }
    return increasing || decreasing;
}

// Main function to calculate safe reports considering the Problem Dampener
int countSafeReportsWithDampener(const vector<vector<int>>& reports) {
    int safeCount = 0;
    for (const auto& report : reports) {
        if (isSafeReport(report)) {
            ++safeCount; // Already safe
            continue;
        }
        // Check if removing one level makes it safe
        bool dampenedSafe = false;
        for (size_t i = 0; i < report.size(); ++i) {
            vector<int> modifiedReport = report;
            modifiedReport.erase(modifiedReport.begin() + i);
            if (isSafeReport(modifiedReport)) {
                dampenedSafe = true;
                break;
            }
        }
        if (dampenedSafe) ++safeCount;
    }
    return safeCount;
}

void solve() {
    string s;
    int cnt = 0;
    int j = 1;
    vector<vector<int>> a;
    while (getline(cin, s)) {
        
        // s.push_back(' ');
        vector<int> arr = {0};
        // cout << s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ' && s[i + 1] != ' '){
                arr.push_back(0);
            }
            else if (s[i] != ' ') {
                arr[arr.size() - 1] = arr[arr.size() - 1] * 10 + (s[i] - 48);
            }
        }
        a.push_back(arr);
    }
    cout << countSafeReportsWithDampener(a);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("D2.inp", "r", stdin);
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
