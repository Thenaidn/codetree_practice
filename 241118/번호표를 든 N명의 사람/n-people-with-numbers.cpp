#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 10000

using namespace std;

// 변수 선언
int n, t_max;
int d[MAX_N];

// 무대에 올라올 수 있는 최대 인원 수를 
// k라 했을 때
// n명의 사람이 전부 무대를 끝내는 데
// 걸리는 시간을 계산하여
// 이 값이 t_max 이하인지를 확인합니다.
bool IsPossible(int k) {
    // 사람들을 순서대로 무대로 올립니다.
    // 각 사람들의 춤이 끝나는 시간 중
    // 가장 빨리 춤이 끝나는 사람을 
    // 계속 빠르게 구해주기 위해
    // 우선순위 큐를 이용합니다.
    // 단, 최솟값이 먼저 나오게 하기 위해
    // 시간 앞에 -를 붙여 넣어야 함에 유의합니다.
    priority_queue<int> pq;

    // 먼저 k명을 무대에 올리고 시작합니다.
    for(int i = 0; i < k; i++)
        pq.push(-d[i]);

    // 남은 사람들을 무대에 세워줍니다.
    // 이때 각 순간마다
    // 가장 먼저 무대를 끝내고 내려오는 사람을 빼주고
    // 새로 사람을 추가해줘야 합니다.
    for(int i = k; i < n; i++) {
        int curr_time = -pq.top();
        pq.pop();

        // 현재 사람이 무대를 끝내게 되는 
        // 시간을 계산하여 넣어줍니다.
        pq.push(-(curr_time + d[i]));
    }

    // 마지막으로 무대에서 내려오는 사람들 중
    // 가장 늦게 내려오는 사람이 
    // 무대를 끝내는 시간을 구해줍니다.
    int end_time = 0;
    while(!pq.empty()) {
        end_time = max(end_time, -pq.top());
        pq.pop();
    }

    // n명의 사람이 전부 무대를 끝내는 데
    // 걸리는 시간이 t_max 이하라면 가능한 것이므로 true를,
    // 아니라면 불가능한 것이므로 false를 반환합니다.
    return end_time <= t_max;
}

int main() {
    // 입력
    cin >> n >> t_max;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    
    int left = 1;                // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int right = n;               // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    int ans = n;                 // 답을 저장합니다.
    
    while (left <= right) {            // [left, right]가 유효한 구간이면 계속 수행합니다.
        int mid = (left + right) / 2;  // 가운데 위치를 선택합니다.
        if(IsPossible(mid)) {          // 결정문제에 대한 답이 Yes라면
            right = mid - 1;           // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            ans = min(ans, mid);       // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else                               
            left = mid + 1;            // 결정문제에 대한 답이 No라면 left를 바꿔줍니다.
    }

    cout << ans;
    return 0;
}