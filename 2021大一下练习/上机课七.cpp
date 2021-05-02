#include<iostream>
#include<iomanip>
#include"AccountPart.h"
using namespace std;
int main() {
	Account* accounts[3];
	accounts[0] = new SavingsAccount(100, 3); //余额100元，利息3%
	accounts[1] = new CheckingAccount(100, 5); //余额100元，交易费5元
	accounts[2] = new CheckingAccount(50, 5); //余额50元，交易费5元
	for (int i = 0; i < 3; i++) {
		cout << "第" << i + 1 << "次循环的结果：" << endl;
		accounts[i]->debit(200); //借款200元
		accounts[i]->debit(40);
		accounts[i]->credit(50); //存款50元
		accounts[i]->debit(49);
		accounts[i]->debit(43);
		accounts[i]->credit(1);
		//将Account指针强制转换为SavingAccount指针
		SavingsAccount* derivedPtr =
			dynamic_cast<SavingsAccount*>(accounts[i]);
		if (derivedPtr != NULL) //如果类型兼容，转换成功
			derivedPtr->credit(derivedPtr->calculateInterest());
		cout << fixed << setprecision(2); //使用定点数格式，2位小数部分
		cout << "账户的余额为：" << accounts[i]->getBalance() << endl;
	}
}

#pragma once
#include<iostream>
using namespace std;
/*基类 Account 应该包括一个 double 类型的数据成员 balance，表示账户的余
额。该类应当提供三个成员函数。成员函数 credit 可以向当前余额加钱；成员函
数 debit 负责从账户中取钱，并且保证账户不会被透支。如果提取金额大于账户
金额，函数将保持 balance 不变，并打印信息“Debit amount exceeded account 
balance”；成员函数 getBalance 则返回当前 balance 的值。*/
/*提示：定义 Account 的 debit 函数使它返回一个 bool 类型值，表示钱是否被
成功提取。然后利用该值决定是否需要扣除交易费。如果取款或存款后，账户的
余额小于每笔交易的费用，则废弃这次交易，使账户余额恢复到取款或存款之前
的值，并打印“Transaction fee exceeded account balance while debiting”或
“Transaction fee exceeded account balance while crediting”*/
class Account {
public:
	Account() {};//构造函数
	virtual bool credit(double x);//向余额加钱
	virtual bool debit(double y);//从账户中取钱
	double getBalance();//返回当前balance的值
	void setBalance(double x);//设置初始余额
private:
	double balance;//表示余额
};
/*派生类 SavingsAccount 不仅继承了基类 Account 的功能，而且应提供一个附
加的 double 类型数据成员 interestRate 表示这个账户的比率（百分比）。
SavingsAccount的构造函数应接受初始余额值和初始利率值，还应提供一个public2
成员函数calculateInterest，返回代表账户的利息的一个double值，这个值是balance
和 interestRate 的乘积。类 SavingsAccount 应继承成员函数 credit 和 debit，不需
要重新定义。*/
class SavingsAccount :public Account {
public:
	SavingsAccount(double x, double y);//构造函数
	double calculateInterest();//返回代表账户的利息的一个double值
private:
	double interestRate;//表示这个账户的比率（百分比）
};
/*派生类 CheckingAccount 不仅继承基类 Account 的功能，还提供一个附加的
double 类型数据成员表示每笔交易的费用。CheckingAccount 的构造函数应接受
初始余额值和交易费用值。类 CheckingAccount 需要重新定义成员函数 credit 和
debit，当每笔交易完成时，从 balance 中减去每笔交易的费用。重新定义这些函
数 时 应分别使用基类 Account 的相关函数来执行账户余额的更新。
CheckingAccount 的 debit 函数只有当钱被成功提取时（即提取金额不超过账户余
额时）才应收取交易费。*/
class CheckingAccount :public Account {
public:
	CheckingAccount(double x, double y);//构造函数
	bool credit(double x);
	bool debit(double y);
private:
	double fee;
};

#include"AccountPart.h"
bool Account::credit(double x) {
	balance += x;
	return true;
}
bool Account::debit(double y) {
	if (y > balance) { 
		cout << "Debit amount exceeded account balance" << endl;
		return false; 
	}
	if (y <= balance) { balance -= y;return true; }
}
double Account::getBalance() {
	return balance;
}
void Account::setBalance(double x) {
	balance = x;
}
SavingsAccount::SavingsAccount(double x, double y) {
	setBalance(x);
	interestRate = y;
}
double SavingsAccount::calculateInterest() {
	return getBalance() * interestRate / 100.0;
}
CheckingAccount::CheckingAccount(double x, double y) {
	setBalance(x);
	fee = y;
}
bool CheckingAccount::credit(double x) {
	if (Account::credit(x)) {
		if (getBalance() < fee) {
			cout << "Transaction fee exceeded account balance while crediting" << endl;
			setBalance(getBalance() - x);
			return false;
		}
		else {
			setBalance(getBalance() - fee);
			return true;
		}
	}
}
bool CheckingAccount::debit(double y) {
	if (Account::debit(y)) {
		if (getBalance() < fee) {
			cout << "Transaction fee exceeded account balance while debiting" << endl;
			setBalance(getBalance() + y);
			return false;
		}
		else {
			setBalance(getBalance() - fee);
			return true;
		}
	}
}
