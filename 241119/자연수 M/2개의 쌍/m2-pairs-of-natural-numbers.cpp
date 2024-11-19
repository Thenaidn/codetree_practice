#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<pair<long long, long long>> maxHeap; // (값, 개수)
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> minHeap;

    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;

        maxHeap.push({y, x});
        minHeap.push({y, x});
    }

    long long res = 0;

    while (!maxHeap.empty() && !minHeap.empty()) {
        auto maxTop = maxHeap.top();
        maxHeap.pop();

        auto minTop = minHeap.top();
        minHeap.pop();

        long long maxVal = maxTop.first;
        long long maxCount = maxTop.second;

        long long minVal = minTop.first;
        long long minCount = minTop.second;

        res = max(res, maxVal + minVal);

        long long pairCount = min(maxCount, minCount);


        if (maxCount > pairCount) {
            maxHeap.push({maxVal, maxCount - pairCount});
        }
        if (minCount > pairCount) {
            minHeap.push({minVal, minCount - pairCount});
        }
    }

    cout << res << endl;
    return 0;
}
