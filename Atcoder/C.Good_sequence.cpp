#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    map<int, int>cnt;

    int n; 
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a; 
        cin >> a;
        cnt[a]++;
    }

    int ans = 0;
    for (auto u : cnt)
    {
        if (u.second >= u.first) ans += (u.second - u.first);
        else ans += u.second;
    }

    cout << ans << endl;


    return 0;
}