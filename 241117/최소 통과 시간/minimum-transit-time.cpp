#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isPossible(vector<int> points, int n, int d) {
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

    
    int left = 1; 
    long long right = points[m - 1] * n;
    int result = INT_MAX;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (isPossible(points, n, mid)) {
            result = min(result, mid);
            right = mid - 1;
          
        }
        else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
