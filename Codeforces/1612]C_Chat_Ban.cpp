///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define int long long

int getSum(int n)
{
    return n * (n + 1) / 2;
}

int totalEmojis(int k, int mid)
{
    if (mid <= k)
    {
        return getSum(mid);
    }
    else
    {
        int first = getSum(k);
        int second = getSum(k - 1);
        int subtract = getSum(2 * k - 1 - mid);
        return first + second - subtract;
    }
}

void testCases(int tt)
{
    int k, x;
    cin >> k >> x;

    int l = 1, r = 2 * k - 1, ans = 2 * k - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int emj = totalEmojis(k, mid);
        if (emj >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}

int32_t main()
{
    fastio();
    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases(tt);
    }
    return 0;
}
