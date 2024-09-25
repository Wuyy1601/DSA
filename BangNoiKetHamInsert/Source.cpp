/*Hãy hoàn thành hàm Insert(Hashtable &, Hocsinh) để thêm một phần tử có kiểu dữ liệu Hocsinh vào một bảng băm kiểu Hashtable. Hàm Insert sẽ trả về kết quả 1 nếu thêm phần tử thành công và trả về 0 nếu không thêm phần tử được. Cho biết:
- Hashtable là loại bảng băm nối kết trực tiếp.
- Sử dụng liên kết đơn List để giải quyết đụng độ.
- Hàm băm Hash sẽ biến đổi dữ liệu mã số (trường Maso) của học sinh thành chỉ số trong bảng băm
- Hệ số tải của bảng băm được ấn định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không quá 70% kích thước của bảng băm.

- Số lượng phần tử cần thêm vào bảng băm không quá 1000. Bảng băm có kích thước không quá 1000 phần tử.
Lưu ý:
1) Chỉ cài đặt hàm Insert.
2) Các kiểu dữ liệu và các hàm cần thiết của các kiểu dữ liệu đã được cài đặt sẵn. Sinh viên có thể đọc để sử dụng.
3) Đầu vào và đầu ra đã được xử lý sẵn và phù hợp với định dạng nhập/xuất.*/

#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node {
    Hocsinh data;
    Node* next;
};

struct List {
    Node* head, * tail;
};

Node* CreateNode(Hocsinh);
void CreateList(List&);
void AddTail(List&, Hocsinh);
int RemoveHead(List&);
int RemoveAfter(List&, Node*);
void DeleteList(List&);

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List* table;
};

void CreateHashtable(Hashtable&, int);
int Hash(Hashtable, int); // Ham bam ma so hoc sinh thanh chi so
int Insert(Hashtable&, Hocsinh);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable&);

void Input(Hocsinh& x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
void CreateList(List& l) {
    l.head = l.tail = NULL;
}

Node* CreateNode(Hocsinh x) {
    Node* p = new Node;
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->data = x;
    return p;
}

void AddTail(List& l, Hocsinh x) {
    Node* p = CreateNode(x);
    if (l.head == NULL)
        l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

int RemoveHead(List& l) {
    if (l.head == NULL)
        return 0;
    Node* p = l.head;
    l.head = p->next;
    if (l.tail == p)
        l.tail = NULL;
    delete p;
    return 1;
}

int RemoveAfter(List& l, Node* q) {
    if (l.head == NULL)
        return 0;

    if (q == NULL)
        return RemoveHead(l);

    Node* p = q->next;
    q->next = p->next;
    if (l.tail == p)
        l.tail = q;
    delete p;
    return 1;
}

void DeleteList(List& l) {
    while (l.head) {
        Node* p = l.head;
        l.head = p->next;
        delete p;
    }
    l.head = l.tail = NULL;
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

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i++) {
        Node* p = ht.table[i].head;
        while (p) {
            Hocsinh hs = p->data;
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "] ";
            p = p->next;
        }
        cout << '\n';
    }
}

void DeleteHashtable(Hashtable& ht) {
    for (int i = 0; i < ht.M; i++) {
        DeleteList(ht.table[i]);
    }
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable& ht, Hocsinh x) {
    if ((double)(ht.n + 1) / ht.M > LOAD) { //check var
        return 0;
    }
    int index = Hash(ht, x.Maso);
    Node* p = ht.table[index].head;
    while (p != nullptr)
    {
        if (p->data.Maso == x.Maso)
            return 0;
        p = p->next;
    }
    AddTail(ht.table[index], x);
    ht.n++;
    return 1;

}