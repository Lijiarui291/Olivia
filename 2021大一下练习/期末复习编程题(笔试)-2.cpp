1、#include <iostream>
using namespace std;
template <class Type>
Type Sum(Type a[], int n)
{
Type tSum = 0;
for (int i = 0; i < n; i++)
{
tSum = tSum + a[i];
}
return tSum;
}
int main()
{
int a[] = {1, 2, 3};
double b[] = {1.5, 2.8, 8.9, 8};
cout << Sum(a, 3) << endl;
cout << Sum(b, 4) << endl;
return 0;
}

2、
#include<iostream>
using namespace std;

class Shape{
public:
	virtual void GetPerimeter()=0;
	virtual ~Shape();
};
class Rectangle:public Shape{
public:
	Rectangle(double x,double y){re1=x;re2=y;}
	void GetPerimeter(){
		cout<<"四边形的周长为："<<2*(re1+re2)<<endl;
}
private:
	double re1;
	double re2;
};
class Circle:public Shape{
public:
	Circle(double x){r=x;}
	void GetPerimeter(){
		cout<<"圆类的周长为："<<3.1415*2*r<<endl;
}
private:
	double r;
};

int main(){
	Rectangle b(4,5);
	b.GetPerimeter;
	Circle a(3);
	a.GetPerimeter;
	Shape *p;
	p=&b;
	p->GetPerimeter;
	p=&a;
	p->GetPerimeter;
	return 0;
}
