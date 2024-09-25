#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
};

Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void Insert_Node(Node*& head, int node_data)
{
    Node* newNode = createNode(node_data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Xuat(Node* head)
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void SapXepBangCachThayDoiInfo(Node* head)
{

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

    SapXepBangCachThayDoiInfo(head);
    cout << "Danh sach sau khi sap xep tang dan bang cach thay doi info cua Node : ";
    Xuat(head);

    return 0;
}
