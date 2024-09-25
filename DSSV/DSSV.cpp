#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
public:
	string TenSV;
	string MSSV;
	float DTB;
	SinhVien* Next;

	SinhVien(string data_MSSV, string data_TenSV, float data_DTB)
	{
		this->MSSV = data_MSSV;
		this->TenSV = data_TenSV;
		this->DTB = data_DTB;
		this->Next = nullptr;
	}
};

class DanhSachSV
{
public:
	SinhVien* head;
	SinhVien* tail;

	DanhSachSV()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	void LuuSV(string data_TenSV, string data_MSSV, float data_DTB)
	{
		SinhVien* SV = new SinhVien(data_MSSV, data_TenSV, data_DTB);
		if (!this->head)
		{
			this->head = SV;
			this->tail = SV;
		}
		else
		{
			SV->Next = this->head;
			this->head = SV;
		}
	}

	void InDanhSach()
	{
		SinhVien* p;
		p = head;
		while (p != nullptr)
		{
			cout <<"Ten sinh vien: " << p->TenSV << endl;
			cout <<"MSSV: " << p->MSSV << endl;
			cout <<"DTB: " << p->DTB << endl;
			p = p->Next;
		}
	}

	int TimSVtronglop(string TenSVcantim)
	{
		SinhVien* p;
		p = head;
		while (p != nullptr)
		{
			if (p->TenSV == TenSVcantim)
				return 1;
			p = p->Next;
		}
		return 0;
	}

	void RemoveX(DanhSachSV*& DanhSach, string x)
	{
		SinhVien* p;
		p = head;
		SinhVien* q;
		q = nullptr;
		while (p != nullptr && p->MSSV != x)
		{
			q = p;
			p = p->Next;
		}

		if (p == nullptr) return;
		if (q != nullptr)
		{
			q->Next = p->Next;
			if (p == tail) tail = q;
			delete p;
		}
		else
		{
			head = p->Next;
			delete p;
		}
	}

	void TimSVDTBlonhon5()
	{
		SinhVien* p = head;
		while (p != nullptr)
		{
			if (p->DTB >= 5)
			{
				cout << "Ten sinh vien: " << p->TenSV << endl;
				cout << "MSSV: " << p->MSSV << endl;
				cout << "DTB: " << p->DTB << endl;
			}
			p = p->Next;
		}
	}

	void XepLoai()
	{
		SinhVien* p = head;
		while (p != nullptr)
		{
			if (p->DTB <= 3.6)
			{
				cout << "Loai yeu." << endl;
				cout << "Ten sinh vien: " << p->TenSV << endl;
				cout << "MSSV: " << p->MSSV << endl;
				cout << "DTB: " << p->DTB << endl;

			}
			if (p->DTB >= 5 && p->DTB < 6.5)
			{
				cout << "Loai trung binh." << endl;
				cout << "Ten sinh vien: " << p->TenSV << endl;
				cout << "MSSV: " << p->MSSV << endl;
				cout << "DTB: " << p->DTB << endl;
			}
			if (p->DTB >= 6.5 && p->DTB < 7.0)
			{
				cout << "Loai trung binh kha." << endl;
				cout << "Ten sinh vien: " << p->TenSV << endl;
				cout << "MSSV: " << p->MSSV << endl;
				cout << "DTB: " << p->DTB << endl;
			}
			if (p->DTB >= 7.0 && p->DTB < 8.0)
			{
				cout << "Loai kha." << endl;
				cout << "Ten sinh vien: " << p->TenSV << endl;
				cout << "MSSV: " << p->MSSV << endl;
				cout << "DTB: " << p->DTB << endl;
			}
			if (p->DTB >= 8 && p->DTB < 9)
			{
				cout << "Loai gioi." << endl;
				cout << "Ten sinh vien: " << p->TenSV << endl;
				cout << "MSSV: " << p->MSSV << endl;
				cout << "DTB: " << p->DTB << endl;
			}
			if (p->DTB >= 9)
			{
				cout << "Loai gioi." << endl;
				cout << "Ten sinh vien: " << p->TenSV << endl;
				cout << "MSSV: " << p->MSSV << endl;
				cout << "DTB: " << p->DTB << endl;
			}

			p= p->Next;
		}
	}

	void SapXep()
	{
		SinhVien* p = head;
		if (p == nullptr || p->Next == nullptr)
			return;
		SinhVien* q = nullptr;
		SinhVien* temp;
		while (p != nullptr)
		{
			q = p->Next;
			while (q != nullptr)
			{
				if (p->DTB > q->DTB)
				{
					temp = p;
					p = q;
					q = temp;
				}
				q = q->Next;
			}
			p = p->Next;
		}
	}

