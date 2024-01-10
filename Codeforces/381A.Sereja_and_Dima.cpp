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

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    int sereja = 0, dima = 0, turn = 1;

    while (!v.empty())
    {
        if (turn == 1)
        {
            if (v[0] > v.back())
            {
                sereja += v[0];
                v.erase(v.begin());
            }
            else 
            {
                sereja += v.back();
                v.pop_back();
            }

            turn = 2;
        }
        else 
        {
            if (v[0] > v.back())
            {
                dima += v[0];
                v.erase(v.begin());
            }
            else 
            {
                dima += v.back();
                v.pop_back();
            }
            
            turn = 1;
        }
    }

    cout << sereja << " " << dima;

    return 0;
}