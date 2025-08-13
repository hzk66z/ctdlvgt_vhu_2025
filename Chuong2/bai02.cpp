#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct sanPham{
	string maSp;
	string tenSp;
	double donGia;
	int soLuong;
};

typedef sanPham sp;

void menu();
void nhapDanhSach(int& n, sp a[]);
void xuatDanhSach(int n, sp a[]);
void SelectionSort(sp a[], int n);
void InsertionSort(sp a[], int n);
void BubbleSort(sp a[], int n);


void nhapDanhSach(int & n, sp a[]){
	do{
		cout << "Nhap so luong san pham: ";
		cin >> n;
	}while(n < 1 || n > 20);
	
	cin.ignore();
	
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin san pham thu " << i + 1 << ":\n";
		do{
			cout << "Ten san pham: ";
			getline(cin, a[i].tenSp);
			cout << "Ma san pham: ";
			getline(cin, a[i].maSp);
			cout << "So luong san pham: ";
			cin >> a[i].soLuong;
			cout << "Gia san pham: ";
			cin >> a[i].donGia;
			cin.ignore();
			if(a[i].maSp.length() < 1 || a[i].maSp.length() > 5 || a[i].tenSp.length() < 1 || a[i].tenSp.length() > 50 || a[i].donGia < 0 || a[i].soLuong < 0){
				cout << "Thong tin khong hop le, vui long nhap lai!";
			}
		}while(a[i].maSp.length() < 1 || a[i].maSp.length() > 5 || a[i].tenSp.length() < 1 || a[i].tenSp.length() > 50 || a[i].donGia < 0 || a[i].soLuong < 0);
	}
}

void xuatDanhSach(int n, sp a[]){
	cout << endl;
	
	cout << left
		 << setw(15) << "TEN SAN PHAM"
		 << setw(30) << "MA SAN PHAM"
		 << setw(25) << "SO LUONG"
		 << setw(20) << "DON GIA"
		 << endl;
	
	for(int i = 0; i < n; i++){
	cout << left
		 << setw(15) << a[i].tenSp
		 << setw(30) << a[i].maSp
		 << setw(25) << a[i].soLuong
		 << fixed << setprecision(2) << setw(20) << a[i].donGia
		 << endl;
	}
}

void SelectionSort(sp a[], int n )
{
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
		sp tam = a[i];
		a[i] = a[vtmin];
		a[vtmin] = tam;
	}
	}	
}

void BubbleSort(sp a[], int n )
{
	int i, j;
	for (i=0; i<n-1; i++)
	{
		for (j=n-1; j>i; j --)
	{
		if(a[j].tenSp < a[j-1].tenSp){
				sp tam = a[j];
				a[j] = a[j-1];
				a[j-1] = tam;
		}

	}
	}
}

void InsertionSort(int n, sp a[]){
	for(int i = 1; i<n; i++){
		int j = i - 1 ;
		sp key = a[i]; 
		while(j >= 0 && a[j].donGia > key.donGia){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
}
}

void menu(){
	cout << "==========================================================" << endl;
	cout << "1. Xuat danh sach cac san pham da nhap" << endl;
	cout << "2. Su dung Selection Sort sap xep tang dan theo so luong" << endl;
	cout << "3. Su dung Insertion Sort sap xep tang dan theo don gia" << endl;
	cout << "4. Su dung Bubble Sort sap xep tang dan theo ten san pham" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "==========================================================" << endl;
}

int main(){
	
	sp a[20];
	int n;
	nhapDanhSach(n, a);
	
	while(true){
		
		menu();
		int choice;
		cout << "Nhap lua chon cua ban: ";
		cin >> choice;
		
		switch(choice){
			case 1:{
				xuatDanhSach(n, a);	
				break;
			}
			case 2: {
				SelectionSort(a, n);
				xuatDanhSach(n, a);
				break;
			}
			case 3:{
				InsertionSort(n, a);
				xuatDanhSach(n, a);
				break;
			}
			case 4:{
				BubbleSort(a, n);
				xuatDanhSach(n, a);
				break;
			}
			case 0:
				return 0;
			default:
				break;
		}
	}
}