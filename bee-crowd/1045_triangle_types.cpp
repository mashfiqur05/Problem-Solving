#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    double a, b, c, i, j, k, temp;
    cin >> a >> b >> c;    /// take input 3 double.
    i = a, j = b, k = c;

    /// assending the triangle sides.
    if (i < j)
    {
        temp = i;
        i = j;
        j = temp;
    }  
    if (i < k)
    {
        temp = i;
        i = k;
        k = temp;
    }
    if (j < k)
    {
        temp = j;
        j = k;
        k = temp;
    }

    ///triangle or not.
    if (j + k <= i) 
    {
        cout << "NAO FORMA TRIANGULO" << endl;
        goto end;
    }
    /// check every casses of triangle types.
    if (i >= (b + c)) cout << "NAO FORMA TRIANGULO" << endl;
    if (i * i == j * j + k * k) cout << "TRIANGULO RETANGULO" << endl;
    if (i * i > (j * j + k * k)) cout << "TRIANGULO OBTUSANGULO" << endl;
    if (i * i < (j * j + k * k)) cout << "TRIANGULO ACUTANGULO" << endl;
    if (i == j && i == k && j == k) cout << "TRIANGULO EQUILATERO" << endl;
    if ((i == j || j == k) && ( i != j || j != k)) cout << "TRIANGULO ISOSCELES" << endl;
    
    end:
    
    return 0;
}