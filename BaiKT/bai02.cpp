#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    Node* next;
};

// Khởi tạo danh sách liên kết đơn
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL; // Khởi tạo danh sách rỗng
    }

    // Hàm thêm phần tử vào cuối danh sách
    void themCuoi(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Hàm thêm phần tử vào đầu danh sách
    void themDau(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    // Hàm thêm phần tử vào vị trí bất kỳ
    void themVaoViTri(int x, int pos) {
        if (pos < 0) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        if (pos == 0) {
            themDau(x);
            return;
        }
        Node* newNode = new Node;
        newNode->data = x;
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Vi tri vuot qua danh sach!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Hàm xóa phần tử ở đầu danh sách
    void xoaDau() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Hàm xóa phần tử ở cuối danh sách
    void xoaCuoi() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    // Hàm xóa phần tử ở vị trí bất kỳ
    void xoaVaoViTri(int pos) {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        if (pos < 0) {
            cout << "Vi tri khong hop le!" << endl;
            return;
        }
        if (pos == 0) {
            xoaDau();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Vi tri khong ton tai!" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Hàm tìm vị trí của phần tử x
    void timViTri(int x) {
        Node* temp = head;
        int pos = 0;
        bool found = false;
        while (temp != NULL) {
            if (temp->data == x) {
                cout << "Phan tu " << x << " xuat hien tai vi tri: " << pos << endl;
                found = true;
            }
            temp = temp->next;
            pos++;
        }
        if (!found) {
            cout << "Khong tim thay " << x << " trong danh sach!" << endl;
        }
    }

    // Hàm xóa phần tử có giá trị x
    void xoaPhanTuX(int x) {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != x) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Khong tim thay " << x << " de xoa!" << endl;
            return;
        }
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    // Hàm xuất danh sách
    void xuatDanhSach() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Danh sach: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Hàm xuất các phần tử chia hết cho 2 hoặc cho 3
    void xuatPhanTuChiaHet2Hoac3() {
        if (head == NULL) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        bool hasElement = false;
        cout << "Cac phan tu chia het cho 2 hoac 3: ";
        while (temp != NULL) {
            if (temp->data % 2 == 0 || temp->data % 3 == 0) {
                cout << temp->data << " ";
                hasElement = true;
            }
            temp = temp->next;
        }
        if (!hasElement) {
            cout << "Khong co phan tu nao chia het cho 2 hoac 3!" << endl;
        } else {
            cout << endl;
        }
    }

    // Hàm giải phóng bộ nhớ
    ~LinkedList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Hàm menu
void menu() {
    cout << "===========================MENU===========================" << endl;
    cout << "1. Them phan tu vao cuoi danh sach" << endl;
    cout << "2. Them phan tu vao dau danh sach" << endl;
    cout << "3. Them phan tu vao vi tri bat ky" << endl;
    cout << "4. Xoa phan tu o dau danh sach" << endl;
    cout << "5. Xoa phan tu o cuoi danh sach" << endl;
    cout << "6. Xoa phan tu o vi tri bat ky" << endl;
    cout << "7. Tim vi tri cua phan tu x" << endl;
    cout << "8. Xoa phan tu co gia tri x" << endl;
    cout << "9. Xuat danh sach" << endl;
    cout << "10. Xuat cac phan tu chia het cho 2 hoac 3" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "===========================================================" << endl;
}

int main() {
    LinkedList list;
    int choice, x, pos;

    do {
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Nhap phan tu can them: ";
                cin >> x;
                list.themCuoi(x);
                break;
            case 2:
                cout << "Nhap phan tu can them: ";
                cin >> x;
                list.themDau(x);
                break;
            case 3:
                cout << "Nhap phan tu can them: ";
                cin >> x;
                cout << "Nhap vi tri: ";
                cin >> pos;
                list.themVaoViTri(x, pos);
                break;
            case 4:
                list.xoaDau();
                break;
            case 5:
                list.xoaCuoi();
                break;
            case 6:
                cout << "Nhap vi tri can xoa: ";
                cin >> pos;
                list.xoaVaoViTri(pos);
                break;
            case 7:
                cout << "Nhap phan tu can tim: ";
                cin >> x;
                list.timViTri(x);
                break;
            case 8:
                cout << "Nhap phan tu can xoa: ";
                cin >> x;
                list.xoaPhanTuX(x);
                break;
            case 9:
                list.xuatDanhSach();
                break;
            case 10:
                list.xuatPhanTuChiaHet2Hoac3();
                break;
            case 0:
                cout << "Thoat chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    return 0;
}