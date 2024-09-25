#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head, * tail;
};

struct Hashtable {
    int M; // Kích thước bảng băm
    int n; // Số phần tử trong bảng băm
    List* table;
};

void CreateList(List& l) {
    l.head = l.tail = nullptr;
}

Node* CreateNode(int data) {
    Node* p = new Node;
    if (p == nullptr)
        exit(1);
    p->next = nullptr;
    p->data = data;
    return p;
}

void AddTail(List& l, int data) {
    Node* p = CreateNode(data);
    if (l.head == nullptr)
        l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void CreateHashtable(Hashtable& ht, int m) {
    ht.table = new List[m];
    for (int i = 0; i < m; i++)
        CreateList(ht.table[i]);
    ht.M = m;
    ht.n = 0;
}

int Hash(Hashtable ht, int maso) {
    return maso % ht.M;
}

int Search(Hashtable ht, int socantim) {
    int index = Hash(ht, socantim);
    int count = 0;
    Node* p = ht.table[index].head;

    while (p != nullptr) {
        if (p->data == socantim) {
            return count;
        }
        p = p->next;
        count++;
    }
    return -1; 
}

void Input(int& data) {
    cin >> data;
}

int main() {
    int m, n, N;
    float LOAD;

    cin >> m >> LOAD >> N;

    Hashtable hashtable;
    CreateHashtable(hashtable, m);

    for (int i = 0; i < N; i++) {
        int data;
        Input(data);

        if ((hashtable.n + 1) / static_cast<float>(hashtable.M) > LOAD) {
            continue;
        }

        AddTail(hashtable.table[Hash(hashtable, data)], data);
        hashtable.n++;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int key;
        Input(key);
        int result = Search(hashtable, key);

        if (result == -1)
            cout << "KHONG" << endl;
        else
            cout << result +1 << endl;
    }

    for (int i = 0; i < hashtable.M; i++) {
        Node* current = hashtable.table[i].head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] hashtable.table;

    return 0;
}
