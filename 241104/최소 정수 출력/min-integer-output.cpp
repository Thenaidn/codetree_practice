#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

int n, m;
int a, b, c, d, e;


string t;



int main() {
    
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a != 0) {
            pq.push(a);
        }
        else {
            if (pq.size() == 0) { cout << 0 << endl; }
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
       

        
    }

    return 0;
}