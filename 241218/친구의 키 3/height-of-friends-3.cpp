#include <iostream>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;
#define MAXN 100001
// 정점 7개, 간선 8개인 그래프
int n = 7, m = 8;

vector<int> edges[MAXN];
bool visited[MAXN];
stack<int> reversed_order;

int cnt = 0;

// DFS 탐색을 진행합니다.
void DFS(int x) {
    cnt++;
    // x에서 갈 수 있는 모든 곳을 탐색합니다.
    // 단, 방문한 적이 없는 경우에만 진행합니다.
    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];

        if(!visited[y]) {
            visited[y] = true;
            DFS(y);
        }
    }

    // 퇴각 직전에
    // 현재 노드 번호를 stack에 넣어줍니다.
    reversed_order.push(x);
}

int main() {

    cin >> n >> m;
    // 인접리스트로 관리합니다.
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        //tie(x, y) = given_edges[i];

        edges[x].push_back(y);   
    }

    // DFS 탐색을 진행합니다.
    // 단, 방문표시가 되지 않은 모든 곳을 시작으로 하여
    // DFS를 진행해야 합니다.
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }
    if(cnt >= n){
        cout << -1;
    }
    else{
        while(!reversed_order.empty()) {
            cout << reversed_order.top() << " ";
            reversed_order.pop();
        }
    }
    
    return 0;
}
