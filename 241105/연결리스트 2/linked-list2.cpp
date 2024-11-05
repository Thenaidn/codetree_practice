#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>
#include <set>
using namespace std;

#define MAX_N 100001
#define MOD 1000000007

struct Node {
    // Linked list의 노드에 담을 데이터
    int data;

    // 노드의 prev와 next 노드를 가리키는 포인터
    Node* prev, * next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// 노드 u 뒤에 단일 노드 singleton를 삽입
void InsertNext(Node* u, Node* singleton) {
    // singleton의 prev와 next를 설정
    singleton->prev = u;
    singleton->next = u->next;

    // singleton의 이전 노드의 next와
    //             다음 노드의 prev를 설정
    if (nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if (nullptr != singleton->next)
        singleton->next->prev = singleton;
}

// 노드 u 앞에 단일 노드 singleton를 삽입
void InsertPrev(Node* u, Node* singleton) {
    // singleton의 prev와 next를 설정
    singleton->prev = u->prev;
    singleton->next = u;

    // singleton의 이전 노드의 next와
    //             다음 노드의 prev를 설정
    if (nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if (nullptr != singleton->next)
        singleton->next->prev = singleton;
}

// 연결 리스트에서 노드 u를 삭제
void Pop(Node* u) {
    // u의 이전 노드와 다음 노드를 서로 이어줌
    if (nullptr != u->prev)
        u->prev->next = u->next;
    if (nullptr != u->next)
        u->next->prev = u->prev;

    // 이제, u는 단일 노드가 됨
    u->prev = u->next = nullptr;
}
int n, m;
int a, b, c, d, e;
string t;
unordered_map<int, Node*> Nodes;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> e;
    Node* tmp = new Node(1);
    Nodes[1] = tmp;
    for (int i = 2; i <= e; i++) {
        Node* tmp2 = new Node(i);
        //InsertNext(tmp, tmp2);
        Nodes[i] = tmp2;
    }
    cin >> n;
    Node* cur = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m == 1) {
            cin >> a;
            Pop(Nodes[a]);
        }
        if (m == 2) {
            cin >> a >> b;
            Pop(Nodes[b]);
            InsertPrev(Nodes[a], Nodes[b]);
        }
        if (m == 3) {
            cin >> a >> b;
            Pop(Nodes[b]);
            InsertNext(Nodes[a], Nodes[b]);

        }
        if (m == 4) {
            cin >> a;
            cur = Nodes[a];
            if (nullptr != cur->prev) {
                cout << cur->prev->data << " ";
            }
            else { cout << "0 "; }
            if (nullptr != cur->next) {
                cout << cur->next->data << " ";
            }
            else { cout << "0 "; }
            cout << endl;
        }
    }

    for (int i = 1; i <= e; i++) {
        if (nullptr != Nodes[i]->next) {
            cout << Nodes[i]->next->data << " ";
        }
        else { cout << "0 "; }
    }

    return 0;
}