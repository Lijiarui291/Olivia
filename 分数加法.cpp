#include<iostream>
using namespace std;

int gcd(int x, int y) {//���Լ��
	int Min = min(x, y);
	int GCD;//ָ���Լ��
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
	int aa = b * d;//��ʼ��ĸ
	int bb = a * d + c * b;//��ʼ����
	int x = gcd(aa, bb);
	if (x == 1) { cout << bb << '/' << aa; }
	else { cout << bb / x << '/' << aa / x; }
	return 0;
}