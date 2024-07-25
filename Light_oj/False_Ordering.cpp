#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

const int MX = 1000 + 123;

bool cmp(pair<int, int> d1, pair<int, int> d2)
{
    if (d1.first != d2.first) return d1.first < d2.first;
    else return d1.second > d2.second;  
}

int divisorCount(int n)
{
    if (n == 0) return 0; 
    int cnt = 0;
    int q = sqrt(n);
    for (int i = 1; i <= q; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (i != n / i) cnt++;
        }
    }
    return cnt;
}

int32_t main()
{
    Bismillah();

    vector<pair<int, int>> v;
    for (int i = 1; i <= 1000; i++)  
    {
        v.push_back(make_pair(divisorCount(i), i));
    }
    sort(all(v), cmp);

    int testcases;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;

        cout << "Case " << tt << ": " << v[n - 1].second << endl;  
    }
    
    return 0;
}
