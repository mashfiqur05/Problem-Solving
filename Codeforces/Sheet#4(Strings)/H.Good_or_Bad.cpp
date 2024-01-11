#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int t;
    string s;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> s;
        int good = 0;
        
        for (int j = 0; j < s.length(); j++)
        {
            char s1 = s[j];
            char s2 = s[j+1];
            char s3 = s[j+2];

            if ((s1 == '1' && s2 == '0' && s3 == '1') || (s1 == '0' && s2 == '1' && s3 == '0'))
            {
                good = 1; 
                break;
            }
        }

        if (good) cout << "Good" << endl;
        else cout << "Bad" << endl;
    }

    return 0;
}