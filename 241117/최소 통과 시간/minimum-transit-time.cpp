#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isPossible(vector<int> points, int n, long long d) {
    long long total = 0;
    for (int time : points) {
        total += d / time;
    }
    return total >= n;

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> points(m);
    for (int i = 0; i < m; i++) {
        cin >> points[i];
    }
    sort(points.begin(), points.end());


    long long left = 1;
    long long right = (long long)points[0] * n;
    long long result = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;


        if (isPossible(points, n, mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

    }

    cout << result << endl;
    return 0;
}
