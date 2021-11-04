#include<iostream>	//	QUAN LY THU VIEN _ updated2 _
#include<string>	//chay tren visual studio __ chay tren dev C bi loi + thieu thu vien ho tro
#include<fstream>
#include<iomanip>
#include<Windows.h>

using namespace std;
struct sach
{
	string maSach;
	string tenSach;
	string tenTacGia;
	string nhaSanXuat;
	string namSanXuat;
	int trangThaiSach;
};
struct Node {
	sach info;
	Node* next;
};
typedef Node NODE;
struct DSsach
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct DSsach ListDSsach;

///Cau 1.Khoi tao danh sach

void Init(ListDSsach& l)
{
	l.pHead = l.pTail = NULL;
	cout << endl << "\t\t<=*=> Khoi Tao Danh Sach Thanh Cong !!!<=*=>" << endl;
}

// getNode chia du lieu info dua vao Data; 
NODE* getNode(sach s)
{

	NODE* p;
	p = new NODE;
	if (p == NULL)
	{
		cout << endl << " Khong du bo nho";
		return NULL;
	}
	p->info = s;
	p->next = NULL;
	return p;
}
//  Cau hinh them vao dau (Them Head) danh sach
void AddHead(ListDSsach& ds, Node* p) {

	if (ds.pHead == NULL) {
		ds.pHead = ds.pTail = p;
	}
	else
	{
		p->next = ds.pHead;
		ds.pHead = p;
	}
}
//  Cau hinh them vao cuoi (Them Tail) danh sach
void AddTail(ListDSsach& ds, Node* p)
{
	if (ds.pHead == NULL)
	{
		ds.pHead = ds.pTail = p;
	}
	else
	{
		ds.pTail->next = p;
		ds.pTail = p;
	}
}
// Ham them sach vào dau danh sach //
void ThemDanhDauDS(ListDSsach& ds)
{
	int n;
	cout << "Ban muon nhap bao nhieu cuon sach: ";
	cin >> n;
	sach s;
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Nhan 1 de nhap trang thai sach: ";
		cin >> s.trangThaiSach;
		cin.ignore();
		cout << endl << "Nhap ma sach: " << endl;
		getline(cin, s.maSach);
		cout << "Nhap ten Sach: " << endl;
		getline(cin, s.tenSach);
		cout << "Nhap ten tac gia cua sach: " << endl;
		getline(cin, s.tenTacGia);
		cout << "Nhap ten nha xuat ban sach: " << endl;
		getline(cin, s.nhaSanXuat);
		cout << "Nhap nam san xuat cua sach: " << endl;
		getline(cin, s.namSanXuat);

		NODE* p = getNode(s);
		AddHead(ds, p);
	}
}
/// Thêm vào sau 1 cuon sach nao do 
void InsertAfter(ListDSsach& ds)
{
	sach s;
	cout << endl << "Ban muon them vao sau quyen sach nao? (nhap vao ma so cua quyen sach truoc do: ): ";
	string ma;
	cin.ignore();
	getline(cin, ma);

	cout << endl << "\t<=> Nhap Thong Tin Sach Ban Muon Them <=>";
	cout << endl << "Nhan 1 de nhap trang thai cua sach: ";
	cin >> s.trangThaiSach;
	cin.ignore();
	cout << endl << "Nhap ma sach : ";
	getline(cin, s.maSach);
	cout << endl << "Nhap ten sach: ";
	getline(cin, s.tenSach);
	cout << endl << "Nhap ten tac gia cua sach: ";
	getline(cin, s.tenTacGia);
	cout << endl << "Nhap ten nha xuat ban sach: ";
	getline(cin, s.nhaSanXuat);
	cout << endl << "Nhap nam san xuat cua sach: " << endl;
	getline(cin, s.namSanXuat);
	// q là sach moi
	NODE* q = getNode(s);

	NODE* before, * after;
	after = ds.pHead;
	while ((after != NULL))

	{
		if ((after->info.maSach.compare(ma) == 0))
		{
			before = after;
			after = after->next;
			q->next = after;
			if (ds.pHead == after)
				ds.pHead = q;
			else before->next = q;
			break;
		}
		after = after->next;
	}

}
// Ham them sach vào cuoi danh sach
void ThemDanhCuoiDS(ListDSsach& ds)
{
	int n;
	cout << "Ban muon nhap bao nhieu cuon sach (Nhap vao so luong): ";
	cin >> n;
	sach s;
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Nhan 1 de nhap trang thai sach: ";
		cin >> s.trangThaiSach;
		cin.ignore();
		cout << endl << "Nhap ma sach : ";
		getline(cin, s.maSach);
		cout << endl <<  "Nhap ten cua sach : ";
		getline(cin, s.tenSach);
		cout << endl << "Nhap ten tac gia cua sach: ";
		getline(cin, s.tenTacGia);
		cout << endl << "Nhap ten nha xuat ban sach: ";
		getline(cin, s.nhaSanXuat);
		cout << endl << "Nhap nam san xuat cua sach: ";
		getline(cin, s.namSanXuat);

		NODE* p = getNode(s);
		AddTail(ds, p);
	}
}

