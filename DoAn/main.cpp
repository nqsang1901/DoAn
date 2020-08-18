#include <iostream>
#include <cstring>
#include <time.h>
#include <conio.h>
#include<fstream>
#include<string>
using namespace std;
#define MAX 12345 // Số sinh viên tối đa dự kiến

struct Ngay {
	int ngay, thang, nam;
};
struct DiemMonHoc {
	float Diem;
	Ngay NgayVaoDiem;
};
struct MonHoc {
	char TenMH[20];
	int  SoTietLT;
	int  SoTietTH;
	int  SoLanHoc;
	DiemMonHoc DiemMH[14]; // gia dinh SV co the hoc 1 mon toi da 14 lan 
};
struct SINHVIEN {
	char MaSV[9];
	char TenSV[30];
	char GioiTinh[5];
	Ngay NgaySinh;
	char SoCC[13];
	char DiaChi[90];
	char Email[40];
	char SoDT[12];
	char NganhHoc[30];
	int  SoMonDaHoc;
	MonHoc Mon[50];
};
struct Element { // struct of Element
	SINHVIEN key;
	double xyz;  // And /Or Sth else
};
typedef struct {
	Element* sv;
	int n; // so SV thuc su
	int size; // kich thuoc toi da hien tai cua mang (so phtu duoc cap phat trong Heap)
} DanhSachSV;
typedef struct tagNode { // Singly LL Node
	Element data;
	struct tagNode* pNext;
} NODE;

typedef struct {  // Singly Linked List Type
	NODE* pHead;
	NODE* pTail;
} SLList;

