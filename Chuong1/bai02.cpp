#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Ngay {
    int ngay, thang, nam;
};

struct SanPham {
    string maSP;
    string tenSP;
    double donGia;
    Ngay ngaySX;
    int soNgaySD;
    string noiSX;
};

typedef SanPham sp;

void menu();
void nhapDanhSach(int& n, sp ds[]);
void xuatDanhSach(int n, sp ds[]);
void inSanPhamDuoi30Ngay(int n, sp ds[]);
void inTheoNoiSanXuat(int n, sp ds[]);
void inTheoNamSanXuat(int n, sp ds[]);
void inDonGiaTren50000(int n, sp ds[]);

int main() {
    int n;
    sp arr[40]; // Danh sach toi da 40 sp
    int luaChon;
    while(true) {
        menu();
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1: {
				nhapDanhSach(n, arr); 
				break;
			}
            case 2: {
            	xuatDanhSach(n, arr);
				break;
			}
            case 3: {
            	inSanPhamDuoi30Ngay(n, arr);
				break;
			}
            case 4: {
            	inTheoNoiSanXuat(n, arr);
				break;
			}
            case 5: {
            	inTheoNamSanXuat(n, arr);
				break;
			}
            case 6: {
            	inDonGiaTren50000(n, arr);
				break;
			}
            default: 
			break;
        }
        if(luaChon == 0)
        	return 0;
    }
    return 0;
}

void menu() {
    cout << "\n===================================="<<endl;
    cout << "1. Nhap danh sach san pham"<<endl;
    cout << "2. Xuat danh sach san pham"<<endl;
    cout << "3. In san pham co so ngay su dung < 30"<<endl;
    cout << "4. Tim theo noi san xuat"<<endl;
    cout << "5. Tim theo nam san xuat"<<endl;
    cout << "6. In san pham co don gia > 50000"<<endl;
    cout << "0. Thoat"<<endl;
    cout << "======================================"<<endl;
}

void nhapDanhSach(int& n, SanPham ds[]) {
    do {
        cout << "Nhap so luong san pham (toi da 40): ";
        cin >> n;
    } while (n < 1 || n > 40);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin san pham thu " << i + 1 << ":"<<endl;
        cout << "Ma san pham: "; 
		getline(cin, ds[i].maSP);
        cout << "Ten san pham: "; 
		getline(cin, ds[i].tenSP);
        cout << "Don gia: "; 
		cin >> ds[i].donGia;
        cout << "Ngay san xuat (ngay thang nam): ";
        cin >> ds[i].ngaySX.ngay >> ds[i].ngaySX.thang >> ds[i].ngaySX.nam;
        cout << "So ngay su dung: "; 
		cin >> ds[i].soNgaySD;
        cin.ignore();
        cout << "Noi san xuat: "; 
		getline(cin, ds[i].noiSX);
    }
}

void xuatDanhSach(int n, SanPham ds[]) {
    cout << left << setw(10) << "MaSP" << setw(20) << "TenSP"
         << setw(12) << "DonGia" << setw(15) << "NgaySX"
         << setw(10) << "SoNgay" << setw(20) << "NoiSX" << endl;
    cout << string(87, '-') << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << ds[i].maSP
             << setw(20) << ds[i].tenSP
             << setw(12) << fixed << setprecision(2) << ds[i].donGia
             << setw(2) << ds[i].ngaySX.ngay << "/" << ds[i].ngaySX.thang << "/" << ds[i].ngaySX.nam << string(4, ' ')
             << setw(10) << ds[i].soNgaySD
             << setw(20) << ds[i].noiSX << endl;
    }
}

void inSanPhamDuoi30Ngay(int n, SanPham ds[]) {
    cout << "\nSan pham co so ngay su dung < 30:\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].soNgaySD < 30) {
            cout << ds[i].tenSP << " (" << ds[i].soNgaySD << " ngay)\n";
        }
    }
}

void inTheoNoiSanXuat(int n, SanPham ds[]) {
    string noi;
    cin.ignore();
    cout << "Nhap noi san xuat can tim: ";
    getline(cin, noi);
    cout << "\nSan pham san xuat tai '" << noi << "':\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].noiSX == noi) {
            cout << ds[i].tenSP << " - " << ds[i].noiSX << endl;
        }
    }
}

void inTheoNamSanXuat(int n, SanPham ds[]) {
    int nam;
    cout << "Nhap nam san xuat can tim: ";
    cin >> nam;
    cout << "\nSan pham san xuat nam " << nam << ":\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].ngaySX.nam == nam) {
            cout << ds[i].tenSP << " - " << ds[i].ngaySX.ngay << "/" << ds[i].ngaySX.thang << "/" << ds[i].ngaySX.nam << endl;
        }
    }
}

void inDonGiaTren50000(int n, SanPham ds[]) {
	bool check = false;
    cout << "\nSan pham co don gia > 50000:\n";
    for (int i = 0; i < n; i++) {
        if (ds[i].donGia > 50000) {
        	check = true;
            cout << ds[i].tenSP << " - " << ds[i].donGia << endl;
        }
    }
    if(check == false){
    	cout<<"Khong co san pham > 50000!"<<endl;
	}
}
