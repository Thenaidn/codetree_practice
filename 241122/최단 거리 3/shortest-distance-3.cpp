#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 1000

using namespace std;

// 변수 선언
int n, m;
int a, b;
int graph[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];

int dist[MAX_N + 1];

int main() {
    // 입력
    cin >> n >> m;

    // 그래프를 인접행렬로 표현
    // 양방향 그래프이므로 양쪽 다 표시해줍니다.
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = z;
        graph[y][x] = z;
    }

    cin >> a >> b;

    // 그래프에 있는 모든 노드들에 대해
    // 초기값을 전부 아주 큰 값으로 설정
    // INT_MAX 그 자체로 설정하면
    // 후에 덧셈 진행시 overflow가 발생할 수도 있으므로
    // 적당히 큰 숫자로 적어줘야함에 유의!
    for (int i = 1; i <= n; i++)
        dist[i] = (int)1e9;

    // 시작위치에는 dist값을 0으로 설정
    dist[b] = 0;

    // O(|V|^2) 다익스트라 코드
    for (int i = 1; i <= n; i++) {
        // V개의 정점 중 
        // 아직 방문하지 않은 정점 중
        // dist값이 가장 작은 정점을 찾아줍니다.
        int min_index = -1;
        for (int j = 1; j <= n; j++) {
            if (visited[j])
                continue;

            if (min_index == -1 || dist[min_index] > dist[j])
                min_index = j;
        }

        // 최솟값에 해당하는 정점에 방문 표시를 진행합니다.
        visited[min_index] = true;

        // 최솟값에 해당하는 정점에 연결된 간선들을 보며
        // 시작점으로부터의 최단거리 값을 갱신해줍니다.
        for (int j = 1; j <= n; j++) {
            // 간선이 존재하지 않는 경우에는 넘어갑니다.
            if (graph[min_index][j] == 0)
                continue;

            if (dist[j] > dist[min_index] + graph[min_index][j])
                dist[j] = dist[min_index] + graph[min_index][j];
        }
    }

    // 정점 B에서 정점 A로 가기 위한 최단거리를 출력합니다.
    cout << dist[a] << endl;

    // 도착지 A에서 시작하여
    // 시작점 B가 나오기 전까지
    // 최단거리를 만족하는 경로 중
    // 가장 간선 번호가 작은 곳으로 이동합니다.
    //int x = a;
    //cout << x << " ";
    //while (x != b) {
    //    for (int i = 1; i <= n; i++) {
    //        // 간선이 존재하지 않는 경우에는 넘어갑니다.
    //        if (graph[i][x] == 0)
    //            continue;

    //        // 만약 b -> ... -> i -> x ... -> a로 
    //        // 실제 최단거리가 나올 수 있는 상황이었다면
    //        // i를 작은 번호부터 보고 있으므로
    //        // 바로 선택해줍니다.
    //        if (dist[i] + graph[i][x] == dist[x]) {
    //            x = i;
    //            break;
    //        }
    //    }
    //    cout << x << " ";
    //}
    return 0;
}