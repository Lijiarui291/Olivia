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

2、(1)
#include<iostream>
using namespace std;

class Vector2d {
private:
	double x;
	double y;
public:
	Vector2d(double xx, double yy) { x = xx;y = yy; }
	void Show() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	void operator+(const Vector2d& obj) {
		x = x + obj.x;
		y = y + obj.y;
	}
};

int main() {
	Vector2d a(3, 4);
	Vector2d b(5, 6);
	a.Show();
	b.Show();
	a + b;
	a.Show();
	return 0;
}
2、(2)
#include<iostream>
using namespace std;

class Vector2d {
private:
	double x;
	double y;
public:
	Vector2d(double xx, double yy) { x = xx;y = yy; }
	void Show() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	Vector2d operator+(const Vector2d& obj) {
		return Vector2d(x + obj.x, y + obj.y);
	}
};

int main() {
	Vector2d a(3, 4);
	Vector2d b(5, 6);
	Vector2d c(0, 0);
	a.Show();
	b.Show();
	c = a + b;
	c.Show();
	return 0;
}
