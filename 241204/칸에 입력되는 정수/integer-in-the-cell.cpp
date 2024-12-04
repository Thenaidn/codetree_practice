#include <iostream>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, m;

// 번호별 그룹을 관리합니다.
// uf[i] : i번 보다 작거나 같은 위치 중에 값이 들어갈 수 있는 최대 위치를 의미합니다.
int uf[MAX_N + 1];

// x의 대표 번호를 찾아줍니다.
int Find(int x) {
    // x가 루트 노드라면 x값을 반환합니다.
    if(uf[x] == x)
        return x;
    // x가 루트 노드가 아니라면
    // x의 부모인 uf[x]에서 탐색을 더 진행한 뒤
    // 찾아낸 루트 노드를 uf[x]에 넣어줌과 동시에
    // 해당 노드값을 반환합니다.
    return uf[x] = Find(uf[x]);
}

int main() {
    // 입력:
    cin >> n;
    cin >> m;

    // 초기 uf 값을 설정합니다.
    for(int i = 1; i <= n; i++)
        uf[i] = i;

    // m개의 정보를 입력받습니다. x번 보다 작거나 같은 위치에 값이 들어갈 수 있는지 확인합니다.
    int ans = m;
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        // x번보다 작거나 같은 위치 중에 값이 들어갈 수 있는 최대 위치로 이동합니다.
        int X = Find(x);
        if(X == 0) {
            // 그런 값이 없다면 공을 넣을 수 없습니다.
            ans = i - 1;
            break;
        }

        // X번보다 작은 위치 중에 값이 들어갈 수 있는 최대 위치로 이동합니다.
        int Y = Find(X - 1);
        uf[X] = Y;
    }

    cout << ans;
    return 0;
}