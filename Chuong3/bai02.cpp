#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct CATHUCHANH{
	string maLHP;
	string tenHP;
	int mSSV;
	string maPH;
};

typedef CATHUCHANH th;

void menu();
void nhapDanhSach(int &n, th a[]);
void xuatDanhSach(int n, th a[]);
void timKhiBietMaLopHocPhan(int n, th a[]);
void timKhiBietTenHocPhan(int n, th a[]);
void timCaHocThucHanh(int n, th a[]);

void menu(){
	cout << "======================================================================" << endl;
	cout << "1. Xuat danh sach cac ca hoc thuc hanh" << endl;
	cout << "2. Tim kiem ca hoc thuc hanh khi biet ma lop hoc phan" << endl;
	cout << "3. Tim kiem ca hoc thuc hanh khi biet ten lop hoc phan" << endl;
	cout << "4. Tim kiem cac ca hoc thuc hanh khi biet ma phong hoc" << endl;
	cout << "5. Sap xep danh sach ca hoc thuc hanh theo ma lop hoc phan tang dan" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "======================================================================" << endl;
}

void nhapDanhSach(int &n, th a[]){
	do{
		cout << "Nhap so luong ca hoc: ";
		cin >> n;
	}while(n < 1);
	cin.ignore();
	
	for(int i = 0; i < n; i++){
		cout << "Nhap ca hoc thu " << i + 1 << ": \n" << endl;
		do{
			cout << "Nhap ma lop hoc phan: ";
			getline(cin, a[i].maLHP);
		//	cin.ignore();
			cout << "Nhap ten hoc phan: ";
			getline(cin, a[i].tenHP);
		//	cin.ignore();
			cout << "Nhap ma so sinh vien: ";
			cin >> a[i].mSSV;
			cin.ignore();
			cout << "Nhap ma phong hoc: ";
			getline(cin, a[i].maPH);
//			cin.ignore();
			if(a[i].maLHP.length() < 1 || a[i].maLHP.length() > 10 || a[i].tenHP.length() < 1|| a[i].tenHP.length() > 50 || a[i].mSSV < 1 || a[i].maPH.length() < 1 || a[i].maPH.length() > 10){
				cout << "Thong tin khong hop le vui long nhap lai!" << endl;
			}
		}while(a[i].maLHP.length() < 1 || a[i].maLHP.length() > 10 || a[i].tenHP.length() < 1 || a[i].tenHP.length() > 50 || a[i].mSSV < 1 || a[i].maPH.length() < 1 || a[i].maPH.length() > 10);
	}
}

void xuatDanhSach(int n, th a[]){
	
	cout << endl;
	cout << left
		 << setw(20) << "MA LOP HOC PHAN"
		 << setw(20) << "TEN LOP HOC PHAN"
		 << setw(20) << "MA SO SINH VIEN"
		 << setw(20) << "MA PHONG HOC"
		 << endl;
		 
	for(int i = 0; i < n; i++){
		cout << left
			 << setw(20) << a[i].maLHP
			 << setw(20) << a[i].tenHP
			 << setw(20) << a[i].mSSV
			 << setw(20) << a[i].maPH
			 << endl;
	}
}

void timKhiBietMaLopHocPhan(int n, th a[]){
	string maLHP;
	cout << "Nhap ma lop hoc phan can tim: " ;
	cin >> maLHP;
	
	bool check = false;
	for(int i = 0; i < n; i++){
		if(a[i].maLHP == maLHP){
			check = true;
	}
} 
	if(check == true){
		cout << endl;
		cout << left
		 << setw(20) << "MA LOP HOC PHAN"
		 << setw(20) << "TEN LOP HOC PHAN"
		 << setw(20) << "MA SO SINH VIEN"
		 << setw(20) << "MA PHONG HOC"
		 << endl; 
}
	for(int i = 0; i < n; i++){
	if(a[i].maLHP == maLHP){
		cout << left
			 << setw(20) << a[i].maLHP
			 << setw(20) << a[i].tenHP
			 << setw(20) << a[i].mSSV
			 << setw(20) << a[i].maPH
			 << endl;
	}
}
}
void timKhiBietTenHocPhan(int n, th a[]){
	string tenHP;
	cout << "Nhap ten lop hoc phan can tim: " ;
	cin >> tenHP;
	
	bool check = false;
	for(int i = 0; i < n; i++){
		if(a[i].tenHP == tenHP){
			check = true;
	}
} 
	if(check == true){
			cout << endl;
		cout << left
		 << setw(20) << "MA LOP HOC PHAN"
		 << setw(20) << "TEN LOP HOC PHAN"
		 << setw(20) << "MA SO SINH VIEN"
		 << setw(20) << "MA PHONG HOC"
		 << endl; 
}
	for(int i = 0; i < n; i++){
	if(a[i].tenHP == tenHP){
		cout << left
			 << setw(20) << a[i].maLHP
			 << setw(20) << a[i].tenHP
			 << setw(20) << a[i].mSSV
			 << setw(20) << a[i].maPH
			 << endl;
	}
}
}
void timCaHocThucHanh(int n, th a[]){
	string maPH;
	cout << "Nhap ma phong hoc can tim: ";
	cin >> maPH;
	bool check = false;
	for(int i = 0; i<n; i++){
		if(a[i].maPH == maPH){
			check = true;
		}
	}
	if(check == true){
		cout << endl;
		cout << left
		 << setw(20) << "MA LOP HOC PHAN"
		 << setw(20) << "TEN LOP HOC PHAN"
		 << setw(20) << "MA SO SINH VIEN"
		 << setw(20) << "MA PHONG HOC"
		 << endl; 
	} else{
		cout << "Khong tim thay ca hoc!" << endl;
	}
	for(int i = 0; i <n; i++){
		if(a[i].maPH == maPH){
			cout << left
			 << setw(20) << a[i].maLHP
			 << setw(20) << a[i].tenHP
			 << setw(20) << a[i].mSSV
			 << setw(20) << a[i].maPH
			 << endl;
		}
	}
}


int main(){
	
	int n;
	th a[100];
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
				timKhiBietMaLopHocPhan(n, a);
				break;
			}
			case 3:{
				timKhiBietTenHocPhan(n, a);
				break;
			}
			case 4:{
				timCaHocThucHanh(n, a);
				break;
			}
			case 0:
				return 0;
				default:
				break;
		}
	}
}
