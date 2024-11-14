#include <iostream>
#include<string>
#include <set>
using namespace std;

int main() {
    int t[100000]; int k; int n;
    int left = 0; int right = 1;
    int a, b;
    cin >> a >> b;
    set<int> fire;
    set<int> fighter;
    for (int i = 0; i < a; i++) {
        int c; cin >> c;
        fire.insert(c);
    }
    for (int i = 0; i < b; i++) {
        int c; cin >> c;
        fighter.insert(c);
    }
    int res = 0;

    for (int i : fire) {
        auto it = fighter.lower_bound(i);
        int upper = *it; 
        int lower;
        res = max(res, abs(i - upper));
        if (it != fighter.begin()) {
            it--;
            lower = *it;
            res = max(res, abs(i - lower));
        }
    }
    
    
    cout << res;
    return 0;
}