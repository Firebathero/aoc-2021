
#include <bits/stdc++.h>
#define arr array

typedef long long ll;
using namespace std;


int main() {
    string s;
    freopen("input.txt", "r", stdin);
    int n;

    vector<int>v;
    while (cin >> n) {
        v.push_back(n);
    }  
    int prev = v[0] + v[1] + v[2];
    int ct = 0;

    for (int i = 3; i < v.size(); ++i) {
        int curr = prev - v[i-3];
        curr += v[i];
        if (curr > prev) ct++;
    }
    cout << ct;  
}










*/
