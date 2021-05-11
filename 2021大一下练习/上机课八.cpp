#include<iostream>
#include<math.h>
#include<iomanip>
#ifndef ARRAY_H
#define ARRAY_H
#include <cassert>
using namespace std;
//Array.h
//其中:setiosflags(ios::fixed) << setprecision(2)用来控制小数点后保留两位小数 

//数组类模板定义
template <class T>
class Array {
private:
	T* list;	//T类型指针，用于存放动态分配的数组内存首地址
	int size;	//数组大小（元素个数）
public:
	Array(int sz = 50);			//构造函数
	Array(const Array<T>& a);	//拷贝构造函数
	~Array();	//析构函数
	Array<T>& operator = (const Array<T>& rhs); //重载"="使数组对象可以整体赋值
	T& operator [] (int i);	//重载"[]"，使Array对象可以起到C++普通数组的作用
	const T& operator [] (int i) const;	//"[]"运算符的const版本
	operator T* ();	//重载到T*类型的转换，使Array对象可以起到C++普通数组的作用
	operator const T* () const;	//到T*类型转换操作符的const版本
	int getSize() const;	//取数组的大小
	void resize(int sz);	//修改数组的大小
};

//构造函数
template <class T>
Array<T>::Array(int sz) {
	size = sz;	// 将元素个数赋值给变量size
	list = new T[size];	//动态分配size个T类型的元素空间
}

//析构函数
template <class T>
Array<T>::~Array() {
	delete[] list;
}

//拷贝构造函数
template <class T>
Array<T>::Array(const Array<T>& a) {
	//从对象x取得数组大小，并赋值给当前对象的成员
	size = a.size;
	//为对象申请内存并进行出错检查
	list = new T[size];	// 动态分配n个T类型的元素空间
	//从对象X复制数组元素到本对象  
	for (int i = 0; i < size; i++)
		list[i] = a.list[i];
}

//重载"="运算符，将对象rhs赋值给本对象。实现对象之间的整体赋值
template <class T>
Array<T>& Array<T>::operator = (const Array<T>& rhs) {
	if (&rhs != this) {
		//如果本对象中数组大小与rhs不同，则删除数组原有内存，然后重新分配
		if (size != rhs.size) {
			delete[] list;		//删除数组原有内存
			size = rhs.size;	//设置本对象的数组大小
			list = new T[size];	//重新分配n个元素的内存
		}
		//从对象X复制数组元素到本对象  
		for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	}
	return *this;	//返回当前对象的引用
}

//重载下标运算符，实现与普通数组一样通过下标访问元素，并且具有越界检查功能
template <class T>
T& Array<T>::operator[] (int n) {
	return list[n];				//返回下标为n的数组元素
}

template <class T>
const T& Array<T>::operator[] (int n) const {
	return list[n];			//返回下标为n的数组元素
}

//重载指针转换运算符，将Array类的对象名转换为T类型的指针，
//指向当前对象中的私有数组。
//因而可以象使用普通数组首地址一样使用Array类的对象名
template <class T>
Array<T>::operator T* () {
	return list;	//返回当前对象中私有数组的首地址
}

template <class T>
Array<T>::operator const T* () const {
	return list;	//返回当前对象中私有数组的首地址
}

//取当前数组的大小
template <class T>
int Array<T>::getSize() const {
	return size;
}

// 将数组大小修改为sz
template <class T>
void Array<T>::resize(int sz) {
	if (sz == size)	//如果指定的大小与原有大小一样，什么也不做
		return;
	T* newList = new T[sz];	//申请新的数组内存
	int n = (sz < size) ? sz : size;	//将sz与size中较小的一个赋值给n
	//将原有数组中前n个元素复制到新数组中
	for (int i = 0; i < n; i++)
		newList[i] = list[i];
	delete[] list;		//删除原数组
	list = newList;	// 使list指向新数组
	size = sz;	//更新size
}
#endif  //ARRAY_H
/*设计类的层次。设计一个 Shape 抽象类；并设计 Shape 类的派生类：圆 Circle
类、长方形 Rectangle 类、直角三角形 RightTriangle 类。并且周长（Circumference）
不能作为类的成员变量，而是通过调用对象的 getCircumference 成员函数求得，
精确到小数点后 2 位。请考虑如何通过继承，尽可能多的复用代码。*/
class Shape {
public:
	virtual double getCircumference() = 0;
	virtual void show() = 0;
	virtual ~Shape() { }
	bool operator >(Shape& shape);

};

