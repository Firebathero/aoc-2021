#include <bits/stdc++.h>
#define arr array
typedef long long ll;
using namespace std;
#define mp make_pair
#define pb push_back
#define pob pop_back()
#define rep(i, a, b) for (int i = a; i < b; ++i)

int n;
string s,t;
vector<int>v;

int main()
{
    freopen("input", "r", stdin);
    cin >> s;
    int prev = 0;
    for (int i = 0; i < s.length(); ++i)
        if(s[i]==',') {
            t = s.substr(prev,i-prev);
            v.push_back(stoi(t));
            prev = i+1;
        }
    int ans = 0, res = 0;
    v.push_back(stoi(s.substr(prev, s.length()-prev)));
    
    //solve
    for (int d : v) ans += d;
    int mean = ans/v.size();
    for (int d : v) {
        d = abs(mean-d);
        res += (d*(d+1))/2; 
    }
    cout << res;
}
