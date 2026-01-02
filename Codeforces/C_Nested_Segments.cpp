///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int MX = 2e5;

int segm_tree[8*MX], arr[2*MX];

// Calculate the value of a node from its children
int calculate(int node) {
    return (segm_tree[2*node]+ segm_tree[2*node + 1]);
}

// Build the segment tree: node = current node in tree, [left, right] = segment


// Update position idx to value val
void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segm_tree[node] = val;
    } else {
        int mid = left + (right - left)/2;
        if (idx <= mid) update(2*node, left, mid, idx, val);
        else update(2*node + 1, mid + 1, right, idx, val);
        segm_tree[node] = calculate(node);
    }
}

// Query minimum in range [l, r]
int query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) return 0; // no overlap
    if (l <= left && right <= r) return segm_tree[node]; // full overlap
    int mid = left + (right - left)/2;
    return (
        query(2*node, left, mid, l, r)+
        query(2*node + 1, mid + 1, right, l, r)
    );
}

bool cmp (pair<int, pair<int, int>>&a, pair<int, pair<int, int>>&b)
{
    return a.second.second < b.second.second;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    // Read 1-indexed array
    for (int i = 1; i <= 2*n; i++) cin >> arr[i];
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= 2*n; i++)
    {
        if (mp[arr[i]].first == 0) mp[arr[i]].first = i;
        else mp[arr[i]].second = i;
    }

    // for (auto u : mp) cout << u.first << " " << u.second.first << " " << u.second.second << endl;
    vector<pair<int, pair<int, int>>> v;
    for (auto u : mp)
    {
        v.push_back({u.first, {u.second.first, u.second.second}});
    }

    sort (v.begin(), v.end(), cmp);
    vector<int>ans(n+1);
    for (auto u : v)
    {
        int l = u.second.first, r = u.second.second, ind = u.first;

        int cnt = query (1, 1, 2*n, l, r);
        update (1, 1, 2*n, l, 1);
        ans[ind] = cnt;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}