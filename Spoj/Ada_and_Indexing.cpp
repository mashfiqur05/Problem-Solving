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


struct Trie {
    struct node {
        node* nxt[26];
        int cnt;
        int prefCnt;
        node() {
            for(int i = 0; i < 26; i++) nxt[i] = NULL;
            cnt = 0;
            prefCnt = 0;
        }
    }*root;

    Trie() { root = new node(); }

    void insert(string& s) {
        node* cur = root;
        for(char c : s) {
            int b = c - 'a';
            if(cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];
            cur->prefCnt++;
        }
        cur->cnt++;
    }

    // checks if query string exists exactly OR is a prefix of any inserted string
    int query(string& s) {
        node* cur = root;
        for(char c : s) {
            int b = c - 'a';
            if(cur->nxt[b] == NULL) return 0; // doesn't exist at all
            cur = cur->nxt[b];
        }

        // int isExact  = cur->cnt;         // exact match exists
        // int isPrefix = cur->cnt;               // we reached here = it's a prefix
        return cur->prefCnt;
    }
};

void solve ()
{
    Trie trie;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        trie.insert (s);
    }

    while (q--)
    {
        string s; cin >> s;
        int ans = trie.query(s);
        cout << ans << endl;
    }
}


int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}