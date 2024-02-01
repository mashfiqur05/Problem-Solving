/// Given an integer array and a non-negative integer k, count all distinct pairs with difference equal to k, i.e., A[ i ] - A[ j ] = k

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx =1e6+123;
int arr[mx];

int main()
{
    optimize();

    int n, t, k;
    cin >> t;

    while (t--)
    {
        vector<pair<int, int>> v;
        cin >> n >> k;

        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i != j) && (arr[i] - arr[j] == k)) v.push_back({ arr[i], arr[j]});
            }
        }

        sort(v.begin(), v.end());
        int size = unique(v.begin(), v.end()) - v.begin();
        cout << size << endl;
    }

    return 0;
}