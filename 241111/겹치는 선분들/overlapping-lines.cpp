#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, int> points;  

    int prev = 0; 
    for (int i = 0; i < n; i++) {
        int length;
        char dir;
        cin >> length >> dir;

        int x1, x2;
        if (dir == 'L') {
            x2 = prev;
            prev -= length;
            x1 = prev;
        }
        else {  
            x1 = prev;
            prev += length;
            x2 = prev;
        }

        
        points[x1] += 1;  
        points[x2] -= 1; 
    }

    long long res = 0;
    int sum_val = 0; 
    int prev_pos = 0; 
    for (auto& p : points) {
        int x = p.first;  
        int v = p.second; 

        if (sum_val >= k) {
            res += (x - prev_pos);  
        }

        sum_val += v;  
        prev_pos = x;  
    }

    cout << res << endl;
    return 0;
}