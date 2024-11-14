#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    deque<int> minDeque, maxDeque;
    int left = 0;
    int result = INT_MAX;

    for (int right = 0; right < n; right++) {
        while (!minDeque.empty() && points[minDeque.back()].second >= points[right].second) {
            minDeque.pop_back();
        }
        while (!maxDeque.empty() && points[maxDeque.back()].second <= points[right].second) {
            maxDeque.pop_back();
        }
        minDeque.push_back(right);
        maxDeque.push_back(right);

        while (points[maxDeque.front()].second - points[minDeque.front()].second >= d) {
            result = min(result, points[right].first - points[left].first);
            left++;


            if (minDeque.front() < left) {
                minDeque.pop_front();
            }
            if (maxDeque.front() < left) {
                maxDeque.pop_front();
            }
        }
    }

    // 결과 출력
    if (result == INT_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}
