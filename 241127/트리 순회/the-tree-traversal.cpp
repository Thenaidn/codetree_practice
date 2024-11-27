#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<char, pair<char, char>> tree; // 각 노드와 자식 노드 정보 저장

// 전위 순회 (Preorder)
void preorder(char node) {
    if (node == '.') return; // 유효하지 않은 노드면 리턴
    cout << node;            // 루트
    preorder(tree[node].first);  // 왼쪽 자식
    preorder(tree[node].second); // 오른쪽 자식
}

// 중위 순회 (Inorder)
void inorder(char node) {
    if (node == '.') return;
    inorder(tree[node].first);  // 왼쪽 자식
    cout << node;               // 루트
    inorder(tree[node].second); // 오른쪽 자식
}

// 후위 순회 (Postorder)
void postorder(char node) {
    if (node == '.') return;
    postorder(tree[node].first);  // 왼쪽 자식
    postorder(tree[node].second); // 오른쪽 자식
    cout << node;                 // 루트
}

int main() {
    int n;
    cin >> n;

    // 트리 정보 입력
    for (int i = 0; i < n; i++) {
        char node, left, right;
        cin >> node >> left >> right;
        tree[node] = { left, right };
    }

    // 순회 결과 출력
    preorder('A'); cout << endl; // 루트는 항상 'A'
    inorder('A'); cout << endl;
    postorder('A'); cout << endl;

    return 0;
}
