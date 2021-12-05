
#include <bits/stdc++.h>
#define arr array
typedef long long ll;
using namespace std;
#define mp make_pair
#define pb push_back
#define pob pop_back()
#define rep(i, a, b) for (int i = a; i < b; ++i)

int n;
string s;
char a[1500][1500];

int main()
{

    for (int i = 0; i < 1500; ++i)
    {
        for (int j = 0; j < 1500; ++j)
        {
            a[i][j] = '.';
        }
    }

    vector<string> v;
    int ans = 0;
    freopen("input.txt", "r", stdin);

    while (getline(cin, s))
    {
        v.pb(s);
    }
    vector<int> x1, x2, y1, y2;

    for (int i = 0; i < 500; ++i)
    {

        string line = v[i];
        string temp = "";
        int j = 0;

        while (line[j] != ',' && line[j] != '-' && line[j] != '>' && line[j] != ' ')
        {
            temp += line[j];
            j++;
        }
        x1.push_back(stoi(temp));
        j++;
        temp = "";

        while (line[j] != ',' && line[j] != '-' && line[j] != '>' && line[j] != ' ')
        {
            temp += line[j];
            j++;
        }

        y1.push_back(stoi(temp));
        temp = "";
        j += 4;

        while (line[j] != ',' && line[j] != '-' && line[j] != '>' && line[j] != ' ')
        {
            temp += line[j];
            j++;
        }
        x2.push_back(stoi(temp));
        temp = "";
        j++;

        while (line[j] != ',' && line[j] != '-' && line[j] != '>' && line[j] != ' ')
        {
            temp += line[j];
            j++;
        }
        y2.push_back(stoi(temp));
    }

    int xc1, xc2, yc1, yc2;

    for (int i = 0; i < y1.size(); ++i)
    {
        if (y1[i] == y2[i])
        {
            yc1 = y1[i];
            yc2 = y2[i];
            xc1 = x1[i];
            xc2 = x2[i];

            if (xc1 > xc2)
                swap(xc1, xc2);

            for (int k = xc1; k <= xc2; ++k)
            {
                if (a[yc1][k] == '.')
                    a[yc1][k] = 'x';
                else if (a[yc1][k] == 'x')
                    a[yc1][k] = 'b';
            }
        }
    }
    for (int i = 0; i < x1.size(); ++i)
    {
        if (x1[i] == x2[i])
        {
            yc1 = y1[i];
            yc2 = y2[i];
            xc1 = x1[i];
            xc2 = x2[i];
            if (yc1 > yc2)
                swap(yc1, yc2);

            for (int j = yc1; j <= yc2; ++j)
            {
                if (a[j][xc1] == '.')
                    a[j][xc1] = 'x';
                else if (a[j][xc1] == 'x')
                    a[j][xc1] = 'b';
            }
        }
    }
    for (int i = 0; i < x1.size(); ++i)
    {
        bool slant_down = false;
        if (abs(x1[i] - x2[i]) == abs(y1[i] - y2[i]))
        {

            yc1 = y1[i];
            yc2 = y2[i];
            xc1 = x1[i];
            xc2 = x2[i];

            if (xc2 < xc1 && yc2 < yc1)
            {
                swap(xc1, xc2);
                swap(yc1, yc2);
                slant_down = false;
            }
            else if (xc1 < xc2 && yc1 < yc2)
            {
                slant_down = false;
            }

            else if (xc2 < xc1)
            {
                swap(xc1, xc2);
                swap(yc1, yc2);
                slant_down = true;
            }
            else
            {
                slant_down = true;
            }
            if (slant_down)
            {

                for (int c = yc1, r = xc1; c >= yc2; c--, r++)
                {
                    if (a[c][r] == '.')
                        a[c][r] = 'x';
                    else if (a[c][r] == 'x')
                        a[c][r] = 'b';
                }
            }
            else
            {
                cout << xc1 << " " << xc2 << " " << yc1 << " " << yc2 << '\n';
                for (int c = yc1, r = xc1; c <= yc2; c++, r++)
                {
                    if (a[c][r] == '.')
                        a[c][r] = 'x';
                    else if (a[c][r] == 'x')
                        a[c][r] = 'b';
                }
            }
        }
    }
    for (int i = 0; i < 1001; ++i)
    {
        for (int j = 0; j < 1001; ++j)
        {
            if (a[i][j] == 'b')
                ans++;
        }
    }
    cout << ans;
}
