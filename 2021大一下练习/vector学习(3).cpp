//编写程序，判断两个vector<int>是否相等
//两个vector的capacity不会影响相等性判等，因此invec1添加、删除元素后仍与ivec相等

#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int main() {
	vector<int> ivec{ 1,2,3,4,5,6,7,8 };
	ivec.pop_back();//pop_back:删除最后一个元素
	cout << ivec.capacity() << " " << ivec.size() << endl;//注意capacity和size的异同
	vector<int> ivec1{ 1,2,3,4,5,6 };
	if (ivec == ivec1) { cout << "ivec equals to ivec1!"; }
	else cout << "ivec != ivec1.";
	return 0;
}