// Xuat toan bo danh sach trong thu vien

void Xuat(ListDSsach ds)
{
	int i = 0;
	cout << " ___________________________________________________               ________________________________________________" << endl;
	cout << "|													 |___o_____o___|						                        |" << endl;
	cout << "|                                                                                                                  |" << endl;
	cout << "|               CHAO MUNG CAC BAN DEN VOI THU VIEN TRUONG DH SU PHAM THANH PHO HO CHI MINH - HCMUE				    |" << endl;
	cout << "|__________________________________________________________________________________________________________________/" << endl << endl;
	cout << "| STT |      MaSach     |             Ten Sach              |TrangThaiSach|             Ten Tac Gia           |          NhaSanXuat            |   NamSanXuat    |" << endl;
	cout << "|_____|_________________|___________________________________|_____________|___________________________________|________________________________|_________________|" << endl;


	for (NODE* p = ds.pHead; p != NULL; p = p->next)
	{
		i++;
		cout << "|" << setw(3) << i << "  |" << setw(15) << p->info.maSach << "  |" << setw(32) << p->info.tenSach << "   |"
			<< setw(6) << p->info.trangThaiSach << "       |" << setw(33) << p->info.tenTacGia << "  |"
			<< setw(28) << p->info.nhaSanXuat << "    |" << setw(12) << p->info.namSanXuat << "     |\n";
	
		cout << "|" << setw(3) << "_____" << "|" << setw(14) << "_________________" << "|" << setw(35)
			<< "___________________________________" << "|"
			<< setw(9) << "_____________" << "|" << setw(35) << "___________________________________"
			<< "|"
			<< setw(32) << "________________________________" << "|" << setw(17) << "_________________" << "|\n";
	}
}
// Xuat toan bo danh sach da cho muon trong thu vien

void XuatdaMuon(ListDSsach ds)
{
	int i = 0;
	cout << " ________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|                                                                                                                                                                |" << endl;
	cout << "|                                                           TOAN BO NHUNG CUON SACH DA MUON                                                                      |" << endl;
	cout << "|________________________________________________________________________________________________________________________________________________________________|" << endl;
	cout << "| STT |      MaSach     |             Ten Sach              |TrangThaiSach|             Ten Tac Gia           |          NhaSanXuat            |   NamSanXuat    |" << endl;
	cout << "|_____|_________________|___________________________________|_____________|___________________________________|________________________________|_________________|" << endl;


	for (NODE* p = ds.pHead; p != NULL; p = p->next)
		if (p->info.trangThaiSach == 1)
		{
			i++;
			cout << "|" << setw(3) << i << "  |" << setw(15) << p->info.maSach << "  |" << setw(32) << p->info.tenSach << "   |"
				<< setw(6) << p->info.trangThaiSach << "       |" << setw(33) << p->info.tenTacGia << "  |"
				<< setw(28) << p->info.nhaSanXuat << "    |" << setw(12) << p->info.namSanXuat << "     |\n";
		
			cout << "|" << setw(3) << "_____" << "|" << setw(14) << "_________________" << "|" << setw(35)
				<< "___________________________________" << "|"
				<< setw(9) << "_____________" << "|" << setw(35) << "___________________________________"
				<< "|"
				<< setw(32) << "________________________________" << "|" << setw(17) << "_________________" << "|\n";

		}
}
// Xuat toàn bo danh sach chua cho muon trong thu vien

