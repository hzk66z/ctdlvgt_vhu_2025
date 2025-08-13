#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

typedef struct{
	int ngay;
	int thang;
	int nam;
} Ngay;

struct SANPHAM {
	string maSP;
	string tenSP;
	double donGia;
	int ngaySD;
	string noiSX;
	Ngay nsx;
};

typedef SANPHAM sp;

void menu();
void nhapDanhSach(int & n, sp a[]);
void xuatDanhSach(int n, sp a[]);
void timKhiBietMaSanPham(int n, sp a[]);
void timKiemKhiBietTenSanPham(int n, sp a[]);
void sapXepTangDan(int n, sp a[]);
void HoanVi(sp& x, sp& y);
void inKhiBietNoiSanXuat(int n, sp a[]);


void menu(){
	cout << "======================================================================" << endl;
	cout << "1. Xuat danh sach da nhap" << endl;
	cout << "2. Tim kiem san pham khi biet ma san pham" << endl;
	cout << "3. Tim kiem san pham khi biet ten san pham" << endl;
	cout << "4. In ra danh sach cac san pham khi biet noi san xuat" << endl;
	cout << "5. Sap xep danh sach san pham theo thu tu tang dan cua ten san pham" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "======================================================================" << endl;
}
void HoanVi(sp& x, sp& y){
	sp tam = x;
	x = y;
	y = tam;
}

void nhapDanhSach(int & n, sp a[]){
	do{
		cout << "Nhap so luong san pham: ";
		cin >> n;
		cout << endl;
	}while(n < 1 || n > 40);
	cin.ignore();
	
	for(int i = 0; i< n; i++){
		cout << "Nhap san pham thu " << i + 1 << ": \n" << endl;
		
		do{
		cout << "Nhap ma san pham: ";
		getline(cin, a[i].maSP);
		cout << "Nhap ten san pham: ";
		getline(cin, a[i].tenSP);
		cout << "Nhap gia san pham: ";
		cin >> a[i].donGia;
		cin.ignore();
		cout << "Nhap ngay san xuat: ";
		cin >> a[i].nsx.ngay >> a[i].nsx.thang >> a[i].nsx.nam;
		cin.ignore();
		cout << "So ngay su dung: ";
		cin >> a[i].ngaySD;
		cin.ignore();
		cout << "Noi san xuat: ";
		getline(cin, a[i].noiSX);
		if(a[i].maSP.length() < 1 || a[i].maSP.length() > 5 || a[i].tenSP.length() < 1 || a[i].tenSP.length() > 50
		|| a[i].donGia < 0 || a[i].nsx.ngay < 0 || a[i].nsx.thang < 0|| a[i].nsx.nam < 0 || a[i].ngaySD < 0 || a[i].noiSX.length() < 1 || a[i].noiSX.length() > 30){
			cout << "Thong tin khong hop le vui long nhap lai!" << endl;
		} 
	}while(a[i].maSP.length() < 1 || a[i].maSP.length() > 5 || a[i].tenSP.length() < 1 || a[i].tenSP.length() > 50
		|| a[i].donGia < 0 ||  a[i].nsx.ngay < 0 || a[i].nsx.thang < 0|| a[i].nsx.nam < 0  || a[i].ngaySD < 0 || a[i].noiSX.length() < 1 || a[i].noiSX.length() > 30);
	} 
}

void xuatDanhSach(int n, sp a[]){
	cout << endl
		 << setw(20) << "MA SAN PHAM"
		 << setw(25) << "TEN SAN PHAM"
		 << setw(20) << "GIA SAN PHAM"
		 << setw(20) << "NGAY SAN XUAT"
		 << setw(20) << "NGAY SU DUNG"
		 << setw(20) << "NOI SAN XUAT"
		 << endl;
		 
	for(int i = 0; i < n; i++){
		cout << endl
			 << setw(20) << a[i].maSP
			 << setw(25) << a[i].tenSP
			 << setw(20) << a[i].donGia
			 << setw(20) << a[i].nsx.ngay << "-" << a[i].nsx.thang << "-" << a[i].nsx.nam
			 << setw(20) << a[i].ngaySD
			 << setw(20) << a[i].noiSX
			 << endl; 
	}
}

