#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 100001

int n, m;
vector<int> edges[MAXN];  
int indegree[MAXN];      
bool has_cycle = false;

int main() {
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b); 
        indegree[b]++;     
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    

    while (!pq.empty()) {
        int node = pq.top();  
        pq.pop();
        result.push_back(node);  


        for (int next : edges[node]) {
            indegree[next]--; 
            if (indegree[next] == 0) {
                pq.push(next);  
            }
        }
    }

    if (result.size() != n) {  
        cout << -1 << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
