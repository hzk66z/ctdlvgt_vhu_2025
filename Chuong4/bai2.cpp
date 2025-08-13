#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct Node {
    int info;
    Node* Next;
};

struct SList {
    Node* head;
    Node* tail;
};

void InitSList(SList& sl) {
    sl.head = NULL;
    sl.tail = NULL;
}

Node* CreateNode(int x) {
    Node* p = new Node;
    if (p == NULL) {
        cout << "Khong du bo nho!";
        return NULL;
    }
    p->info = x;
    p->Next = NULL;
    return p;
}

void ShowNode(Node* p) {
    cout << p->info << " ";
}

int IsEmpty(SList sl) {
    return sl.head == NULL;
}

void ShowSList(SList sl) {
    if (IsEmpty(sl)) {
        cout << "\nDanh sach rong.\n";
        return;
    }
    cout << "\nNoi dung danh sach: ";
    for (Node* p = sl.head; p != NULL; p = p->Next)
        ShowNode(p);
    cout << endl;
}

int InsertHead(SList& sl, Node* p) {
    if (p == NULL) return 0;
    if (IsEmpty(sl)) {
        sl.head = sl.tail = p;
    }
    else {
        p->Next = sl.head;
        sl.head = p;
    }
    return 1;
}

int InsertTail(SList& sl, Node* p) {
    if (p == NULL) return 0;
    if (IsEmpty(sl)) {
        sl.head = sl.tail = p;
    }
    else {
        sl.tail->Next = p;
        sl.tail = p;
    }
    return 1;
}

int InsertAfter(SList& sl, Node* q, Node* p) {
    if (q == NULL || p == NULL) return 0;
    p->Next = q->Next;
    q->Next = p;
    if (sl.tail == q)
        sl.tail = p;
    return 1;
}

int Search(SList sl, int x) {
    Node* p = sl.head;
    int pos = 1;
    while (p != NULL && p->info != x) {
        p = p->Next;
        pos++;
    }
    return (p != NULL) ? pos : 0;
}

int DeleteHead(SList& sl) {
    if (IsEmpty(sl)) return 0;
    Node* p = sl.head;
    sl.head = sl.head->Next;
    delete p;
    if (sl.head == NULL) sl.tail = NULL;
    return 1;
}

int DeleteTail(SList& sl) {
    if (IsEmpty(sl)) return 0;
    if (sl.head == sl.tail) {
        delete sl.head;
        sl.head = sl.tail = NULL;
    }
    else {
        Node* p = sl.head;
        while (p->Next != sl.tail)
            p = p->Next;
        delete sl.tail;
        sl.tail = p;
        sl.tail->Next = NULL;
    }
    return 1;
}

int DeleteAfter(SList& sl, Node* q) {
    if (q == NULL || q->Next == NULL) return 0;
    Node* temp = q->Next;
    q->Next = temp->Next;
    if (temp == sl.tail)
        sl.tail = q;
    delete temp;
    return 1;
}

void CreateSList(SList& sl) {
    InitSList(sl);
    int n, x;
    do {
        cout << "Nhap so phan tu (n > 0): ";
        cin >> n;
    } while (n <= 0);

    for (int i = 1; i <= n; i++) {
        cout << "Nhap gia tri thu " << i << ": ";
        cin >> x;
        Node* p = CreateNode(x);
        InsertTail(sl, p);
    }
}

void CreateAutoSList(SList& sl) {
    InitSList(sl);
    int n, x;
    do {
        cout << "Nhap so phan tu (n > 0): ";
        cin >> n;
    } while (n <= 0);

    srand(time(NULL));
    for (int i = 1; i <= n; i++) {
        x = (rand() % 199) - 99;
        Node* p = CreateNode(x);
        InsertTail(sl, p);
    }
}

void chenThemNut(SList& sl, int x, int y) {
    Node* p1 = CreateNode(x);
    Node* p2 = CreateNode(y);
    if (p1 && p2) {
        InsertTail(sl, p1);
        InsertTail(sl, p2);
    }
}

void vietHamXoaCacPhanTuLonHonGiaTriX(SList& sl, int x) {
    Node* p = sl.head;
    Node* prev = NULL;
    while (p != NULL) {
        if (p->info > x) {
            if (p == sl.head) {
                DeleteHead(sl);
                p = sl.head;
            }
            else if (p == sl.tail) {
                DeleteTail(sl);
                p = NULL;
            }
            else {
                DeleteAfter(sl, prev);
                p = (prev) ? prev->Next : sl.head;
            }
        }
        else {
            prev = p;
            p = p->Next;
        }
    }
}

void vietHamXoaCacPhanTuChan(SList& sl) {
    Node* p = sl.head;
    Node* prev = NULL;
    while (p != NULL) {
        if (p->info % 2 == 0) {
            if (p == sl.head) {
                DeleteHead(sl);
                p = sl.head;
            }
            else if (p == sl.tail) {
                DeleteTail(sl);
                p = NULL;
            }
            else {
                DeleteAfter(sl, prev);
                p = (prev) ? prev->Next : sl.head;
            }
        }
        else {
            prev = p;
            p = p->Next;
        }
    }
}

