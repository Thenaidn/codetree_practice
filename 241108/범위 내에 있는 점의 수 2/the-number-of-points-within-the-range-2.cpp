#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int arr[100001] = { 0 };
    vector<int> v;
    int n, q;
    cin >> n >> q;
    int p = 0;
    int afds;

    for (int i = 0; i < n; i++) {
        cin >> afds;
        for (int i = afds; i < 100001; i++) { arr[i]++; }
        //v.push_back(arr[i]);
    }
    //sort(v.begin(), v.end());

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}