#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

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
void connect(Node* s, Node* e) {
    if (nullptr != s)
        s->next = e;
    if (nullptr != e)
        e->prev = s;
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
string t;
unordered_map<int, Node*> Nodes;
int main() {
    int a;
    cin >> n >> m;

    cin >> a;
    Node* tmp = new Node(a); 
    Nodes[a] = tmp;
    Node* head = tmp;
    Node* tmp2 = nullptr;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        tmp2 = new Node(a);
        Nodes[a] = tmp2;
        InsertNext(tmp, tmp2);
        tmp = tmp2;
    }
    connect(tmp2, head);

    for (int i = 0; i < m; i++) {
        cin >> a;
        cout << Nodes[a]->next->data << " " << Nodes[a]->prev->data << endl;
        Pop(Nodes[a]);
    }

    return 0;
}