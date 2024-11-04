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
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        cin >> a;
        pq.push(a);

        
    }

    for (int i = 0; i < m; i++) {
        int tmp = pq.top();
        pq.pop(); pq.push(tmp - 1);
    }

    cout << pq.top() << " ";  // 최댓값을 출력해줍니다.
    return 0;
}