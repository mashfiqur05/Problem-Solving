///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

const int MX = 4e5+123;

int segm_tree[4*MX];
vector<int> arr(MX);

// Calculate the value of a node from its children
int calculate(int node) {
    return segm_tree[2*node] + segm_tree[2*node + 1];
}

// Build the segment tree
void build(int node, int left, int right) {
    if (left == right) {
        segm_tree[node] = arr[left];
    } else {
        int mid = (left + right) / 2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);
        segm_tree[node] = calculate(node);
    }
}

// Update position idx by val (+1 or -1)
void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segm_tree[node] += val;
    } else {
        int mid = (left + right) / 2;
        if (idx <= mid) update(2*node, left, mid, idx, val);
        else update(2*node + 1, mid + 1, right, idx, val);
        segm_tree[node] = calculate(node);
    }
}

// Query count in range [l, r]
int query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) return 0;
    if (l <= left && right <= r) return segm_tree[node];
    int mid = (left + right) / 2;
    return query(2*node, left, mid, l, r) +
           query(2*node + 1, mid + 1, right, l, r);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> v(n+1);
    vector<int> allVals;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        allVals.push_back(v[i]);
    }

    vector<tuple<char,int,int>> queries;
    for (int i = 0; i < q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        queries.push_back({type, a, b});
        if (type == '!') allVals.push_back(b);
    }

    // Coordinate compression
    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

    map<int,int> compress;
    for (int i = 0; i < (int)allVals.size(); i++)
        compress[allVals[i]] = i + 1;

    int m = allVals.size(); 

    for (int i = 1; i <= n; i++) 
    {
        int c = compress[v[i]];
        arr[c]++;
        v[i] = c;
    }

    build(1, 1, m);

    for (auto &t : queries) {
        char type;
        int a, b;
        tie(type, a, b) = t;

        if (type == '!') {
            int newVal = compress[b];
            update(1, 1, m, v[a], -1);
            update(1, 1, m, newVal, +1);
            v[a] = newVal;
        }
        else
        {
            auto it1 = compress.lower_bound(a);
            if (it1 == compress.end())
            {
                cout << 0 << endl;
                continue;
            }
            int L = it1->second;

            auto it2 = compress.upper_bound(b);
            if (it2 == compress.begin())
            {
                cout << 0 << endl;
                continue;
            }
            it2--;
            int R = it2->second;

            if (L > R)
            {
                cout << 0 << endl;
                continue;
            }

            cout << query(1, 1, m, L, R) << endl;
        }
    }
}
