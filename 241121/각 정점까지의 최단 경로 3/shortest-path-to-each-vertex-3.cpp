#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 100

using namespace std;

int graph[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];

int dist[MAX_N + 1];

int main() {
    // 정점의 수 : 5, 간선의 수 : 8인 그래프
    int n = 5, m = 8;
    
    // 주어진 간선 정보 (x, y, z)
    //              x -> y로 향하는 간선이 있으며, 가중치는 z 
    vector<tuple<int, int, int> > edges = {
        make_tuple(-1, -1, -1),
        make_tuple(2, 1, 3),
        make_tuple(1, 4, 3),
        make_tuple(4, 2, 1),
        make_tuple(5, 2, 4),
        make_tuple(5, 4, 2),
        make_tuple(4, 3, 2),
        make_tuple(3, 4, 1),
        make_tuple(1, 3, 6)
    };

    cin >> n >> m;
    // 그래프를 인접행렬로 표현
    for(int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        //tie(x, y, z) = edges[i];
        graph[x][y] = z;
    }
    
    // 그래프에 있는 모든 노드들에 대해
    // 초기값을 전부 아주 큰 값으로 설정
    // INT_MAX 그 자체로 설정하면
    // 후에 덧셈 진행시 overflow가 발생할 수도 있으므로
    // 적당히 큰 숫자로 적어줘야함에 유의!
    for(int i = 1; i <= n; i++)
        dist[i] = (int)1e9;

    // 시작위치에는 dist값을 0으로 설정
    // 여기서는 시작위치를 5번으로 가정
    dist[1] = 0;

    // O(|V|^2) 다익스트라 코드
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

        // 최솟값에 해당하는 정점에 연결된 간선들을 보며
        // 시작점으로부터의 최단거리 값을 갱신해줍니다.
        for(int j = 1; j <= n; j++) {
            // 간선이 존재하지 않는 경우에는 넘어갑니다.
            if(graph[min_index][j] == 0)
                continue;

            dist[j] = min(dist[j], dist[min_index] + graph[min_index][j]);
        }
    }

    // 시작점(5번 정점)으로부터 각 지점까지의 최단거리 값을 출력합니다.

    for(int i = 2; i <= n; i++){
        if(dist[i] == (int)1e9){dist[i] = -1;}
         cout << dist[i] << "\n";
    }   

    return 0;
}
