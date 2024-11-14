#include <iostream>
#include <set>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    set<int> fire;  
    set<int> fighter; 

    for (int i = 0; i < a; i++) {
        int c;
        cin >> c;
        fire.insert(c);
    }


    for (int i = 0; i < b; i++) {
        int c;
        cin >> c;
        fighter.insert(c);
    }

    int res = 0; 


    for (int i : fire) {

        auto it = fighter.lower_bound(i);
        int dist = INT_MAX;

 
        if (it != fighter.end()) {
            dist = abs(i - *it);
        }


        if (it != fighter.begin()) {
            it--;
            dist = min(dist, abs(i - *it));
        }


        res = max(res, dist);
    }


    cout << res;
    return 0;
}
