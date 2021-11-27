#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> vec;
unordered_map<int,int> m;
int n, target = 2020;

void in() {
    freopen("input.txt", "r", stdin);
    while (cin >> n) {
        vec.push_back(n);
    }
}

void solve () {
    int sz = vec.size();
    for (int i = 0; i < sz; ++i) {
        m[vec[i]] = vec[i];
    }
    
    for (int i = 0; i < sz; ++i) {
        for (int j = i+1; j < sz; ++j) {
            int twosum = vec[i] + vec[j];
            if (m.find(target - twosum) != m.end()) {
                cout << vec[i] * vec[j] * m[target - twosum];
                return;
            }
        }
    }
}

int main() {
    in();
    solve();
}



