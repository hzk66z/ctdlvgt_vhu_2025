#include "iostream"
#include "iomanip"
using namespace std;

struct THUVIEN{
	string maSach;
	string tenSach;
	string tacGia;
	string nhaXuatBan;
	int namXuatBan;
	int soLuong;
	double donGia;
};

typedef THUVIEN tv;

void menu();
void nhapDanhSach(int& n, tv arr[]);
void xuatDanhSach(int n, tv arr[]);
double tinhTongTien(int n, tv arr[]);
void xuatSachTheoNhaXuatBan(int n, tv arr[]);
void xuatSachTheoNamXuatBan(int n, tv arr[]);
void xuatSachTheoTacGia(int n, tv arr[]);

int main(){
	int n;
	tv arr[30]; // Toi da 30 sach
	int luaChon;
	while(true){
		menu();
		do{
		cout<<"Moi nhap lua chon muon thuc hien: ";
		cin >> luaChon;
		} while(luaChon < 0 || luaChon > 6);
		switch(luaChon){
			case 1: {
				nhapDanhSach(n, arr);
				break;
			}
			case 2:{
				xuatDanhSach(n, arr);
				break;
			}
			case 3:{
				double tong = tinhTongTien(n, arr);
    			cout << fixed << setprecision(2);
    			cout << "\n==> Tong tien phai tra la: " << tong << " VND\n";
				break;
			}
			case 4:{
				xuatSachTheoNhaXuatBan(n, arr);
				break;
			}
			case 5:{
				xuatSachTheoNamXuatBan(n, arr);
				break;
			}
			case 6:{
				xuatSachTheoTacGia(n, arr);
				break;
			}
			default:
				return 0;
		}	
		if (luaChon == 0){
		break;
	}
	}
}
void menu(){
	cout << "====================================================================="<<endl;
	cout << "1. Nhap mot danh sach cac dau sach co trong thu vien."<<endl;
	cout << "2. Xuat danh sach da nhap ra man hinh."<<endl;
	cout << "3. Tinh tong tien phai tra khi mua cac dau sach co trong danh sach." <<endl;
	cout << "4. In ra man hinh cac dau sach thuoc nha xuat ban Dai hoc quoc gia." <<endl;
	cout << "5. Tim va in ra man hinh cac dau sach duoc xuat ban trong nam Y."<<endl;
	cout << "6. In ra man hinh cac dau sach khi biet ten tac gia."<<endl;
	cout << "0. Thoat"<<endl;
	cout << "====================================================================="<<endl;
}
void nhapDanhSach(int& n, tv arr[]){
	do{
		cout <<"Nhap so luong dau sach: ";
		cin >> n;
	} while (n < 1 || n > 30);
	
	cin.ignore();
	
	for(int i = 0 ; i<n; i++){
		cout<<"Nhap thong tin sach dau sach thu "<<i + 1<< ":\n";
		do{
			cout<<"Ma sach: ";
			getline(cin, arr[i].maSach);
			cout<<"Ten sach: ";
			getline(cin, arr[i].tenSach);
			cout<<"Tac gia: ";
			getline(cin, arr[i].tacGia);
			cout<<"Nha xuat ban: ";
			getline(cin, arr[i].nhaXuatBan);
			cout<<"Nam xuat ban: ";
			cin >> arr[i].namXuatBan;
			cout<<"So luong: ";
			cin >> arr[i].soLuong;
			cout<<"Don gia: ";
			cin >> arr[i].donGia;
			cin.ignore();
			if(arr[i].maSach.length() < 1 || arr[i].maSach.length() > 10 
		|| arr[i].tenSach.length() < 1 || arr[i].tenSach.length()>50
		|| arr[i].tacGia.length() < 1 || arr[i].tacGia.length()>50
		|| arr[i].nhaXuatBan.length() < 1 || arr[i].nhaXuatBan.length()>50
		|| arr[i].namXuatBan < 1000 || arr[i].namXuatBan > 9999
		|| arr[i].soLuong < 0
		|| arr[i].donGia < 0){
			cout<<"Thong tin da nhap khong hop le vui long nhap lai!"<<endl;
		}
		} while (arr[i].maSach.length() < 1 || arr[i].maSach.length() > 10 
		|| arr[i].tenSach.length() < 1 || arr[i].tenSach.length()>50
		|| arr[i].tacGia.length() < 1 || arr[i].tacGia.length()>50
		|| arr[i].nhaXuatBan.length() < 1 || arr[i].nhaXuatBan.length()>50
		|| arr[i].namXuatBan < 1000 || arr[i].namXuatBan > 9999
		|| arr[i].soLuong < 0
		|| arr[i].donGia < 0);
	}
}
void xuatDanhSach(int n, tv arr[]) {
    cout << endl;

    cout << left
         << setw(15) << "MA SACH"
         << setw(30) << "TEN SACH"
         << setw(25) << "TAC GIA"
         << setw(25) << "NHA XUAT BAN"
         << setw(15) << "NAM XB"
         << setw(12) << "SO LUONG"
         << setw(10) << "DON GIA" << endl;

    cout << string(132, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(15) << arr[i].maSach
             << setw(30) << arr[i].tenSach
             << setw(25) << arr[i].tacGia
             << setw(25) << arr[i].nhaXuatBan
             << setw(15) << arr[i].namXuatBan
             << setw(12) << arr[i].soLuong
             << fixed << setprecision(2) << setw(10) << arr[i].donGia
             << endl;
    }
}
double tinhTongTien(int n, tv arr[]){
	double tong = 0;
	for(int i = 0; i < n; i++){
		tong += arr[i].soLuong * arr[i].donGia;
	}
	return tong;
}
void xuatSachTheoNhaXuatBan(int n, tv arr[]) {
    bool coSach = false;
    cout << "\n==> Cac sach thuoc nha xuat ban 'Dai hoc Quoc gia':\n";

    cout << left
         << setw(15) << "MA SACH"
         << setw(30) << "TEN SACH"
         << setw(25) << "TAC GIA"
         << setw(25) << "NHA XUAT BAN"
         << setw(15) << "NAM XB"
         << setw(12) << "SO LUONG"
         << setw(10) << "DON GIA" << endl;

    cout << string(132, '-') << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].nhaXuatBan == "Dai hoc Quoc gia") {
            coSach = true;
            cout << left
                 << setw(15) << arr[i].maSach
                 << setw(30) << arr[i].tenSach
                 << setw(25) << arr[i].tacGia
                 << setw(25) << arr[i].nhaXuatBan
                 << setw(15) << arr[i].namXuatBan
                 << setw(12) << arr[i].soLuong
                 << fixed << setprecision(2) << setw(10) << arr[i].donGia
                 << endl;
        }
    }

    if (!coSach) {
        cout << "Khong co sach nao thuoc NXB 'Dai hoc Quoc gia'.\n";
    }
}
void xuatSachTheoNamXuatBan(int n, tv arr[]) {
    int nam;
    cout << "Nhap nam xuat ban can tim: ";
    cin >> nam;

    bool timThay = false;
    cout << "\n==> Cac sach duoc xuat ban trong nam " << nam << ":\n";

    cout << left
         << setw(15) << "MA SACH"
         << setw(30) << "TEN SACH"
         << setw(25) << "TAC GIA"
         << setw(25) << "NHA XUAT BAN"
         << setw(15) << "NAM XB"
         << setw(12) << "SO LUONG"
         << setw(10) << "DON GIA" << endl;

    cout << string(132, '-') << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].namXuatBan == nam) {
            timThay = true;
            cout << left
                 << setw(15) << arr[i].maSach
                 << setw(30) << arr[i].tenSach
                 << setw(25) << arr[i].tacGia
                 << setw(25) << arr[i].nhaXuatBan
                 << setw(15) << arr[i].namXuatBan
                 << setw(12) << arr[i].soLuong
                 << fixed << setprecision(2) << setw(10) << arr[i].donGia
                 << endl;
        }
    }

    if (!timThay) {
        cout << "Khong co sach nao duoc xuat ban trong nam " << nam << ".\n";
    }
}
void xuatSachTheoTacGia(int n, tv arr[]) {
    string tenTacGia;
    cin.ignore();
    cout << "Nhap ten tac gia can tim: ";
    getline(cin, tenTacGia);

    bool timThay = false;
    cout << "\n==> Cac sach cua tac gia \"" << tenTacGia << "\":\n";

    cout << left
         << setw(15) << "MA SACH"
         << setw(30) << "TEN SACH"
         << setw(25) << "TAC GIA"
         << setw(25) << "NHA XUAT BAN"
         << setw(15) << "NAM XB"
         << setw(12) << "SO LUONG"
         << setw(10) << "DON GIA" << endl;

    cout << string(132, '-') << endl;

    for (int i = 0; i < n; i++) {
        if (arr[i].tacGia == tenTacGia) {
            timThay = true;
            cout << left
                 << setw(15) << arr[i].maSach
                 << setw(30) << arr[i].tenSach
                 << setw(25) << arr[i].tacGia
                 << setw(25) << arr[i].nhaXuatBan
                 << setw(15) << arr[i].namXuatBan
                 << setw(12) << arr[i].soLuong
                 << fixed << setprecision(2) << setw(10) << arr[i].donGia
                 << endl;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sach cua tac gia \"" << tenTacGia << "\".\n";
    }
}
