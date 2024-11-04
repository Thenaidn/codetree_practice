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
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
    }
    while (pq.size() >= 2) {
        b = pq.top();
        pq.pop();
        c = pq.top();
        pq.pop();
        int sub = b - c;
        if (sub != 0) {
            pq.push(sub);
        }
    }

    if (pq.size() == 1) {
        cout << pq.top();
    }
    else { cout << -1; }

    return 0;
}