#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>

using namespace std;

int a, b, c, d, e, n, m, k;

priority_queue<int, vector<int>, greater<int>> q;
priority_queue<int, vector<int>, greater<int>> q2;

bool IsPossible(int mid, priority_queue<int, vector<int>, greater<int>> q2) {

    for (int i = 0; i < k; i++) {
        if (q2.empty()) { return true; }
        int first = q2.top();
        q2.pop();
        while (!q2.empty() && q2.top() <= first + mid + mid) {
            q2.pop();
        }
    }
    return q2.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a;
        q.push(a);
    }
    q2 = priority_queue<int, vector<int>, greater<int>>(q);

    int left = 1;
    int right = 500000000;
    int ans = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (IsPossible(mid, q2)) {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else {
            left = mid + 1;
        }
        q2 = priority_queue<int, vector<int>, greater<int>>(q);
    }

    cout << ans;

    return 0;
}
