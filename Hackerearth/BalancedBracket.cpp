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


bool isBalanced (char c1, char c2)
{
    return (c1 == '(' && c2 == ')') ||  (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']');
}


int main()
{
    optimize();

    int t = 1;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;

        stack <char> st;
        bool ans = 0;
        int cnt = 0;

        for (auto u : s)
        {
            if (u == '(' || u == '{' || u == '[') st.push (u);
            else 
            {
                if (st.empty())
                {
                    ans = 0;
                    break;
                }
                else 
                {
                    if (isBalanced (st.top(), u)) st.pop();
                    else 
                    {
                        ans = 0;
                        break;
                    }
                }
            }
        }

        if (!st.empty()) ans = 0;

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}