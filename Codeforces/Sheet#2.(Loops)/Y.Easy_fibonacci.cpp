#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);

int main()
{
    optimize();

    int num;
    cin >> num;

    if (num == 1)
    {
        cout << "0";
        goto end;
    }
    else if (num == 2)
    {
        cout << "0" << " " << "1";
        goto end;
    }
    else
    {
        cout << "0" << " " << "1" << " ";
        int next = 1;
        int prev = 0;
        int i = 2;
        do
        {
            int temp = next + prev;
            prev = next;
            next = temp;
            cout << next << " ";
            i++;
        } while (i != num);
    }

end:

    return 0;
}