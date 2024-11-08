#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int a,b,c,d,e;
int main() {
    int arr[1001][1001];
    int prefix_sum[1001][1001] = {};
    cin >> a >> b;

    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= a; j++)
            cin >> arr[i][j];

    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= a; j++)
            prefix_sum[i][j] = prefix_sum[i - 1][j] + 
                               prefix_sum[i][j - 1] -
                               prefix_sum[i - 1][j - 1] +
                               arr[i][j];

    int m = INT_MIN;

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= a; j++){
            for(int k=1; k<=a;k++){
                if(i-k>=0&&j-k>=0){
                    m = max(m, prefix_sum[i][j] - 
                    prefix_sum[i][j-k] - prefix_sum[i-k][j] + prefix_sum[i-k][j-k]);
                }
                else if(j-k>=0){
                    m = max(m, prefix_sum[i][j] - prefix_sum[i][j-k]);
                }
                else if(i-k>=0){
                    m = max(m, prefix_sum[i][j] - prefix_sum[i-k][j]);
                }
            }
        }
    }
    cout << m;
    return 0;
}