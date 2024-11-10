#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
char able[3] = { 'C', 'O', 'W' };
char arr[100001];
int L[3][100001] = { 0 }; // H S P
int R[3][100001] = { 0 };
int main() {
    int n; cin >> n;
    string t; cin >> t;
    for (int i = 0; i < n; i++) {
        arr[i] = t[i];
    }

    L[0][1] = 0; L[1][1] = 0; L[2][1] = 0;
    R[0][n] = 0; R[0][n] = 0; R[0][n] = 0;

    for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= n; i++) {
            L[j][i] = L[j][i - 1];
            if (arr[i - 1] == able[j]) { L[j][i]++; }
        }

        for (int i = n; i >= 1; i--) {
            R[j][i] = R[j][i + 1];
            if (arr[i - 1] == able[j]) { R[j][i]++; }
        }
    }



    int res = 0;
    int m = INT_MIN;
    //m = max(m, L[j][n]);
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] == 'O') {
            res += (L[0][i] * R[2][i + 2]);
        }
    }



    cout << res;
    return 0;
}