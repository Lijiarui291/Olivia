#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	//找最小公倍数：
	cout << "Please enter two numbers:" << endl;
	int x, y;
	cin >> x;cin >> y;
	int LCM;//指最小公倍数
	int Max = max(x, y);
	if (Max % x == 0 && Max % y == 0) {
		LCM = Max;
	}
	else {
		while (1) {
			if (Max % x == 0 && Max % y == 0) {
				LCM = Max;
				break;
			}
			else { Max++; }
		}
	}
	cout << "The LCM is:" << LCM << endl;

	//找最大公约数：
	int Min = min(x, y);
	int GCD;//指最大公约数
	if (y % Min == 0 && x % Min == 0) { 
		GCD = Min; 
		cout << "The GCD is:" << GCD << endl;
	}
	else {
		while (Min > 1) {
			if (x % Min == 0 && y % Min == 0) {
				GCD = Min;
				cout << "The GCD is:" << GCD << endl;
				break;
			}
			else { Min--; }
		}
		if (Min == 1) { cout << "No GCD"; }
	}
	return 0;
}