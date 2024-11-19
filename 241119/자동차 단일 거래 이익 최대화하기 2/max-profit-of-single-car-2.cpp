#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int arr[100000];
    int n; cin >> n;
    int res = 0;
    for(int i=0;i<n;i++){cin >> arr[i];}
    int ma = arr[0]; int mi = arr[0];
    for(int i=1;i<n;i++){
        int revenue = arr[i] - mi;
        res = max(res, revenue);
        mi = min(mi, arr[i]);
    }
    cout << res;
    return 0;
}