#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int main() {
	//对一个成绩的集合(0-100)，以10分为一个分段，统计各个分段各有多少个成绩
	//其中100独自为一个分数段
	int grade;
	vector<int> Grade(11,0);//注意这里类型int是要用<>来括，而不是()
	while (cin >> grade) {
		auto index = grade / 10;
		Grade[index] += 1;
	}
	for (auto& i : Grade) {
		cout << i << " ";
	}
	return 0;
}
