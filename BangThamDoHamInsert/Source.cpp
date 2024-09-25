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

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <string>
#include <string.h>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh* table;
};

void CreateHashtable(Hashtable& ht, int m) {
    ht.table = new Hocsinh[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++) {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i++) {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso << ",  " << "  , " << ", " << ", " << "]\n";
    }
}
void DeleteHashtable(Hashtable& ht) {
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable& ht, Hocsinh x) {
    if ((double)(ht.n + 1) / ht.M > LOAD) { //check var
        return 0;
    }
    int i = 0;
    int hashValue = x.Maso;
    while (i < ht.M)
    {
        int index = ((hashValue % ht.M) + i) % ht.M;
        if (ht.table[index].Maso == EMPTY || ht.table[index].Maso == DELETE)
        {
            ht.table[index] = x;
            ht.n++; // tăng phần tử trong mảng
            return 1;
        }
        else {
            i = i + 1;
        }
    }
    return 0;
}

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
