///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int MX = 2e5;

int segm_tree[4*MX], arr[MX];

// Calculate the value of a node from its children
int calculate(int node) {
    return (segm_tree[2*node] + segm_tree[2*node + 1]);
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
void update(int node, int left, int right, int idx) {
    if (left == right) {
        arr[idx] = 0;
        segm_tree[node] = arr[idx];
    } else {
        int mid = left + (right - left)/2;
        if (idx <= mid) update(2*node, left, mid, idx);
        else update(2*node + 1, mid + 1, right, idx);
        segm_tree[node] = calculate(node);
    }
}
 
// Query minimum in range [l, r]
int query(int node, int left, int right, int k) {
    int mid = left + (right - left)/2;
    if (left == right) return left;
    else if (segm_tree[2*node] < k) return query (2*node+1, mid+1, right, k-segm_tree[2*node]);
    else return query (2*node, left, mid, k);
}
 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> v(n+1), ind(n+1);


    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> ind[i];
    for (int i = 1; i <= n; i++) arr[i] = 1;

    build (1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        int actualInd = query (1, 1, n, ind[i]);
        cout << v[actualInd] << " ";
        update (1, 1, n, actualInd);
    }
}