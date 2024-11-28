#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 후위 순회 결과를 계산하는 재귀 함수
void buildPostOrder(const vector<int>& preorder, const vector<int>& inorder, 
                    int preStart, int preEnd, int inStart, int inEnd, 
                    unordered_map<int, int>& indexMap, vector<int>& postOrder) {
    if (preStart > preEnd || inStart > inEnd) {
        return;
    }

    int root = preorder[preStart];  // 전위 순회에서 루트
    int rootIndex = indexMap[root]; // 중위 순회에서 루트의 위치
    int leftSize = rootIndex - inStart; // 왼쪽 서브트리 크기

    // 왼쪽 서브트리 처리
    buildPostOrder(preorder, inorder, preStart + 1, preStart + leftSize, 
                   inStart, rootIndex - 1, indexMap, postOrder);
    // 오른쪽 서브트리 처리
    buildPostOrder(preorder, inorder, preStart + leftSize + 1, preEnd, 
                   rootIndex + 1, inEnd, indexMap, postOrder);
    // 루트를 후위 순회에 추가
    postOrder.push_back(root);
}

int main() {
    // 입력 처리
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    // 중위 순회 값의 인덱스를 저장
    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; i++) {
        indexMap[inorder[i]] = i;
    }

    // 후위 순회 결과를 저장할 벡터
    vector<int> postOrder;

    // 후위 순회 계산
    buildPostOrder(preorder, inorder, 0, n - 1, 0, n - 1, indexMap, postOrder);

    // 결과 출력
    for (int i = 0; i < postOrder.size(); i++) {
        cout << postOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
