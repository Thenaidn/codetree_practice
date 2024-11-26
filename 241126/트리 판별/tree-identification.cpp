#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
vector<pair<int, int>> edges;
bool haveline[10001] = { false, };
set<int> mayberoot;
set<int> notroot;
bool visited[10001] = { false, };
map<int, int> points;

int res = 0;
void bfs(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        res++;
        int front = q.front();
        visited[front] = true;
        q.pop();

        for (pair<int, int> i : edges) {
            if (i.first == front && !visited[i.second]) { q.push(i.second); }
            if (i.second == front && !visited[i.first]) { q.push(i.first); }
        }
    }
}

int main() {
    bool istree = true;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (points.find(a) == points.end()) { points[a] = 1; }
        else { points[a]++; }
        if (points.find(b) == points.end()) { points[b] = 1; }
        else { points[b]++; }
        
        edges.push_back({ a,b });
        if (haveline[b]) { istree = false; }
        haveline[b] = true;
    }

    int haveroot = 0;
    for (pair<int, int> i : points) {
        if (i.second == 1) {
            bfs(i.first);
            if (res == points.size()) { haveroot++; }
            res = 0;
            for (int j = 0; j < 10001; j++) { visited[j] = false; }
        }
    }
    if (haveroot < 1) { istree = false; }
    if (istree) { cout << 1; }
    else { cout << 0; }
    return 0;
}