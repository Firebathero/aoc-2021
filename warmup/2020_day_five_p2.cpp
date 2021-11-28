//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++

int main() {
    freopen("input.txt", "r", stdin);
    
    string s;
    vector<int>seats;

    int mx_seat = INT_MIN;
    while (cin >> s) {
    
        int row_l = 0, row_r = 127, col_l = 0, col_r = 7;
        for (int i = 0; i < s.length(); ++i) {
            
            if (s[i] == 'F') {
                row_r -= (row_r-row_l+1)/2;
            }
            else if (s[i] == 'B') {
                row_l += (row_r-row_l+1)/2;
            }
            else if (s[i] == 'L') {
                col_r -= (col_r-col_l+1)/2;
            }
            else if (s[i] == 'R') {
                col_l += (col_r-col_l+1)/2;
            }
        }
        int seat_num = row_l * 8 + col_l;
        seats.push_back(seat_num);
        mx_seat = max(seat_num, mx_seat);
    }
    sort(seats.begin(), seats.end());
    for (int seat : seats) cout << seat << '\n';
}


