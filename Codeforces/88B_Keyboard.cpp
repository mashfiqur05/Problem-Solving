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

const int MAX_N = 35; 
const int MAX_TEXT = 1000000;

char key[MAX_N][MAX_N]; 
char text[MAX_TEXT]; 

vector<pair<int, int>> posKey[26];
vector<pair<int, int>> shift;
bool can[26];

int n, m, k, q;

int distance (int i, int j, int x, int y) 
{
    return (i - x)*(i - x) + (j - y)*(j - y);
}

bool check(int i, int j) 
{
    for (auto& s : shift) 
    {
        int dis = distance (i, j, s.first, s.second);
        if (dis <= k * k) 
        {
            return true;
        }
    }
    return false;
}

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cin >> n >> m >> k;

        for (int i = 0; i < n; ++i) {
        cin >> key[i];
        for (int j = 0; j < m; ++j) 
        {
            if (key[i][j] == 'S') 
            {
                shift.push_back(make_pair(i, j));
            } 
            else 
            {
                posKey[key[i][j] - 'a'].push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < 26; ++i) 
    {
        for (auto& p : posKey[i]) 
        {
            if (check(p.first, p.second)) 
            {
                can[i] = true;
                break;
            }
        }
    }

    cin >> q >> text;

    int res = 0;
    for (int i = 0; i < q; ++i) 
    {
        if (islower(text[i])) 
        {
            if (posKey[text[i] - 'a'].empty()) 
            {
                res = -1;
                break;
            }
        } 
        else 
        {
            text[i] = tolower(text[i]);
            if (shift.empty() || posKey[text[i] - 'a'].empty()) 
            {
                res = -1;
                break;
            }
            if (!can[text[i] - 'a']) 
            {
                ++res;
            }
        }
    }


    printf("%d\n", res);
        
    }
    
    return 0;
}