#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[301][301] = {}; int prefix_sum[301][301] = {};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    // prefix_sum 계산하기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix_sum[i][j] = arr[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    int max_sum = INT_MIN;
    
    for (int top = 1; top <= n; top++) {
        for (int bottom = top; bottom <= n; bottom++) {
            
            int current_sum = 0;
            for (int col = 1; col <= n; col++) {
                int sum = prefix_sum[bottom][col] - prefix_sum[top - 1][col];
                current_sum += sum;

                if (current_sum > max_sum) {
                    max_sum = current_sum;
                }
                
                if (current_sum < 0) {
                    current_sum = 0;
                }
            }
        }
    }

    cout << max_sum << endl;
    return 0;
}