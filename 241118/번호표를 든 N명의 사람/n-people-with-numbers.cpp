#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int n;
using namespace std;
int usng[10000] = { 0, };
bool isPossible(vector<int> points, int m, long long d) {
    long long total = 0;
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        usng[tmp] += points[i];
        if (usng[tmp] > n) {
            if (tmp == d) { return false; }
            usng[tmp] -= points[i]; i--; tmp++;
        }
    }
    for (int i = 0; i < 10000; i++) {
        usng[i] = 0;
    }

    return true;

}

int main() {
    int m;
    cin >> m >> n;

    vector<int> points(m);
    for (int i = 0; i < m; i++) {
        cin >> points[i];
    }
    sort(points.begin(), points.end());


    long long left = 1;
    long long right = n;
    long long result = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;


        if (isPossible(points, m, mid)) {
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
