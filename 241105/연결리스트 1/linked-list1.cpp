#include <iostream>
#include <string>
using namespace std;

struct Node {
    // Linked list의 노드에 담을 데이터
    string data;
    
    // 노드의 prev와 next 노드를 가리키는 포인터
    Node *prev, *next;
    
    Node(string data) : data(data), prev(nullptr), next(nullptr) {}
};

// 노드 u 뒤에 단일 노드 singleton를 삽입
void InsertNext(Node *u, Node *singleton) {
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
void InsertPrev(Node *u, Node *singleton) {
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
void Pop(Node *u) {
    // u의 이전 노드와 다음 노드를 서로 이어줌
    if (nullptr != u->prev)
        u->prev->next = u->next;
    if (nullptr != u->next)
        u->next->prev = u->prev;

    // 이제, u는 단일 노드가 됨
    u->prev = u->next = nullptr;
}
int n,m;
string t;
int main() {
    // 여기에 코드를 작성해주세요.
    cin >> t;
    Node *cur = new Node(t);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> m;
        if(m==1){
            cin >> t;
            Node *tmp = new Node(t);
            InsertPrev(cur, tmp);
        }
        if(m==2){
            cin >> t;
            Node *tmp = new Node(t);
            InsertNext(cur, tmp);
        }
        if(m==3){
            if (nullptr != cur->prev){
                cur = cur->prev;
            }
        }
        if(m==4){
            if (nullptr != cur->next){
                cur = cur->next;
            }
        }

        if (nullptr != cur->prev){
            cout << cur->prev->data << " ";
        }
        else{cout << "(Null) ";}
        cout << cur->data << " ";
        if (nullptr != cur->next){
            cout << cur->next->data << " ";
        }
        else{cout << "(Null) ";}
        cout << endl;
    } 

    return 0;
}