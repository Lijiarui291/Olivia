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
