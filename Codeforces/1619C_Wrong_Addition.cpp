///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define endl '\n'
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string a, s;
        cin >> a >> s;
        stringstream b;

        ll i = s.size()-1, j = a.size()-1;

        while (i >= 0 && j >= 0)
        {
            int x, y;
            if (s[i] < a[j])
            {
                if (i == 0) { // Prevent out-of-bound access
                    b.str("");  // Clear the stringstream
                    break;
                }
                x = (10 * (s[i-1]-'0')) + (s[i]-'0');
                i -= 2;
            }
            else 
            {
                x = s[i] - '0';
                i--;
            }

            y = a[j]-'0';
            j--;

            int val = x - y;
            if (val <= 9 && val >= 0) b << (char)(val + '0');
            else { 
                b.str("");  // Clear the stringstream on invalid value
                break;
            }
        }
        
        if (j != -1 || b.str() == "") 
        {
            cout << -1 << endl;
        }
        else 
        {
            while (i >= 0)
            {
                b << s[i--];
            }

            string result = b.str();
            reverse(result.begin(), result.end());
            
            // Remove leading zeros
            ll k = 0;
            while (k < result.size() && result[k] == '0') k++;
            result = result.substr(k);

            if (result.empty()) result = "0";
            cout << result << endl;
        }
    }

    return 0;
}
