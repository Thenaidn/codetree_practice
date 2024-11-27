#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    vector<int> v;
    int n; cin >> n;
    v.push_back(0);
    for (int i = 0; i < pow(2,n) - 1; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    int mid = pow(2, n - 1);
    queue<int> q; q.push(mid);


    cout << v[mid] << endl;
    int qsize = 2;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (n > 1) {
            
            int left = cur - pow(2, n - 2);
            int right = cur + pow(2, n - 2);
            q.push(left);
            q.push(right);
            cout << v[left] << " " << v[right] << " ";
        }
        if (q.size() == qsize) {
            n--; qsize *= 2;
            cout << endl;
        }
    }
    return 0;
}