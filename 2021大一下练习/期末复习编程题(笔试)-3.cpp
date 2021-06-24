1、
#include<iostream>
using namespace std;

template<class Type>
Type Average(Type a[],int n);

template<class Type>
Type Average(Type a[],int n){
	Type Sum=0;
	for(int i=0;i<n;i++){Sum+=a[i];}
	return Sum/n;
}

int main(){
	int a[]={1,2,3,4,5,6};
	double b[]={1.2,2.3,3.4};
	cout<<Average(a,6)<<endl;
	cout<<Average(b,3)<<endl;
	return 0;
}

2、
#include<iostream>
using namespace std;

class Person{
public:
	Person(char n,int a,char s){name=n;age=a;sex=s;}
	virtual ~Person();
	virtual Show(){cout<<name<<" "<<age<<" "<<sex<<endl;}
private:
	char name;
	int age;
	char sex;
};
class Teacher:virtual public Person{
public:
	Teacher(char n,int a,char s,char t):Person(n,a,s){title=t;}
	~Teacher();
	Show(){cout<<name<<" "<<age<<" "<<sex<<" "<<title<<endl;}
private:
	char title;
};
class Cadre:virtual public Person{
public:
	Teacher(char n,int a,char s,char p):Person(n,a,s){post=p;}
	~Cadre();
	Show(){cout<<name<<" "<<age<<" "<<sex<<" "<<post<<endl;}
private:
	char post;
};
class TeacherCadre:public Teacher,public Cadre{
public:
	TeacherCadre(char n,int a,char s,char p,double w):Person(n, a, s), Teacher(n, a, s, t), Cadre(n, a, s, p){wages=w;}
	~TeacherCadre();
	Show(){cout<<name<<" "<<age<<" "<<sex<<" "<<post<<" "<<wages<<endl;}
private:
	double wages;
};
int main(){
	TeacherCadre a("Li",25,"F","teacher",5000);
	a.Show();
	return 0;
}
