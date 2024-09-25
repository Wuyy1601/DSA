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

void SapXepBangCachThayDoiNext(Node*& head)
{

    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Node* Sorted = nullptr;
    while (head != nullptr)
    {
        Node* current = head;
        head = head->next;
        if (Sorted == nullptr || current->data < Sorted->data)
        {
            current->next = Sorted;
            Sorted = current;
        }
        else {
            Node* temp = Sorted;
            while (temp->next != nullptr && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = Sorted;

}



void Noi2DSLK(Node* head, Node* head1)
{
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = head1;
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

    Node* head1 = nullptr;
    int SinglyLinkedListNodeCount1;

    cout << "Nhap so luong phan tu cua danh sach: ";
    cin >> SinglyLinkedListNodeCount1;
    cout << "Nhap cac phan tu cua danh sach:\n";
    for (int i = 0; i < SinglyLinkedListNodeCount1; ++i) {
        int Node_Item;
        cin >> Node_Item;
        Insert_Node(head, Node_Item);
    }

    cout << "Danh sach lien ket: ";
    Xuat(head);

    SapXepBangCachThayDoiNext(head);
    cout << "Danh sach sau khi sap xep tang dan bang cach thay doi info cua Node : ";
    Xuat(head);

    return 0;
}

