1、
#include<iostream>
using namespace std;
class Rect {
private:
	double length;
	double width;
public:
	Rect(double l=0,double w=0):length(l),width(w){}
	void SetLength(double le) { if(le<50&&le>0)length = le; }
	void SetWidth(double wi) { if (wi < 50 && wi>0)width = wi; }
	double GetPerimeter();
};
double Rect::GetPerimeter() {
	return 2 * (length + width);
}
int main() {
	Rect a;
	cout << a.GetPerimeter() << endl;
	Rect b(3, 5);
	cout << b.GetPerimeter() << endl;
	b.SetLength(4);
	b.SetWidth(5);
	cout << b.GetPerimeter() << endl;
	return 0;
}
