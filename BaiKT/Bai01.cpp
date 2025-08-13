#include <iostream>
using namespace std;

void nhapMang(int &n, int a[]);
void xuatMang(int n, int a[]);
void HoanVi(int &a, int &b); 
void InterchangeSort(int a[], int n);
void BubbleSort(int a[], int n);
void InsertionSort(int n, int a[]);
void viTriXuatHienCuaX(int n, int a[]);

void nhapMang(int &n, int a[]) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void xuatMang(int n, int a[]) {
    cout << "Mang da nhap la: ";
    for(int i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
}

void menu() {
    cout << "===========================MENU===========================" << endl;
    cout << "1. Xuat mang da nhap ra man hinh" << endl;
    cout << "2. Thuat toan Interchange Sort sap xep giam dan" << endl;
    cout << "3. Thuat toan Bubble Sort sap xep giam dan" << endl;
    cout << "4. Thuat toan Insertion Sort sap xep giam dan" << endl;
    cout << "5. Tim x, xuat ra vi tri cua x" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "===========================================================" << endl;
}

void HoanVi(int &a, int &b) {
    int tam = a;
    a = b;
    b = tam;
}

void InterchangeSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (a[j] > a[i]) { 
                HoanVi(a[i], a[j]);
            }
        }
    }
}

void BubbleSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = n-1; j > i; j--) {
            if (a[j] > a[j-1]) { 
                HoanVi(a[j], a[j-1]);
            }
        }
    }
}

void InsertionSort(int n, int a[]) {
    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j;
        for(j = i - 1; j >= 0 && a[j] < key; j--) { 
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}

void viTriXuatHienCuaX(int n, int a[]) {
    int x;
    cout << "Nhap x can tim: ";
    cin >> x;
    cin.ignore();
    
    bool ktra = false;
    for(int i = 0; i < n; i++) {
        if(a[i] == x) {
            ktra = true;
        }
    }
    if(ktra == true) {
        cout << "vi tri xuat hien cua " << x << " la: "; 
        for(int i = 0; i < n; i++) {
            if(a[i] == x) {
                cout << " " << i;
            }
        }
    }
    if(ktra == false) {
        cout << "x khong co trong mang!" << endl;
    }
    cout << endl;
}

int main() {
    int a[30];
    int n;
    
    do {
        cout << "Nhap so luong phan tu: ";
        cin >> n;
    } while(n < 1 || n > 20);
    nhapMang(n, a);
    
    while(true) {
        menu();
        int choice;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                xuatMang(n, a);
                break;
            }
            case 2: {
                InterchangeSort(a, n);
                xuatMang(n, a);
                break;
            }
            case 3: {
                BubbleSort(a, n);
                xuatMang(n, a);
                break;
            }
            case 4: {
                InsertionSort(n, a);
                xuatMang(n, a);
                break;
            }
            case 5: {
                viTriXuatHienCuaX(n, a);
                xuatMang(n, a);
                break;
            }
            case 0:
                return 0; 
            default:
                break;
        }
    }
    return 0;
}