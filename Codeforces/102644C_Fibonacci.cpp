///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

/// Function to multiply two matrix
void multiply(vector<vector<long long> >& A,
              vector<vector<long long> >& B)
{
    // Matrix to store the result
    vector<vector<long long> > C(2, vector<long long>(2));

    // Matrix Multiply
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

      // Copy the result back to the first matrix
    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}

// Function to find (Matrix M ^ expo)
vector<vector<long long> >
power(vector<vector<long long> > M, int expo)
{
    // Initialize result with identity matrix
    vector<vector<long long> > ans = { { 1, 0 }, { 0, 1 } };

    // Fast Exponentiation
    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }

    return ans;
}

// function to find the nth fibonacci number
int nthFibonacci(int n)
{
    // base case
    if (n == 0 )
        return 0;

    vector<vector<long long> > M = { { 1, 1 }, { 1, 0 } };
    
    // Matrix F = {{f(0), 0}, {f(1), 0}}, where f(0) and f(1) are first two terms of fibonacci sequence
    vector<vector<long long> > F = { { 1, 0 }, { 0, 0 } };

    // Multiply matrix M (n - 1) times
    vector<vector<long long> > res = power(M, n - 1);

    // Multiply Resultant with Matrix F
    multiply(res, F);

    return res[0][0] % MOD;
}

void solve (int CaseNo)
{
    int n;
    cin >> n;
    cout << nthFibonacci(n) << endl;    
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}