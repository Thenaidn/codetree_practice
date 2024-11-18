#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


bool isPossible(const vector<int>& times, int m, long long maxLoad) {
    int lanes = 1;
    long long currentLoad = 0;

    for (int time : times) {
        if (time > maxLoad) { return false; }
        if (currentLoad + time <= maxLoad) {
            currentLoad += time;
        }
        else {
            lanes++;
            currentLoad = time;
            if (lanes > m) return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    long long left = 1;
    long long right = 144000000;
    long long result = right;


    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (isPossible(times, m, mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result;
    return 0;
}
