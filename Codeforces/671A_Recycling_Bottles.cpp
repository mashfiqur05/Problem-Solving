///   ***   ---   |||   In the name of ALLAH   |||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    int n;
    cin >> n;

    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<double> da(n), db(n);
    double base = 0.0;

    for (int i = 0; i < n; i++) {
        double d = hypot(x[i] - tx, y[i] - ty);
        base += 2.0 * d;
    }

    for (int i = 0; i < n; i++) {
        da[i] = hypot(x[i] - ax, y[i] - ay)
              - hypot(x[i] - tx, y[i] - ty);

        db[i] = hypot(x[i] - bx, y[i] - by)
              - hypot(x[i] - tx, y[i] - ty);
    }

    int besta = 0, bestb = 0;
    for (int i = 0; i < n; i++) {
        if (da[i] < da[besta]) besta = i;
        if (db[i] < db[bestb]) bestb = i;
    }

    double best = min(da[besta], db[bestb]);

    for (int i = 0; i < n; i++) {
        if (i != besta) {
            best = min(best, da[besta] + db[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != bestb) {
            best = min(best, da[i] + db[bestb]);
        }
    }

    cout << fixed << setprecision(10) << base + best << '\n';
    return 0;
}
