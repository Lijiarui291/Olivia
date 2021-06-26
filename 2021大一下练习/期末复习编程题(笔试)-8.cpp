1、
#include<iostream>
using namespace std;

template<class Type>
Type Sum(Type a[], int n);

template<class Type>
Type Sum(Type a[], int n) {
	Type res = 0;
	for (int i = 0;i < n;i++) {
		res += a[i];
	}
	return res;
}

int main() {
	int a[] = { 1,2,3,4,5,6 };
	double b[] = { 2.0,3.0,4.0,5.0 };
	cout << Sum(a, 6) << endl;
	cout << Sum(b, 4) << endl;
	return 0;
}
