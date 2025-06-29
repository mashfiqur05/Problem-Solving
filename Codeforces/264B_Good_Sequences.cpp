#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long

const int MX = 2e5+123;

vector<int> primeDivisors(int n) {
    vector<int> ret;
    if (n % 2 == 0) ret.push_back(2);
    while (n % 2 == 0) n /= 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) ret.push_back(i);
        while (n % i == 0) n /= i;
    }
    if (n > 2) ret.push_back(n);
    return ret;
}

void testCases(int tt) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> div[MX];

    for (int i = 0; i < n; i++) {
        div[i] = primeDivisors(v[i]);
    }

    vector<int> dp(MX, 0);

    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (auto u : div[i]) mx = max(mx, dp[u]);
        for (auto u : div[i]) dp[u] = mx + 1;
    }

    int ans = *max_element(dp.begin(), dp.end());
    cout << max (1LL, ans) << endl;
}

int32_t main() {
    fastio();
    int testcases = 1;
    for (int tt = 1; tt <= testcases; tt++) {
        testCases(tt);
    }
    return 0;
}
