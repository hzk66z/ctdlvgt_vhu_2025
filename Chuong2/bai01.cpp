  #include "iostream"

using namespace std;

// Khai báo hàm chức năng - hàm thực thi
void nhapMang(int n, int a[]);
void xuatMang(int n, int a[]);
void menu();
void insertionSort(int n, int a[]);
void InterchangeSort(int a[], int n );
void BubbleSort(int a[], int n );
void QuickSort(int a[], int l, int r);
void SelectionSort(int a[], int n );
void HoanVi(int a, int b);

// Khai báo hàm main

int main(){
	// Khai báo biến
	int l, r;
	int n;
	int a[30];
	// Lập điều kiện nhập số phần tử có tối đa 30 có nghĩa là từ 1 - 30
	// Lớn hơn hoặc nhỏ hơn sẽ lập lại câu lệnh nhập
	do {
		// thực thi câu lệnh
		cout << "Nhap so phan tu: ";
		cin >> n;
	} while (n < 1 || n > 30);
	nhapMang(n, a);
	
	// Tạo vòng lặp vô hạn cho menu
	while(true){
		// Xuất bảng menu thực hiện chức năng
		menu();
		
		// Tạo biến lựa chọn
		int choice;
		cout << "Moi nhap lua chon cua ban: ";
		cin >> choice;
		
		switch(choice){
			case 1:{
				xuatMang(n, a);
				break;
			}
			case 2:{
				insertionSort(n, a);
				xuatMang(n, a);
				break;
			}
			case 3:{
				InterchangeSort(a, n);
				xuatMang(n, a);
				break;
			}
			case 4:{
				BubbleSort(a, n);
				xuatMang(n, a);
				break;
			}
			case 5:{
				QuickSort(a, l, r);
				xuatMang(n, a);
				break;
			}
			case 6:{
				SelectionSort(a, n);
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

void HoanVi(int a, int b){
	int tam = a;
	a = b;
	b = tam;
}

// Tạo menu theo bài tập
void menu(){
	cout << "====================================================" << endl;
	cout << "1. Xuat mang da nhap" << endl;
	cout << "2. Thuat toan Insertion Sort sap xep tang dan." << endl;
	cout << "3. Thuat toan Interchange Sort sap xep giam dan." << endl;
	cout << "4. Thuat toan Bubble Sort sap xep tang dan." << endl;
	cout << "5. Thuat toan Quick Sort sap xep tang dan." <<endl;
	cout << "6. Thuat toan Selection Sort sap xep tang dan." << endl;
	cout << "0. Thoat." << endl;
	cout << "====================================================" << endl;
}

void nhapMang(int n, int a[]){
	for(int i = 0; i<n; i++){
		cout << "Nhap phan tu thu " << i+1 <<": ";
		cin >> a[i];
	}
}
void xuatMang(int n, int a[]){
	cout << "Mang da nhap la: ";
	for(int i = 0; i<n; i++){
		cout << " " << a[i];
	}
	cout << endl;
}
void insertionSort(int n, int a[]){
	for(int i = 1; i<n; i++){
		// mảng vòng lặp lần 2 -> 2  5  9  1
		// 						  2  5  1  9 -> mảng hoàn thành sau khi so sánh 1 và 9
		//						  2  1  5  9 -> mảng hoàn thành sau khi so sánh 1 và 5
		// 						  a0 a1 a2 a3
		int j;
		int key = a[i]; // gắn cờ - khóa tại vị trí a[i] hiện tại để so sánh với vị trí a[i-1] sau
		// i = 1 -> a[i] = 1 -> key = a[i] = 1
		// j = 2 -> a[j] = a[2] = 9
		// j = 1 -> a[j] = a[1] = 5
		// j = 0 -> a[j] = a[0] = 2
		// j = -1 -> kết thúc điều lặp dừng bài toán.
		for(j = i - 1; j >= 0 && a[j] > key; j--){
			// mà theo điều kiện a[j] > key thì thực hiện chuyển dời a[j] sang phải
			a[j+1] = a[j];
			// 1 -> 9 -> mảng thay đổi [ 2 5 9 9 ]
			// j - 1 -> [ 2 5 1 9 ] -> thực hiện so sánh với 5
			// 1 -> 5 -> mảng thay đổi [ 2 5 5 9 ]
			// j - 1 -> [ 2 1 5 9 ]
			// 1 -> 2 -> mảng thay đổi [ 2 2 5 9 ]
			// j - 1 -> [ 1 2 5 9 ]
		}
		a[j+1] = key;
	}
}
void InterchangeSort(int a[], int n )
{
	int i, j;
	
	for (i=0; i<n-1; i++)
	{
	for (j=i+1; j<n; j++)
		if(a[j ]< a[i]);
		HoanVi(a[i], a[j]);

	}
}
void BubbleSort(int a[], int n )
{
	int i, j;
	for (i=0; i<n-1; i++)
	{
		for (j=n-1; j>i; j --)
	{
	
		if(a[j] < a[j-1])
	
		HoanVi(a[j], a[j-1]);

	}
	}
}
void QuickSort(int a[], int l, int r)
{
	int i, j, x;

	x=a[(l+r)/2]; //Chọn phần tử giữa làm giá trị mốc
	i=l;
	j=r;
	do{
		while(a[i] < x)
		i++;
		while(a[j] > x)
		j--;
		if(i <= j)
	{

		HoanVi(a[i], a[j]);

			i++;
				j--;
	}
} while(i < j);
	if(l < j)
		QuickSort(a, l, j);
	if(i < r)
		QuickSort(a, i, r);

}
void SelectionSort(int a[], int n )
{
	int vtmin;
	for (int i=0; i<n-1; i++)
	{
	vtmin = i;
	for(int j=i+1; j<n; j++)
	
	{
	
	if (a[j ] < a[vtmin])
	vtmin = j;
	
	}
	
	HoanVi(a[vtmin], a[i]);
	}	
}