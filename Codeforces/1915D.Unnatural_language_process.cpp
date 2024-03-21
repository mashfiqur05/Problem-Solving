#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t = 1;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        stack<char> st;

        for (int i = s.length() - 1; i >= 0;)
        {
            if (s[i] == 'a' || s[i] == 'e')
            {
                st.push (s[i]);
                st.push (s[i-1]);
                if ((i-1) != 0) st.push ('.');
                i -= 2;
            }
            else 
            {
                st.push (s[i]);
                st.push (s[i-1]);
                st.push (s[i-2]);
                if ((i-2) != 0) st.push ('.');
                i -= 3;
            }
        }

        string ans;

        while (!st.empty())
        {
            ans.push_back (st.top());
            st.pop();
        }

        cout << ans << endl;
    }
    
    return 0;
}