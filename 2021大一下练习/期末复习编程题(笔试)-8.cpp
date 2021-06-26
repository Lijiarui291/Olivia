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

2、
#include<iostream>
using namespace std;

class Shape {
public:
	virtual void Show() = 0;
};
class Rectangle :public Shape {
public:
	Rectangle(double l,double w):length(l),width(w){}
	void Show();
private:
	double length;
	double width;
};
void Rectangle::Show() {
	cout << "The length of the rectangle is: " << length << ",";
	cout << "the width of the rectangle is: " << width << endl;
}
class Circle :public Shape {
public:
	Circle(double r):radium(r){}
	void Show();
private:
	double radium;
};
void Circle::Show() {
	cout << "The radium of the circle is: " << radium << endl;
}

int main() {
	Shape* p;
	Rectangle a(6.8, 3.2);
	Circle b(5);
	p = &a;
	p->Show();
	p = &b;
	p->Show();
	return 0;
}
