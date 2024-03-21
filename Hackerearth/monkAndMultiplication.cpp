#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 1e6+123;
int arr[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    while (testcases--) 
    {
        priority_queue <int> pq;

        int sizeArray; 
        cin >> sizeArray;

        for (int i = 1; i <= sizeArray; i++) cin >> arr[i];

        for (int i = 1; i <= sizeArray; i++)
        {
            pq.push (arr[i]);
            
            if (pq.size() >= 3)
            {
                int a1 = pq.top();
                pq.pop();
                
                int a2 = pq.top();
                pq.pop();
                
                int a3 = pq.top();
                pq.pop();

                cout << 1ll * a1 * a2 * a3 << endl;

                pq.push( a1 );
                pq.push( a2 );
                pq.push( a3 );
            }
            else cout << "-1" << endl;
        }
    }
    
    return 0;
}