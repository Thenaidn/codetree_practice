#include <iostream>
#include <cmath>
using namespace std;

long long countTurns(long long n, long long target) {
    long long left = 1, right = n;
    int turns = 0;

    while (left <= right) {
        turns++;
        long long mid = (left + right) / 2;
        if (mid == target) break;
        else if (mid > target) right = mid - 1;
        else left = mid + 1;
    }
    return turns;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, a, b;
    cin >> n >> a >> b;

    int minTurns = countTurns(n, (a + b) / 2);
    int maxTurns = max(countTurns(n, a), countTurns(n, b)); 

    cout << minTurns << " " << maxTurns;
    return 0;
}
