/// Given two numbers A and B.Print all lucky numbers between Aand B inclusive.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
   optimize();

   int a, b;
   int countr = 0;
   cin >> a >> b;

   for (int i = a; i <= b ; i++)
   {
      int n = i;
      int mod = 1;

      while (i != 0)
      {
         short digit = n % 10;
         n /= 10;
         if (digit != 4 && digit != 7) mod = 0;
      }

      if (mod == 0) 
      {
         cout << i << " ";
         countr++;
      }
   }

   if (countr == 0) cout << "-1";   


   return 0;
}