///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

const int MX = 2e5+123;

vector<int> g[MX];
int n, k, depthArr[MX], subtree[MX];
bool vis[MX];

/// DFS to calculate depth and subtree size
void dfs(int u, int parent) {
    subtree[u] = 1;
    for (auto v : g[u]) {
        if (v == parent) continue;
        depthArr[v] = depthArr[u] + 1;
        dfs(v, u);
        subtree[u] += subtree[v];
    }
}

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // root is 1 (capital)
    depthArr[1] = 0;
    dfs(1, -1);

    // compute "gain" for each node
    vector<int> gain;
    for (int i = 1; i <= n; i++) {
        int val = depthArr[i] - (subtree[i] - 1);
        gain.push_back(val);
    }

    // sort in descending order
    sort(gain.rbegin(), gain.rend());

    // pick top k gains
    long long ans = 0;
    for (int i = 0; i < k; i++) ans += gain[i];

    cout << ans << endl;
}

int32_t main() {
    fastio();

    int testcases = 1;
    //cin >> testcases;
    while (testcases--) {
        solve();
    }
    return 0;
}
