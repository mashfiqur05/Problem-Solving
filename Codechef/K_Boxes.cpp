///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

const int MX = 2e5+123;

void testCases(int tt)
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, pair<int, int>>> v(n); // a, b, ind
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first; 
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second.first; 
        v[i].second.second = i;   
    }

    sort(all(v));

    vector<int> ans(n);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int coin = v[i].second.first;
        int idx = v[i].second.second;

        ans[idx] = sum;

        minHeap.push(coin);
        sum += coin;

        if ((int)minHeap.size() > k)
        {
            sum -= minHeap.top();
            minHeap.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}
