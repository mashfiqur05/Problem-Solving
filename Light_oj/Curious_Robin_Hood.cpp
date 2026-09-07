///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


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
void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segm_tree[node] += val;
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



void solve ()
{
    int n, q; cin >> n >> q;
    for (int  i = 1; i <= n; i++) cin >> arr[i];
    build (1, 1, n);
    while (q--)
    {
        int type; cin >> type;
        if (type == 1)
        {
            int i; cin >> i;i++;
            int val = query (1, 1, n, i, i);
            cout << val << endl;
            update (1, 1, n, i, (-1)*val);
        }
        else if (type == 2)
        {
            int i, val; cin >> i >> val;i++;
            update (1, 1, n, i, val);
        }
        else 
        {
            int l, r; cin >> l >> r;l++; r++;
            int val = query(1, 1, n, l, r);
            cout << val << endl;
        }
    }
}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": " << endl;
        solve ();
    }

    return 0;
}