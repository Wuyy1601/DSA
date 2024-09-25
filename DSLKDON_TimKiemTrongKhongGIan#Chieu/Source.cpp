#include <iostream>
#include <cmath>

using namespace std;
struct Node {
    float x, y, z;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
};

void CreateList(LinkedList& list) {
    list.head = list.tail = nullptr;
}

Node* CreateNode(float x, float y, float z) {
    Node* node = new Node;
    node->x = x;
    node->y = y;
    node->z = z;
    node->next = nullptr;
    return node;
}

void AddTail(LinkedList& list, float x, float y, float z) {
    Node* node = CreateNode(x, y, z);
    if (list.head == nullptr) {
        list.head = list.tail = node;
    }
    else {
        list.tail->next = node;
        list.tail = node;
    }
}

int Search(LinkedList& list, float x, float y, float z) {
    Node* current = list.head;
    int index = 0;
    while (current != nullptr) {
        if (fabs(current->x - x) < 1e-6 && fabs(current->y - y) < 1e-6 && fabs(current->z - z) < 1e-6) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void run() {
    LinkedList list;
    CreateList(list);

    int n, m;
    float x, y, z;


    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        AddTail(list, x, y, z);
    }


    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        int result = Search(list, x, y, z);
        if (result == -1) {
            cout << "KHONG" << endl;
        }
        else {
            cout << result << endl;
        }
    }

    Node* current = list.head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
int main() {

	int* a = new int[256];
	int* b = new int[256];
	delete[] a;
	run();
	delete[] b;
}