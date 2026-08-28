#include <iostream>
using namespace std;
#include <stack>
#include <vector>
int main() {
	//对象创建
	/*1.默认//默认是个双端队列
		2.拷贝*/
	stack <int> b;
	stack <int> a(b);

	//赋值
	stack <int> a1;
	stack <int> a2;
	a1 = a2;//默认赋值，用的是deuqe的=重载
	 
	//入栈
	//调用双端队列的push_back
	//出栈
	//调用双端队列的pop_back

	//栈顶
	//调用双端队列的back（）

	//stack的大小：empty，size（）；


	//容器替换
	stack <int, vector<int>> sk;
	//原本调用deque，现在调用vector中的代码
	return 0;
}