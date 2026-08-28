#include<iostream>
#include <set>
#include <vector>
using namespace std;
void pr(const set<int>& m) {
	 set<int>::const_iterator it = m.begin();
	for (; it != m.end(); it++) {
		cout << *it<<' ';
	}
	cout << endl;
}
int main() {
	//默认构造
	set<int> s1;
	//初始化列表
	set<int> s2 = { 1,2,42,9,2 };
	//所有元素不重复，multiset可以
	pr(s2);
	set<int> s3({ 1,2,42,9,312 });
	//迭代器
	set<int> s4(s3.begin(), s3.end());
	//拷贝构造
	set<int> s5(s2);


	//赋值（都运算符重载）
	set<int> s6;
	s6 = s1;
	pr(s6);
	s6 = { 1,3,5 };

	//大小
	s6.empty();
	cout<<s6.size();

	//插入有序，不重复logn复杂度
	s6.insert(7);//插入一个元素
	vector<int>m = { 1,3,1000 };
	s6.insert(m.begin(), m.end());//不能用front，back
	pr(s6);

	//查找
	s6.find(4);//返回迭代器，否则返回。end（）


	//删除
	s6.erase(1);
	s6.erase(s6.begin(), s6.end());//左闭右开
    //s6.erase(迭代器)

	//计数  count  multiset count 可以有重复元素
	return 0;
}