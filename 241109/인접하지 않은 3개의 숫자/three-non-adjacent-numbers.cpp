#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
int arr[100001];
int L[100001] = {};
int R[100001] = {};
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    L[1] = arr[1];
    for (int i = 2; i <= n; i++)
        L[i] = max(arr[i], L[i - 1]);


    // R 배열을 채워줍니다.
    R[n] = arr[n];
    for (int i = n - 1; i >= 1; i--)
        R[i] = max(R[i + 1], arr[i]);

    int m = INT_MIN;
    for (int i = 3; i <= n - 2; i++) {
        m = max(m, arr[i] + L[i - 2] + R[i + 2]);
    }

    cout << m;
    return 0;
}