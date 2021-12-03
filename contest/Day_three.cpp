
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
    
    freopen("input.txt", "r", stdin);
    while (cin >> s) {
        v.pb(s);
    }
    vector<bool>b(v.size());
    for (int i = 0; i < v.size(); ++i) {
        b[i] = true;
    }
    for (int i = 0; i < v[0].size(); ++i) {
        int zeroes = 0, ones = 0;

        for (int j = 0; j < v.size(); ++j) {
            if (b[j] == true) {
                if (v[j][i] == '1') ones++;
                else if (v[j][i] == '0') zeroes++;
            }
        }
        char keep_me;
        if (ones < zeroes) keep_me = '1';
        else keep_me = '0';

        for (int k = 0; k < v.size(); ++k) {
            if (v[k][i] != keep_me) {
                b[k] = false;
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            if (b[i]) {
                cout << v[i] << '\n';
            }
        }
    }
}
