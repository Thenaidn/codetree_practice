#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define MAX_N 1000

using namespace std;

// 변수 선언
int n, m;

map<string, int> string_to_node;
string nodes[MAX_N + 1];

vector<int> edges[MAX_N + 1];

vector<int> root;
vector<int> child[MAX_N + 1];

// 진입차수를 관리합니다.
int indegree[MAX_N + 1];

// 위상정렬을 위한 큐를 관리합니다.
queue<int> q;

int main() {
    // 입력:
    cin >> n;

    // 각 노드의 이름을 입력받습니다.
    // 처음부터 노드의 이름 순으로 정렬해
    // 노드의 번호를 매겨주면 구현이 쉽습니다.
    for(int i = 1; i <= n; i++)
        cin >> nodes[i];

    sort(nodes + 1, nodes + n + 1);
    for(int i = 1; i <= n; i++)
        string_to_node[nodes[i]] = i;

    cin >> m;
    // 인접리스트로 관리합니다.
    for(int i = 1; i <= m; i++) {
        string x_str, y_str;
        cin >> x_str >> y_str;

        int x, y;
        x = string_to_node[x_str];
        y = string_to_node[y_str];

        edges[y].push_back(x); 
        indegree[x]++; // 진입차수를 갱신합니다.  
    }

    // 처음 indegree 값이 0인 곳이 루트가 됩니다.
    // 이 노드들을 queue에 넣어주고, 정답으로 미리 저장해 놓습니다.
    for(int i = 1; i <= n; i++)
        if(!indegree[i]) {
            q.push(i);

            // indegree가 0인 지점들이 각 트리에서의 루트가 됩니다.
            root.push_back(i);
        }
    
    // 위상정렬을 진행합니다.
    // queue에 원소가 남아있다면 계속 진행합니다.
    while(!q.empty()) {
        // 가장 앞에 있는 원소를 뽑아줍니다.
        int x = q.front();
        q.pop();

        // x에서 갈 수 있는 모든 곳을 탐색합니다.
        for(int i = 0; i < (int) edges[x].size(); i++) {
            int y = edges[x][i];

            // 해당 노드의 indegree를 1만큼 감소시켜줍니다.
            indegree[y]--;

            // 비로소 indegree가 0이 되었다면
            // 해당 노드는 x노드의 바로 자식노드입니다.
            // queue에 새로 넣어주고, 자식노드 정보를 갱신합니다.
            if(!indegree[y]) {
                q.push(y);

                // 0이 되는 순간에 이용한 간선들이
                // 결국 트리에서의 실제 간선이 됩니다. 
                child[x].push_back(y);
            }
        }
    }

    // 자식 노드들을 이름 순으로 정렬합니다.
    for(int i = 1; i <= n; i++)
        sort(child[i].begin(), child[i].end());

    // 정답을 순서대로 출력합니다.
    cout << root.size() << endl;
    for(int i = 0; i < root.size(); i++)
        cout << nodes[root[i]] << " ";

    cout << endl;
    for(int i = 1; i <= n; i++) {
        cout << nodes[i] << " ";
        cout << (int) child[i].size() << " ";
        for(int j = 0; j < child[i].size(); j++) {
            int x = child[i][j];
            cout << nodes[x] << " ";
        }
        cout << endl;
    }
    return 0;
}