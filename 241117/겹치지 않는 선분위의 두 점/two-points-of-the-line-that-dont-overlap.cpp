#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> points, int m, int d) {
    int count = 1; 
    int last_position = points[0];

    for (int i = 1; i < points.size(); i++) {
        if (points[i] - last_position >= d) {
            count++;
            last_position = points[i];
            if (count >= m) return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> points;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a  >> b;
        for(int j=b;j>=a;j--){
            points.push_back(j);
        }
    }
    sort(points.begin(), points.end());

    
    int left = 1; 
    int right = points[points.size() - 1] - points[0];
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (isPossible(points, n, mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}
