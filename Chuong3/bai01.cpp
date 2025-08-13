#include <iostream>

using namespace std;

void menu();
void nhapMang(int &n, int a[]);
void xuatMang(int n, int a[]);
void giaiThuatTimX(int n, int a[]);
void xuatTheoThuTuTangDan(int n, int a[]);
int timKiemNhiPhan(int n, int a[], int x);
void viTriXuatHienCuaX(int n, int a[]);

void menu(){
	cout << "====================================================================" << endl;
	cout << "1. Xuat mang da nhap ra man hinh" << endl;
	cout << "2. Giai thuat tuyen tinh tim phan tu x. Cho biet vi tri xuat hien" << endl;
	cout << "3. Sap xep day so theo thu tu tang dan" << endl;
	cout << "4. Giai thuat tim kiem nhi phan, tim phan tu x" << endl;
	cout << "5. Tim gia tri x xuat hien nhieu lan trong mang" << endl;
	cout << "0. Thoat chuong trinh" << endl;
	cout << "====================================================================" << endl;
}

void nhapMang(int & n, int a[] ){
	for (int i = 0; i < n; i ++){
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> a[i];
	}
}

void xuatMang(int n, int a[]){
	cout << "Mang da nhap la: ";
	for(int i = 0; i < n; i++){
		cout << " " << a[i];
	}
	cout << endl;
}

void giaiThuatTimX(int n, int a[]){
	int x, vtri;
	cout << "Nhap x can tim: ";
	cin >> x;
	cin.ignore(); 
	
	bool ktra = false;

	for(int i = 0; i < n; i++){
			if(a[i] == x){
			ktra = true;
		}
	}
	if(ktra == true){
		cout << "x co trong mang va x nam o vi tri: ";
			for(int i = 0; i <n; i++){
		if(a[i] == x){
			ktra = true;
			cout << " " << i;
		}
	}
	}
	cout << endl;
	if(ktra == false){
		cout << "x khong co trong mang!" << endl;
}
	cout << endl;
}

void xuatTheoThuTuTangDan(int n, int a[]){
		int i, j;
	for (i=0; i<n-1; i++)
	{
		for (j=n-1; j>i; j --)
	{
		if(a[j] < a[j-1]){
				int tam = a[j];
				a[j] = a[j-1];
				a[j-1] = tam;
		}

	}
	}
}

int timKiemNhiPhan(int n, int a[], int x){
		cout << "Nhap x can tim: ";
	cin >> x;
	int left = 0, right = x;
	cin.ignore(); 
	int mid;
		while(left <= right){
			mid = (left + right)/2;
			if(x == a[mid]){
				cout << "x co trong mang" << endl;
				return mid;
			}
			if(x < a[mid]){
			right = mid - 1;
		}
			else{
			left = mid + 1;
		}
}
	cout << "x khong co trong mang!" << endl;
	return 0;
}

void viTriXuatHienCuaX(int n, int a[]){
	int x, vtri;
	cout << "Nhap x can tim: ";
	cin >> x;
	cin.ignore(); 
	
	bool ktra = false;

	for(int i = 0; i < n; i++){
			if(a[i] == x){
			ktra = true;
		}
	}
	if(ktra == true){
		cout << "vi tri xuat hien cua " << x << " la:" << endl;
			for(int i = 0; i <n; i++){
		if(a[i] == x){
			ktra = true;
			cout << " " << i;
		}
	}
	}
	cout << endl;
	if(ktra == false){
		cout << "x khong co trong mang!" << endl;
}
	cout << endl;
	
}

int main(){
	int left, right, mid;
	int x;
	int a[20];
	int n;
	
	do{
		cout << "Nhap so luong phan tu: ";
		cin >> n;
	}while(n < 1 || n > 20);
		nhapMang(n, a);
		
		while(true){
		menu();
		int choice;
		cout << "Nhap lua chon cua ban: ";
		cin >> choice;
		
			switch(choice){
		case 1:{
			xuatMang(n, a);
			break;
		}
		case 2:{
			giaiThuatTimX(n, a);
			xuatMang(n, a);
			break;
		}
		case 3:{
			xuatTheoThuTuTangDan(n, a);
			xuatMang(n, a);
			break;
		}
		case 4:{
			timKiemNhiPhan(n, a, x);
			xuatMang(n, a);
			break;
		}
		case 5:{
			viTriXuatHienCuaX(n, a);
			xuatMang(n, a);
			break;
		}
		case 0:
		default:
			break;
	}
	}
	
	}
	
