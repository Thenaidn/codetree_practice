#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> time(n + 1, 0);  // 작업별 걸리는 시간
    vector<int> in_degree(n + 1, 0);  // 각 작업의 선행 작업 개수
    vector<vector<int>> graph(n + 1);  // 각 작업의 선행 작업 목록
    vector<int> result_time(n + 1, 0);  // 각 작업이 끝나는 시간

    // 각 작업에 대한 정보 입력
    for (int i = 1; i <= n; ++i) {
        int t, m;
        m = 0;
        cin >> t;
        time[i] = t;
        in_degree[i] = m;

        // 선행 작업들 입력
        int pre_task;
        cin >> pre_task;
        while(pre_task != -1){
            graph[pre_task].push_back(i);  // 선행 작업 -> 현재 작업
            in_degree[i] = ++m;
            cin >> pre_task;
        }

    }

    // 위상 정렬을 위한 큐
    queue<int> q;

    // 처음 시작할 수 있는 작업들은 진입 차수가 0인 작업들
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
            result_time[i] = time[i];  // 선행 작업이 없으면 바로 시작
        }
    }

    // 위상 정렬 시작
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // 현재 작업이 끝난 후 해당 작업에 의존하는 작업들 처리
        for (int next : graph[current]) {
            in_degree[next]--;

            // 선행 작업들이 모두 끝났으면
            if (in_degree[next] == 0) {
                q.push(next);
            }

            // 현재 작업이 끝난 시간 + 현재 작업의 시간을 더해준다
            result_time[next] = max(result_time[next], result_time[current] + time[next]);
        }
    }

    // 모든 작업이 끝나는 최소 시간 출력
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        cout << result_time[i] << endl;
    }

    //cout << answer << endl;

    return 0;
}