void XuatchuaMuon(ListDSsach ds)
{
	int i = 0;
	cout << " ________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|                                                                                                                                                                |" << endl;
	cout << "|                                                           TOAN BO NHUNG CUON SACH CHUA MUON                                                                    |" << endl;
	cout << "|________________________________________________________________________________________________________________________________________________________________|" << endl;
	cout << "| STT |      MaSach     |             Ten Sach              |TrangThaiSach|             Ten Tac Gia           |          NhaSanXuat            |   NamSanXuat    |" << endl;
	cout << "|_____|_________________|___________________________________|_____________|___________________________________|________________________________|_________________|" << endl;

	for (NODE* p = ds.pHead; p != NULL; p = p->next)
		if (p->info.trangThaiSach == 0)
		{
			i++;
			cout << "|" << setw(3) << i << "  |" << setw(15) << p->info.maSach << "  |" << setw(32) << p->info.tenSach << "   |"
				<< setw(6) << p->info.trangThaiSach << "       |" << setw(33) << p->info.tenTacGia << "  |"
				<< setw(28) << p->info.nhaSanXuat << "    |" << setw(12) << p->info.namSanXuat << "     |\n";
		
			cout << "|" << setw(3) << "_____" << "|" << setw(14) << "_________________" << "|" << setw(35)
				<< "___________________________________" << "|"
				<< setw(9) << "_____________" << "|" << setw(35) << "___________________________________"
				<< "|"
				<< setw(32) << "________________________________" << "|" << setw(17) << "_________________" << "|\n";

		}
}

// Xoa nhung cuon sách o dau danh sach (xoa Head)

int DeleteHead(ListDSsach& l)
{
	if (l.pHead == NULL) // neu danh sach null -> return danh sach rong 
	{
		return 0;
	}
	else if (l.pHead != NULL)
	{
		NODE* p = l.pHead;
		l.pHead = l.pHead->next;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}

// xoa nhung quyen sach theo Ma
int XoaTheoMa(ListDSsach* ds, string ma)
{
	NODE* p = ds->pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->info.maSach.compare(ma) == 0)
			break;
		q = p;
		p = p->next;
	}
	if (p == NULL)// ko tim thay
		return 0;


	if (q != NULL)
	{
		q->next = p->next;
		delete p;
	}
	else
	{
		ds->pHead = p->next;
		if (ds->pHead == NULL)
			ds->pTail = NULL;
	}
	return 1;
}
// xoa nhung cuon sach theo Ten Sach

int XoaTheoTenSach(ListDSsach* ds, string tensach)
{
	NODE* p = ds->pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->info.tenSach.compare(tensach) == 0)
			break;
		q = p;
		p = p->next;
	}
	if (p == NULL)
		return 0; //ko tim thay
	if (q != NULL)
	{
		ds->pTail = q;
		q->next = p->next;
		delete p;
	}
	else
	{
		ds->pHead = p->next;
		if (ds->pHead == NULL)
			ds->pTail = NULL;
	}
	return 1;
}
// xoa nhung quyen sach theo ten tac gia

int XoaTheoTenTacGia(ListDSsach* ds, string tentacgia)
{
	NODE* p = ds->pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->info.tenTacGia.compare(tentacgia) == 0)
			break;
		q = p;
		p = p->next;
	}
	if (p == NULL)
		return 0; //ko tim thay
	if (q != NULL)
	{
		ds->pTail = q;
		q->next = p->next;
		delete p;
	}
	// q == null -> tuc la xoa head
	else
	{
		ds->pHead = p->next;
		if (ds->pHead == NULL)
			ds->pTail = NULL;
	}
	return 1;
}
// -------------
int DeleteAfter(ListDSsach& ds)
{
	cout << endl << "Nhap vao ma so quyen sach dung truoc de xoa quyen o ngay sau do! ";
	string ma;
	cin.ignore();
	getline(cin, ma);
	NODE* p, * before, * after;
	p = ds.pHead;
	while ((p != NULL))

	{
		if ((p->info.maSach.compare(ma) == 0))
		{
			before = p;
			p = p->next;
			after = p->next;
			if (after != NULL)
			{
				if (ds.pHead == p) ds.pHead = p->next;
				else before->next = p->next;
				delete p;
			}
			return 1;
			break;
		}
		p = p->next;
	}
	return 0;
}

