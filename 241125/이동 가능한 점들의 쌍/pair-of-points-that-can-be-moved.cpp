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
    int p,q; cin >> p >> q;


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
        
            dist[x][y] = z;
        
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }


    int res = 0;
    long long sum = 0;
    for(int i=0;i<q;i++){
        int a, b; cin >> a >> b;
        bool exist = false;
        int mi = (int)1e9;
        for(int j=1;j<=p;j++){
            if(dist[a][j] < (int)1e9 && dist[j][b] < (int)1e9){
                exist = true;
                mi = min(mi, dist[a][j] + dist[j][b]);
            }
        }
        if(exist){res++; sum += mi;}
    }
    cout << res << endl << sum;

    return 0;
}
