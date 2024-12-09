#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
const int MAXN = 10001;
// 변수 선언
// 정점의 수 : 5, 간선의 수 : 7인 그래프
int n = 5, m = 7;
int graph[MAXN][MAXN];
bool visited[MAXN];

int dist[MAXN];

int main() {
    
    cin >> n >> m;
    // 그래프를 인접행렬로 표현
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = z;
        graph[y][x] = z;
    }
    
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
    int ans = 0;
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

        // mst 값을 갱신해줍니다.
        ans += dist[min_index];

        // 최솟값에 해당하는 정점에 연결된 간선들을 보며
        // 시작점으로부터의 최솟값을 갱신해줍니다.
        for(int j = 1; j <= n; j++) {
            // 간선이 존재하지 않는 경우에는 넘어갑니다.
            if(graph[min_index][j] == 0)
                continue;

            dist[j] = min(dist[j], graph[min_index][j]);
        }
    }

    cout << ans;
    return 0;
}
