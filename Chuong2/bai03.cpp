#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct thuVien{
	string maSach;
	string tenSach;
	double donGia;
	int soLuong;
	string tenTacGia;
	string nhaXuatBan;
};

typedef thuVien tv;
void menu();
void nhapDanhSach(int &n, tv a[]);
void xuatDanhSach(int n, tv a[]);
void xuatDanhSachKhiBietTacGia(int n, tv a[]);
void xuatTangDanTheoSL(int n, tv a[]);
void xuatGiamDanTheoDonGia(int n, tv a[]);
void xuatTangDanTheoTenTacGia(int n, tv a[]);
void tongGiaTriKhiBietTenNhaXB(int n, tv a[]);

void menu(){
	cout << "===============================================================" << endl;
	cout << "1. Xuat danh sach da nhap" << endl;
	cout << "2. Xuat danh sach khi biet ten tac gia" << endl;
	cout << "3. Sap xep danh sach tang dan theo so luong" << endl;
	cout << "4. Sap xep danh sach giam dan theo don gia" << endl;
	cout << "5. Sap xep danh sach tang dan theo ten tac gia" << endl;
	cout << "6. Tinh tong gia tri cac dau sach khi biet ten nha xuat ban" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "===============================================================" << endl;
}

void nhapDanhSach(int & n, tv a[]){
	do{
		cout << "Nhap so luong sach: ";
		cin >> n;
	}while(n < 1 || n > 20);
	
	cin.ignore();
		for(int i = 0; i < n; i++){
		cout << "Nhap thong tin sach thu " << i + 1 << ":\n";
		do{
			cout << "Ten sach: ";
			getline(cin, a[i].tenSach);
			cout << "Ma sach: ";
			getline(cin, a[i].maSach);
			cout << "So luong sach: ";
			cin >> a[i].soLuong;
			cin.ignore();
			cout << "Don gia sach: ";
			cin >> a[i].donGia;
			cin.ignore();
			cout << "Ten tac gia: ";
			getline(cin, a[i].tenTacGia);
			cout << "Ten nha xuat ban: ";
			getline(cin, a[i].nhaXuatBan)
			;
			if(a[i].maSach.length() < 1 || a[i].maSach.length() > 10 || a[i].tenSach.length() < 1 || a[i].tenSach.length() > 50 || a[i].soLuong < 0 
			|| a[i].donGia < 0 || a[i].tenTacGia.length() < 1 || a[i].tenTacGia.length() > 50 || a[i].nhaXuatBan.length() < 1 || a[i].nhaXuatBan.length() > 50 ){
				cout << "Thong tin khong hop le, vui long nhap lai!";
			}
		}while(a[i].maSach.length() < 1 || a[i].maSach.length() > 10 || a[i].tenSach.length() < 1 || a[i].tenSach.length() > 50 || a[i].soLuong < 0 
			|| a[i].donGia < 0 || a[i].tenTacGia.length() < 1 || a[i].tenTacGia.length() > 50 || a[i].nhaXuatBan.length() < 1 || a[i].nhaXuatBan.length() > 50);
	}
}

void xuatDanhSach(int n, tv a[]){
	cout << endl;
	
	cout << left
		 << setw(15) << "TEN SAN PHAM"
		 << setw(30) << "MA SAN PHAM"
		 << setw(20) << "TEN TAC GIA"
		 << setw(20) << "NHA XUAT BAN"
		 << setw(25) << "SO LUONG"
		 << setw(20) << "DON GIA"
		 << endl;
	
	for(int i = 0; i < n; i++){
	cout << left
		 << setw(15) << a[i].tenSach
		 << setw(30) << a[i].maSach
		 << setw(20) << a[i].tenTacGia
		 << setw(20) << a[i].nhaXuatBan
		 << setw(25) << a[i].soLuong
		 << fixed << setprecision(2) << setw(20) << a[i].donGia
		 << endl;
	}
}