class Circle : public Shape {
public:
	Circle(double radius) :radius(radius) { }
	double getCircumference();
	void show();
	static Shape* assignCircle() {
		cout << "请输入圆形的半径：";
		int radius;
		cin >> radius;
		return new Circle(radius);
	}
private:
	int radius;
	const double PAI = 3.1415926;
};
double Circle::getCircumference() {
	return 2 * PAI * radius;
}
void Circle::show() {
	if(int(getCircumference())!=getCircumference()){
			cout << "1．圆，半径" << radius << "，周长" << setiosflags(ios::fixed) << setprecision(2) << getCircumference() << endl;
	}	
	else cout << "1．圆，半径" << radius << "，周长" << getCircumference() << endl;
}

class Rectangle : public Shape {
public:
	Rectangle(double l, double w) :length(l), width(w) { }
	double getCircumference();
	void show();
	static Shape* assignRectangle() {
		cout << "请输入长方形的长和宽：";
		double length, width;
		cin >> length >> width;
		return new Rectangle(length, width);
	}

private:
	int length;
	int width;
};
double Rectangle::getCircumference() {
	return 2 * (length + width);
}
void Rectangle::show() {
	if(int(getCircumference())!=getCircumference()){
		cout << "2．长方形，长" << length << ", 宽 " << width << ", 周长" << setiosflags(ios::fixed) << setprecision(2) << getCircumference() << endl;
	}
	else cout << "2．长方形，长" << length << ", 宽 " << width << ", 周长" << getCircumference() << endl;
}

class RightTriangle : public Shape {
public:
	RightTriangle(double r1, double r2) :rightAngleSide1(r1), rightAngleSide2(r2) { }
	double getCircumference();
	void show();
	static Shape* assignRightTriangle() {
		cout << "请输入直角三角形的两条边长：";
		double rightAngleSide1, rightAngleSide2;
		cin >> rightAngleSide1 >> rightAngleSide2;
		return new RightTriangle(rightAngleSide1, rightAngleSide2);
	}
private:
	int rightAngleSide1;
	int rightAngleSide2;
};
double RightTriangle::getCircumference() {
	return rightAngleSide1 + rightAngleSide2 + pow((rightAngleSide1 * rightAngleSide1 + rightAngleSide2 * rightAngleSide2), 0.5);
}
void RightTriangle::show() {
	if(int(getCircumference())!=getCircumference()){
		cout << "3．直角三角形，直角边" << rightAngleSide1 << "， " << "直角边" << rightAngleSide2 << ", 周长" << setiosflags(ios::fixed) <<setprecision(2) << getCircumference() << endl;
	}
	else cout << "3．直角三角形，直角边" << rightAngleSide1 << "， " << "直角边" << rightAngleSide2 << ", 周长" << getCircumference() << endl;
}
bool Shape::operator >(Shape& shape) {
	return (getCircumference() < shape.getCircumference());
}
void Sort(Array<Shape*>& shapes, int index, Shape* ptr) {// 将新创建的形状ptr插入到动态数组shapes中
	int size = shapes.getSize();
	int boundary = 0;

	for (; boundary < index; boundary++) {
		if (*shapes[boundary] > *ptr)
			break;
	}

	for (int i = size - 1; i > boundary; i--)
		shapes[i] = shapes[i - 1];
	shapes[boundary] = ptr;
}

int main() {
	cout << "输入框架图案的序号，直至输入-1 后，选择产品结束" << endl;
	cout << "1表示圆类，2表示长方形，3表示直角三角形" << endl;
	int preSize = 2;// 动态数组的初始大小
	Array<Shape*> shapes(preSize);
	for (int i = 0; i < preSize; i++)	// 要将shapes中的指针元素初始化为NULL，否则有可能是“野指针”
		shapes[i] = NULL;

	int index = 0;
	int option = 0;
	cin >> option;

	while (option != -1) {
		Shape* ptr = NULL;
		switch (option) {
		case 1:
			ptr = Circle::assignCircle();
			break;
		case 2:
			ptr = Rectangle::assignRectangle();
			break;
		case 3:
			ptr = RightTriangle::assignRightTriangle();
			break;
		}
		Sort(shapes, index, ptr);// 执行插入排序
		index++;

		if (index >= preSize) {// 调整动态数组的大小
			preSize *= 2;
			shapes.resize(preSize);
		}

		cin >> option;// 接收新的输入选项
	}

	for (int i = 0; i < index; i++)
		shapes[i]->show();

	return 0;
}
