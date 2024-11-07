#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int arr[501][501] = {0};
    int prefix_sum[501][501] = {};

    int a,b; cin >> a >> b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= a; j++)
            prefix_sum[i][j] = prefix_sum[i - 1][j] + 
                               prefix_sum[i][j - 1] -
                               prefix_sum[i - 1][j - 1] +
                               arr[i][j];
    int m=0;
    for(int i=0;i<a-b;i++){
        for(int j=0;j<a-b;j++){
            int sum = prefix_sum[i+b][j+b]-prefix_sum[i][j+b]-
            prefix_sum[i+b][j]+prefix_sum[i][j];
            m = max(m,sum);
        }
    }
    cout << m;
    // (1, 1) ~ (3, 3) 사이의 합 = 34
    //cout << prefix_sum[3][3] - prefix_sum[0][3] - 
        //    prefix_sum[3][0] + prefix_sum[0][0] << endl;
    // (1, 2) ~ (3, 2) 사이의 합 = 13
    //cout << prefix_sum[3][2] - prefix_sum[0][2] - 
      //      prefix_sum[3][1] + prefix_sum[0][1] << endl;
    return 0;
}