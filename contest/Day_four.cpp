
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
    int ans = 0;
    int a[5][5];
    freopen("input.txt", "r", stdin);
    
    cin >> s;
    vector<string> strs;
    
    int d = 0;
    string t = "";
    while (d < s.length()) {
        if (s[d] != ',') {
            t += s[d];
        }
        else {
            strs.push_back(t);
            t = "";
        }
        d++;
    }
    strs.push_back(t); 
    
    int matrix[100][25];
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 25; ++j) {
            cin >> matrix[i][j];
        }
    }
    set<int>st;
    vector<int>chrono;
    bool bingo = false;
    int final_val;
    for (int i = 0; i < strs.size(); ++i) {
        int bingo_ball = stoi(strs[i]);
        
        for (int k = 0; k < 100; ++k) {
            bingo = false;
            for (int j = 0; j < 25; ++j) {
                if (matrix[k][j] == bingo_ball) {
                    final_val = matrix[k][j];
                    matrix[k][j] = -1;

                    for (int c = 0; c < 5; ++c) {
                        if (matrix[k][c] == -1 && matrix[k][c+5] == -1 &&
                            matrix[k][c+10] == -1 && matrix[k][c+15] == -1 && matrix[k][c+20] == -1) {
                                bingo = true;
                            } 
                    }
                    for (int c = 0; c < 25; c+=5) {
                        if (matrix[k][c] == -1 && matrix[k][c+1] == -1 &&
                            matrix[k][c+2] == -1 && matrix[k][c+3] == -1 && matrix[k][c+4] == -1) {
                                bingo = true;
                            } 
                    }
                    
                   if (bingo) {
                       int ans = 0;
                        for (int r = 0; r < 25; ++r) {
                            if (matrix[k][r] != -1) ans+= matrix[k][r];
                        }

                        if (st.find(k) == st.end()) {
                            st.insert(k);
                            chrono.push_back(k);
                        }
                        
                        if (k == chrono[chrono.size()-1]) {
                            cout << final_val * ans;
                            return 0;
                        }
                   }

                }
            }
        }  
    } 
}
