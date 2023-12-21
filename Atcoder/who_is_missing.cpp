/* We have 4 cards with an integer 1 written on it, 4 cards with 2, …, 4 cards with N, for a total of 4N cards.Takahashi shuffled these cards, removed one of them,and
gave you a pile of the remaining 4N−1 cards. The i-th card (1≤i≤4N−1) of the pile has an integer A i written on it.Find the integer written on the card removed by Takahashi.*/

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n;
    cin >> n;
    vector<int> count(n + 1);

    for (int i = 1; i <= (4 * n -1); i++)
    {
        int a;
        cin >> a;
        count[a]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (count[i] == 3) cout << i << endl; 
    }
    

    return 0;
}