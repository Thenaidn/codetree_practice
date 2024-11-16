#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int use[100001] = { INT_MAX, };
bool isPossible(vector<int> points, int n, int m, int d) {
    int count = n; 
    for (int i = 0; i < m; i++) {
        if (points[i] <= d) {
            use[i] = points[i];
            count--;
        }
    }

    while (d > 0) {
        for (int i = 0; i < m; i++) {
            if (use[i] > 0) { use[i]--; }
            if (use[i] == 0 && points[i] <= d) {
                use[i] = points[i];
                count--;
            }
        }


        d--;
    }
    for (int i = 0; i < m; i++) { 
        if (use[i] > 0) { count++; }
        use[i] = INT_MAX; 
    }
       
    return count <= 0;
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
    int right = points[m - 1] * n;
    int result = INT_MAX;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (isPossible(points, n, m, mid)) {
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
