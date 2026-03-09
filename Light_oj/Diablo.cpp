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
const int MX = 1e5+50003;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int segment_tree[4*MX], arr[MX];

// Calculate the value of a node from its children
int calculate(int node) {
    return (segment_tree[2*node] + segment_tree[2*node + 1]);
}

// Build the segment tree: node = current node in tree, [left, right] = segment
void build(int node, int left, int right) {
    if (left == right) {
        segment_tree[node] = (arr[left] != 0);
        return; // leaf node
    } else {
        int mid = left + (right - left)/2;
        build(2*node, left, mid);
        build(2*node + 1, mid + 1, right);
        segment_tree[node] = calculate(node);
    }
}

// Update position idx to value val
void update(int node, int left, int right, int idx) {
    if (left == right) {
        segment_tree[node] = 1;
        return;
    } else {
        int mid = left + (right - left)/2;
        if (idx <= mid) update(2*node, left, mid, idx);
        else update(2*node + 1, mid + 1, right, idx);
        segment_tree[node] = calculate(node);
    }
}

void del(int node, int left, int right, int idx) {
    if (left == right) {
        segment_tree[node] = 0;
        return;
    } else {
        int mid = left + (right - left)/2;
        if (idx <= mid) del(2*node, left, mid, idx);
        else del(2*node + 1, mid + 1, right, idx);
        segment_tree[node] = calculate(node);
    }
}

int kth (int node, int l, int r, int k)
{
    if (l == r)return l;
    int mid = (l + r)/2;
    if (segment_tree[2*node] >= k) return kth (2*node, l, mid, k);
    else return kth(2*node + 1, mid+1, r, k-segment_tree[2*node]);
}



void solve (int CaseNo)
{
    cout << "Case " << CaseNo << ":" << endl;
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int limit = n+q;
    build (1,1, limit);
    
    // for (int i = 1; i <= 3*n; i++) cout << segment_tree[i] << " ";cout << endl;

    while (q--)
    {
        char ch; cin >> ch;
        if (ch == 'a')
        {
            int p;
            cin >> p;
            n++;
            arr[n] = p;
            update (1, 1, limit, n);
        }
        else 
        {
            int k;
            cin >> k;
            // cout << segment_tree[0] <<" " << segment_tree[1] << endl;
            if (k > segment_tree[1])
            {
                cout << "none" << endl;
                continue;
            }
            int ind = kth (1, 1, limit, k);
            cout << arr[ind] << endl;
            del (1, 1, limit, ind);
        }
        // for (int i = 1; i <= n; i++) cout << arr[i] << " ";cout << endl;
        // for (int i = 1; i <= 3*n; i++) cout << segment_tree[i] << " ";cout << endl;
    }

    mem (arr, 0);
    mem (segment_tree, 0);
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}