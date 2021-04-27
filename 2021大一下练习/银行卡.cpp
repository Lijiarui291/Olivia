#include<iostream>
using namespace std;
class Account {
public:
	int id;//卡号
	string name;//姓名
	float balance = 100;//余额；
	void deposit(float amount);//存钱；
	bool withdraw(float amount);//取钱；
	float getbalance();//显示属性的值；
	void show();//显示函数
	Account(int x);
	Account();
};
Account::Account(int x) {
	id = x;
}
void Account::show() {
	cout << "Main menu" << endl;
	cout << "1 : check balance" << endl;
	cout << "2 : withdraw" << endl;
	cout << "3 : deposit" << endl;
	cout << "4 : exit" << endl;
	cout << "Enter a choice :" ;
	switch (4) {
	case 1:
		getbalance();
	case 2:
		cout << "Enter an amount to withdraw :";
		float x;
		cin >> x;
		withdraw(x);
	case 3:
		cout << "Enter an amount to deposit :";
		float y;
		cin >> y;
		deposit(y);
	case 4:
		show();
	}
	cout << endl;
}
bool Account::withdraw(float amount) {
	if (amount > balance) { cout << "Please enter another amount!"; }
	else {
		balance -= amount;
	}
	return 1;
}
void Account::deposit(float amount) {
	balance += amount;
}
float Account::getbalance() {
	cout << "The balance is ";
	return balance;
}
//创建一个有5个账户的数组，其id为101~105，并初始化余额为100元。系统提示用户输入一个id
//如果输入的id不正确，就要求用户输入一个正确的id。
//一旦接受一个id，则显示下面的主菜单。
/*Enter an id : 101
Main menu
1 : check balance
2 : withdraw
3 : deposit
4 : exit
Enter a choice : 2
Enter an amount to withdraw : 3

Main menu
1:check balance
2:withdraw
3:deposit
4:exit
Enter a choice: 1
The balance is 97.0 */
int main() {
	Account A[5];
	A[0].id = 101;A[1].id = 102;A[2].id = 103;A[3].id = 104;A[4].id = 105;
	cout << "Please enter an id:" << endl;
	int x;
	cin >> x;
	if (x < 101 || x>105) { cout << "Please ensure the id you enter is correct!"; }
	else {
		for (int i = 0;i < 5;i++) {
			if (x == A[i].id) {
				A[i].show();
			}
		}
	}
	return 0;
}
