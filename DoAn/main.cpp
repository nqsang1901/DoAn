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
	bool GioiTinh;
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
	int size; // kich thuoc toi da hien tai cua mang (so phtu duoc cap phat trong Heap
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
	char Ho[11][8] = { "Nguyen", "Tran", "Le", "Pham", "Huynh", "Phan", "Vu","Vo", "Dang", "Bui" };
	char Lot[8][8] = { "Van", "Thi" };
	char Ten[18][8] = { "Xuan", "Ha", "Thu", "Dong", "Tay", "Nam", "Bac", "Trung", "Dai",
			"Cuc","Mai", "Dao", "Le", "Nho", "Cam", "Quit", "Buoi", "Tac" };
	X.TenSV[0] = 0;
	strcat_s(X.TenSV, Ho[rand() % 9]); strcat_s(X.TenSV, " ");
	int iTenLot = rand() % 3;
	if (iTenLot != 2) strcat_s(X.TenSV, Lot[iTenLot]);
	else {
		iTenLot = rand() % 3;
		if (strncmp(Ho[iTenLot], X.TenSV, strlen(Ho[iTenLot])))
			strcat_s(X.TenSV, Ho[rand() % 9]);
	}
	strcat_s(X.TenSV, " "); strcat_s(X.TenSV, Ten[rand() % 17]);
}
void Xuat(SINHVIEN& X) {
	cout << X.TenSV << endl;
}
bool TaoNgauNhien(DanhSachSV& aList, int num, int maxsize = MAX) {
	if (num < MAX) aList.size = maxsize;
	else aList.size = num + 100;
	aList.sv = new Element[num];
	//aList.sv[1].key = new SINHVIEN[aList.size];
	if (aList.sv == NULL) return false;
	aList.n = num;
	//srand(time(0));
	for (int i = 0; i < aList.n; i++) {
		TaoNgauNhien(aList.sv[i].key);
		aList.sv[i].xyz = rand() % 100;
	}	
	return true;
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
//bool MoRongDS(DanhSachSV& aList, int Inc = 101) {
//	if (aList.n == aList.size) {
//		for (; Inc > 0; Inc -= 10) {
//			SINHVIEN p = (SINHVIEN*)realloc(aList.sv, (aList.size + Inc) * sizeof(SINHVIEN));
//			if (p != NULL) {
//				aList.sv->key = p;
//				break;
//			}
//		}
//		if (Inc <= 0) return false;
//		aList.size += Inc;
//	}
//	return true;
//}
bool ThemSV(DanhSachSV& aList, SINHVIEN X = { "20192000", "Nguyen Van Cu", true, { 1, 1, 1999 },
		"079099001002", "", "", "", "Cong nghe Thong tin", 0 }) {
	if (aList.n == aList.size) // must increase array size
	//	if (!MoRongDS(aList)) return false; //can not increase array size

	aList.sv[aList.n++].key = X;
	return true;
}
void main()
{
	DanhSachSV L;
	//	cout << " Chuong trinh Quan Ly Sinh Vien * Phong Dao Tao * DHKHTN "<<endl;
	if (!TaoNgauNhien(L, 7, 7)) // dung mang dong thi 10000 sv hoac tham chi nhieu hon han van thuong ok
		return;
	//int second = Xuat(L, L.n + 1);
	//ThemSV(L);
	Xuat(L, L.n + 1);
	system("pause");
}