//Hàm này cho phép tạo ngẫu nhiên thông tin của 1 sinh viên
void TaoNgauNhien(SINHVIEN& X) {
	//Tạo ngẫu nhiên mã sinh viên
	int Ma= (100000 + rand() % (999999 - 100000 + 1));
	_itoa_s(Ma, X.MaSV, 10);

	//Tạo ngẫu nhiên họ tên sinh viên
	char Ho[11][8] = { "Nguyen", "Tran", "Le", "Pham", "Huynh", "Phan", "Vu","Vo", "Dang", "Bui" };
	char Lot[8][8] = { "Van", "Thi", "Quang", "Xuan", "Phi" };
	char Ten[18][8] = { "Xuan", "Ha", "Thu", "Dong", "Tay", "Nam", "Bac", "Trung", "Dai",
			"Cuc","Mai", "Dao", "Le", "Nho", "Cam", "Quit", "Buoi", "Tac" };
	X.TenSV[0] = 0;
	strcat_s(X.TenSV, Ho[rand() % 9]); strcat_s(X.TenSV, " ");
	int iTenLot = rand() % 5;
	if (iTenLot != 2) strcat_s(X.TenSV, Lot[iTenLot]);
	else {
		iTenLot = rand() % 5;
		if (strncmp(Ho[iTenLot], X.TenSV, strlen(Ho[iTenLot])))
			strcat_s(X.TenSV, Ho[rand() % 9]);
	}

	//Tạo ngẫu nhiên giới tính sinh viên
	X.GioiTinh[0] = 0;
	strcat_s(X.TenSV, " "); strcat_s(X.TenSV, Ten[rand() % 17]);
	char GT[3][4] = {"Nam", "Nu" };
	strcat_s(X.GioiTinh,GT[rand() % 2]);

	//Tạo ngẫu nhiên ngày sinh sinh viên
	X.NgaySinh.ngay = rand() % 30 + 1;
	X.NgaySinh.thang = rand() % 12 + 1;
	X.NgaySinh.nam = (1990 + rand() % (2005 - 1990 + 1));

	//Tạo ngẫu nhiên số CC sinh viên
	int cc = (100000000 + rand() % (999999999 - 100000000 + 1));
	_itoa_s(cc, X.SoCC, 10);

	//Tạo ngẫu nhiên địa chỉ sinh viên
	char So = _itoa_s(rand() % 200 + 2, X.DiaChi, 10);
	char Duong[11][30] = { " Hoa Binh", " Tran Hung Dao", " Le Thi Rieng", " Pham Ngu Lao", " Huynh Thuc Khang", 
		" Phan Van Tri",  " Bui Thi Xuan" };
	char Phuong[11][10] = {"1","2","3","4","5","6"};
	char Quan[10][15] = {"Tan Binh", "1","2","Go Vap","Binh Thanh","5"};
	X.DiaChi[3] = So;
	strcat_s(X.DiaChi,Duong[rand() % 7]); strcat_s(X.DiaChi, " Phuong ");
	strcat_s(X.DiaChi, Phuong[rand() % 6]); strcat_s(X.DiaChi, " Quan ");
	strcat_s(X.DiaChi, Quan[rand() % 6]); 	strcat_s(X.DiaChi, " TP.HCM");

	//Tạo ngẫu nhiên số điện thoại sinh viên
	_itoa_s((100000000 + rand() % (999999999 - 100000000 + 1)), X.SoDT, 10);

	//Tạo ngẫu nhiên ngành học sinh viên
	/*char Nganh[11][30] = { " Hoa Binh", " Tran Hung Dao", " Le Thi Rieng", " Pham Ngu Lao", " Huynh Thuc Khang",
		" Phan Van Tri",  " Bui Thi Xuan" };
	strcat_s(X.NganhHoc, Nganh[rand() % 7]);*/

	/*X.SoMonDaHoc = rand() % 4+1;
	char MonHoc[11][30] = { "Toan", "Ngu Van", "Hoa hoc", "Sinh hoc", "Cong nghe", "Anh van",  "Dia ly" };
	for (int i = 0; i <= X.SoMonDaHoc-1; i++)
	{
		strcat_s(X.Mon->TenMH, MonHoc[1]);
		X.Mon->SoTietLT = rand() % 30+10;
		X.Mon->SoTietTH = rand() % 33+12;
		X.Mon->SoLanHoc = rand() % 4+1;
		for (int j = 0; j <= X.Mon->SoLanHoc-1; j++)
		{
			X.Mon->DiemMH->Diem = rand() % 10;
			X.Mon->DiemMH->NgayVaoDiem.ngay = rand() % 30 + 1;
			X.Mon->DiemMH->NgayVaoDiem.thang = rand() % 12 + 1;
			X.Mon->DiemMH->NgayVaoDiem.nam = 2018 + rand() % (2020 - 2018 + 1);
		}
	}*/
}
void NhapNgay(Ngay& N)
{
	cout << "Nhap ngay: "; cin >> N.ngay;
	cout << "Nhap thang: "; cin >> N.thang;
	cout << "Nhap nam: "; cin >> N.nam;
	cout << endl;
}
void NhapDiemMonHoc(DiemMonHoc& Diem)
{
	cout << "Nhap diem: "; cin >> Diem.Diem;
	cout << "Nhap ngay vao diem: " << endl;
	NhapNgay(Diem.NgayVaoDiem);
}
void NhapMonHoc(MonHoc& MH)
{
	cout << "Nhap ten mon hoc: "; cin >> MH.TenMH;
	cout << "Nhap so tiet ly thuyet: "; cin >> MH.SoTietLT;
	cout << "Nhap so tiet thuc hanh: "; cin >> MH.SoTietTH;
	cout << "Nhap so lan hoc: "; cin >> MH.SoLanHoc;
	for (int i = 0; i < MH.SoLanHoc; i++)
	{
		NhapDiemMonHoc(MH.DiemMH[i]);
	}
}
void NhapSinhVien(SINHVIEN& X)
{
	cout << "Nhap MaSV: "; cin >> X.MaSV;
	cout << "Nhap ten SV: "; cin >> X.TenSV;
	cout << "Nhap gioi tinh: (0.Nam, 1.Nu) "; cin >> X.GioiTinh;
	cout << "Nhap ngay sinh: " << endl; NhapNgay(X.NgaySinh);
	cout << "Nhap so CC: "; cin >> X.SoCC;
	cout << "Nhap dia chi: "; cin >> X.DiaChi;
	cout << "Nhap Email: "; cin >> X.Email;
	cout << "Nhap SDT: "; cin >> X.SoDT;
	cout << "Nhap nganh hoc: "; cin >> X.NganhHoc;
	cout << "Nhap so mon da hoc: "; cin >> X.SoMonDaHoc;
	for (int i = 0; i <= X.SoMonDaHoc-1; i++)
	{
		NhapMonHoc(X.Mon[i]);
	}
}
void Xuat(SINHVIEN& X) {
	cout <<"Ho ten: "<< X.TenSV << endl;
	cout <<"- "<<"MSSV: "<< X.MaSV << endl;
	cout <<"- "<< "Gioi tinh: "<<X.GioiTinh << endl;
	cout << "- " << "Ngay sinh: "<<X.NgaySinh.ngay << "/" << X.NgaySinh.thang << "/" << X.NgaySinh.nam << endl;
	cout << "- " << "So CC: "<< X.SoCC << endl;
	cout << "- " <<"Dia chi: " << X.DiaChi << endl;
	cout << "- " << "SDT: "<< X.SoDT << endl;
	/*cout << "- " << "Nganh hoc: " << X.NganhHoc << endl;*/
	//cout << "- " << "So mon da hoc: " << endl;
	//for (int i = 0; i <= X.SoMonDaHoc-1; i++)
	//{
	//	cout << "    "<<i+1<<". "<< X.Mon->TenMH << ": " << endl;
	//	cout << "   + " <<"So lan da hoc: "<< X.Mon->SoLanHoc << endl;
	//	for (int j = 0; j <= X.Mon->SoLanHoc-1; j++)
	//	{
	//		cout << "Diem: " << X.Mon->DiemMH->Diem<<endl;
	//		cout << "Ngay vao diem: " << X.Mon->DiemMH->Diem<<endl;
	//	}
	//}
	cout << endl;
}
void ghiThongTin1SinhVien(ofstream& fileout, SINHVIEN sv)
{
	fileout << sv.TenSV << ", ";
	fileout << sv.MaSV << ", ";
	fileout << sv.GioiTinh << ", ";
	fileout << sv.NgaySinh.ngay << "/" << sv.NgaySinh.thang << "/" << sv.NgaySinh.nam << ", ";
	fileout << sv.SoCC<<",";
	fileout << sv.DiaChi<<",";
	fileout << sv.SoDT;
}
void ghiThongTinDanhSachSinhVien(SLList &L)
{
	ofstream fileout;
	fileout.open("DanhSachSV.TXT", ios::out);
	for (NODE* k = L.pHead; k != NULL; k = k->pNext)
	{
		ghiThongTin1SinhVien(fileout, k->data.key);
		fileout << endl;
	}
	fileout.close();
}
void ghiThongTinDanhSachSinhVien(DanhSachSV& aList)
{
	ofstream fileout;
	fileout.open("DanhSachSV.TXT", ios::out);
	for (int i = 0; i < aList.n; i++)
	{
		ghiThongTin1SinhVien(fileout, aList.sv[i].key);
		fileout << endl;
	}
	fileout.close();
}
void Doc_Ngay_Thang_Nam(ifstream& filein, Ngay& ngay)
{
	filein >> ngay.ngay;
	filein.seekg(1, 1); // dịch sang phải 1 byte để bỏ qua kí tự '/'
	filein >> ngay.thang;
	filein.seekg(1, 1); // dịch sang phải 1 byte để bỏ qua kí tự '/'
	filein >> ngay.nam;
}
bool makeRandomList(DanhSachSV& aList) {
	cout << "Enter number of elements: ";
	int num;  cin >> num;
	/*if (num < MAX) aList.size = maxsize;*/
	aList.size = num + 100;
	aList.sv = new Element[MAX];
	//aList.sv[1].key = new SINHVIEN[aList.size];
	if (aList.sv == NULL) return false;
	aList.n = num;
	srand(time(0));
	for (int i = 0; i < aList.n; i++) {

		TaoNgauNhien(aList.sv[i].key);
		aList.sv[i].xyz = rand() % 100;
	}	
	return true;
}
void deleteList(DanhSachSV& aList) {
		delete []aList.sv;
		aList.n = 0;
}
NODE* searchNode(const SLList L, char MaSV[9]) {
	NODE* current = L.pHead;
	while (current != NULL && strcmp(current->data.key.MaSV, MaSV) != 0)
		current = current->pNext;
	if (current == NULL)
		return NULL;
	return current;
}
NODE* updateNode(SLList& L) {  // return NULL if not found
	cout << "Enter MaSV of SV: ";
	char MaSV[9]; cin >> MaSV;
	int dem = 0;

	NODE* p = L.pHead;
	for (p; p != NULL; p = p->pNext)
	{
		if (strcmp(p->data.key.MaSV, MaSV) == 0) {
			cout << "Enter the new SV of node: " << endl;
			cout << "Nhap ten SV: "; cin >> p->data.key.TenSV;
			cout << "Nhap gioi tinh: (0.Nam, 1.Nu) "; cin >> p->data.key.GioiTinh;
			cout << "Nhap ngay sinh: " << endl; NhapNgay(p->data.key.NgaySinh);
			cout << "Nhap so CC: "; cin >> p->data.key.SoCC;
			cout << "Nhap dia chi: "; cin >> p->data.key.DiaChi;
			cout << "Nhap Email: "; cin >> p->data.key.Email;
			cout << "Nhap SDT: "; cin >> p->data.key.SoDT;
			cout << "Nhap nganh hoc: "; cin >> p->data.key.NganhHoc;
			dem++;
			break;
		}
	}
	if (dem == 0)
		cout << "Khong tim thay SV" << endl;
	cout << "------------------------------------" << endl;
	return p;
}

