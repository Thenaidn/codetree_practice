#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define MAXN 100001

int n, m; // 조각의 수와 조립 방법 수
vector<int> edges[MAXN]; // 인접 리스트로 조립 방법 저장
int indegree[MAXN] = {0}; // 각 조각의 진입 차수
set<int> available_pieces; // 현재 사용할 수 있는 조각

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, k;
        cin >> a >> k; // 만들 조각 번호와 필요한 조각 수
        for (int j = 0; j < k; j++) {
            int piece;
            cin >> piece;
            edges[piece].push_back(a); // 조립 방법 저장
            indegree[a]++; // 진입 차수 증가
        }
    }

    int current_piece_count;
    cin >> current_piece_count;

    queue<int> q;

    // 초기 보유 조각 처리
    for (int i = 0; i < current_piece_count; i++) {
        int piece;
        cin >> piece;
        available_pieces.insert(piece);
        q.push(piece); // 보유한 조각은 큐에 추가
    }

    set<int> result = available_pieces;

    // 위상 정렬 BFS
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : edges[current]) {
            indegree[next]--;
            if (indegree[next] == 0) { // 모든 선행 조건 충족
                if (result.find(next) == result.end()) { // 중복 방지
                    result.insert(next);
                    q.push(next);
                }
            }
        }
    }

    // 결과 출력
    cout << result.size() << "\n";
    for (int piece : result) {
        cout << piece << " ";
    }

    return 0;
}