//--------
int DeleteTail(ListDSsach& l)
{
	NODE* p = l.pHead;
	NODE* r = l.pTail;
	if (l.pHead == NULL) {
		return 0;
	}
	if (p == r) {
		l.pHead = l.pTail = NULL;
		delete(p);
		return 1;
	}
	for (NODE* k = l.pHead; k != NULL; k = k->next)
	{
		// phat hien sach ke cuoi
		if (k->next == l.pTail) {
			delete (l.pTail); // xóa di thang cuoi
			k->next = NULL;  // cho con tro cua node ke cuoi tro den vung nho null
			l.pTail = k; // cap nhat lai danh sach
		}
	}
	return 1;
}
// ----------------
void Doc_File(ifstream& Filein, sach& s)
{
	getline(Filein, s.maSach, ',');

	Filein.seekg(1, 1);
	getline(Filein, s.tenSach, ',');

	Filein.seekg(1, 1);
	Filein >> s.trangThaiSach;

	Filein.seekg(1, 1);// skip qua phai 1 ky tu khoang trang
	getline(Filein, s.tenTacGia, ',');

	Filein.seekg(1, 1);
	getline(Filein, s.nhaSanXuat, ',');

	Filein.seekg(1, 1);
	getline(Filein, s.namSanXuat); //skip qua phai 1 ky tu khoang trang
}
void Doc_File_DS_Sach(ifstream& Filein, ListDSsach& DS)
{
	while (!Filein.eof())	//doc du lieu toi cuoi file
	{
		// doc thông tin sinh viên
		sach Sach;
		Doc_File(Filein, Sach);
		// Khoi tao 1 Node Sach
		NODE* p = getNode(Sach);
		//Them vao cuoi (Tail)
		AddTail(DS, p);
	}
}
//----------

void Giai_Phong_Vung_Nho(ListDSsach& l)
{
	NODE* p = NULL;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->next;
		delete p;
	}
}
///-------

void Doc(ifstream& file, ListDSsach& DS)
{
	file.open("SachThuVien.txt", ios::in);
	Doc_File_DS_Sach(file, DS);
	cout << "\t\t<=*=> Doc File Thanh Cong !!! <=*=>" << endl;
	//Giai_Phong_Vung_Nho(DS);
	file.close();
}

void Ghi_File(ofstream& Fileout, sach s)
{
	Fileout << s.maSach << ", ";
	Fileout << s.tenSach << ", ";
	Fileout << s.trangThaiSach << ", ";
	Fileout << s.tenTacGia << ", ";
	Fileout << s.nhaSanXuat << ", ";
	Fileout << s.namSanXuat;
}
void Luu_File_Sach(ListDSsach l)
{
	ofstream fileout;
	fileout.open("SachThuVien.txt", ios::out);

	for (NODE* p = l.pHead; p != NULL; p = p->next)
	{
		if (p != l.pTail) {
			Ghi_File(fileout, p->info);
			
			fileout << endl;
		}
		else Ghi_File(fileout, p->info);
	}
	fileout.close();
}

void SearchTheoTenSach(ListDSsach* ds, string tenSach)
{
	NODE* p = ds->pHead;
	int i = 0;
	while (p != NULL)
	{
		if (p->info.tenSach.compare(tenSach) == 0)
		{
			i++;
			cout << "|" << setw(3) << i << "  |" << setw(15) << p->info.maSach << "  |" << setw(32) << p->info.tenSach << "   |"
				<< setw(6) << p->info.trangThaiSach << "       |" << setw(33) << p->info.tenTacGia << "  |"
				<< setw(28) << p->info.nhaSanXuat << "    |" << setw(12) << p->info.namSanXuat << "     |\n";

			cout << "|" << setw(3) << "_____" << "|" << setw(14) << "_________________" << "|" << setw(35)
				<< "___________________________________" << "|"
				<< setw(9) << "_____________" << "|" << setw(35) << "___________________________________"
				<< "|"
				<< setw(32) << "________________________________" << "|" << setw(17) << "_________________" << "|\n";
		}

		p = p->next;
	}


}