void updateSV(DanhSachSV& aList)
{
	int dem = 0;
	SINHVIEN sv;
	cout << "Enter MaSV of SV: ";
	char MaSV[9]; cin >> MaSV;
	for (int i = 0; i < aList.n; i++)
	{
		if (strcmp(aList.sv[i].key.MaSV, MaSV) == 0) {  //so sánh MSSV với chuỗi vừa nhập
			cout << "Enter the new SV : " << endl;						//Nhập SV
			cout << "Nhap ten SV: "; cin >> aList.sv[i].key.TenSV;
			cout << "Nhap gioi tinh: (0.Nam, 1.Nu) "; cin >> aList.sv[i].key.GioiTinh;
			cout << "Nhap ngay sinh: " << endl; NhapNgay(aList.sv[i].key.NgaySinh);
			cout << "Nhap so CC: "; cin >> aList.sv[i].key.SoCC;
			cout << "Nhap dia chi: "; cin >> aList.sv[i].key.DiaChi;
			cout << "Nhap Email: "; cin >> aList.sv[i].key.Email;
			cout << "Nhap SDT: "; cin >> aList.sv[i].key.SoDT;
			cout << "Nhap nganh hoc: "; cin >> aList.sv[i].key.NganhHoc;
			dem++;									//nếu tìm thấy sv thì dem++
		}
	}
	if (dem == 0)
		cout << "Khong tim thay SV" << endl;
}

