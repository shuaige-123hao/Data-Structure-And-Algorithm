#include <iostream>
#include <string>
//string c={'a','b'};
//string 会自己加'\0'
using namespace std;
int main() {
	//字符串的前n个字符
	string c("帅哥是我", 5);
	cout << c;
	cout << endl << sizeof(c) << "  " << c.size()<<"   ";
	//拷贝构造
	string a(c);
	cout << a<<"  ";
	//所有字符都初始化为同一个
	string n(8, 'a');
	cout << n;


	n.assign("我爱你",4);//4个有效字节的字符串
	cout << n;

	//字符串拼接用’+‘号+=也是一样运算符重载
	//a=a+b
	//append函数
	//a.append("",4)//取前4个有效
	//	a.append（“”，3,4）第三个位置后取4个
	//	push_back()括号必须是char常量


	//字符串比较
	//1.compare前面ASCII大返回1，一样返回0，小返回-1
	//aab-aaba得到-1
	//aaba-aab得到1
	//运算符重载
	//长度大的是1
	cout << endl;
	string a2 = "ab";
	cout << a.compare("c");

	//随机访问 at会检测异常 1【】效率高 可以修改


	//插入
	string c1 = "abc";
	c1.insert(1, 2, 'm');
	cout << c1<<endl;
	c1.insert(3, " ioi");
	cout << c1;
	cout << endl;
	c1.insert(c1.begin(), 'l');
	cout << c1<<endl;
	//删除
	//erase()全删
	string s1 = "kejqoe666";
	s1.erase(7);//7后面全删
	cout << s1<<endl;
	s1.erase(3, 2);//从第3个开始删2个
	cout << s1 << endl;

	s1.erase(s1.begin());//1个字符
		cout << s1<<endl;
		s1.erase(s1.begin() + 3, s1.end());
		//左闭右开
		cout << s1;



//查找
		cout << endl << "chazhao"<<endl;
		string s2 = "hello wooooooorld";
		cout << s2.find("oooooo") << endl<<endl;//返回索引
		cout << (int)s2.find("oooo", 15) << endl;//从索引10开始找字符串是否存在，存在返回索引，不存在返回-1
		cout << endl << "cha" << endl;
		cout << s2.find('v')<<endl;
		cout << endl << s2.rfind("oo");


//数据替换
		cout << endl << "替换";
		string s3 = "hello wooooooorld";
		s3.replace(3, 5, "niu");//把从索引三开始连续5个字符串替换
		cout << s3 << endl;

		//传迭代器，和第一个一样，不过迭代器默认左闭右开
		s3.replace(3, 5, "niu6666wqiiswi", 4);//取前4个字符
		cout << s3 << endl;


//子串获取
		string s4 = "hello worlllddd";
		string sub = s4.substr(0, 3);//从索引0开始，往后取3个字符串
		cout << sub;


		return 0;
}