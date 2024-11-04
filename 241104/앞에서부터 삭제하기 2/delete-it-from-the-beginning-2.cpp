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
priority_queue<int> pq;

vector<int> v;
int main() {
    float res = 0;
    cin >> n;
    //priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    for (int i = 1; i < n - 2; i++) {
        priority_queue<int, vector<int>, greater<int>> pq;
        float sum = 0;
        for (int j = i; j < n; j++) {
            pq.push(v[j]);
            sum += v[j];

            if (j == n - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        res = max(res, sum / pq.size());
    }

    printf("%.2f", res);

    return 0;
}