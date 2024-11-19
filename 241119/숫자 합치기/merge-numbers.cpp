#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n; cin >> n;
    for (int i = 0; i < n; i++) { int a; cin >> a; pq.push(a); }
    int res = 0;
    while (pq.size() > 1) {
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        res += a + b;
        pq.push(a + b);
    }
    cout << res;
    // 여기에 코드를 작성해주세요.
    return 0;
}