void SearchTheoTenTacGia(ListDSsach* ds, string tentacgia)
{
	NODE* p = ds->pHead;
	int i = 0;
	while (p != NULL)
	{
		if (p->info.tenTacGia.compare(tentacgia) == 0)
		{
			i++;
			cout << "|" << setw(3) << i << "  |" << setw(15) << p->info.maSach << "  |" << setw(32) << p->info.tenSach << "   |"
				<< setw(6) << p->info.trangThaiSach << "       |" << setw(33) << p->info.tenTacGia << "  |"
				<< setw(28) << p->info.nhaSanXuat << "    |" << setw(12) << p->info.namSanXuat << "     |\n";
			
			cout << "|" << setw(3) << "_____" << "|" << setw(14) << "_________________" << "|" << setw(35)
				<< "___________________________________" << "|"
				<< setw(9) << "_____________" << "|" << setw(35) << "___________________________________"
				<< "|"
				<< setw(32) << "________________________________" << "|" << setw(17) << "_________________" << "|\n";

		}

		p = p->next;
	}


}
void SearchTheoNhaXuatBan(ListDSsach* ds, string nhaxuatban)
{
	NODE* p = ds->pHead;
	int i = 0;
	while (p != NULL)
	{
		if (p->info.nhaSanXuat.compare(nhaxuatban) == 0)
		{
			i++;
			cout << "|" << setw(3) << i << "  |" << setw(15) << p->info.maSach << "  |" << setw(32) << p->info.tenSach << "   |"
				<< setw(6) << p->info.trangThaiSach << "       |" << setw(33) << p->info.tenTacGia << "  |"
				<< setw(28) << p->info.nhaSanXuat << "    |" << setw(12) << p->info.namSanXuat << "     |\n";
			
			cout << "|" << setw(3) << "_____" << "|" << setw(14) << "_________________" << "|" << setw(35)
				<< "___________________________________" << "|"
				<< setw(9) << "_____________" << "|" << setw(35) << "___________________________________"
				<< "|"
				<< setw(32) << "________________________________" << "|" << setw(17) << "_________________" << "|\n";


		}

		p = p->next;
	}


}
int muon(ListDSsach& ds, string ma)
{
	NODE* p = ds.pHead;

	while (p != NULL)
	{
		if (p->info.maSach.compare(ma) == 0)
		{
			p->info.trangThaiSach = 1;
			return 1;
			break;
		}
		p = p->next;
	}
	return 0;
}

int tra(ListDSsach& ds, string ma)
{
	NODE* p = ds.pHead;
	while (p != NULL)
	{
		if (p->info.maSach.compare(ma) == 0)
		{
			p->info.trangThaiSach = 0;
			return 1;
			break;
		}
		p = p->next;
	}
}
void EditName(ListDSsach& ds, string ma)
{
	NODE* p = ds.pHead;
	cout << "\n Moi nhap vao ten moi : ";
	string newname;
	cin.ignore();
	getline(cin, newname);
	while (p != NULL)
	{
		if (p->info.maSach.compare(ma) == 0)
		{
			p->info.tenSach = newname;
			break;
		}
		p = p->next;
	}
	cout << "\n\t\t<=*=> Da cap nhat thanh cong!! <=*=>";
}

void EditNameofWriter(ListDSsach& ds, string ma)
{
	NODE* p = ds.pHead;
	cout << "\n Moi nhap vao ten tac gia moi : ";
	string newname;
	cin.ignore();
	getline(cin, newname);
	while (p != NULL)
	{
		if (p->info.maSach.compare(ma) == 0)
		{

			p->info.tenTacGia = newname;
			break;
		}
		p = p->next;
	}
	cout << "\n\t\t<=*=> Da cap nhat thanh cong!! <=*=>";
}

void EditNameofProducer(ListDSsach& ds, string ma)
{
	NODE* p = ds.pHead;
	cout << "\n Moi nhap vao ten nha xuat ban moi : ";
	string newname;
	cin.ignore();
	getline(cin, newname);
	while (p != NULL)
	{
		if (p->info.maSach.compare(ma) == 0)
		{
			p->info.nhaSanXuat = newname;
			break;
		}
		p = p->next;
	}
	cout << "\n\t\t<=*=> Da cap nhat thanh cong!! <=*=>";
}

