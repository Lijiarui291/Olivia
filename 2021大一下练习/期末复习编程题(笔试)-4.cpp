1、
#include<iostream>
using namespace std;

template<class Type>
Type Min(Type a[], int n);

template<class Type>
Type Min(Type a[], int n) {
	Type min=a[0];
	for (int i = 0;i < n;i++) {
		if (min > a[i])min = a[i];
	}
	return min;
}

int main() {
	int a[] = { 1,2,3,4,5,6 };
	double b[] = { 8.9,4.3,2.1,10.2 };
	cout << Min(a, 6) << endl;
	cout << Min(b, 4) << endl;
	return 0;
}

2、
#include<iostream>
using namespace std;

const double a = 3.1415;
class Shape {
public:
	~Shape() { cout << "Destructing Shape." << endl; }
	virtual void ShowArea();
};
void Shape::ShowArea() {
	cout << "The area is unknown!" << endl;
}
class Circle :public Shape {
public:
	Circle(int r):radium(r){}
	~Circle(){ cout << "Destructing Circle." << endl; }
	void ShowArea();
private:
	double radium;
};
void Circle::ShowArea() { cout << "The area is " << a * radium * radium << endl; }
class Rectangle :public Shape {
public:
	Rectangle(double l,double w) :length(l),width(w) {}
	~Rectangle() { cout << "Destructing Rectangle." << endl; }
	void ShowArea();
private:
	double length;
	double width;
};
void Rectangle::ShowArea() { cout << "The area is " << length * width << endl; }
class Square :public Shape {
public:
	Square(int x) :xx(x) {}
	~Square() { cout << "Destructing Square." << endl; }
	void ShowArea();
private:
	double xx;
};
void Square::ShowArea() { cout << "The area is " << xx * xx << endl; }
int main() {
	Circle A(2);
	A.ShowArea();
	Rectangle B(3.4, 5.8);
	B.ShowArea();
	Square C(6);
	C.ShowArea();
	return 0;
}
