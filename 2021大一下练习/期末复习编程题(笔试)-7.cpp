1、
#include<iostream>
using namespace std;

template<class Type>
Type Mul(Type a[], int n);

template<class Type>
Type Mul(Type a[], int n) {
	Type res = 1;
	for (int i = 0;i < n;i++) {
		res *= a[i];
	}
	return res;
}

int main() {
	int a[] = { 1,2,3,4,5,6 };
	double b[] = { 1.0,2.0,3.0,4.0,5.0,6.0 };
	cout << Mul(a, 6) << endl;
	cout << Mul(b, 6) << endl;
	return 0;
}
