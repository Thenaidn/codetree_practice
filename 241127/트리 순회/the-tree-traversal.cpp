#include <iostream>
#include <map>
#include <queue>
using namespace std;

map<char, int> m;
char tree[10000] = { '.', };
int cnt = 0;

void preorder(int n) {
    if (tree[n] < 'A' || tree[n] > 'Z') return; // 유효하지 않은 노드면 리턴
    cout << tree[n]; // 루트
    preorder(n * 2); // 왼쪽
    preorder(n * 2 + 1); // 오른쪽
}

void inorder(int n) {
    if (tree[n] < 'A' || tree[n] > 'Z') return;
    inorder(n * 2); // 왼쪽
    cout << tree[n]; // 루트
    inorder(n * 2 + 1); // 오른쪽
}

void postorder(int n) {
    if (tree[n] < 'A' || tree[n] > 'Z') return;
    postorder(n * 2); // 왼쪽
    postorder(n * 2 + 1); // 오른쪽
    cout << tree[n]; // 루트
}

int main() {
    // 여기에 코드를 작성해주세요.


    int n; cin >> n;
    map<char, pair<char, char>> ma;
    for (int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        ma.insert({ a,{b,c} });
    }
    tree[1] = 'A'; m['A'] = 1;

    
    queue<char> q; q.push('A');
    while (!q.empty()) {
        char next = q.front(); q.pop();
        char b, c;
        b = ma[next].first; c = ma[next].second;
        int tmp = m[next];
        if (b >= 'A' && b <= 'Z') {
            tree[tmp * 2] = b;
            m[b] = tmp * 2;
            q.push(b);
        }
        if (c >= 'A' && c <= 'Z') {
            tree[tmp * 2 + 1] = c;
            m[c] = tmp * 2 + 1;
            q.push(c);
        }
        
    }

    preorder(1); cout << endl; cnt = 0;
    inorder(1); cout << endl; cnt = 0;
    postorder(1); cout << endl; cnt = 0;

    return 0;
}