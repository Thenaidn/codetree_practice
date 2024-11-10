#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;
int arr[100001];
int L[100001] = {};
int R[100001] = {};
int main() {
    int n, q; cin >> n >> q;
    //int x, y; cin >> x >> y;
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }



    L[1] = arr[1];
    for (int i = 2; i <= n; i++)
        L[i] = max(L[i - 1], arr[i]);


    // R 배열을 채워줍니다.
    R[n] = arr[n];
    for (int i = n - 1; i >= 1; i--)
        R[i] = max(R[i + 1], arr[i]);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << max(L[a - 1], R[b + 1]) << endl;
    }

    
    return 0;
}