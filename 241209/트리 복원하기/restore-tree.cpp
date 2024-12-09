#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 500

using namespace std;

// 변수 선언
int n, m;
int graph[MAX_N + 1][MAX_N + 1];

int dist[MAX_N + 1];

// Prim 진행시 각 노드가 MST에 연결되기 위해
// 어느 노드에 연결하는 것이 최선인지를 관리합니다.
int dist_from[MAX_N + 1];
bool visited[MAX_N + 1];

vector<tuple<int, int, int> > mst_edges;

int main() {
    // 입력
    cin >> n;

    // 그래프의 인접 행렬을 입력받습니다.
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> graph[i][j];

    // 그래프에 있는 모든 노드들에 대해
    // 초기값을 전부 아주 큰 값으로 설정
    // INT_MAX 그 자체로 설정하면
    // 후에 덧셈 진행시 overflow가 발생할 수도 있으므로
    // 적당히 큰 숫자로 적어줘야함에 유의!
    for(int i = 1; i <= n; i++)
        dist[i] = (int)1e9;

    // 시작위치에는 dist값을 0으로 설정
    dist[1] = 0;

    // O(|V|^2) 프림 코드
    for(int i = 1; i <= n; i++) {
        // V개의 정점 중 
        // 아직 방문하지 않은 정점 중
        // dist값이 가장 작은 정점을 찾아줍니다.
        int min_index = -1;
        for(int j = 1; j <= n; j++) {
            if(visited[j])
                continue;
            
            if(min_index == -1 || dist[min_index] > dist[j])
                min_index = j;
        }

        // 최솟값에 해당하는 정점에 방문 표시를 진행합니다.
        visited[min_index] = true;

        // mst에 해당하는 간선들을 저장합니다.
        if(min_index != 1)
            mst_edges.push_back(make_tuple(
                min(min_index, dist_from[min_index]), 
                max(min_index, dist_from[min_index]), 
                dist[min_index]
            ));

        // 최솟값에 해당하는 정점에 연결된 간선들을 보며
        // 시작점으로부터의 최솟값을 갱신해줍니다.
        for(int j = 1; j <= n; j++) {
            // 간선이 존재하지 않는 경우에는 넘어갑니다.
            if(graph[min_index][j] == 0)
                continue;

            // j번 노드로부터 가장 가까운 간선과
            // 그 간선의 정보들을 저장합니다.
            if(dist[j] > graph[min_index][j]) {
                dist[j] = graph[min_index][j];
                // j번 정점이 새로 MST에 들어오기 위해서는 
                // min_index 정점과 연결되는 것이 최선임을 표시해줍니다.
                dist_from[j] = min_index;
            }
        }
    }

    // mst에 해당하는 간선들을 사전 순으로 정렬합니다.
    sort(mst_edges.begin(), mst_edges.end());

    for(int i = 0; i < (int) mst_edges.size(); i++) {
        int a, b, w;
        tie(a, b, w) = mst_edges[i];

        cout << a << " " << b << " " << w << endl;
    }
    
    return 0;
}