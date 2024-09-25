#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void Insert_Node(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Xuat(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* search(Node* head, int x) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == x) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void DeleteFirstNode(Node*& head) {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteNode(Node*& head, int x) {
    Node* temp = head;
    Node* prev = nullptr;
    if (temp != nullptr && temp->data == x) {
        head = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) {
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void SapXep(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Node* current = head;
    Node* index = nullptr;
    int temp;
    while (current != nullptr) {
        index = current->next;
        while (index != nullptr) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void insertInOrder(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    int SinglyLinkedListNodeCount;

    cout << "Nhap so luong phan tu cua danh sach: ";
    cin >> SinglyLinkedListNodeCount;

    cout << "Nhap cac phan tu cua danh sach:\n";
    for (int i = 0; i < SinglyLinkedListNodeCount; ++i) {
        int Node_Item;
        cin >> Node_Item;
        Insert_Node(head, Node_Item);
    }

    cout << "Danh sach lien ket: ";
    Xuat(head);

    int choice;
    cout << "Lua chon chuc nang: " << endl;
    cout << "1: Tim kiem phan tu. " << endl;
    cout << "2: Xoa phan tu dau tien." << endl;
    cout << "3: Xoa phan tu x. " << endl;
    cout << "4: Sap xep tang dan." << endl;
    cout << "5: Chen phan tu bat ki." << endl;
    cout << "0: Ket thuc chuong trinh." << endl;
    cin >> choice;
    if (choice == 0) { return 0; }
    while (1 <= choice <= 4)
    {
        if (choice == 1)
        {
            int x;
            cout << "Nhap phan tu can tim kiem: ";
            cin >> x;
            Node* found = search(head, x);
            if (found != nullptr) {
                cout << "Tim thay phan tu " << x << " trong danh sach." << endl;
            }
            else {
                cout << "Khong tim thay phan tu " << x << " trong danh sach." << endl;
            }
        }
        if (choice == 2)
        {
            DeleteFirstNode(head);
            cout << "Danh sach sau khi xoa phan tu dau tien: ";
            Xuat(head);
        }

        if (choice == 3)
        {
            int y;
            cout << "Nhap phan tu can xoa: ";
            cin >> y;
            deleteNode(head, y);
            cout << "Danh sach sau khi xoa phan tu " << y << ": ";
            Xuat(head);
        }

        if (choice == 4)
        {
            SapXep(head);
            cout << "Danh sach sau khi sap xep tang dan: ";
            Xuat(head);
        }

        if (choice == 5)
        {
            int z;
            cout << "Nhap phan tu can chen: ";
            cin >> z;
            insertInOrder(head, z);
            cout << "Danh sach sau khi chen phan tu " << z << ": ";
            Xuat(head);
        }
        cout << "Lua chon chuc nang: " << endl;
        cout << "1: Tim kiem phan tu. " << endl;
        cout << "2: Xoa phan tu dau tien." << endl;
        cout << "3: Xoa phan tu x. " << endl;
        cout << "4: Sap xep tang dan." << endl;
        cout << "5: Chen phan tu bat ki." << endl;
        cout << "0: Ket thuc chuong trinh." << endl;
        cin >> choice;
        if (choice == 0)
        {
            return 0;
        }
    }
    return 0;
}