NODE* prependNode(SLList& L, Element X) { //return newNode
	NODE* newNode = new NODE{ X, NULL };
	if (newNode == NULL) return NULL;
	if (L.pHead == NULL)  // SLL is empty
		L.pHead = L.pTail = newNode;
	else {
		newNode->pNext = L.pHead;
		L.pHead = newNode;
	}
	return newNode;
}
NODE* appendNode(SLList& L, Element X) { //return newNode
	NODE* newNode = new NODE{ X, NULL };
	if (L.pHead == NULL)  // SLL is empty
		L.pHead = L.pTail = newNode;
	else {
		L.pTail->pNext = newNode;
		L.pTail = newNode;
	}
	return newNode;
}
NODE* insertNode(SLList& L, Element X, int Pos) {
	if (Pos == 0) return prependNode(L, X);
	if (Pos == -1) return appendNode(L, X);
	NODE* q = L.pHead;
	for (int i = 1; i < Pos && q != NULL; i++) // find node at (Pos-1)
		q = q->pNext;
	if (q == NULL) return NULL; // Pos > number of elemens
	// insert <newNode> after node <q>
	NODE* newNode = new NODE{ X, q->pNext };
	if (newNode == NULL) return NULL;
	q->pNext = newNode;
	if (q == L.pTail) L.pTail = newNode;
	return newNode;
}
NODE* addNode(SLList& L,SINHVIEN sv) {
	TaoNgauNhien(sv);
	Element X = { sv,99 };
	cout << "Enter position to insert (-1 for append): ";
	int pos; cin >> pos;
	return insertNode(L, X, pos);
}
void deleteFirstNode(SLList& L) {
	if (L.pHead == L.pTail) { //There is only one node
		delete L.pHead;
		L.pHead = L.pTail = NULL;
		return;
	}
	NODE* p = L.pHead;
	L.pHead = L.pHead->pNext;
	delete p;
}
void deletetNodeAtPosition(SLList& L, int Pos) {
	if (Pos == 0) return deleteFirstNode(L);
	NODE* q = L.pHead;
	for (int i = 1; i < Pos && q != NULL; i++) // find node at (Pos-1)
		q = q->pNext;
	if (q == NULL) return; // Pos > number of elemens
	NODE* p = q->pNext;  // <p> : the node must be delete
	if (p == NULL) return;
	q->pNext = p->pNext;
	if (L.pTail == p)  L.pTail = q;
	delete p;
}
void deletetNodeAtPosition(DanhSachSV& aList) 
{
	cout << "Enter position to delete or -1 to delete by MaSV): ";
	int pos; cin >> pos;
	if (pos > aList.n - 1 || pos < 0)
	{
		cout << "Pos invalid location" << endl;
		return;
	}
	aList.n--;
	for (int i = pos; i < aList.n; i++) {
		aList.sv[i] = aList.sv[i + 1];
	}
}
void deleteNodeByMaSV(SLList& L, char MaSV[9]) {
	if (L.pHead == NULL) return;
	if (strcmp(L.pHead->data.key.MaSV,MaSV)==0) return deleteFirstNode(L);
	NODE* q = L.pHead, * p = q->pNext;
	while (p != NULL && strcmp(p->data.key.MaSV ,MaSV)!=0) {
		q = p;
		p = p->pNext;   // <q> is always the previous of <p>
	}
	if (p == NULL) return; // not found
	q->pNext = p->pNext;
	if (L.pTail == p)  L.pTail = q;
	delete p;
}
void deleteNode(SLList& L) {
	cout << "Enter position to delete or -1 to delete by MaSV): ";
	int pos; cin >> pos;
	if (pos != -1)
		return deletetNodeAtPosition(L, pos);
	cout << "Enter the MaSV of node: ";
	char MaSV[9];  cin >> MaSV;
	deleteNodeByMaSV(L, MaSV); // delete 1st node found 
}
void deleteList(SLList& L) {
	while (L.pHead)
		deleteFirstNode(L);
}

