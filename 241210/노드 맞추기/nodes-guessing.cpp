#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;

    unordered_map<string, int> node_to_int; // 노드 이름 -> 숫자 매핑
    vector<string> int_to_node(N);         // 숫자 -> 노드 이름 역매핑

    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        node_to_int[name] = i;   // 이름을 숫자로 매핑
        int_to_node[i] = name;   // 숫자를 이름으로 역매핑
    }

    cin >> M;

    vector<unordered_set<int>> input_g(N); // 그래프 저장
    vector<int> degree(N, 0);              // 진입 차수 저장

    for (int i = 0; i < M; i++) {
        string child, parent;
        cin >> child >> parent;
        int child_id = node_to_int[child];
        int parent_id = node_to_int[parent];
        input_g[parent_id].insert(child_id);
        degree[child_id]++;
    }

    deque<int> Q;
    vector<int> roots;                     // 루트 노드 저장
    vector<set<int>> answer_g(N);          // 결과 트리 저장

    // 진입 차수가 0인 노드 찾기
    for (int i = 0; i < N; i++) {
        if (degree[i] == 0) {
            Q.push_back(i);
            roots.push_back(i);
        }
    }

    // BFS를 사용해 트리 복원
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop_front();
        for (int child : input_g[node]) {
            degree[child]--;
            if (degree[child] == 0) {
                Q.push_back(child);
                answer_g[node].insert(child);
            }
        }
    }

    // 출력
    cout << roots.size() << '\n';
    sort(roots.begin(), roots.end(), [&](int a, int b) { return int_to_node[a] < int_to_node[b]; });
    for (int root : roots) {
        cout << int_to_node[root] << " ";
    }
    cout << '\n';

    for (int i = 0; i < N; i++) {
        cout << int_to_node[i] << " " << answer_g[i].size();
        for (int child : answer_g[i]) {
            cout << " " << int_to_node[child];
        }
        cout << '\n';
    }

    return 0;
}
