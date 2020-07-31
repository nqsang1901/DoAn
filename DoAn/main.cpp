#include <iostream>
#include <cstring>
#include <time.h>
#include <conio.h>
using namespace std;
#define MAX 12345 // so SV toi da du kien cua truong

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

void TaoNgauNhien(SINHVIEN& X) {
	
	int Ma= (100000 + rand() % (999999 - 100000 + 1));
	_itoa_s(Ma, X.MaSV, 10);

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

	X.GioiTinh[0] = 0;
	strcat_s(X.TenSV, " "); strcat_s(X.TenSV, Ten[rand() % 17]);
	char GT[3][4] = {"Nam", "Nu" };
	strcat_s(X.GioiTinh,GT[rand() % 2]);

	X.NgaySinh.ngay = rand() % 30 + 1;
	X.NgaySinh.thang = rand() % 12 + 1;
	X.NgaySinh.nam = (1990 + rand() % (2005 - 1990 + 1));

	int cc = (100000000 + rand() % (999999999 - 100000000 + 1));
	_itoa_s(cc, X.SoCC, 10);

	char So = _itoa_s(rand() % 200 + 2, X.DiaChi, 10);
	char Duong[11][30] = { " Hoa Binh", " Tran Hung Dao", " Le Thi Rieng", " Pham Ngu Lao", " Huynh Thuc Khang", " Phan Van Tri",  " Bui Thi Xuan" };
	char Phuong[11][10] = {"1","2","3","4","5","6"};
	char Quan[10][15] = {"Tan Binh", "1","2","Go Vap","Binh Thanh","5"};
	X.DiaChi[3] = So;
	strcat_s(X.DiaChi,Duong[rand() % 7]); strcat_s(X.DiaChi, ", Phuong ");
	strcat_s(X.DiaChi, Phuong[rand() % 6]); strcat_s(X.DiaChi, ", Quan ");
	strcat_s(X.DiaChi, Quan[rand() % 6]); 	strcat_s(X.DiaChi, ", TP. HCM");

	_itoa_s((100000000 + rand() % (999999999 - 100000000 + 1)), X.SoDT, 10);
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
		NhapDiemMonHoc(MH.DiemMH[14]);
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
	for (int i = 0; i < X.SoMonDaHoc; i++)
	{
		NhapMonHoc(X.Mon[50]);
	}
}
void Xuat(SINHVIEN& X) {
	cout << X.TenSV << endl;
	cout <<"- "<< X.MaSV << endl;
	cout <<"- "<< X.GioiTinh << endl;
	cout << "- " << X.NgaySinh.ngay << "/" << X.NgaySinh.thang << "/" << X.NgaySinh.nam << endl;
	cout << "- " << X.SoCC << endl;
	cout << "- " << X.DiaChi << endl;
	cout << "- " << X.SoDT << endl;
}
bool makeRandomList(DanhSachSV& aList, int num, int maxsize = MAX) {
	if (num < MAX) aList.size = maxsize;
	else aList.size = num + 100;
	aList.sv = new Element[num];
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
NODE* searchNode(const SLList L, char MaSV[9]) {
	NODE* current = L.pHead;
	while (current != NULL && strcmp(current->data.key.MaSV, MaSV) != 0)
		current = current->pNext;
	return current;
}
NODE* updateNode(SLList& L) {  // return NULL if not found
	cout << "Enter MaSV of SV: ";
	char MaSV[9]; cin >> MaSV;
	NODE* p = searchNode(L, MaSV);
	if (p == NULL) {
		cout << "Not found!" << endl;
		return NULL;
	}
	cout << "Enter the new SV of node: ";
	//cin >> p->data.key;
	cout << "Enter the new <sth_more> of node: ";
	cin >> p->data.xyz;
	return p;
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
//NODE* addNode(SLList& L) {
//	cout << "Enter value of node: ";
//	Element X; cin >> X.key;
//	cout << "Enter position to insert (-1 for append): ";
//	int pos; cin >> pos;
//	return insertNode(L, X, pos);
//}
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
//void deleteNodeByKey(SLList& L, int Key) {
//	if (L.pHead == NULL) return;
//	if (L.pHead->data.key == Key) return deleteFirstNode(L);
//	NODE* q = L.pHead, * p = q->pNext;
//	while (p != NULL && p->data.key != Key) {
//		q = p;
//		p = p->pNext;   // <q> is always the previous of <p>
//	}
//	if (p == NULL) return; // not found
//	q->pNext = p->pNext;
//	if (L.pTail == p)  L.pTail = q;
//	delete p;
//}
//void deleteNode(SLList& L) {
//	cout << "Enter position to delete or -1 to delete by key): ";
//	int pos; cin >> pos;
//	if (pos != -1)
//		return deletetNodeAtPosition(L, pos);
//	cout << "Enter the key of node: ";
//	int key;  cin >> key;
//	deleteNodeByKey(L, key); // delete 1st node found 
//}
void deleteList(SLList& L) {
	while (L.pHead)
		deleteFirstNode(L);
}
int makeRandomList(SLList& L) {
	if (L.pHead != NULL)  deleteList(L);
	cout << "Enter number of elements: ";
	int Num;  cin >> Num;
	L.pHead = L.pTail = NULL;
	for (int i = 0; i < Num; i++) {
		int random = (int)rand() % 2020;
		Element X = { random, 1.0 * random / 99 };
		if (!prependNode(L, X)) return i;
	}
}
void printList(const SLList L) {
	NODE* current = L.pHead;
	cout << "------------------------------------"
		<< endl << " Elements of List: [ ";
	while (current != NULL) {
		Xuat(current->data.key);
		current = current->pNext;
	}
	cout << "]" << endl << "........................." << endl;
}
int Xuat(DanhSachSV aList, int num = 100) {
	cout << "Danh sach SV: " << endl;
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
//bool ThemSV(DanhSachSV& aList, SINHVIEN X = { "20192000", "Nguyen Van Cu", true, { 1, 1, 1999 },
//		"079099001002", "", "", "", "Cong nghe Thong tin", 0 }) {
//	if (aList.n == aList.size) // must increase array size
//		if (!MoRongDS(aList)) return false; //can not increase array size
//
//	aList.sv[aList.n++].key = X;
//	return true;
//}
void Menu()
{
	DanhSachSV DArr;
	bool ArrFlag;
	cout << "Do you want to create dynamic arrays(0. yes, 1. no): ";
	cin >> ArrFlag;
	if (ArrFlag==0)
		makeRandomList(DArr,3,3); // makeRandom Dynamic Array with N elements
	//else 
	//	makeRandomList(SLList); // makeRandom Singly Linked List with N elements
	while (true) {
		cout << "0. Quit" << endl
			<< "1. Read List from File" << endl
			<< "2. Save List to File" << endl
			<< "3. Print List " << endl
			<< "4. Update an Element" << endl
			<< "5. Add an Element " << endl
			<< "6. Delete an Element " << endl
			<< "7. Sort List" << endl
			<< "8. Set List to Dynamic Array" << endl
			<< "9. Set List to Linked List" << endl;
		cout << endl << "Enter operation number: ";
		int choice; cin >> choice;
		switch (choice) {
			/*	case 0: if (ArrFlag) deleteList(DArr);
					  else deleteList(SLList);
					return 0;*/
		case 3: if (ArrFlag==0)
			Xuat(DArr, DArr.n + 1);
			//else printList(SLList);
			break;
		case 5: if (ArrFlag == 0)
		
			//else printList(SLList);
			break;
		default: cout << "You need to enter a number between 0 & 9";
		}
	}

}
void main()
{
	Menu();
	system("pause");
}