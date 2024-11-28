#include <iostream>

#define MAX_N 200000

using namespace std;

// 변수 선언
int n;
long long k;
int left_num[MAX_N + 1], right_num[MAX_N + 1];
int ans;

// 트리의 루트 노드에서부터 시작해
// k번째 공이 어느 노드로 내려갈지 DFS로 계산합니다.
void DFS(int x, long long ball_num) {
    // 리프 노드에 도착하면 해당 위치가 답이 됩니다.
    if(left_num[x] == -1 && right_num[x] == -1) {
        ans = x;
        return;
    }

    // 왼쪽 노드가 비어있다면 오른쪽으로 이동합니다.
    if(left_num[x] == -1)
        DFS(right_num[x], ball_num);
    // 오른쪽 노드가 비어있다면 왼쪽으로 이동합니다.
    else if(right_num[x] == -1)
        DFS(left_num[x], ball_num);
    // 홀수 개의 공이 남았다면
    // 왼쪽으로 1개 더 공이 떨어지게 되며
    // 우리는 왼쪽으로 이동해야 합니다.
    else if(ball_num % 2 == 1)
        DFS(left_num[x], (ball_num + 1) / 2);
    // 짝수 개의 공이 남았다면
    // 왼쪽, 오른쪽 공이 동일하게 떨어지게 되며
    // 우리는 오른쪽으로 이동해야 합니다.
    else
        DFS(right_num[x], ball_num / 2);
}

int main() {
    // 입력:
    cin >> n;

    // 각 노드의 왼쪽 자식노드와 오른쪽 자식노드를 입력받습니다.
    for(int i = 1; i <= n; i++)
        cin >> left_num[i] >> right_num[i];

    cin >> k;

    // 트리의 루트 노드에서부터 시작해
    // k번째 공이 어느 노드로 내려갈지 DFS로 계산합니다.
    DFS(1, k);

    // 공이 마지막에 멈추는 노드의 번호를 출력합니다.
    cout << ans;
    return 0;
}