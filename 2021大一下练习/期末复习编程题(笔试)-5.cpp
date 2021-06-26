1、
#include<iostream>
using namespace std;

class DateInfo {
public:
	DateInfo(int y,int m,int d):year(y),month(m),day(d){}
	DateInfo() :year(2010), month(6), day(8) {}
	void SetDate(int y, int m, int d);
	void Show();
private:
	int year;
	int month;
	int day;
};
void DateInfo::SetDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}void DateInfo::Show() {
	cout << "The year you enter is: " << year << endl;
	cout << "The month you enter is: " << month << endl;
	cout << "The day you enter is: " << day << endl;
}

int main(){
	DateInfo a;
	DateInfo b(2000, 11, 28);
	DateInfo c;
	a.Show();
	b.Show();
	c.SetDate(2002, 8, 21);
	c.Show();
	return 0;
}

2、
#include<iostream>
using namespace std;

class Staff {
public:
	Staff(char N[],char n[],double r,double b,double p):num(N),name(n),rateOfAttend(r),basicSal(b),prize(p){}
	virtual void Output();
	virtual double OutputWage();
	char *num;
	char *name;
	double rateOfAttend;
	double basicSal;
	double prize;
};
void Staff::Output() {
	cout << "The person is " << name << endl;
	cout << "His/Her number is " << num << endl;
	cout << "The rate of his/her attend is " << rateOfAttend << "%" << endl;
	cout << "His/Her basic salary is " << basicSal << endl;
	cout << "His/Her prize is " << prize << endl;
}
double Staff::OutputWage() {
	cout << "The final wage he/she gets is ";
	return basicSal + prize * rateOfAttend / 100;
}
class Saleman :public Staff {
public:
	Saleman(char N[], char n[], double r, double b, double p, double d, double P) :Staff(N, n, r, b, p) {
		deductRate = d;
		personAmount = P;
	}
	void Output() {
		Staff::Output();
		cout << "His/Her rate of deduct is " << deductRate << "%" << endl;
		cout << "His/Her personAmount is " << personAmount << endl;
	}
	double Outputwage() {
		return Staff::OutputWage() + personAmount * deductRate / 100;
	}
private:
	double deductRate;
	double personAmount;
};
class Manager :public Staff {
public:
	Manager(char N[], char n[], double r, double b, double p, double T, double t) :Staff(N, n, r, b, p) {
		totalDeductRate = T;
		totalAmount = t;
	}
	void Output() {
		Staff::Output();
		cout << "The total deduct rate is " << totalDeductRate << "%" << endl;
		cout << "His/Her personAmount is " << totalAmount << endl;
	}
	double Outputwage() {
		return Staff::OutputWage() + totalAmount * totalDeductRate / 100;
	}
private:
	double totalDeductRate;
	double totalAmount;
};
int main() {
	char AAA[] = "052";
	char* A = AAA;
	char AAAA[] = "Liu";
	char* AA = AAAA;
	Staff a(A, AA, 78, 30000, 8000);
	a.Output();
	cout << a.OutputWage() << endl;
	char BBB[] = "076";
	char* B = BBB;
	char BBBB[] = "Du";
	char* BB = BBBB;
	Saleman b(B, BB, 90, 20000, 10000, 50, 10000);
	char CCC[] = "186";
	char* C = CCC;
	char CCCC[] = "Qiu";
	char* CC = CCCC;
	Manager c(C, CC, 80, 30000, 10000, 50, 20000);
	c.Output();
	cout << c.OutputWage() << endl;
	return 0;
}