int makeRandomList(SLList& L) {
	if (L.pHead == NULL)  
		deleteList(L);
	cout << "Enter number of elements: ";
	int Num;  cin >> Num;
	L.pHead = L.pTail = NULL;
	for (int i = 0; i < Num; i++) {
		int random = (int)rand() % 2020;
		SINHVIEN sv;
		TaoNgauNhien(sv);
		Element X = { sv, 1.0 * random / 99 };
		if (!prependNode(L, X)) return i;
	}
}
void printList(const SLList L) {
	NODE* current = L.pHead;
	cout << "------------------------------------"
		<< endl << " Elements of List: "<<endl;
	int i = 0;
	while (current != NULL) {
		cout << "\t#" << i + 1 << ". ";
		Xuat(current->data.key);
		current = current->pNext;
		i++;
	}
	cout << endl << "........................." << endl;
}
int Xuat(DanhSachSV aList, int num = 100) {
	cout << "Danh sach SV: " << endl;
	if (aList.n <= 0) cout << "Empty" << endl;
	for (int i = 0; i < aList.n; i++) {
		cout << "\t#" << i + 1 << ". ";
		Xuat(aList.sv[i].key);
	}
	cout << endl;
	return 0;
}
bool MoRongDS(DanhSachSV& aList, int Inc = 101) {
	if (aList.n == aList.size) {
		for (; Inc > 0; Inc -= 10) {
			SINHVIEN *p = (SINHVIEN*)realloc(aList.sv, (aList.size + Inc) * sizeof(SINHVIEN));
			if (p != NULL) {
				aList.sv->key = *p;
				aList.sv->xyz = rand() % 100;
				break;
			}
		}
		if (Inc <= 0) return false;
		aList.size += Inc;
	}
	return true;
}
bool Add2DynamicArr(DanhSachSV& aList, SINHVIEN sv)
{
	cout << "Enter position to insert: ";
	int pos; cin >> pos;
	if (pos<0 || pos>aList.n)
	{
		cout << "Pos invalid location" << endl;
		return false;
	}
	Element item = { sv,rand() % 100 };
	if (aList.size == aList.n) {
		for (int i = 101; i >= -9; i -= 10) {
			if (i == -9)return false;
			Element* temp = (Element*)realloc(aList.sv, aList.size);
			if (temp) {
				aList.sv = temp;
				aList.size += i;
				break;
			}	
		}
	}
	for (int i = ++aList.n; i > pos; i--) {
		aList.sv[i] = aList.sv[i - 1];
	}
	aList.sv[pos] = item;
	return true;
}
void Swap(SINHVIEN &a, SINHVIEN &b)
{
	SINHVIEN temp = a;
	a = b;
	b = temp;
}
void SortListByMaSV(DanhSachSV& aList)
{
	for (int i = 0; i < aList.n-1; i++)
	{
		for (int j = i + 1; j < aList.n; j++)
		{
			if (atoi(aList.sv[i].key.MaSV) > atoi(aList.sv[j].key.MaSV)) {
				Swap(aList.sv[i].key, aList.sv[j].key);
			}
		}
	}
}
void SortListByMaSV(SLList& L)
{
	for (NODE* p1 = L.pHead; p1; p1 = p1->pNext) {
		for (NODE* p2 = p1->pNext; p2; p2 = p2->pNext) {
			if (atoi(p1->data.key.MaSV) > atoi(p2->data.key.MaSV))
				Swap(p1->data.key, p2->data.key);
		}
	}
}
void SLList2Array(SLList& L, DanhSachSV& aList)
{
	if (L.pHead == NULL) return;
	int num = 0;
	for (NODE* p = L.pHead; p; p = p->pNext)
		num++;
	aList.sv = new Element[MAX];
	aList.n = 0;
	aList.size = 100+num;
	for (NODE* p = L.pHead; p; p = p->pNext)
	{
		aList.sv[aList.n++] = p->data;
	}
}
int Array2SLList(DanhSachSV& aList,SLList& L )
{
	if (aList.n == 0)return aList.n;
	L.pHead = L.pTail = NULL;
	for (int i = 0; i < aList.n; i++)
	{
		if(appendNode(L, aList.sv[i])==NULL)
			return i+1;
	}
	return aList.n;
}

