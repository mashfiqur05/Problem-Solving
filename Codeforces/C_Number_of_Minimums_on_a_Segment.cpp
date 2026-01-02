///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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

struct Node {
    int mn;   // minimum value
    int cnt;  // count of minimum
};

Node segment_tree[4*MX];
int arr[MX];

Node calculate (Node left, Node right)
{
    Node res;
    if (left.mn < right.mn) res = left;
    else if (right.mn < left.mn) res = right;
    else 
    {
        res.mn = left.mn;
        res.cnt = left.cnt + right.cnt;
    }

    return res;
}

void build(int node, int left, int right) {
    if (left == right) {
        segment_tree[node] = {arr[left], 1}; // leaf node
    } else {
        int mid = left + (right - left)/2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);
        segment_tree[node] = calculate(segment_tree[2*node], segment_tree[2*node+1]);
    }
}

void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segment_tree[node] = {val, 1};
    } else {
        int mid = left + (right - left)/2;
        if (idx <= mid) update(2*node, left, mid, idx, val);
        else update(2*node + 1, mid + 1, right, idx, val);
        segment_tree[node] = calculate(segment_tree[2*node], segment_tree[2*node+1]);
    }
}

Node query(int node, int left, int right, int l, int r) {
    if (r < left || right < l) return {LLONG_MAX, 0}; // no overlap
    if (l <= left && right <= r) return segment_tree[node]; // full overlap
    int mid = left + (right - left)/2;
    
    Node n1 = query(2*node, left, mid, l, r);
    Node n2 = query (2*node + 1, mid+1, right, l, r);

    if (n1.mn == LLONG_MAX) return n2;
    if (n2.mn == LLONG_MAX) return n1;

    return calculate (n1,n2);
}


void solve (int CaseNo)
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build (1, 1, n);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            a++; 
            update(1, 1, n, a, b);
        } else {
            a++;
            Node ans = query(1, 1, n, a, b);
            cout << ans.mn << " " << ans.cnt << endl;
        }
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}