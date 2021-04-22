#include<iostream>
using namespace std;

int gcd(int x, int y) {//最大公约数
	int Min = min(x, y);
	int GCD;//指最大公约数
	if (y % Min == 0 && x % Min == 0) {
		GCD = Min;
		return GCD;
	}
	else {
		while (Min > 1) {
			if (x % Min == 0 && y % Min == 0) {
				GCD = Min;
				return GCD;
				break;
			}
			else { Min--; }
		}
		if (Min == 1) { return 1; }
	}

}

int main() {
	int a, b, c, d;
	char e, f;
	cin >> a;cin >> e;cin >> b;cin >> c;cin >> f;cin >> d;
	int aa = b * d;//初始分母
	int bb = a * d + c * b;//初始分子
	int x = gcd(aa, bb);
	if (x == 1) { cout << bb << '/' << aa; }
	else { cout << bb / x << '/' << aa / x; }
	return 0;
}