#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int arr[1001] = { 0 };
    int prefix_sum[1001] = {};

    int arr2[1001] = { 0 };
    int prefix_sum2[1001] = {};

    int arr3[1001] = { 0 };
    int prefix_sum3[1001] = {};

    int a, b, c; cin >> a >> b;
    int z;
    for (int i = 1; i <= a; i++) {
        arr[i] = 0; arr2[i] = 0; arr3[i] = 0;
            cin >> z;
            if (z == 1) {
                arr[i] = 1;
            }
            if (z == 2) {
                arr2[i] = 1;
            }
            if (z == 3) {
                arr3[i] = 1;
            }
            prefix_sum[i] = arr[i] + prefix_sum[i - 1];
            prefix_sum2[i] = arr2[i] + prefix_sum2[i - 1];
            prefix_sum3[i] = arr3[i] + prefix_sum3[i - 1];
    }

    for (int i = 0; i < b; i++) {
        int x, y; cin >> x >> y;
        cout << prefix_sum[y] - prefix_sum[x - 1] << " ";
        cout << prefix_sum2[y] - prefix_sum2[x - 1] << " ";
        cout << prefix_sum3[y] - prefix_sum3[x - 1] << " ";
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