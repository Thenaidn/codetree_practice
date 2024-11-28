#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// 이진 트리를 나타내는 노드 구조체
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 전위 순회 결과를 바탕으로 이진 검색 트리 생성
Node* buildTree(const vector<int>& preorder, int& index, int min, int max) {
    if (index >= preorder.size()) return nullptr;
    
    int current = preorder[index];
    if (current < min || current > max) return nullptr;

    Node* root = new Node(current);
    index++;
    root->left = buildTree(preorder, index, min, current - 1);
    root->right = buildTree(preorder, index, current + 1, max);

    return root;
}

// 후위 순회 결과 출력
void postOrderTraversal(Node* root) {
    if (!root) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << endl;
}

int main() {
    // 입력
    int n;
    cin >> n; // 전위 순회 결과의 크기
    vector<int> preorder(n);
    for (int i = 0; i < n; ++i) {
        cin >> preorder[i];
    }

    // 트리 생성
    int index = 0;
    Node* root = buildTree(preorder, index, INT_MIN, INT_MAX);

    // 후위 순회 출력
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
