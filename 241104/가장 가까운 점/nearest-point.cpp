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
    
    cin >> n >> m;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater< tuple<int, int, int>>> pq;
    vector<pair<int, int> > points;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        pq.push({abs(a) + abs(b), a, b});
    }
    

    
    for (int i = 0; i < m; i++) {
        tuple<int, int, int> closest = pq.top();

        int sum, x, y;
        tie(sum, x, y) = closest;
        
        pq.pop();

        pq.push(make_tuple(abs(x + 2) + abs(y + 2), x + 2, y + 2));

    }

    tuple<int, int, int> closest = pq.top();

    int sum, x, y;
    tie(sum, x, y) = closest;

    cout << x << " " << y;

    return 0;
}