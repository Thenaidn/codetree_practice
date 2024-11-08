#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        auto left = lower_bound(points.begin(), points.end(), a);
        auto right = upper_bound(points.begin(), points.end(), b);
        
        int count = right - left;
        cout << count << endl;
    }

    return 0;
}