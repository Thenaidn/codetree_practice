#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n; int res = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }


    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == 0) {
            arr[i] = 1;
            arr[i + 1] = (arr[i + 1] == 0) ? 1 : 0;
            if (i != n - 2) { arr[i + 2] = (arr[i + 2] == 0) ? 1 : 0; }
            res++;
        }
    }
    if (arr[n - 1] == 0) { cout << -1; }
    else { cout << res; }
    // 여기에 코드를 작성해주세요.
    return 0;
}