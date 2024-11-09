#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
pair<int, int> arr[100001];
int L[100001] = {};
int R[100001] = {};
int main() {
    int n; cin >> n;
    int x, y; cin >> x >> y;
    arr[0] = { 0,0 };
    arr[1] = { x,y };
    for (int i = 2; i <= n; i++) {
        int x2, y2; cin >> x2 >> y2;
        arr[i] = { x2,y2 };
    }

    L[1] = 0;
    for (int i = 2; i <= n; i++)
        L[i] = L[i - 1] + abs(arr[i].first - arr[i - 1].first) + abs(arr[i].second - arr[i - 1].second);


    // R 배열을 채워줍니다.
    R[n] = 0;
    for (int i = n - 1; i >= 1; i--)
        R[i] = R[i + 1] + abs(arr[i + 1].first - arr[i].first)+ abs(arr[i + 1].second - arr[i].second);

    int m = INT_MAX;
    for (int i = 2; i < n - 1; i++) {
        m = min(m, L[i - 1] + R[i + 1] + abs(arr[i + 1].first - arr[i - 1].first) + abs(arr[i + 1].second - arr[i - 1].second));
    }

    cout << m;
    return 0;
}