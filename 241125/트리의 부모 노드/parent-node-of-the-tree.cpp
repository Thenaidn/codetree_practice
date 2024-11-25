#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tree[100001];
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int a, b; cin >> a >> b;
        tree[b] = a;
    }
    for(int i=2;i<=n;i++){
        cout << tree[i] << endl;
    }
    return 0;
}