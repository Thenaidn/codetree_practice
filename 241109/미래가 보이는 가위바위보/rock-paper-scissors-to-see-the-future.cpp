#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
char able[3] = { 'H', 'S', 'P' };
char arr[100001];
int L[3][100001] = {0}; // H S P
int R[3][100001] = {0};
int main() {
    int n; cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    L[0][1] = 0; L[1][1] = 0; L[2][1] = 0;
    R[0][n] = 0; R[0][n] = 0; R[0][n] = 0;

    for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= n; i++) {
            L[j][i] = L[j][i - 1];
            if (arr[i] == able[j]) { L[j][i]++; }
        }

        for (int i = n; i >= 1; i--) {
            R[j][i] = R[j][i + 1];
            if (arr[i] == able[j]) { R[j][i]++; }
        }
    }
    


    
    int m = INT_MIN;
    for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= n - 1; i++) {
            m = max(m, L[j][i] + max(R[(j + 1) % 3][i + 1], R[(j + 2) % 3][i + 1]));
        }
    }
    

    cout << m;
    return 0;
}