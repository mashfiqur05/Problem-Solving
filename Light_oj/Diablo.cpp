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

struct Node {
    int sum;

    Node(int _sum = 0) {
        sum = _sum;
    }
};

struct SegTree {

    int n;
    vector<Node> tree;
    vector<int> arr;

    SegTree(int _n) {
        n = _n;

        tree.assign(4 * n + 5, Node());
        arr.assign(n + 1, 0);
    }

    Node mergeNode(Node left, Node right) {
        return Node((left.sum + right.sum));
    }

    void build(int node, int left, int right) {

        if (left == right) {
            tree[node] = Node(arr[left]);
            return;
        }

        int mid = left + (right - left) / 2;

        build(2 * node, left, mid);
        build(2 * node + 1, mid + 1, right);

        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }

    void update(int node, int left, int right,
                int idx, int val) {

        if (left == right) {
            tree[node] = Node(val);
            return;
        }

        int mid = left + (right - left) / 2;

        if (idx <= mid)
            update(2 * node, left, mid, idx, val);

        else
            update(2 * node + 1,
                   mid + 1, right,
                   idx, val);


        tree[node] =
            mergeNode(tree[2 * node],
                      tree[2 * node + 1]);
    }

    int kth(int node, int left, int right, int k)
    {
        if (left == right)
            return left;

        int mid = left + (right - left) / 2;

        int leftCount = tree[2 * node].sum;

        if (k <= leftCount)
            return kth(2 * node, left, mid, k);

        return kth(2 * node + 1,
                   mid + 1, right,
                   k - leftCount);
    }
};

void solve ()
{
    int n, q; cin >> n >> q;

    SegTree st(n+q);

    vector<int> v(n + q + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        st.arr[i] = 1;
    }
    st.build(1, 1, n+q);

    int cur = n+1;
    int qq = q;
    while (qq--)
    {
        char ch; cin >> ch;
        int i; cin >> i;
        if (ch == 'a')
        {
            v[cur] = i;
            st.update(1, 1, n+q, cur, 1);
            cur++;
        }
        else 
        {
            if (st.tree[1].sum < i) cout << "none" << endl;
            else 
            {
                int ind = st.kth (1, 1, n+q, i);
                cout << v[ind] << endl;
                st.update(1, 1, n+q, ind, 0);
            }
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
        cout << "Case " << tt << ":" << endl;
        solve ();
    }

    return 0;
}