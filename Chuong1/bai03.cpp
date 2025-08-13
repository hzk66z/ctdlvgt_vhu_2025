#include <iostream> 
#include <string>   
#include <vector>   
#include <limits>   


using namespace std;


struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};


struct NgayVaoLam {
    int ngay;
    int thang;
    int nam;
};


struct NhanVien {
    string maNV;
    string tenNV;
    NgaySinh n1; 
    NgayVaoLam n2; 
};

struct PhongBan {
    string maPB;
    string tenPB;
    string truongPB; 
    vector<NhanVien> danhSachNhanVien; 
};


typedef PhongBan pb;


void menu();
void nhapDanhSach(int& n, pb ds[]);
void xuatDanhSach(int n, pb ds[]);
void inDanhSachNVThuocMaPB(int n, pb ds[]);
void inThongTinTruongPhongT10(int n, pb ds[]);
void inThongTinPhongBan(int n, pb ds[]);
void themNhanVienVaoPhongBan(int n, pb ds[]); 

int main() {
    int n; 
    pb arr[20]; 
    int luaChon;

    while (true) { 
        menu(); 
        cout << "Nhap lua chon: ";
        cin >> luaChon; 
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                inDanhSachNVThuocMaPB(n, arr);
                break;
            }
            case 4: {
                inThongTinTruongPhongT10(n, arr);
                break;
            }
            case 5: { 
                inThongTinPhongBan(n, arr);
                break;
            }
            case 0: {
                cout << "Ket thuc chuong trinh." << endl;
                return 0; 
            }
            default: { 
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
            }
        }
        cout << "\n========================================\n";
    }

    return 0;
}


void menu() {
    cout << "\n================== MENU ==================" << endl;
    cout << "1. Nhap danh sach cac phong ban" << endl;
    cout << "2. Xuat danh sach cac phong ban da nhap" << endl;
    cout << "3. In danh sach nhan vien thuoc ma phong ban" << endl;
    cout << "4. In ra cac truong phong co ngay sinh thang 10" << endl;
    cout << "5. In thong tin phong ban khi biet ma so truong phong" << endl;
    cout << "0. Thoat" << endl;
    cout << "==========================================" << endl;
}


void nhapDanhSach(int& n, pb ds[]) {
    do {
        cout << "Nhap danh sach cac phong ban (toi da 20 phong): ";
        cin >> n;
        if (n < 1 || n > 20) {
            cout << "So luong phong ban khong hop le. Vui long nhap tu 1 den 20." << endl;
        }
    } while (n < 1 || n > 20);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin phong ban thu " << i + 1 << ":" << endl;
        cout << "Ma phong ban: ";
        getline(cin, ds[i].maPB);
        cout << "Ten phong ban: ";
        getline(cin, ds[i].tenPB);
        cout << "Ma so truong phong: ";
        getline(cin, ds[i].truongPB); 

        
        int soLuongNV;
        cout << "Nhap so luong nhan vien trong phong " << ds[i].tenPB << ": ";
        cin >> soLuongNV;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        ds[i].danhSachNhanVien.resize(soLuongNV); 

        for (int j = 0; j < soLuongNV; j++) {
            cout << "  Nhap thong tin nhan vien thu " << j + 1 << ":" << endl;
            cout << "    Ma nhan vien: ";
            getline(cin, ds[i].danhSachNhanVien[j].maNV);
            cout << "    Ten nhan vien: ";
            getline(cin, ds[i].danhSachNhanVien[j].tenNV);

            cout << "    Ngay sinh (dd mm yyyy): ";
            cin >> ds[i].danhSachNhanVien[j].n1.ngay
                >> ds[i].danhSachNhanVien[j].n1.thang
                >> ds[i].danhSachNhanVien[j].n1.nam;

            cout << "    Ngay vao lam (dd mm yyyy): ";
            cin >> ds[i].danhSachNhanVien[j].n2.ngay
                >> ds[i].danhSachNhanVien[j].n2.thang
                >> ds[i].danhSachNhanVien[j].n2.nam;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


void xuatDanhSach(int n, pb ds[]) {
    if (n == 0) {
        cout << "Chua co du lieu phong ban nao duoc nhap." << endl;
        return;
    }
    cout << "\n============== DANH SACH PHONG BAN ==============" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Phong ban " << i + 1 << ":" << endl;
        cout << "  Ma PB: " << ds[i].maPB << endl;
        cout << "  Ten PB: " << ds[i].tenPB << endl;
        cout << "  Ma Truong PB: " << ds[i].truongPB << endl;
        cout << "  So luong nhan vien: " << ds[i].danhSachNhanVien.size() << endl;
        if (!ds[i].danhSachNhanVien.empty()) {
            cout << "  --- Danh sach nhan vien trong phong ---" << endl;
            for (const auto& nv : ds[i].danhSachNhanVien) {
                cout << "    - Ma NV: " << nv.maNV
                     << ", Ten NV: " << nv.tenNV
                     << ", Sinh: " << nv.n1.ngay << "/" << nv.n1.thang << "/" << nv.n1.nam
                     << ", Vao lam: " << nv.n2.ngay << "/" << nv.n2.thang << "/" << nv.n2.nam << endl;
            }
        }
        cout << "------------------------------------------" << endl;
    }
    cout << "=================================================" << endl;
}


void inDanhSachNVThuocMaPB(int n, pb ds[]) {
    if (n == 0) {
        cout << "Chua co du lieu phong ban de tim kiem." << endl;
        return;
    }
    string maCanTim;
    cout << "Nhap ma phong ban can tim nhan vien: ";
    getline(cin, maCanTim);

    bool timThayPhongBan = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].maPB == maCanTim) {
            timThayPhongBan = true;
            cout << "\n============== NHAN VIEN PHONG BAN " << ds[i].tenPB << " ==============" << endl;
            if (ds[i].danhSachNhanVien.empty()) {
                cout << "Phong ban nay hien khong co nhan vien nao." << endl;
            } else {
                for (const auto& nv : ds[i].danhSachNhanVien) {
                    cout << "  - Ma NV: " << nv.maNV
                         << ", Ten NV: " << nv.tenNV
                         << ", Sinh: " << nv.n1.ngay << "/" << nv.n1.thang << "/" << nv.n1.nam
                         << ", Vao lam: " << nv.n2.ngay << "/" << nv.n2.thang << "/" << nv.n2.nam << endl;
                }
            }
            cout << "=================================================" << endl;
            break; 
        }
    }
    if (!timThayPhongBan) {
        cout << "Khong tim thay phong ban voi ma " << maCanTim << endl;
    }
}