void TimSVtheoMSSV(SLList L)
{
	int dem = 0;
	cout << "Nhap MSSV can tim: ";
	char k[30];
	cin >> k;

	NODE* p = L.pHead;
	cout << "------------------------------------" << endl;
	for (p; p != NULL; p = p->pNext)
	{
		if (strcmp(p->data.key.MaSV, k) == 0) {//so sánh MSSV với chuỗi vừa nhập
			Xuat(p->data.key);					 //Xuất sv 
			dem++;								//nếu tìm thấy sv thì dem++
			break;
		}
	}
	if (dem == 0)
		cout << " Khong tim thay SV" << endl;

	cout << endl << "........................." << endl;
}

void TimSVtheoMSSV(DanhSachSV aList)
{
	cout << "Nhap MSSV can tim: ";
	char k[30];
	cin >> k;
	int dem = 0;
	for (int i = 0; i < aList.n; i++)
	{
		if (strcmp(aList.sv[i].key.MaSV, k) == 0) {  //so sánh MSSV với chuỗi vừa nhập
			Xuat(aList.sv[i].key);				  //Xuất sv 
			dem++;									//nếu tìm thấy sv thì dem++
		}
	}
	if (dem == 0)
		cout << "Khong tim thay SV" << endl;
}

void TimSVtheoGioiTinh(DanhSachSV aList)
{
	cout << "Nhap Gioi tinh: ";
	char k[30];
	cin >> k;
	int dem = 0;
	for (int i = 0; i < aList.n; i++)
	{
		if (strcmp(aList.sv[i].key.GioiTinh, k) == 0) {  //so sánh Gioi tính với chuỗi vừa nhập
			Xuat(aList.sv[i].key);				  //Xuất sv 
			dem++;									//nếu tìm thấy sv thì dem++
		}
	}
	if (dem == 0)
		cout << "Khong tim thay SV" << endl;
}


void TimSVtheoGioiTinh(SLList L)
{
	int dem = 0;
	cout << "Nhap Gioi tinh can tim: ";
	char k[30];
	cin >> k;
	NODE* p = L.pHead;
	cout << "------------------------------------" << endl;
	for (p; p != NULL; p = p->pNext)
	{
		if (strcmp(p->data.key.GioiTinh, k) == 0) { //so sánh Giới tính với chuỗi vừa nhập
			Xuat(p->data.key);
			dem++;
		}
	}
	if (dem == 0)
		cout << " Khong tim thay SV" << endl;

	cout << endl << "........................." << endl;
}
void TimSVtheoNam(DanhSachSV aList)
{
	cout << "Nhap Nam sinh: ";
	int k;
	cin >> k;
	int dem = 0;
	for (int i = 0; i < aList.n; i++)
	{
		if (aList.sv[i].key.NgaySinh.nam == k) {  //so sánh năm sinh với chuỗi vừa nhập
			Xuat(aList.sv[i].key);
			dem++;
		}
	}
	if (dem == 0)
		cout << "Khong tim thay SV" << endl;
}

