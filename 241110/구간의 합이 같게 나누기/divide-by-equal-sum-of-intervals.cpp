#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
int arr[100001];
long long L[100001] = {};
long long R[100001] = {};
int main() {
    int n; cin >> n;
    //int x, y; cin >> x >> y;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }



    L[1] = arr[1];
    for (int i = 2; i <= n; i++)
        L[i] = L[i - 1] + arr[i];


    // R 배열을 채워줍니다.
    R[n] = arr[n];
    for (int i = n - 1; i >= 1; i--)
        R[i] = R[i + 1] + arr[i];

    long long m = 0;
    for (int i = 2; i <= n - 2; i++) {
        
        if (L[i] == R[i + 1]) {
            int left = 0;
            for (int j = 1; j < i; j++) {
                    if (L[j] == L[i] - L[j]) {
                        left++;
                    }
                
            }
            int right = 0;
            for (int k = i + 1; k <= n - 1; k++) {
                if (L[k] - L[i] == R[k + 1]) {
                    right++;
                }
            }
            m += (left * right);
        }
    }

    cout << m;
    return 0;
}