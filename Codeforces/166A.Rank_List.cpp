#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

bool cmp ( const pair<int,int> &p1, const pair<int, int> &p2 )
{
    if (p1.first > p2.first) return 1;
    else if (p1.first == p2.first) return (p1.second < p2.second);
    else return 0;
}


int main()
{
    optimize();

    int t, n;
    cin >> t >> n; 
    vector<pair<int, int>> v(t);

    for (int i = 0; i < t; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort (v.begin(), v.end(), cmp);
    int cnt = 0;

    for (auto u : v)
    {
        if (u == v[n-1]) cnt++;
    } 

    cout << cnt << endl;

    return 0;
}