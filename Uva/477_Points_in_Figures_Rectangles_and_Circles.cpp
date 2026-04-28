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
#define sq(a) ((a) * (a))

struct Rectangle {
    int id;
    double x1, y1, x2, y2; 
};
struct Circle {
    int id;
    double cx, cy, r;
};

bool insideRect(Rectangle& r, double px, double py) {
    double minX = min(r.x1, r.x2);
    double maxX = max(r.x1, r.x2);
    double minY = min(r.y1, r.y2);
    double maxY = max(r.y1, r.y2);
    return px > minX && px < maxX && py > minY && py < maxY;
}

bool insideCircle (Circle& c, double px, double py)
{
    double distance = sqrt (sq(abs(px-c.cx)) + sq(abs(py-c.cy)));

    return distance <= c.r;
}

int main()
{
    fastio();

    vector<Rectangle> fig1;
    vector<Circle> fig2;

    int t = 1;
    char c;
    while (cin >> c)
    {
        if (c == '*') break;
        if (c == 'r')
        {
            Rectangle rect;
            cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
            rect.id = t;
            fig1.push_back(rect);
        }
        else 
        {
            Circle c;
            cin >> c.cx >> c.cy >> c.r;
            c.id = t;
            fig2.push_back (c);
        }
        t++;
    }

    double px, py;
    int pointIdx = 1;
    while (cin >> px >> py)
    {
        if (px == 9999.9 && py == 9999.9) break;

        bool found = false;
        vector<int> ans;
        for (int i = 0; i < sz(fig1); i++)
        {
            if (insideRect(fig1[i], px, py))
            {
                // cout << fig1[i].x1 << " " << fig1[i].x2 << " " << fig1[i].y1 << " " << fig1[i].y2 << endl;
                ans.push_back (fig1[i].id);
                found = true;
            }
        }

        for (int i = 0; i < sz(fig2); i++)
        {
            if (insideCircle(fig2[i], px, py))
            {
                ans.push_back (fig2[i].id);
                found = true;
            }
        }

        sort (all (ans));
        if (!found)
            cout << "Point " << pointIdx << " is not contained in any figure" << endl;
        else 
        {
            for (auto u : ans)
            {
                cout << "Point " << pointIdx << " is contained in figure " << u << endl;
            }
        }

        pointIdx++;
    }

    return 0;
}