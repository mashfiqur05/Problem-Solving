///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int MX = 2e5;

struct Node {
    int totalSum;
    int prefSum;
};

Node segm_tree[4*MX]; 
int arr[MX];

Node make_node(int val) {
    Node res;
    res.totalSum = val;
    res.prefSum = max (val, 0LL);
    return res;
}

// Calculate the value of a node from its children
Node calculate(Node left, Node right) {
    Node res;
    res.totalSum = left.totalSum + right.totalSum;
    res.prefSum = max (left.prefSum, left.totalSum + right.prefSum);

    return res;
}

// Build the segment tree: node = current node in tree, [left, right] = segment
void build(int node, int left, int right) {
    if (left == right) {
        segm_tree[node] = make_node (arr[left]);
    } else {
        int mid = left + (right - left)/2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);
        segm_tree[node] = calculate(segm_tree[2*node], segm_tree[2*node+1]);
    }
}

// Update position idx to value val
void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segm_tree[node] = make_node(val);
    } else {
        int mid = left + (right - left)/2;
        if (idx <= mid) update(2*node, left, mid, idx, val);
        else update(2*node + 1, mid + 1, right, idx, val);
        segm_tree[node] = calculate(segm_tree[2*node], segm_tree[2*node+1]);
    }
}

// Query minimum in range [l, r]
Node query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) return {0, 0};// no overlap
    if (l <= left && right <= r) return segm_tree[node]; // full overlap
    int mid = left + (right - left)/2;
    Node l_node = query(2*node, left, mid, l, r);
    Node r_node = query(2*node+1, mid+1, right, l, r);

    return calculate (l_node, r_node);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    // Read 1-indexed array
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n); // root at 1, array 1-indexed


    while (q--) {
        int t, a, b;
        cin>> t >> a >> b;

        if (t == 1){
            // a++;
            update(1, 1, n, a, b); 
        }
        else 
        {
            // a++; b++;
            cout << query(1, 1, n, a, b).prefSum << endl;
        }
        
    }
}