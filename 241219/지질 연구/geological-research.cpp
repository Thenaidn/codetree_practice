#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

// 변수 선언
int n, m;

vector<int> edges[MAX_N + 1];

// 진입차수를 관리합니다.
int indegree[MAX_N + 1];

// pressure[i] : i번 지층의 압력도를 관리합니다.
int pressure[MAX_N + 1];

// max_pressure[i] : i번 지층이 받는 압력 중 최대 압력입니다.
// max_pressure_cnt[i] : i번 지층이 최대 압력으로 받는 지층 개수입니다.
int max_pressure[MAX_N + 1];
int max_pressure_cnt[MAX_N + 1];

// 위상정렬을 위한 큐를 관리합니다.
queue<int> q;

int main() {
    // 입력:
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        // 인접리스트로 관리합니다.
        int x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        indegree[y]++; // 진입차수를 갱신합니다.  
    }

    // 처음 indegree 값이 0인 곳이 시작점이 됩니다.
    // 이 노드들을 queue에 넣어줍니다.
    for(int i = 1; i <= n; i++)
        if(!indegree[i]) {
            q.push(i);
            
            // 아무 압력도 받지 않는 지층입니다.
            // 해당 지층은 압력도가 1입니다.
            pressure[i] = 1;
        }
    
    // 위상정렬을 진행합니다.
    // queue에 원소가 남아있다면 계속 진행합니다.
    while(!q.empty()) {
        // 가장 앞에 있는 원소를 뽑아줍니다.
        int x = q.front();
        q.pop();
        
        // x에서 갈 수 있는 모든 곳을 탐색합니다.
        for(int i = 0; i < (int) edges[x].size(); i++) {
            int y = edges[x][i];

            // y번 압력의 정보를 갱신합니다.
            if(max_pressure[y] < pressure[x]) {
                max_pressure[y] = pressure[x];
                max_pressure_cnt[y] = 1;
            }
            else if(max_pressure[y] == pressure[x]) {
                max_pressure_cnt[y]++;
            }

            // 해당 노드의 indegree를 1만큼 감소시켜줍니다.
            indegree[y]--;

            // 비로소 indegree가 0이 되었다면
            // pressure 정보를 갱신하고
            // queue에 새로 넣어줍니다.
            if(!indegree[y]) {
                if(max_pressure_cnt[y] == 1)
                    pressure[y] = max_pressure[y];
                else
                    pressure[y] = max_pressure[y] + 1;
                
                q.push(y);
            }
        }
    }

    // 모든 지층의 압력도 중에서
    // 가장 큰 값을 출력합니다.
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, pressure[i]);
    
    cout << ans;
    return 0;
}