	void ThemSVmoi(SinhVien* SVmoi)
	{
		SinhVien* p = head;
		if (head == nullptr )
		{
			SVmoi->Next = head;
			head = SVmoi;
		}
		else
		{
			while (p->Next != nullptr)
			{
				if (p->DTB <= SVmoi->DTB && SVmoi->DTB <= p->Next->DTB)
				{
					SVmoi->Next = p->Next;
					p->Next = SVmoi;
					break;
				}
				p = p->Next;
			}
		}
		if( p == tail)
		{
			tail->Next = SVmoi;
			tail = SVmoi;
		}
	}
};


void freedata(SinhVien* SV)
{
	while (SV)
	{
		SinhVien* temp = SV;
		SV = SV->Next;
		free(temp);
	}
}

int main()
{
	DanhSachSV* DanhSach = new DanhSachSV();

	string data_TenSV;
	cout << "Nhap ten sinh vien: ";
	getline(cin, data_TenSV);
	if (data_TenSV == "") return 0;
	while (data_TenSV != "")
	{
		string data_MSSV;
		cout << "Nhap MSSV: ";
		getline(cin, data_MSSV);
		float data_DTB;
		cout << "Nhap DTB: ";
		cin >> data_DTB;
		DanhSach->LuuSV(data_TenSV, data_MSSV, data_DTB);
		cout << "Nhap ten sinh vien: ";
		cin.ignore();
		getline(cin, data_TenSV);
	}

	int choice;
	cout << "Chon chuc nang: " << endl;
	cout << "1: Tim sinh vien theo ten." << endl;
	cout << "2: Xoa sinh vien." << endl;
	cout << "3: Tim sinh vien co DTB >= 5." << endl;
	cout << "4: Xep loai." << endl;
	cout << "5:Sap xep theo DTB." << endl;
	cout << "6: Chen sinh vien theo DTB." << endl;
	cout << "0: De ket thuc chuong trinh." << endl;
	cin >> choice;
	if (choice == 0)
	{
		cout << "Ket thuc chuong trinh.";
		return 0;
	}

	while (choice != 0)
	{
		if (choice == 1)
		{
			// Tìm SV
			string TenSVcantim;
			cin.ignore();
			cout << "Nhap ten SV can tim: ";
			getline(cin, TenSVcantim);
			int b = DanhSach->TimSVtronglop(TenSVcantim);
			if (b == 1) cout << "Co sinh vien trong lop." << endl;
			else cout << "Khong co sinh vien trong lop." << endl;
		}

		if (choice == 2)
		{
			//Xóa SV
			string MSSVX;
			cout << "Nhap MSSV can xoa: ";
			cin.ignore();
			getline(cin, MSSVX);
			DanhSach->RemoveX(DanhSach, MSSVX);
			cout << "Danh sach sau khi xoa SV x la : ";
			DanhSach->InDanhSach();
		}

		if (choice == 3)
		{
			//Tìm SV có DTB >= 5
			DanhSach->TimSVDTBlonhon5();
		}

		if (choice == 4)
		{
			//Xếp loại
			DanhSach->XepLoai();
		}

		if (choice == 5)
		{
			//Sắp xếp
			DanhSach->SapXep();
			DanhSach->InDanhSach();
		}

		if (choice == 6)
		{
			//thêm sv mới
			string TenSVmoi;
			string MSSVmoi;
			float DTBSVmoi;
			cin.ignore();
			cout << "Nhap ten sinh vien moi: ";
			getline(cin, TenSVmoi);
			cout << "Nhap MSSV sinh vien moi: ";
			getline(cin, MSSVmoi);
			cout << "Nhap DTB sinh vien moi: ";
			cin >> DTBSVmoi;
			SinhVien* SVmoi = new SinhVien(TenSVmoi, MSSVmoi, DTBSVmoi);
			DanhSach->SapXep();
			DanhSach->ThemSVmoi(SVmoi);
			DanhSach->InDanhSach();
		}

		cout << "Chon chuc nang: " << endl;
		cout << "1: Tim sinh vien theo ten." << endl;
		cout << "2: Xoa sinh vien." << endl;
		cout << "3: Tim sinh vien co DTB >= 5." << endl;
		cout << "4: Xep loai." << endl;
		cout << "5:Sap xep theo DTB." << endl;
		cout << "6: Chen sinh vien theo DTB." << endl;
		cout << "0: De ket thuc chuong trinh." << endl;
		cin >> choice;
		if (choice == 0)
		{
			cout << "Ket thuc chuong trinh.";
			return 0;
		}
		
	}

	return 0;

}