void timKhiBietMaSanPham(int n, sp a[]){
	string maSP;
	cout << "Nhap ma san pham can tim: "; 
	cin >> maSP;
	
	bool check = false;
	for(int i = 0; i < n; i++){
		if(a[i].maSP == maSP){
			check = true;			
		}
	} if(check == true){
		cout << endl
		 << setw(20) << "MA SAN PHAM"
		 << setw(20) << "TEN SAN PHAM"
		 << setw(20) << "GIA SAN PHAM"
		 << setw(20) << "NGAY SAN XUAT"
		 << setw(20) << "NGAY SU DUNG"
		 << setw(20) << "NOI SAN XUAT"
		 << endl;
	} else {
		cout << endl;
		cout << "Khong tim thay san pham!" << endl;
	}
	for(int i = 0; i < n; i++){
		if(a[i].maSP == maSP){
			cout << endl
			 << setw(20) << a[i].maSP
			 << setw(25) << a[i].tenSP
			 << setw(20) << a[i].donGia
			 << setw(20) << a[i].nsx.ngay << "-" << a[i].nsx.thang << "-" << a[i].nsx.nam
			 << setw(20) << a[i].ngaySD
			 << setw(20) << a[i].noiSX
			 << endl; 
		}
	}
}

void timKiemKhiBietTenSanPham(int n, sp a[]){
	string tenSP;
	cout << "Nhap ten san pham can tim: ";
	cin >> tenSP;
	
	bool check = false;
	for(int i = 0; i < n; i++){
		if(a[i].tenSP == tenSP){
			check = true;
		}
	} 
	if(check == true){
		cout << endl
		 << setw(20) << "MA SAN PHAM"
		 << setw(20) << "TEN SAN PHAM"
		 << setw(20) << "GIA SAN PHAM"
		 << setw(20) << "NGAY SAN XUAT"
		 << setw(20) << "NGAY SU DUNG"
		 << setw(20) << "NOI SAN XUAT"
		 << endl;
	}else {
		cout << "Khong tim thay san pham!" << endl;
	}
	for(int i = 0; i < n; i++){
		if(a[i].tenSP == tenSP){
				cout << endl
			 << setw(20) << a[i].maSP
			 << setw(25) << a[i].tenSP
			 << setw(20) << a[i].donGia
			 << setw(20) << a[i].nsx.ngay << "-" << a[i].nsx.thang << "-" << a[i].nsx.nam
			 << setw(20) << a[i].ngaySD
			 << setw(20) << a[i].noiSX
			 << endl; 
		}
	}
}

void inKhiBietNoiSanXuat(int n, sp a[]){
	string noiSX;
	cout << "Nhap noi san xuat can tim: ";
	cin >> noiSX;
	
	bool check = false;
	for(int i = 0; i < n; i++){
		if(a[i].noiSX == noiSX){
			check = true;
		}
	}if(check == true){
		cout << endl
			 << setw(20) << "MA SAN PHAM"
			 << setw(20) << "TEN SAN PHAM"
			 << setw(20) << "GIA SAN PHAM"
			 << setw(20) << "NGAY SAN XUAT"
			 << setw(20) << "NGAY SU DUNG"
			 << setw(20) << "NOI SAN XUAT"
			 << endl;
		}else {
			cout << "Khong tim thay san pham!" << endl;
	}for(int i = 0; i< n; i++){
		if(a[i].noiSX == noiSX){
				cout << endl
			 << setw(20) << a[i].maSP
			 << setw(25) << a[i].tenSP
			 << setw(20) << a[i].donGia
			 << setw(20) << a[i].nsx.ngay << "-" << a[i].nsx.thang << "-" << a[i].nsx.nam
			 << setw(20) << a[i].ngaySD
			 << setw(20) << a[i].noiSX
			 << endl; 
		}
	}
}

void sapXepTangDan(int n, sp a[])
{
	int i, j;
	for(int i = 0; i < n- 1; i++)
	{
		for (j=n-1; j>i; j --)
		{
			if(a[j].tenSP < a[j-1].tenSP)
				HoanVi(a[j], a[j-1]);
		}
	}
}

int main(){
	int n;
	sp a[40];
	nhapDanhSach(n, a);
	
	while(true){
		menu();
		int choice;
		cout << "Nhap su lua chon cua ban: ";
		cin >> choice;
		
		switch(choice){
			case 1:{
				xuatDanhSach(n, a);
				break;
			}
			case 2:{
				timKhiBietMaSanPham(n, a);
				break;
			}
			case 3:{
				timKiemKhiBietTenSanPham(n, a);
				break;
			}
			case 4:{
				inKhiBietNoiSanXuat(n, a);
				break;
			}
			case 5:{
				sapXepTangDan(n, a);
				xuatDanhSach(n, a);
				break;
			}
			case 0:
			default:
				return 0;
				break;
		}
	}
}










