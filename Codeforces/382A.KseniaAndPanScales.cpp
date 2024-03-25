#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const ll MX = 123;
//vector<ll> arr(MX);

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        string scale;
        cin >> scale;
        string add;
        cin >> add;

        string left = "", right = "";

        for (int i = 0; i < scale.size(); i++)
        {
            if (scale[i] == '|')
            {
                break;
            }
            else 
            {
                left += scale[i];
            }
        }

        reverse (all (scale));
        
        for (int i = 0; i < scale.size(); i++)
        {
            if (scale[i] == '|')
            {
                break;
            }
            else 
            {
                right += scale[i];
            }
        }

        reverse (all (right));
        reverse (all (scale));

        int sizeLeft = left.size();
        int sizeRight = right.size();
        int sizeAdd = add.size();
        int diff = abs (sizeLeft - sizeRight);

        if ((sizeLeft + sizeRight + sizeAdd) % 2 == 0 && diff <= sizeAdd)
        {
            for (int i = 0; i < (sizeRight + sizeAdd - sizeLeft) / 2; i++)
            {
                cout << add[i];
            }
            cout << scale;
            for (int i = (sizeRight + sizeAdd - sizeLeft) / 2; i < sizeAdd; i++)
            {
                cout << add[i];
            }
        }
        else 
        {
            cout << "Impossible" << endl;
        }
    }
    
    return 0;
}