void HoVaTen()
{
	cout << endl;
	cout << "\t\t _______________________________________________________________" << endl;
	cout << "\t\t|" << setw(45) << "<=: DE TAI :=> QUAN LY THU VIEN" << "        |" << endl;
	cout << "\t\t|_______________________________________________________________|" << endl;
	cout << "\t\t|" << setw(40) << "TRINH HOANG TUNG - 46.01.104.211" << "       |" << endl;
	cout << endl << endl;

	cout << "\t\t|" << setw(43) << "NGUYEN BINH MINH" << "                       |" << endl;
	cout << endl << endl;

	cout << "\t\t|" << setw(43) << "LE DUC THI" << "							 |" << endl;
	cout << endl << endl;

	cout << "\t\t|" << setw(43) << "PHAM HUYNH MINH KHANH" << "                  |" << endl;
	cout << endl << endl;
	cout << "\t\t|_______________________________________________________________|" << endl;
}
void menuMain()
{
	cout << endl;
	cout << "\t\t\t	CAC CHUC NANG CHINH CUA CHUONG TRINH" << endl << endl;
	cout << "\t\t1 - Khoi Tao Danh Sach va Doc File ( +! )" << endl;
	cout << "\t\t2 - Them 1 Quyen Sach vao Danh Sach ( + )"<< endl;
	cout << "\t\t3 - Xoa 1 Cuon Sach trong Danh Sach ( X )" << endl;
	cout << "\t\t4 - Tim Kiem Sach ( --O )" << endl;
	cout << "\t\t5 - Chuc Nang Xem Danh Sach ( -O--O- )" << endl;
	cout << "\t\t6 - Chuc Nang Muon va Tra Sach ( ! > )" << endl;
	cout << "\t\t7 - Chinh Sua Trang Thai Thong Tin Cua Sach ( ~ )" << endl;
	cout << "\t\t8 - Chuc Nang Luu File ( [<- )" << endl;
}
void menu1() {
	cout << "\t1.Khoi Tao Danh Muc Sach !" <<endl;
	cout << "\t2.Doc tu File" << endl;
}
void menu2() {
	cout << "\t1.Them Vao Dau Danh Sach !" << endl;
	cout << "\t2.Them vao sao 1 cuon sach nao do !" << endl;
	cout << "\t3.Them vao cuoi dach sach !" << endl;
}
void menu3() {
	cout << "\t\t\t CAC CHUC NANG XOA DU LIEU"<< endl;
	cout << "\t1.Xoa Theo Ma So Sach" << endl;
	cout << "\t2.Xoa Theo ten sach " << endl;
	cout << "\t3.Xoa theo ten tac gia" << endl;
	cout << "\t4.Xoa cuon sach o dau danh sach" << endl;
	cout << "\t5.Xoa cuon sach sau 1 cuon sach nao do" << endl;
	cout << "\t6.Xoa cuon sach cuoi danh sach !" << endl;
}
void menu4() {
	cout << "\t1.Tim theo ten sach " << endl;
	cout << "\t2.Tim theo ten tac gia" << endl;
	cout << "\t3.Tim theo ten nha xuat ban" << endl;
}
void menu5() {

	cout << "\t1.Xem toan bo danh sach!" << endl;
	cout << "\t2.Xem nhung cuon sach cho muon " << endl;
	cout << "\t3.Xem nhung cuon sach chua cho muon" << endl;
}
void menu51()
{
	cout << "\t1.Xem danh sach theo thu tu chu cai alphabet cua ten tac gia" << endl;
	cout << "\t2.Xem danh sach theo thu tu chu cai alphabet cua ten nha xuat ban" << endl;
	cout << "\t3.Xem danh sach theo nam xuat ban" << endl;
}
void menu6()
{
	cout << "\t1. Muon sach" << endl;
	cout << "\t2. Tra sach"<< endl;
}
void menu7()
{
	cout << "\t1.Chinh sua ten sach" << endl;
	cout << "\t2.Chinh sua ten tac gia cua sach" << endl;
	cout << "\t3.Chinh sua ten nha xuat ban cua sach" << endl;
}
void menu8()
{
	cout << "\t1.Luu File !\n";
}

