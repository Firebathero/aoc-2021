//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
#include <bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define mp make_pair

#define mx(a) max_element(a.begin(), a.end());
#define mn(v) min_element(v.begin(), v.end());
typedef long long ll;
using namespace std;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++

int main() {
    
    vector<string> vec;
    string range;

    freopen("input.txt", "r", stdin);

    int valid_pw = 0;
    while (cin >> range) {
        string valid_char, pw;
        cin >> valid_char >> pw;

        string min_rng, max_rng;
        int i = 0;
        while (range[i] != '-') {
            min_rng += range[i];
            i++;
        }
        i++;
        while (i < range.length()) {
            max_rng += range[i];
            i++;
        }
     
        int min_ct = stoi(min_rng), max_ct = stoi(max_rng);
        int char_ct = 0;
        char c = valid_char[0];

        for (int i = 0; i < pw.length(); ++i) {
            if (c == pw[i]) char_ct++;
        }
        if (char_ct >= min_ct && char_ct <= max_ct) valid_pw++;
      
    }
    cout << valid_pw;

}



