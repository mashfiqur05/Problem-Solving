#include<bits/stdc++.h>
using namespace std;

#define ll long long
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
//int arr[MX];

int reverseDigitsMin(int num) 
{ 
    int tmp = num;
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10; 
        num = num / 10; 
    } 
    
    rev_num = min (rev_num, tmp);
    return rev_num;
} 

int reverseDigitsMax(int num) 
{ 
    int tmp = num;
    int rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num * 10 + num % 10;
        num = num / 10; 
    } 
    
    rev_num = max (rev_num, tmp);
    return rev_num;
} 

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int a, b;
        cin >> a >> b;

        a = reverseDigitsMax (a);
        b = reverseDigitsMin (b);

        if (a > b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}