void inThongTinTruongPhongT10(int n, pb ds[]) {
    if (n == 0) {
        cout << "Chua co du lieu phong ban de kiem tra." << endl;
        return;
    }
    cout << "\n======= TRUONG PHONG CO NGAY SINH THANG 10 =======" << endl;
    bool timThayTruongPhong = false;

    for (int i = 0; i < n; i++) {
      
        for (const auto& nv : ds[i].danhSachNhanVien) {
            if (nv.maNV == ds[i].truongPB) { 
                if (nv.n1.thang == 10) { 
                    timThayTruongPhong = true;
                    cout << "  - Phong ban: " << ds[i].tenPB << endl;
                    cout << "    Ma Truong Phong: " << nv.maNV << endl;
                    cout << "    Ten Truong Phong: " << nv.tenNV << endl;
                    cout << "    Ngay sinh: " << nv.n1.ngay << "/" << nv.n1.thang << "/" << nv.n1.nam << endl;
                    cout << "------------------------------------------" << endl;
                }
                break; 
            }
        }
    }
    if (!timThayTruongPhong) {
        cout << "Khong co truong phong nao sinh vao thang 10." << endl;
    }
    cout << "==================================================" << endl;
}

void inThongTinPhongBan(int n, pb ds[]) {
    if (n == 0) {
        cout << "Chua co du lieu phong ban de tim kiem." << endl;
        return;
    }
    string maTruongPhongCanTim;
    cout << "Nhap ma so truong phong can tim phong ban: ";
    getline(cin, maTruongPhongCanTim);

    bool timThayPhong = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].truongPB == maTruongPhongCanTim) {
            timThayPhong = true;
            cout << "\n============== THONG TIN PHONG BAN ==============" << endl;
            cout << "  Ma PB: " << ds[i].maPB << endl;
            cout << "  Ten PB: " << ds[i].tenPB << endl;
            cout << "  Ma Truong PB: " << ds[i].truongPB << endl;
            cout << "  So luong nhan vien: " << ds[i].danhSachNhanVien.size() << endl;
            if (!ds[i].danhSachNhanVien.empty()) {
                 cout << "  --- Danh sach nhan vien trong phong ---" << endl;
                 for (const auto& nv : ds[i].danhSachNhanVien) {
                     cout << "    - Ma NV: " << nv.maNV
                          << ", Ten NV: " << nv.tenNV
                          << ", Sinh: " << nv.n1.ngay << "/" << nv.n1.thang << "/" << nv.n1.nam
                          << ", Vao lam: " << nv.n2.ngay << "/" << nv.n2.thang << "/" << nv.n2.nam << endl;
                 }
             }
            cout << "===================================================" << endl;
            break;
        }
    }
    if (!timThayPhong) {
        cout << "Khong tim thay phong ban voi ma truong phong " << maTruongPhongCanTim << endl;
    }
}