#include <iostream>
#include <list>
using namespace std;
void plist(const list<int>* a) {
	for (list<int>::const_iterator it = a->begin(); it!=a->end(); it++) {
		cout << *it << "   ";
	}
	cout << endl;
}
int getlist(list<int>& m, int index) {
	list<int>::iterator it = m.begin();
	while (index--) {
		it++;
	}
	return *it;
}
int cmp(int a, int b) {
	return a>b;
}
int main() {
	//对象创建
	//1.默认构造
	list <int> a;

	//2.初始化
	list <int> a1 = { 1,2,3,5,4 };//显示构造
	list <int> a2({ 1,3,4 });//隐式构造函数
	//3.迭代器
	list<int> a3(a1.begin(), a1.end());
	//4.全为一个数字初始化
	list<int> a4(8, 6);
	plist(&a4);
	//5.拷贝构造
	list<int> a5(a4);
	plist(&a5);


	//list赋值操作
	list <int>b = { 98,5 };
	list<int>b1;
	b1 = b;
	//迭代器
	list<int> b2;
	b2.assign(b.begin(), b.end());
	//初始化列表
	list<int> b3;
	b3.assign({ 1,2,6 });
	//初始化a个b
	list<int> b4;
	b4.assign(8, 6);


	//list大小操作
	/*empty
    size
    risize*/
	//empty 空就为1
	list<int>c;
	cout << c.empty()<<endl;
	c.assign({ 1,2 });
	cout << c.empty()<<endl;
	c.resize(20, 6);//20个元素中新生成的全部变为6
	plist(&c);

	//插入
	list<int> m = { 1,2 };
	/*push_front()
		push_back()
		insert*/
	//front前插
//back尾插
	//insert(迭代器，值）;
	list<int>::iterator it = m.begin();
	it++;
	m.insert(it , 100);
	plist(&m);
	//(迭代器，数量，值)
	m.insert(it, 3, 666);
	plist(&m);
	//(迭代器，迭代器开始，迭代器结束）
	it = m.begin();
	it++;
	m.insert(it, m.begin(), m.end());//将begin到end的内容插到it的位置
	plist(&m);

	//数据删除
	/*pop_front
		pop_back
		erase
		clear*/
	list<int> d = { 1,2,5,6,8,9};
	list<int>::iterator it1=d.erase(d.begin());//返回删后的节点
	cout << *it1<<endl;
	plist(&d);
	it1++;
	list<int>::iterator it2 = d.erase(it1);
	cout << *it2 << endl;
	//d.erase(迭代器1，迭代器2)从迭代器1删到迭代器2
	
	//clear
	d.clear();//全部删完




	//数据访问
	//1.不可使用下标访问，at，不存在随机访问
	//对于迭代器list<int> ::iterator it=a.begin(),不可以it=it+n；
	list <int> nnm = { 1,2 };
	//cout << nnm.begin();不存在随机访问


	//链表的反转
	list<int>fan{ 1,2,3,4 };
	fan.reverse();
	plist(&fan);


	//链表的排序
	list<int> niu({ 1,23,34,2,6,3 });
	niu.sort(cmp);
	plist(&niu);
	return 0;
}