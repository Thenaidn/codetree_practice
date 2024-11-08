#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    char arr[1001][1001] = { 0 };
    int prefix_sum[1001][1001] = {};

    char arr2[1001][1001] = { 0 };
    int prefix_sum2[1001][1001] = {};

    char arr3[1001][1001] = { 0 };
    int prefix_sum3[1001][1001] = {};

    int a, b, c; cin >> a >> b >> c;
    char z;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            cin >> z;
            if (z == 'a') {
                arr[i][j] = 1;
            }
            if (z == 'b') {
                arr2[i][j] = 1;
            }
            if (z == 'c') {
                arr3[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] +
                prefix_sum[i][j - 1] -
                prefix_sum[i - 1][j - 1] +
                arr[i][j];

            prefix_sum2[i][j] = prefix_sum2[i - 1][j] +
                prefix_sum2[i][j - 1] -
                prefix_sum2[i - 1][j - 1] +
                arr2[i][j];

            prefix_sum3[i][j] = prefix_sum3[i - 1][j] +
                prefix_sum3[i][j - 1] -
                prefix_sum3[i - 1][j - 1] +
                arr3[i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        

        cout << prefix_sum[c][d] - prefix_sum[a-1][d] - 
                prefix_sum[c][b-1] + prefix_sum[a-1][b-1] << " ";

        cout << prefix_sum2[c][d] - prefix_sum2[a - 1][d] -
            prefix_sum2[c][b - 1] + prefix_sum2[a - 1][b - 1] << " ";

        cout << prefix_sum3[c][d] - prefix_sum3[a - 1][d] -
            prefix_sum3[c][b - 1] + prefix_sum3[a - 1][b - 1] << " ";
        
        cout << endl;
    }

    /*int m = 0;
    for (int i = 0; i <= a - b; i++) {
        for (int j = 0; j <= a - b; j++) {
            int sum = prefix_sum[i + b][j + b] - prefix_sum[i][j + b] -
                prefix_sum[i + b][j] + prefix_sum[i][j];
            m = max(m, sum);
        }
    }
    cout << m;*/

    // (1, 1) ~ (3, 3) 사이의 합 = 34
    //cout << prefix_sum[3][3] - prefix_sum[0][3] - 
        //    prefix_sum[3][0] + prefix_sum[0][0] << endl;
    // (1, 2) ~ (3, 2) 사이의 합 = 13
    //cout << prefix_sum[3][2] - prefix_sum[0][2] - 
      //      prefix_sum[3][1] + prefix_sum[0][1] << endl;
    return 0;
}