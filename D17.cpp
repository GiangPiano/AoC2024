#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

int A, B, C;

void adv(int x) {
    while (x--) A >>= 1;
}

void bxl(int x) {
    B = B ^ x;
}

void bst(int x) {
    B = x % 8;
}

void bxc(int x) {
    B = B ^ C;
}

void out(int x, vector<int> &res) {
    cout << x % 8 << ',';
    res.push_back(x % 8);
}

void bdv(int x) {
    int Atmp = A;
    while (x--) Atmp >>= 1;
    B = Atmp;
}

void cdv(int x) {
    int Atmp = A;
    while (x--) Atmp >>= 1;
    C = Atmp;
}

int combo(int x) {
    if (0 <= x && x <= 3) return x;
    if (x == 4) return A;
    if (x == 5) return B;
    if (x == 6) return C;
    return x;
}

void solve() {
    scanf("Register A: %lld\n", &A);
    scanf("Register B: %lld\n", &B);
    scanf("Register C: %lld\n", &C);

    int oriA = A;
    int oriB = B;
    int oriC = C;

    vector<int> instructions;
    string s;
    getline(cin, s);
    s = s.substr(9, s.size() - 9);

    stringstream ss(s);
    while (getline(ss, s, ',')) {
        instructions.push_back(stoi(s));
    }
    for (int i = 0; i < instructions.size(); i++) cout << instructions[i] << ' ';
    cout << '\n';
    vector<int> res;

    for (int i = 0; i < instructions.size(); i++) {
        if (instructions[i] == 0) {
            adv(combo(instructions[i + 1]));
        } else if (instructions[i] == 1) {
            bxl(instructions[i + 1]);
        } else if (instructions[i] == 2) {
            bst(combo(instructions[i + 1]));
        } else if (instructions[i] == 3) {
            if (A != 0) {
                i = instructions[i + 1] - 2;
            }
        } else if (instructions[i] == 4) {
            bxc(instructions[i + 1]);
        } else if (instructions[i] == 5) {
            out(combo(instructions[i + 1]), res);
        } else if (instructions[i] == 6) {
            bdv(combo(instructions[i + 1]));
        } else if (instructions[i] == 7) {
            cdv(combo(instructions[i + 1]));
        }
        i++;
    }
}

int check(vector<int> instructions, int ans) {
    // if (ans == 0) return -1;
    if (instructions.size() == 0) return ans;
    for (int i = 0; i < instructions.size(); i++) cout << instructions[i] << ' ';
    cout << '\n';
    for (int i = 0; i < 8; i++) {
        A = ans << 3LL | i;
        cout << A << '\n';
        B = A % 8;
        B = B ^ 7;
        C = A >> B;
        B = B ^ C;
        B = B ^ 7;
        if (B % 8 == instructions[instructions.size() - 1]) {
            vector<int> tmp = instructions;
            tmp.pop_back();
            int res = check(tmp, A);
            if (res != -1) return res;
        }
    }
    return -1;
}

void solve2() {
    scanf("Register A: %lld\n", &A);
    scanf("Register B: %lld\n", &B);
    scanf("Register C: %lld\n", &C);

    vector<int> instructions;
    string s; getline(cin, s); cout << s << '\n';
    s = s.substr(9, s.size() - 9);
    stringstream ss(s);
    while (getline(ss, s, ',')) {
        instructions.push_back(stoi(s));
    }

    // while (A != 0) {
    //     B = A % 8;
    //     B = B ^ 7;
    //     C = A >> B;
    //     A = A >> 3;
    //     B = B ^ C;
    //     B = B ^ 7;
    //     cout << B % 8 << ',';
    // }
    // cout << '\n';

    A = 0;
    B = 0;
    C = 0;

    cout << check(instructions, 0) << '\n';
}

/*
2,4: B = A % 8
1,7: B = B ^ 7
7,5: C = C >> B
0,3: A = A >> 3
4,0: B = B ^ C
1,7: B = B ^ 7
5,5: output B
3,0: jump to 0 if A != 0
*/

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    freopen("D17.inp", "r", stdin);
    while (t--) {
        // solve();
        solve2();
    }

    return 0;
}
