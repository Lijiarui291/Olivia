1、template<class Type>
Type Abs(Type a);

template<class Type>
Type Abs(Type a){
  	if(a>=0) return a;
	else return -a;
}


2、class Complex{
public:
	Complex(double r,double i=0);
	void Show();
	Complex operator+(const Complex &obj);
	double real;
	double image;
};
Complex::Complex(double r,double i=0){
	real = r;
	image=i;
}
Complex Complex::operator+(const Complex &obj){
	 Complex temp(real+obj.real,image+obj.image)
	 return temp;
}
void Complex::Show(){
	cout<<real;
	if(image>0)cout<<"+"<<image<<"i"<<endl;
	else if(image<0)cout<<"-"<<image<<"i"<<endl;
	else cout<<endl;
}
#include<iostream>
using namespace std;

int main(){
	Complex z1(2,6),z2(3,8),z3(0);
	z3=z1+z2;
	z3.Show();
	return 0;
}
