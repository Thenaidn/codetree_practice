#include <iostream>
#include<string>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int t[100000]; int k; int n;
    int left = 0; int right = 1;
    int in = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) { cin >> t[i]; }
    if (t[0] == 1) { in = 1; }
    int res = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (t[i] == 1) {
            in++;
        }

        if (in >= k) {
            res = min(res, i - left + 1);
            int count = 0;
            left = i;
            in--;
        }

        
    }
    cout << res;
    return 0;
}