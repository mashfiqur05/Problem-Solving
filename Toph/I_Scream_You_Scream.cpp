///   ***   ---   |||     In the name of ALLAH     |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio();

    int T;
    cin >> T;

    const double PI = 3.141592653589;

    while(T--) {
        double R;
        cin >> R;

        double ans = (4.0 / 3.0) * PI * R * R * R;

        cout << fixed << setprecision(10) << ans << '\n';
    }

    return 0;
}