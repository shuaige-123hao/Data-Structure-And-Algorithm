#include <iostream>
#include <deque>
using namespace std;
void printdeque(deque<int>& m) {
	for (deque<int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << *it  <<"    ";
	}
	cout << endl;
	cout << "打印完毕" << endl;
}
int main() {
	//初始化
	deque <int>q1({1,3,5});
	deque <int>q2={ 1,3,5 };//也走拷贝构造

	deque <int>q3(q2.begin() + 1, q2.end());
	printdeque(q3);

	deque<int> ii(6, 5);
	printdeque(ii);

	//拷贝构造函数
	deque <int> q4(q1);
	printdeque(q4);


	//赋值
	/*1.deque a1;
	deque a2;
	a2 = a1;
	a1.assign(迭代器，迭代)；、
		a1.assign({});
	assign(8, 6);走的都是赋值*/


	/*大小操作
	1.empty
	2.size；
	3.resize；
		resize(18,6)
		新增的元素全变为6，默认变成6；*/

	/*数据插入
	1.push_front;
	2.push_back;
	3.insert;
	insert(迭代器，数据)；
	insert（迭代器，数据个数，数据）；
	insert(插入位置，插入左闭区间，插入右开区间)；*/



	//数据删除
	//1.头删
	//2.尾删
 //   3。部分删，全删
	//erase(迭代器)；//返回被删后的元素的迭代器
	//erase（左闭区间，右开区间）；
	//	clear（）；全删掉将size=0；
	deque <long long> d;
	for (int i = 0; i < 9; i++) {
		d.push_back(i);
	}
	for (int i = 9; i < 18; i++) {
		d.push_front(i);
	}


	//随机访问
	/*at。（）会检查
		【】不会检查*/
	return 0;
}