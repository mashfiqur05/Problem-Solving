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
        int frq;
        string best;
        node() {
            for(int i = 0; i < 26; i++) nxt[i] = NULL;
            frq = 0;
            best = "";
        }
    }*root;

    Trie() { root = new node(); }

    void insert(const string& s, int f) {
        node* cur = root;
        for(char c : s) {
            int b = c - 'a';
            if(cur->nxt[b] == NULL) cur->nxt[b] = new node();
            cur = cur->nxt[b];

            if (f > cur->frq)
            {
                cur->frq = f;
                cur->best = s;
            }
            else if (f == cur->frq && s < cur->best)
            {
                cur->best = s;
            }
        }
    }

    // checks if query string exists exactly OR is a prefix of any inserted string
    pair<string,int> query(string& s) {
        node* cur = root;
        for(char c : s) {
            int b = c - 'a';
            if(cur->nxt[b] == NULL) return {"-1", -1}; // doesn't exist at all
            cur = cur->nxt[b];
        }

        return {cur->best, cur->frq};
    }
};

void solve ()
{
    int n; cin >> n;
    Trie trie;
    map<string, int> fr;
    for (int i = 0; i < n; i++) 
    {
        string s; cin >> s;
        fr[s]++;
    }
    for (auto &u : fr) trie.insert (u.first, u.second);

    int q; cin >> q;
    while (q--)
    {
        string s; cin >> s;
        auto ans = trie.query (s);
        if (ans.first == "-1") cout << -1 << endl;
        else cout << ans.first << " " << ans.second << endl;
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