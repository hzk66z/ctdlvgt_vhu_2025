#include <iostream>
#include <stack>
using namespace std;


void convertToBase(int number, int base) {
    if (number == 0) {
        cout << "0" << endl;
        return;
    }

    stack<int> s; 
    int remainder;
    const string hexChars = "0123456789ABCDEF"; 


    while (number > 0) {
        remainder = number % base;
        s.push(remainder);
        number /= base;
    }

    cout << "So sau khi chuyen sang he co so " << base << " la: ";
    while (!s.empty()) {
        int digit = s.top();
        s.pop();
        if (base == 16 && digit >= 10) {
            cout << hexChars[digit]; 
        } else {
            cout << digit; 
        }
    }
    cout << endl;
}

int main() {
    int number, base;

    cout << "Nhap so nguyen he 10: ";
    cin >> number;
    cout << "Nhap co so muon chuyen sang (2, 8, 16): ";
    cin >> base;

    if (base != 2 && base != 8 && base != 16) {
        cout << "Co so khong hop le! Vui long nhap 2, 8 hoac 16." << endl;
        return 1;
    }

    if (number < 0) {
        cout << "So am khong duoc ho tro! Chuyen thanh so duong." << endl;
        number = -number;
    }
    convertToBase(number, base);

    return 0;
}