void TimSVtheoNam(SLList L)
{
	int dem = 0;
	cout << "Nhap Nam sinh can tim: ";
	int k;
	cin >> k;

	NODE* p = L.pHead;
	cout << "------------------------------------" << endl;
	for (p; p != NULL; p = p->pNext)
	{
		if (p->data.key.NgaySinh.nam == k) {//so sánh Năm sinh với chuỗi vừa nhập
			Xuat(p->data.key);
			dem++;
			break;
		}
	}
	if (dem == 0)
		cout << " Khong tim thay SV" << endl;

	cout << endl << "........................." << endl;
}
void Menu()
{
	DanhSachSV DArr;
	SLList L;
	bool ArrFlag;
	cout << "Do you want to create dynamic arrays(0. yes, 1. no): ";
	cin >> ArrFlag;
	if (ArrFlag==0)
		makeRandomList(DArr); // makeRandom Dynamic Array with N elements
	else 
		makeRandomList(L); // makeRandom Singly Linked List with N elements
	while (true) {
		cout << "------------MENU------------" << endl;
		cout << "0. Quit" << endl
			<< "1. Read List from File" << endl
			<< "2. Save List to File" << endl
			<< "3. Print List " << endl
			<< "4. Update an Element" << endl
			<< "5. Add an Element " << endl
			<< "6. Delete an Element " << endl
			<< "7. Sort List" << endl
			<< "8. Set List to Dynamic Array" << endl
			<< "9. Set List to Linked List" << endl
			<< "10. Search by MSSV" << endl
			<< "11. Search by Gender" << endl
			<< "12. Search by Year of birth" << endl;
		cout << "----------------------------" << endl;
		cout << endl << "Enter operation number: ";
		int choice; cin >> choice;
		switch (choice) {
		case 0: if (ArrFlag==0) deleteList(DArr);
				else deleteList(L);
			break;
		case 1:
		case 2:
			if (ArrFlag == 0)
				ghiThongTinDanhSachSinhVien(DArr);
			else
				ghiThongTinDanhSachSinhVien(L);
			break;
		case 3: 
			if (ArrFlag==0)
				Xuat(DArr, DArr.n + 1);
			else printList(L);
			break;
		case 4:
			if (ArrFlag == 0)
				updateSV(DArr);
			else
				updateNode(L);
			break;
		case 5: 
			SINHVIEN sv;
			TaoNgauNhien(sv);
			if (ArrFlag == 0) {
				if (Add2DynamicArr(DArr, sv)) cout << "Success" << endl;
				else cout << "Failure" << endl;
			}
			else {
				if (addNode(L, sv)) cout << "Success" << endl;
				else cout << "Failure"<<endl;
			}
			break;
		case 6:
			if (ArrFlag == 0)
				deletetNodeAtPosition(DArr);
			else deleteNode(L);
			break;
		case 7:
			if (ArrFlag == 0)
				SortListByMaSV(DArr);
			else SortListByMaSV(L);
			break;
		case 8:
			if (ArrFlag == 1)
				SLList2Array(L, DArr);
			else
				cout << "The list is empty" << endl;
			break;
		case 9:
			if (ArrFlag == 0) 
				Array2SLList(DArr, L);
			else 
				cout << "The Array is empty" << endl;
			break;
		case 10:
			if (ArrFlag == 1)
				TimSVtheoMSSV(L);
			else
				TimSVtheoMSSV(DArr);
			break;
		case 11:
			if (ArrFlag == 0)
				TimSVtheoGioiTinh(DArr);
			else
				TimSVtheoGioiTinh(L);
			break;
		case 12:
			if (ArrFlag == 0)
				TimSVtheoNam(DArr);
			else
				TimSVtheoNam(L);
			break;
		default: cout << "You need to enter a number between 0 & 9";
			break;
		}
	}
}
void main()
{
	Menu();
}