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

vector<int> v;
int main() {
    float res = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);
        if (pq.size() >= 3) {
            b = pq.top(); pq.pop();
            c = pq.top(); pq.pop();
            d = pq.top(); pq.pop();

            cout << b * c * d << endl;

            pq.push(b);
            pq.push(c);
            pq.push(d);
        }
        else { cout << -1 << endl; }
    }


    //printf("%.2f", res);

    return 0;
}