#include <iostream>
#include "ParkManager.h"
//class Automobile {}; // 汽车类
//class Park {}; // 停车场类

int main() {
	int N;
	cout << "请输入停车位数量：";
	cin >> N;// 输入停车位数量，此处输入2
	Park park(N);// 创建一个停车场对象
	Car car1("鲁B-12345","奥迪A6"); // 创建轿车对象
	car1.enter(park); // car1进入停车场，分配停车位
	Truck truck("鲁B-23456", 15); // 创建卡车对象
	truck.enter(park); // truck进入停车场，分配车位
	car1.leave(park); // car1离开停车场，缴纳停车费
	Bus bus("鲁B-34567", 50); // 创建公交车对象
	bus.enter(park); // bus进入停车场，分配车位
	/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
	Car car2("鲁B-45678","宝马320"); // 创建轿车对象
	car2.enter(park); 
	// car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配
	bus.leave(park); // bus离开停车场，缴纳停车费
	truck.leave(park); // truck离开停车场，缴纳停车费3
	/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();
	return 0;
}

#include<iostream>
using namespace std;
class Automobile;//前向引用说明
class Park {
public:
	Park(int N);//构造函数
	~Park() {
		delete[] spaces;
	}
	void showInfo();//显示停放的车辆的车牌号码以及全部停车费收入
	void parkNum(Automobile* automobile);//记录进入的车的函数
	void parkFee(Automobile* automobile, int feePer);//记录停车费
private:
	int n;//停车位数量
	int income;//全部停车费收入
	Automobile** spaces;//数组指针来创建新的停车位
	int freenum;//可停的数量
};
class Automobile {
public:
	string autonumber;//表示车牌号
	Automobile(string x);//构造函数(包含车牌号这一信息)
	void enter(Park &park);//停进的函数
	virtual void leave(Park &park);//开出的函数
	string getAutonumber();//获得车牌号：用于Park类
	//每个派生类中要实现 pay()函数，用于显示车辆信息并交纳停车费
	void pay(int y);
};
class Truck :public Automobile {//派生类Truck
public:
	Truck(string x, float w) :Automobile(x) {
		weight = w;
	}
	void leave(Park &park);
private:
	float weight;//载重量属性（单位吨）
	const int TruckFee = 3;//Truck 收费 3 元/次
};
class Car :public Automobile {//派生类Car
public:
	Car(string x, string b) :Automobile(x) {
		brand = b;
	}
	void leave(Park &park);
private:
	string brand;//品牌属性
	const int CarFee = 1;//Car 收费 1 元/次
};
class Bus :public Automobile {//派生类Bus
public:
	Bus(string x, int p) :Automobile(x) {
		peopleNum = p;
	}
	void leave(Park &park);
private:
	int peopleNum;//核定载员数量
	const int BusFee = 2;//Bus 收费 2 元/次
};


#include "ParkManager.h"
Automobile::Automobile(string x) {
	autonumber = x;
}
string Automobile::getAutonumber() {
	return autonumber;
}
void Automobile::enter(Park &park) {
	park.parkNum(this);
}
void Automobile::leave(Park &park){}
void Truck::leave(Park &park)
{
	park.parkFee(this, TruckFee);
}
void Car::leave(Park &park)
{
	park.parkFee(this, CarFee);
}
void Bus::leave(Park &park)
{
	park.parkFee(this, BusFee);
}
void Automobile::pay(int y)//汽车离开停车场时，需要缴纳的车费
{
	cout << this->getAutonumber() << "离开停车场，缴纳停车费" << y << "元" << endl;
}
Park::Park(int N) {
	this->n = N;
	spaces = new Automobile * [n];
	for (int i = 0;i < n;i++) {
		spaces[i] = NULL;//清零数组
	}
	income = 0;//收入置零
	//freenum = 0;//剩余的停车位数量
}
//void showInfo();//显示停放的车辆的车牌号码以及全部停车费收入
//void parkNum(Automobile* automobile);//记录进入的车的函数
//void parkFee(Automobile* automobile, int feePer);//记录停车费
void Park::parkNum(Automobile* automobile)
{
	for (int i = 0; i < n; i++)
	{
		if (spaces[i] == NULL)
		{
			spaces[i] = automobile;//把车给存进去
			freenum++;
			cout << automobile->getAutonumber() << "进入停车场，分配停车位" << endl;
			return;
		}
	}
	if (freenum >= n)
	{
		cout << "无法为" << automobile->getAutonumber() << "分配停车位" << endl;
	}
}
void Park::parkFee(Automobile* automobile, int feePer) {
	for (int i = 0; i < n; i++)
	{
		if (spaces[i] == automobile)
		{
			spaces[i] = NULL;
			/*for (; i < n - 1; i++)
            {
                spaces[i] = spaces[i + 1];
                spaces[i + 1] = NULL;
            }*/
            freenum -= 1;
			income += feePer;
			automobile->pay(feePer);
			//cout << automobile->getAutonumber() << "离开停车场，缴纳停车费" << feePer << "元" << endl;
		
			return;
		}
	}
	//std::cout << "车牌号为：" << automobile->getAutonumber() << "的汽车不存在" << endl;
	//return 1;
}
void Park::showInfo()
{
	cout << "停车场目前停放了" << freenum << "辆汽车：";
	for (int i = 0; i < n; i++)
	{
		if (spaces[i] != NULL)
		{
			cout << spaces[i]->getAutonumber() << " ";
		}
	}
	cout << "共收入" << income << "元停车费" << endl;
}
