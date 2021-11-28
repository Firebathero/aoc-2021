#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string s;

    int valid = 0, label_ct = 0;
    bool cid_found = false;

    while (getline(cin, s)) {
        if (s == "") {
            if (label_ct == 8 || (label_ct == 7 && !cid_found)) {
                valid++;
            }
            label_ct = 0, cid_found = false;
        }
        else {
            label_ct++;
            int found = s.find("cid");
            if (found != string::npos) cid_found = true;
            for (int i = 0; i < s.length(); ++i) if (s[i] == ' ') label_ct++;
        }
    }
    cout << valid;
}


