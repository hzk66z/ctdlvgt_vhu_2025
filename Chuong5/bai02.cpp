#include <iostream>
using namespace std;


struct Queue {
    int* arr;       
    int front;    
    int rear;       
    int maxSize;    
};

void createQueue(Queue& q, int size) {
    q.arr = new int[size];
    q.maxSize = size;
    q.front = -1;  
    q.rear = -1;
}

void initQueue(Queue& q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}


void enqueue(Queue& q, int x) {
    if (q.rear == q.maxSize - 1) {
        cout << "Queue day! Khong the them phan tu." << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = 0;
    }
    q.rear++;
    q.arr[q.rear] = x;
    cout << "Da them phan tu " << x << " vao Queue." << endl;
}


int dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue rong! Khong the lay phan tu." << endl;
        return -1;
    }
    int x = q.arr[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    } else {
        q.front++;
    }
    return x;
}


int peekFront(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue rong! Khong co phan tu de xem." << endl;
        return -1;
    }
    return q.arr[q.front];
}

int peekRear(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue rong! Khong co phan tu de xem." << endl;
        return -1;
    }
    return q.arr[q.rear];
}


void displayQueue(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue rong!" << endl;
        return;
    }
    cout << "Noi dung Queue: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}


void menu() {
    cout << "===========================MENU===========================" << endl;
    cout << "1. Khoi tao Queue rong" << endl;
    cout << "2. Them phan tu vao Queue" << endl;
    cout << "3. Lay phan tu ra khoi Queue" << endl;
    cout << "4. Xem phan tu o dau Queue" << endl;
    cout << "5. Xem phan tu o cuoi Queue" << endl;
    cout << "6. Hien thi noi dung Queue" << endl;
    cout << "0. Thoat chuong trinh" << endl;
    cout << "===========================================================" << endl;
}

int main() {
    Queue q;
    int choice, size, x;

    cout << "Nhap kich thuoc toi da cua Queue: ";
    cin >> size;
    createQueue(q, size);

    do {
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                initQueue(q);
                cout << "Da khoi tao Queue rong." << endl;
                break;
            case 2:
                cout << "Nhap phan tu can them: ";
                cin >> x;
                enqueue(q, x);
                break;
            case 3:
                x = dequeue(q);
                if (x != -1) {
                    cout << "Da lay phan tu " << x << " ra khoi Queue." << endl;
                }
                break;
            case 4:
                x = peekFront(q);
                if (x != -1) {
                    cout << "Phan tu o dau Queue la: " << x << endl;
                }
                break;
            case 5:
                x = peekRear(q);
                if (x != -1) {
                    cout << "Phan tu o cuoi Queue la: " << x << endl;
                }
                break;
            case 6:
                displayQueue(q);
                break;
            case 0:
                cout << "Thoat chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    delete[] q.arr; 
    return 0;
}