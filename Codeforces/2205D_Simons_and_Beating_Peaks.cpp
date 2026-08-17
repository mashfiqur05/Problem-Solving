///--- In the name of ALLAH ---///

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int MX = 5e5 + 9;
const int INF = 1e18;

int segm_tree[4 * MX];


// Calculate the value of a node from its children
int calculate(int node) {
    return min(segm_tree[2 * node], segm_tree[2 * node + 1]);
}


// Build the segment tree
void build(int node, int left, int right) {
    if (left == right) {
        segm_tree[node] = INF;
        return;
    }

    int mid = left + (right - left) / 2;

    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);

    segm_tree[node] = calculate(node);
}


void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segm_tree[node] = val;
        return;
    }

    int mid = left + (right - left) / 2;

    if (idx <= mid)
        update(2 * node, left, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, right, idx, val);

    segm_tree[node] = calculate(node);
}


int query(int node, int left, int right, int l, int r) {
    if (r < left || right < l)
        return INF;

    if (l <= left && right <= r)
        return segm_tree[node];

    int mid = left + (right - left) / 2;

    return min(
        query(2 * node, left, mid, l, r),
        query(2 * node + 1, mid + 1, right, l, r)
    );
}

// tree[value] = position

void solve() {

    int n;
    cin >> n;

    int a[n + 1], ans_right[n + 1], ans_left[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    memset(ans_right, 0, sizeof(ans_right));
    memset(ans_left, 0, sizeof(ans_left));

    build(1, 1, n);

    for (int i = n; i >= 1; i--) {

        if (i + 1 <= n && a[i] > a[i + 1])
        {

            int idx = query(1,1,n, a[i] + 1, n);

            if (idx == INF) {

                ans_right[i] = n - i;

            } else {
                ans_right[i] = (idx - i - 1) + ans_right[idx];
            }
        }
        else
        {
            if (i + 1 <= n)
                ans_right[i] = ans_right[i + 1];
            else
                ans_right[i] = 0;
        }

        update( 1,1,n,a[i],i);
    }

    reverse(a + 1, a + n + 1);
    build(1, 1, n);

    for (int i = n; i >= 1; i--) {

        if (i + 1 <= n && a[i] > a[i + 1]) {

            int idx = query(1,1,n,a[i] + 1,n);

            if (idx == INF) {

                ans_left[i] = n - i;

            } else {

                ans_left[i] =
                    (idx - i - 1) + ans_left[idx];
            }

        } else {

            if (i + 1 <= n)
                ans_left[i] = ans_left[i + 1];
            else
                ans_left[i] = 0;
        }


        update( 1,1,n,a[i],i);
    }


    reverse(ans_left + 1,ans_left + n + 1);

    int answer = n;
    for (int i = 1; i <= n; i++) {
        answer = min(answer,ans_left[i] + ans_right[i]);
    }

    cout << answer << endl;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}