void xuatDanhSachKhiBietTacGia(int n, tv a[]){
	string tenTacGia;
	cout << "Nhap ten tac gia can tim: ";
	cin.ignore();
	getline(cin, tenTacGia);
	bool found = false;
	
	for(int i = 0; i < n; i++){
	
		if(a[i].tenTacGia == tenTacGia){
			cout << endl;
			cout << left
				 << setw(15) << "TEN SACH"
				 << setw(30) << "MA SACH"
				 << setw(20) << "TEN TAC GIA"
				 << setw(20) << "NHA XUAT BAN"
				 << setw(25) << "SO LUONG"
				 << setw(20) << "DON GIA"
				 << endl;
			cout << left
				 << setw(15) << a[i].tenSach
				 << setw(30) << a[i].maSach
				 << setw(20) << a[i].tenTacGia
				 << setw(20) << a[i].nhaXuatBan
				 << setw(25) << a[i].soLuong
				 << fixed << setprecision(2) << setw(20) << a[i].donGia
				 << endl;
			found = true;
			break;
			}
		}
		if(!found){
		cout << "Khong tim thay sach cua tac gia!" << endl;
	}
}

void xuatTangDanTheoSL(int n, tv a[]){
	int vtmin;
	int i, j;
	for (i=0; i<n-1; i++)
	{
	vtmin = i;
	for(j=i+1; j<n; j++)
	{
		if (a[j].soLuong < a[vtmin].soLuong)
		vtmin = j;
	}
//		int tam;
	if(vtmin != i){
		tv tam = a[i];
		a[i] = a[vtmin];
		a[vtmin] = tam;
	}
	}	
}

void xuatGiamDanTheoDonGia(int n, tv a[]){
	int i, j;
	
	for (i=0; i<n-1; i++)
	{
	for (j=i+1; j<n; j++)
		if(a[j].donGia > a[i].donGia){
			tv tam = a[i];
			a[i] = a[j];
			a[j] = tam;
		}
	}
}


void xuatTangDanTheoTenTacGia(int n, tv a[]){
		int vtmin;
	int i, j;
	for (i=0; i<n-1; i++)
	{
	vtmin = i;
	for(j=i+1; j<n; j++)
	{
		if (a[j].tenTacGia < a[vtmin].tenTacGia)
		vtmin = j;
	}
//		int tam;
	if(vtmin != i){
		tv tam = a[i];
		a[i] = a[vtmin];
		a[vtmin] = tam;
	}
	}	
}

void tongGiaTriKhiBietTenNhaXB(int n, tv a[]){
	double sum = 0;
	string nhaXuatBan;
	bool check = false;
	cout << "Nhap ten nha xuat ban: ";
	cin.ignore();
	getline(cin, nhaXuatBan);
	for(int i = 0; i < n; i++){
		if(nhaXuatBan == a[i].nhaXuatBan){
			check = true;
			sum += a[i].donGia;
	}
}
if(check == true){
		cout << "Tong gia tri cua cac dau sach: " << sum ;
		cout << endl;
	}else{
		cout << "Khong tim thay nha xuat ban!";
		cout << endl;
	}
}


int main(){
	
	int n;
	tv a[20];
	nhapDanhSach(n, a);
	
	while(true){
		
		menu();
		int choice;
		cout << "Nhap su lua chon: ";
		cin >> choice;
		
		switch(choice){
			case 1:{
				xuatDanhSach(n, a);
				break;
			}
			case 2:{
				xuatDanhSachKhiBietTacGia(n, a);
				xuatDanhSach(n, a);
				break;
			}
			case 3:{
				xuatTangDanTheoSL(n, a);
				xuatDanhSach(n, a);
				break;
			}
			case 4:{	
				xuatGiamDanTheoDonGia(n, a);
				xuatDanhSach(n, a);
				break;
			}
			case 5:{
				xuatTangDanTheoTenTacGia(n, a);
				xuatDanhSach(n, a);
				break;
			}
			case 6:{
				tongGiaTriKhiBietTenNhaXB(n, a);
				break;
			}
			case 0:
				return 0;
				default:
					break;
		}
	}
	
}