void main()	//ham main
{
	ListDSsach DS;
	ifstream file;	// khai bao bien lay du lieu tu file (ifstream)
	HoVaTen();
	while (true)
	{
		//menu_main :
		menuMain();
		int chon;
		cout << "\t\t\tXIN CHAO -- MOI BAN CHON CHUC NANG !!!" << endl;
		cin >> chon;
		switch (chon)
		{
		case 1: {
		menu_1:
			menu1();
			int chon1;
			cout << "\t\t\tMOI BAN CHON CHUC NANG" << endl;
			cin >> chon1;
			switch (chon1)
			{
			case 1: {
				Init(DS);
				break;
			}
			case 2: {
				Doc(file, DS);
				break;
			}
			default:  cout << "Ban chon sai chuc nang xin moi chon lai !!\n";
				goto menu_1;
			}
			break;
		}

		case 2: {
		menu_2:
			menu2();
			int chon2;
			cout << "\t\t\tMOI BAN CHON CHUC NANG !!" << endl;
			cin >> chon2;
			switch (chon2)
			{
			case 1: {
				ThemDanhDauDS(DS);
				break;
			}
			case 2: {
				InsertAfter(DS);
				break;
			}
			case 3: {
				ThemDanhCuoiDS(DS);
				break;
			}
			default:cout << "Ban chon sai chuc nang xin moi chon lai !!" << endl;
				goto menu_2;
			}
			break;
		}

		case 3: {
		menu_3:
			menu3();
			int chon3;
			cout << "\t\t\tMOI BAN CHON CHUC NANG !!" << endl;
			cin >> chon3;
			switch (chon3)
			{
			case 1: {
				string ma;
				cin.ignore();
				cout << endl;
				cout << "Nhap ma sach can xoa : ";
				getline(cin, ma);
				int a = XoaTheoMa(&DS, ma);
				if (a == 0)
				{
					cout << endl;
					cout << "\t\t<=*=> Khong Tim Thay Ma !! <=*=>";
				}
				else
				{
					cout << endl;
					cout << "\t\t<=*=> Xoa Thanh Cong !! <=*=>";
				}
				break;
			}
			case 2: {
				string tensach;
				cin.ignore();
				cout << endl;
				cout << "Nhap ten sach can xoa : ";
				getline(cin, tensach);
				int a = XoaTheoTenSach(&DS, tensach);
				if (a == 0)
				{
					cout << endl;
					cout << "\t\t<=*=> Khong Tim Thay Ten Sach !! <=*=>";
				}
				else
				{
					cout << endl;
					cout << "\t\t<=*=> Xoa Thanh Cong !! <=*=>";
				}
				break;
			}
			case 3: {
				string tentacgia;
				cin.ignore();
				cout << endl;
				cout << "Nhap ten tac gia cua sach can xoa : ";
				getline(cin, tentacgia);
				int a = XoaTheoTenTacGia(&DS, tentacgia);
				if (a == 0)
				{
					cout << endl;
					cout << "\t\t<=*=> Khong Tim Thay Ten Tac Gia !! <=*=>";
				}
				else
				{

					cout << endl;
					cout << "\t\t<=*=> Xoa Thanh Cong !! <=*=>";
				}
				break;
			}
			case 4: {
				int a = DeleteHead(DS);
				if (a == 1) {
					cout << endl;
					cout << "\t\t\t\t<=*=> Xoa thanh cong !! <=*=>";
				}
				else {
					cout << endl;
					cout << "\t\t<=*=> Danh Sach Rong !!! <=*=>" << endl;
				}
				break;
			}
			case 5: {
				int a = DeleteAfter(DS);
				if (a == 1) {
					cout << "\n\t\t\t\t<=*=> Xoa thanh cong !! <=*=>";
				}
				else {
					cout << endl;
					cout << "\t\t <=*=> Danh Sach Rong !!! <=*=>" << endl << endl;
				}
				break;
			}
			case 6: {
				int a = DeleteTail(DS);
				if (a == 1) {
					cout << endl;
					cout << "\t\t<=*=> Xoa thanh cong !! <=*=>";
				}
				else {
					cout << endl;
					cout << "\t\t<=*=> Danh Sach Rong !!! <=*=>" << endl;
				}
				break;
			}
			default:
				cout << "Ban chon sai chuc nang xin moi chon lai !!" << endl;
				goto menu_3;
			}
			break;
		}

		case 4: {
		menu_4:
			menu4();
			int chon4;
			cout << "\t\t\tMOI BAN CHON CHUC NANG !!\n";
			cin >> chon4;
			switch (chon4)
			{
			case 1: {
				cout << " Nhap vao ten sach can tim:  ";
				string tenSach;
				cin.ignore();
				getline(cin, tenSach);

				cout << " ________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "|                                                                                                                                                                |" << endl;
				cout << "|                                                                     TOAN BO SACH HIEN CO																		  |" << endl;
				cout << "|________________________________________________________________________________________________________________________________________________________________|" << endl;
				cout << "| STT |      MaSach     |             Ten Sach              |TrangThaiSach|             Ten Tac Gia           |          NhaSanXuat            |   NamSanXuat    |" << endl;
				cout << "|_____|_________________|___________________________________|_____________|___________________________________|________________________________|_________________|" << endl;

				SearchTheoTenSach(&DS, tenSach);
				break;
			}
			case 2: {
				cout << " Nhap vao ten tac gia can tim:   ";
				string tenTacGia;
				cin.ignore();
				getline(cin, tenTacGia);

				cout << " ________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "|                                                                                                                                                                |" << endl;
				cout << "|                                                                     TOAN BO SACH HIEN CO																	      |" << endl;
				cout << "|________________________________________________________________________________________________________________________________________________________________|" << endl;
				cout << "| STT |      MaSach     |             Ten Sach              |TrangThaiSach|             Ten Tac Gia           |          NhaSanXuat            |   NamSanXuat    |" << endl;
				cout << "|_____|_________________|___________________________________|_____________|___________________________________|________________________________|_________________|" << endl;

				SearchTheoTenTacGia(&DS, tenTacGia);
				break;
			}
			case 3: {
				cout << " Nhap vao ten nha xuat ban can tim:  ";
				string tenNhaXuatBan;
				cin.ignore();
				getline(cin, tenNhaXuatBan);

				cout << " ________________________________________________________________________________________________________________________________________________________________" << endl;
				cout << "|                                                                                                                                                                |" << endl;
				cout << "|                                                                     TOAN BO SACH HIEN CO																	      |" << endl;
				cout << "|________________________________________________________________________________________________________________________________________________________________|" << endl;
				cout << "| STT |      MaSach     |             Ten Sach              |TrangThaiSach|             Ten Tac Gia           |          NhaSanXuat            |   NamSanXuat    |" << endl;
				cout << "|_____|_________________|___________________________________|_____________|___________________________________|________________________________|_________________|" << endl;

				SearchTheoNhaXuatBan(&DS, tenNhaXuatBan);
				break;
			}
			default:cout << "Ban chon sai chuc nang xin moi chon lai !!" << endl;
				goto menu_4;
			}
			break;
		}

		case 5: {
		menu_5:
			menu5();
			int chon5;
			cout << "\t\t\tMOI BAN CHON CHUC NANG !!"<< endl;
			cin >> chon5;
			switch (chon5)
			{
			case 1: {
				Xuat(DS);
				break;
			}
			case 2: {
				XuatdaMuon(DS);
				break;
			}
			case 3: {
				XuatchuaMuon(DS);
				break;
			}
			case 4: {
			menu_51:
				menu51();
				int chon51;
				cout << "\t\t\t MOI BAN CHON CHUC NANG !!" << endl;
				cin >> chon51;
				switch (chon51)
				{
				case 1: {
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				default:
					cout << "Ban chon sai chuc nang xin moi chon lai !!\n";
					goto menu_51;
				}
				break;
			}
			default:cout << "Ban chon sai chuc nang xin moi chon lai !!\n";
				goto menu_5;
			}
			break;
		}

		case 6: {
		menu_6:
			menu6();
			int chon6;
			cout << "\t\t\t MOI BAN CHON CHUC NANG !!" << endl;
			cin >> chon6;
			switch (chon6)
			{
			case 1: {
				cout << endl;
				cout << "\t\t<=*=>Danh Sach Nhung Cuon Sach Chua Muon  <=*=>" << endl;
				XuatchuaMuon(DS);
				cout << endl << "Nhap ma so sach ban muon muon :  ";
				string ma;
				cin.ignore();
				getline(cin, ma);
				int a = muon(DS, ma);
				if (a == 1) {
					cout << endl << "\t<=*=> Muon thanh cong !! <=*=>" << endl;
				}
				break;
			}
			case 2: {
				cout << endl <<" Nhap ma so cua cuon sach ban tra : ";
				string maso;
				cin.ignore();
				getline(cin, maso);
				int a = tra(DS, maso);
				if (a == 1) {
					cout << endl << "\t<=*=> Ban Da Tra Sach !! <=*=>";
				}
				break;
			}
			default:  cout << "Ban chon sai chuc nang xin moi chon lai !!" << endl;
				goto menu_6;
			}
			break;
		}

		case 7: {
			cout << "Moi ban nhap ma so cuon sach ban muon chinh sua noi dung: ";
			string ma;
			cin.ignore();
			getline(cin, ma);
		menu_7:

			menu7();
			int chon7;
			cout << "\t\t\tMOI BAN CHON CHUC NANG !!endl" << endl;
			cin >> chon7;
			switch (chon7)
			{
			case 1: {
				// chinh sua theo ten sach
				EditName(DS, ma);
				break;
			}
			case 2: {
				//chinh sua theo ten tac gia
				EditNameofWriter(DS, ma);
				break;
			}
			case 3: {
				// chinh sua theo ten nha xuat ban
				EditNameofProducer(DS, ma);
				break;
			}
			default:  cout << "Ban chon sai chuc nang xin moi chon lai !!" << endl;
				goto menu_7;
			}
			break;
		}

		case 8: {
		menu_8:
			menu8();
			int chon8;
			cout << "\t\t\tMOI BAN CHON CHUC NANG !!" << endl;
			cin >> chon8;
			switch (chon8)
			{
			case 1: {
				//Giai_Phong_Vung_Nho(DS);
				Luu_File_Sach(DS);
				cout << "\t\t\t<=*=>Ghi File Thanh Cong !!! <=*=>";
				break;
			}
			default: cout << "Ban chon sai chuc nang xin moi chon lai !!" << endl << endl;
				goto menu_8;
			}

		}
			  getchar();
		}
	}
}