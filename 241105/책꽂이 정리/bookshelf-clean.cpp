#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

vector<Node*> heads(101, nullptr), tails(101, nullptr);

void InsertNext(Node* u, Node* singleton, int i) {
    singleton->prev = u;
    singleton->next = u->next;
    if (singleton->next) singleton->next->prev = singleton;
    u->next = singleton;
    if (!singleton->next) tails[i] = singleton;
}

void InsertPrev(Node* u, Node* singleton, int i) {
    singleton->next = u;
    singleton->prev = u->prev;
    if (singleton->prev) singleton->prev->next = singleton;
    u->prev = singleton;
    if (!singleton->prev) heads[i] = singleton;
}

void Pop(Node* u, int i) {
    if (u->prev) u->prev->next = u->next;
    else heads[i] = u->next;
    if (u->next) u->next->prev = u->prev;
    else tails[i] = u->prev;
    u->prev = u->next = nullptr;
}

void MoveAllToFront(int src, int dest) {
    if (!heads[src]) return;
    if (!heads[dest]) {
        heads[dest] = heads[src];
        tails[dest] = tails[src];
    }
    else {
        tails[src]->next = heads[dest];
        heads[dest]->prev = tails[src];
        heads[dest] = heads[src];
    }
    heads[src] = tails[src] = nullptr;
}

void MoveAllToBack(int src, int dest) {
    if (!heads[src]) return;
    if (!tails[dest]) {
        heads[dest] = heads[src];
        tails[dest] = tails[src];
    }
    else {
        tails[dest]->next = heads[src];
        heads[src]->prev = tails[dest];
        tails[dest] = tails[src];
    }
    heads[src] = tails[src] = nullptr;
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    Node* current = new Node(1);
    heads[1] = tails[1] = current;

    for (int i = 2; i <= n; i++) {
        Node* tmp = new Node(i);
        InsertNext(tails[1], tmp, 1);
        tails[1] = tmp;
    }

    for (int i = 0; i < q; i++) {
        int op, src, dest;
        cin >> op >> src >> dest;
        if (op == 1) {
            if (heads[src]) {
                Node* d = heads[src];
                Pop(d, src);
                if (!heads[dest]) {
                    heads[dest] = tails[dest] = d;
                }
                else {
                    InsertNext(tails[dest], d, dest);
                    tails[dest] = d;
                }
            }
        }
        else if (op == 2) {
            if (tails[src]) {
                Node* d = tails[src];
                Pop(d, src);
                if (!heads[dest]) {
                    heads[dest] = tails[dest] = d;
                }
                else {
                    InsertPrev(heads[dest], d, dest);
                    heads[dest] = d;
                }
            }
        }
        else if (op == 3) {
            if (src != dest) MoveAllToFront(src, dest);
        }
        else if (op == 4) {
            if (src != dest) MoveAllToBack(src, dest);
        }
    }

    for (int i = 1; i <= k; i++) {
        int count = 0;
        vector<int> books;
        Node* current = heads[i];
        while (current) {
            books.push_back(current->data);
            count++;
            current = current->next;
        }
        cout << count;
        for (int book : books) cout << " " << book;
        cout << endl;
    }

    return 0;
}