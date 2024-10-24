#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

#define MAX_N 1004

int a, b, c, d, e, m, k, n;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int memo[MAX_N] = { -1 };

int Fibbo(int n) {
    if (memo[n] != -1)          // 이미 n번째 값을 구해본 적이 있다면
        return memo[n];        // memo에 적혀있는 값을 반환해줍니다.
    if (n <= 2)                 // n이 2이하인 경우에는 종료 조건이므로 
        memo[n] = 1;           // 해당하는 숫자를 memo에 넣어줍니다.
    else                       // 종료조건이 아닌 경우에는 
        memo[n] = Fibbo(n - 1) + Fibbo(n - 2);  // 점화식을 이용하여 답을 구한 뒤
    // 해당 값을 memo에 저장해줍니다.
    return memo[n];                             // memo 값을 반환합니다.
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < MAX_N; i++) { memo[i] = -1; }
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 2;

    cin >> a;

    cout << Fibbo(a);
    return 0;
}