#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[50]; 
int deleteNode;
int leafCount = 0;

void countLeaves(int node) {
    if (node == deleteNode) return; // 삭제된 노드는 처리하지 않음

    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == deleteNode)) {
        
        leafCount++;
        return;
    }

    for (int child : tree[node]) {
        countLeaves(child); 
    }
}

int main() {
    int n;
    cin >> n;

    int root = -1;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;

        if (parent == -1) {
            root = i;
        }
        else {
            tree[parent].push_back(i);
        }
    }

    cin >> deleteNode;


    if (root == deleteNode) {
        cout << 0 << endl;
    }
    else {
        countLeaves(root); // 루트부터 리프 노드 계산 시작
        cout << leafCount << endl;
    }

    return 0;
}
