/*Hãy hoàn thành hàm Search(Hashtable &, int, int &) để tìm một phần tử có mã số kiểu int (maso) trong một bảng băm kiểu Hashtable (ht). Hàm Search sẽ trả về kết quả là chỉ số kiểu int và số lần dò tìm (nprob) kiểu int cần thiết để tìm thấy phần tử đó. Cho biết:
- Hashtable là loại bảng băm xử lý đụng độ bằng phương pháp thăm dò.
- Hàm băm lại sử dụng phương pháp thăm dò bậc hai: h(key, i) = ((key % M) + i*i) % M. Với M là kích thước bảng băm
- Hàm băm là h(key) = key % M.
- Hệ số tải của bảng băm được ấn định là 0.7, nghĩa là bảng băm luôn đảm bảo số phần tử được lưu trong bảng băm không quá 70% kích thước của bảng băm.
- Hằng ký hiệu EMPTY 0 là giá trị mã số quy định cho trường hợp vị trí tương ứng trên bảng băm đang còn trống.
- Hằng ký hiệu DELETE -1 là giá trị mã số quy định cho trường hợp vị trí tương ứng trên bảng băm có phần tử trước đó nhưng đã bị xóa.

- Số lượng khóa cần tìm không quá 1000. Số lượng phần tử trong bảng băm không quá 1000.
Lưu ý:
1) Chỉ cài đặt hàm Search.
2) Các kiểu dữ liệu và các hàm cần thiết của các kiểu dữ liệu đã được cài đặt sẵn. Sinh viên có thể đọc để sử dụng.
3) Đầu vào và đầu ra đã được xử lý sẵn và phù hợp với định dạng nhập/xuất.*/


/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/
#include <iostream>
#include <string>

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

int Search(Hashtable ht, int maso, int& nprob) {

    int hashValue = maso;
    nprob = -1;
    int  i = 0;
    while (i < ht.M)
    {
        int index = ((hashValue % ht.M) + i * i) % ht.M;
        nprob++;//tăng số lần thăm dò
        if (ht.table[index].Maso == maso)
        {
            ht.table[index].Maso = DELETE;
            return 1;
        }
        else if (ht.table[index].Maso == EMPTY)
        {
            return -1;
        }
        i++;
    }
    return 1;
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

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Search(hashtable, k, nprob) > -1) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG TIM THAY" << endl;
        }
    }
    DeleteHashtable(hashtable);
    return 0;
}

