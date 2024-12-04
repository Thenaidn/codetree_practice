#include <iostream>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, m;

// 번호별 그룹을 관리합니다.
int uf[MAX_N + 1];

// 각 그룹별 대응되는 반대팀 그룹을 관리합니다.
int against[MAX_N + 1];

// 모순이 있는지 여부를 저장합니다.
bool is_con = false;

// x의 대표 번호를 찾아줍니다.
int Find(int x) {
    // x가 루트 노드라면 x값을 반환합니다.
    if (uf[x] == x)
        return x;
    // x가 루트 노드가 아니라면
    // x의 부모인 uf[x]에서 탐색을 더 진행한 뒤
    // 찾아낸 루트 노드를 uf[x]에 넣어줌과 동시에
    // 해당 노드값을 반환합니다.
    return uf[x] = Find(uf[x]);
}

// x, y가 같은 집합이 되도록 합니다.
void Union(int x, int y) {
    // x, y의 대표 번호를 찾은 뒤
    // 연결해줍니다.
    int X = Find(x);
    int Y = Find(y);

    uf[X] = Y;
}

// x, y는 반대팀의 집합이 되도록 합니다.
void Beta(int x, int y) {
    // x, y의 대표 번호를 찾은 뒤
    // 서로의 반대 집합으로 연산합니다.
    int X = Find(x);
    int Y = Find(y);

    // 둘이 같은 집합이면 모순입니다.
    if (X == Y) {
        is_con = true;
        return;
    }

    if (against[X])
        Union(against[X], Y);

    if (against[Y])
        Union(against[Y], X);

    // 결합된 X와 Y의 신규 최종 노드번호를 찾고 반대팀으로 저장해줍니다.
    int X2 = Find(X);
    int Y2 = Find(Y);

    against[X2] = Y2;
    against[Y2] = X2;
}

int main() {
    // 입력:
    cin >> n >> m;

    // 초기 uf 값을 설정합니다.
    for (int i = 1; i <= n; i++)
        uf[i] = i;

    // m개의 정보를 입력받습니다. 입력된 각각의 값은 서로 상대팀이 됩니다.
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        Beta(x, y);
    }

    if (is_con) cout << 0;
    else cout << 1;

    return 0;
}