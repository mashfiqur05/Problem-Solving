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

void generateSequences(vector<string>& S, vector<int>& seq, int N, int K, int depth, vector<string>& all) {
    if (depth == K) {
        string result = "";
        for (int idx : seq) {
            result += S[idx];
        }
        all.push_back(result);
        return;
    }

    for (int i = 0; i < N; i++) {
        seq.push_back(i);
        generateSequences(S, seq, N, K, depth + 1, all);
        seq.pop_back(); // backtrack
    }
}

void solve (int CaseNo)
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<string> ans;
    vector<int> seq;
    generateSequences (v, seq, n, k, 0, ans);

    sort (all (ans));

    cout << ans[x-1] << endl;
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