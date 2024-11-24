#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX_N 1005

using namespace std;

// 변수 선언
int dist[MAX_N + 1][MAX_N + 1];

int main() {
    // 정점의 수 : 5, 간선의 수 : 8인 그래프
    int n = 5, m = 8; cin >> n >> m;



    // dist 초기값을 전부 아주 큰 값으로 설정
    // INT_MAX 그 자체로 설정하면
    // 후에 덧셈 진행시 overflow가 발생할 수도 있으므로
    // 적당히 큰 숫자로 적어줘야함에 유의!
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            dist[i][j] = (int)1e9;

        // 자기 자신으로 가는 값은 0으로 설정해줘야 함에 유의합니다.
        dist[i][i] = 0;
    }

    // 그래프를 인접행렬로 표현
    for (int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        //tie(x, y, z) = edges[i];
        if (dist[x][y] > z) {
            dist[x][y] = z;
        }
    }

    for (int k = 1; k <= n; k++) // 확실하게 거쳐갈 정점을 1번부터 N번까지 순서대로 정의합니다.
        for (int i = 1; i <= n; i++) // 고정된 k에 대해 모든 쌍 (i, j)를 살펴봅니다.
            for (int j = 1; j <= n; j++)
                // i에서 j로 가는 거리가 k를 경유해 가는 것이 더 좋다면
                // dist[i][j]값을 갱신해줍니다.
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int res = (int)1e9;
    // 모든 쌍에 대한 최단거리 결과를 출력합니다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp = dist[i][j] + dist[j][i];
            if (tmp != 0) { res = min(res, dist[i][j] + dist[j][i]); }
            
        }

    }
    cout << res;
    return 0;
}
