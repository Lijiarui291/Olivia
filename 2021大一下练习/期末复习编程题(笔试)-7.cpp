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

2、
#include<iostream>
using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date(int y=2000,int m=11,int d=28):year(y),month(m),day(d){}
	friend void operator<<(ostream& cout, Date& obj) {
		cout << "You are born in " << obj.year << ", ";
		cout << "and your birthday month is " << obj.month << ", ";
		cout << "the special day is " << obj.day << endl;
	}
	friend void operator>>(istream& cin, Date& obj) {
		cout << "Please enter your birth year:" << endl;
		cin >> obj.year;
		cout << "Please enter your birth month:" << endl;
		cin >> obj.month;
		cout << "Please enter the day you born in:" << endl;
		cin >> obj.day;
	}
};

int main() {
	Date A;
	Date B(2002, 8, 21);
	Date C;
	cout << A;
	cout << B;
	cin >> C;
	cout << C;
	return 0;
}