void sapXepDSLKDTangDan(SList& sl) {
    for (Node* i = sl.head; i != NULL; i = i->Next)
        for (Node* j = i->Next; j != NULL; j = j->Next)
            if (j->info < i->info) swap(i->info, j->info);
}

void choBietTongDSLKDCaoBaoNhieuSoNguyenTo(SList sl) {
    int count = 0;
    auto isPrime = [](int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    };
    for (Node* p = sl.head; p != NULL; p = p->Next)
        if (isPrime(p->info)) count++;
    cout << "So luong so nguyen to: " << count << endl;
}

void tinhTongCacSoChinhPhuongTrongDSLKd(SList sl) {
    int sum = 0;
    auto isPerfectSquare = [](int n) {
        int sqrtN = sqrt(n);
        return sqrtN * sqrtN == n;
    };
    for (Node* p = sl.head; p != NULL; p = p->Next)
        if (isPerfectSquare(p->info)) sum += p->info;
    cout << "Tong cac so chinh phuong: " << sum << endl;
}

void timPhanTuNhoNhatPhanTuLonNhatTrongDSLKd(SList sl) {
    if (IsEmpty(sl)) {
        cout << "Danh sach rong" << endl;
        return;
    }
    int min = sl.head->info, max = sl.head->info;
    for (Node* p = sl.head; p != NULL; p = p->Next) {
        if (p->info < min) min = p->info;
        if (p->info > max) max = p->info;
    }
    cout << "Phan tu nho nhat: " << min << ", Phan tu lon nhat: " << max << endl;
}

void Menu() {
    cout << "\n====== MENU ======" << endl;
    cout << "1. Tao danh sach nhap tay" << endl;
    cout << "2. Tao danh sach tu dong" << endl;
    cout << "3. Hien thi danh sach" << endl;
    cout << "4. Them phan tu vao dau" << endl;
    cout << "5. Them phan tu vao cuoi" << endl;
    cout << "6. Tim kiem phan tu" << endl;
    cout << "7. Xoa dau danh sach" << endl;
    cout << "8. Xoa cuoi danh sach" << endl;
    cout << "9. Chen them nut p chua gia tri x va nut q chua gia tri y" << endl;
    cout << "10. Viet ham xoa cac phan tu lon hon gia tri x" << endl;
    cout << "11. Viet ham xoa cac phan tu chan" << endl;
    cout << "12. Sap xep danh sach tang dan" << endl;
    cout << "13. Cho biet tong danh sach co bao nhieu so nguyen to" << endl;
    cout << "14. Tinh tong cac so chinh phuong trong danh sach" << endl;
    cout << "15. Tim phan tu nho nhat va phan tu lon nhat trong danh sach" << endl;
    cout << "16. Thoat" << endl;
    cout << "==================" << endl;
}

int main() {
    SList sl;
    InitSList(sl);
    int choice, x, y;

    do {
        Menu();
        cout << "Chon chuc nang: ";
        cin >> choice;
        switch (choice) {
        case 1:
            CreateSList(sl);
            break;
        case 2:
            CreateAutoSList(sl);
            break;
        case 3:
            ShowSList(sl);
            break;
        case 4:
            cout << "Nhap gia tri can them dau: ";
            cin >> x;
            InsertHead(sl, CreateNode(x));
            break;
        case 5:
            cout << "Nhap gia tri can them cuoi: ";
            cin >> x;
            InsertTail(sl, CreateNode(x));
            break;
        case 6:
            cout << "Nhap gia tri can tim: ";
            cin >> x;
            {
                int pos = Search(sl, x);
                if (pos)
                    cout << "Tim thay " << x << " tai vi tri " << pos << endl;
                else
                    cout << "Khong tim thay " << x << endl;
            }
            break;
        case 7:
            DeleteHead(sl);
            break;
        case 8:
            DeleteTail(sl);
            break;
        case 9:
            cout << "Nhap gia tri x: ";
            cin >> x;
            cout << "Nhap gia tri y: ";
            cin >> y;
            chenThemNut(sl, x, y);
            break;
        case 10:
            cout << "Nhap gia tri x: ";
            cin >> x;
            vietHamXoaCacPhanTuLonHonGiaTriX(sl, x);
            break;
        case 11:
            vietHamXoaCacPhanTuChan(sl);
            break;
        case 12:
            sapXepDSLKDTangDan(sl);
            break;
        case 13:
            choBietTongDSLKDCaoBaoNhieuSoNguyenTo(sl);
            break;
        case 14:
            tinhTongCacSoChinhPhuongTrongDSLKd(sl);
            break;
        case 15:
            timPhanTuNhoNhatPhanTuLonNhatTrongDSLKd(sl);
            break;
        case 16:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Chuc nang khong hop le!\n";
        }
    } while (choice != 16);

    return 0;
}