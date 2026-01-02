///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int MX = 2e5;

int segm_tree[4*MX], arr[MX];

// Calculate the value of a node from its children
int calculate(int node) {
    return (segm_tree[2*node]+segm_tree[2*node + 1]);
}

// Build the segment tree: node = current node in tree, [left, right] = segment
void build(int node, int left, int right) {
    if (left == right) {
        segm_tree[node] = arr[left]; // leaf node
    } else {
        int mid = left + (right - left)/2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);
        segm_tree[node] = calculate(node);
    }
}

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

int query(int node, int left, int right, int k) {
    int mid = left + (right - left)/2;
    if (left == right) return left;
    else if (segm_tree[2*node+1] >= k) return query (2*node+1, mid+1, right, k);
    else return query (2*node, left, mid, k-segm_tree[2*node+1]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    // Read 1-indexed array
    for (int i = 1; i <= n; i++) arr[i] = 1;

    build(1, 1, n); // root at 1, array 1-indexed
    vector<int> v(n+1), ans(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    // for (int i = 1; i <= n; i++) cout << v[i] << " "; cout << endl;

    // for (int i = 1; i <= 10; i++) cout << i << " " << segm_tree[i] << endl;
    // cout << query (1, 1, n, 1) << endl;

    for (int i = n; i >= 0; i--)
    {
        int ind = query (1, 1, n, v[i]+1);
        update (1, 1, n, ind, 0);
        ans[i] = ind;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";cout << endl;
}