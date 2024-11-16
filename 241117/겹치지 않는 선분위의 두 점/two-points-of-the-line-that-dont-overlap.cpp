#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(const vector<pair<int, int>>& segments, int n, int d) {
    int count = 0;
    int last_position = -1e9;

    for (const auto& segment : segments) {
        int start = max(segment.first, last_position + d);
        while (start <= segment.second) {
            count++;
            last_position = start;
            start += d;
            if (count >= n) return true;
        }
    }

    return count >= n;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> segments(m);
    for (int i = 0; i < m; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    sort(segments.begin(), segments.end());

    int left = 1;
    int right = 1e9;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(segments, n, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}
