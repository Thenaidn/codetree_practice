#include <iostream>
#include <vector>
using namespace std;

// 후위 순회를 구하는 재귀 함수
void postOrderTraversal(const vector<int>& preorder, int start, int end, vector<int>& postOrder) {
    if (start > end) {
        return;
    }

    int root = preorder[start]; // 루트 노드
    int split = start + 1;

    // 왼쪽 서브트리의 끝을 찾음
    while (split <= end && preorder[split] < root) {
        split++;
    }

    // 왼쪽 서브트리 탐색
    postOrderTraversal(preorder, start + 1, split - 1, postOrder);
    // 오른쪽 서브트리 탐색
    postOrderTraversal(preorder, split, end, postOrder);

    // 루트를 결과에 추가
    postOrder.push_back(root);
}

int main() {
    // 입력 처리
    int n;
    cin >> n;
    vector<int> preorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    // 후위 순회 결과를 저장할 벡터
    vector<int> postOrder;

    // 후위 순회 계산
    postOrderTraversal(preorder, 0, n - 1, postOrder);

    // 결과 출력
    for (int value : postOrder) {
        cout << value << "\n";
    }

    return 0;
}
