#include <bits/stdc++.h>
#define int long long
using namespace std;

struct coord {
    int x, y;
};

void solve() {
    coord a, b, c;
    int res = 0;

    while (scanf("Button A: X+%lld, Y+%lld\nButton B: X+%lld, Y+%lld\nPrize: X=%lld, Y=%lld\n",
                 &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) != -1) {
        int minValue = LLONG_MAX;
        c.x += 10000000000000;
        c.y += 10000000000000;

        // Check if the lines are parallel
        if (a.x * b.y != a.y * b.x) { // Lines are not parallel
            // Solve using determinants
            int det = a.x * b.y - a.y * b.x;
            int detX = c.x * b.y - c.y * b.x;
            int detY = a.x * c.y - a.y * c.x;

            // Check if det divides detX and detY
            if (det != 0 && detX % det == 0 && detY % det == 0) {
                int A = detX / det;
                int B = detY / det;

                if (A > 0 && B > 0) {
                    res += 3 * A + B;
                }
            } else { // Lines are parallel
                if (a.x * c.y == a.y * c.x && b.x * c.y == b.y * c.x) {
                    // Check all valid values of A
                    for (int A = 1;; ++A) {
                        if (a.x * A > c.x) break; // Stop when A exceeds the boundary

                        if ((c.x - a.x * A) % b.x == 0) {
                            int B = (c.x - a.x * A) / b.x;
                            if (B > 0) {
                                minValue = min(minValue, 3 * A + B);
                            }
                        }
                    }

                    if (minValue == LLONG_MAX) {
                        cout << "No solution\n";
                    } else {
                        res += minValue;
                    }
                }
            }
        }
    }
    cout << res << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Open input file
    freopen("D13.inp", "r", stdin);

    solve();

    return 0;
}
