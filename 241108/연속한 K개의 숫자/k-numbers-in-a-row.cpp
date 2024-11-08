#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[100001] = { 0 };
    int prefix_sum[100001] = { 0 };
    int n, k, b;
    cin >> n >> k >> b;
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
        prefix_sum[i] = i;
        if (i > 1) { prefix_sum[i] += prefix_sum[i - 1]; }
    }
    for (int i = 0; i < b; i++) {
        int a;
        cin >> a;
        arr[a] = 0;
    }

    int m = 1000000;
    for (int i = k; i <= n; i++) {
        int tmp = 0;
        for (int j = i - k + 1; j <= i; j++) {
            if (arr[j] == 0) { tmp++; }
        }
        m = min(m, tmp);
    }
    cout << m;
    return 0;
}