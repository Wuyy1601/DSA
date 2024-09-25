/*Hãy hoàn thành hàm Insert(Hashtable &, Hocsinh) để thêm một phần tử có kiểu dữ liệu Hocsinh vào một bảng băm kiểu Hashtable. Hàm Insert sẽ trả về kết quả 1 nếu thêm phần tử thành công và trả về 0 nếu không thêm phần tử được. Cho biết:
- Hashtable là loại bảng băm xử lý đụng độ bằng phương pháp thăm dò.
- Hàm băm lại sử dụng phương pháp thăm dò tuyến tính: h(key, i) = ((key % M) + i) % M. Với M là kích thước bảng băm
- Hàm băm là h(key) = key % M.
- Hệ số tải của bảng băm được ấn định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không quá 70% kích thước của bảng băm.
- Hằng ký hiệu EMPTY 0 là giá trị mã số quy định cho trường hợp vị trí tương ứng trên bảng băm đang còn trống.
- Hằng ký hiệu DELETE -1 là giá trị mã số quy định cho trường hợp vị trí tương ứng trên bảng băm có phần tử trước đó nhưng đã bị xóa.

- Số lượng phần tử cần thêm vào bảng băm không quá 1000. Kích thước bảng băm không quá 1000 phần tử.
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
int Delete(Hashtable&, int);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable&);
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

int Delete(Hashtable& ht, int maso) {
    //Tính toán vị trí của phần tử cần xóa bằng hàm băm
    int index = Hash(ht, maso);

    //Duyệt qua danh sách liên kết đơn tại index
    Node* p = ht.table[index].head;
    Node* q = nullptr;
   /* cách 1: 
   while (p != nullptr)
    {
        if (p->data.Maso == maso)
        {
            if (q) //nếu đã duyệt qua thì q!=null->p!=head
            {
                q->next = p->next;
            }
            else // p là head
            {
                ht.table[index].head = p->next;
            }
            delete p;
            ht.n--;//giảm sl bảng băm
            return 1;
        }
        q = p;//duyệt qua thì gán để duyệt lần kế
        p = p->next;
    }*/
    while (p != nullptr)
    {
        if (p->data.Maso == maso)
        {
            if (p == ht.table[index].head)// khi p = head
            {
                RemoveHead(ht.table[index]);
            }
            else
            {
                Node* q = ht.table[index].head;
                while (q->next != p)
                {
                    q = q->next;
                }
                RemoveAfter(ht.table[index], q);
            }
            ht.n--;
            return 1;
        }
        p = p->next;
    }
    return 0;// ko tìm thấy;
}

void Input(Hocsinh& x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n, k;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        cin >> k;
        hashtable.n += k;
        for (int j = 0; j < k; j++) {
            Input(hs);
            AddTail(hashtable.table[i], hs);
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;

        if (Delete(hashtable, k) == 0)
            cout << "KHONG XOA DUOC\n";
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
