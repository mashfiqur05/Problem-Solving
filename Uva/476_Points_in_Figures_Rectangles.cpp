///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(2); cout.setf(ios::fixed,ios::floatfield);

#define endl '\n'
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

struct Rectangle {
    double x1, y1, x2, y2; 
};

bool insideRect(Rectangle& r, double px, double py) {
    double minX = min(r.x1, r.x2);
    double maxX = max(r.x1, r.x2);
    double minY = min(r.y1, r.y2);
    double maxY = max(r.y1, r.y2);
    return px > minX && px < maxX && py > minY && py < maxY;
}

int main()
{
    fastio();

    vector<Rectangle> figures;

    char c;
    while (cin >> c)
    {
        if (c == '*') break;
        if (c == 'r')
        {
            Rectangle rect;
            cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
            figures.push_back(rect);
        }
    }

    double px, py;
    int pointIdx = 1;
    while (cin >> px >> py)
    {
        if (px == 9999.9 && py == 9999.9) break;

        bool found = false;
        for (int i = 0; i < sz(figures); i++)
        {
            if (insideRect(figures[i], px, py))
            {
                cout << "Point " << pointIdx << " is contained in figure " << (i + 1) << endl;
                found = true;
            }
        }
        if (!found)
            cout << "Point " << pointIdx << " is not contained in any figure" << endl;

        pointIdx++;
    }

    return 0;
}