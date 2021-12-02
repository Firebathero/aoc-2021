
#include <bits/stdc++.h>
#define arr array
typedef long long ll;
using namespace std;
#define mp make_pair
#define pb push_back
#define pob pop_back()
#define rep(i,a,b) for (int i = a; i < b; ++i)

int n;
string s;

int main() {
    vector<string>v;
    int ans = 0;
    freopen("input.txt", "r", stdin);
    
    while (getline(cin, s)) {
        v.pb(s);
    }

    int depth = 0, horiz = 0, aim = 0;

    rep(i,0,v.size()) {
        string s = v[i];
        char dir = s[0];
        int len = s.length()-1;
        int dist = s[len] - '0';
        
        if (dir == 'f') {
            horiz += dist;
            depth += aim * dist;
        }
        else if (dir == 'd') {
            aim += dist;
        }
        else if (dir == 'u') {
            aim -= dist;
        }
    }
    cout << horiz << " " << depth << '\n';
    ans = depth * horiz;
    cout << ans;
}



