#include <iostream>
using namespace std;
#include <vector>
 void printt(vector <int>& a) {
     for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) {
         cout << *iter << " ";

     }
     cout << endl;
}
 void remove(int index, vector<int>& c) {
     swap(c[index], c.back());
     c.pop_back();//时间复杂度1
 }
int main() {
    vector<int>a{2,0,2,1,1,0};
    for (int i = 0; i < 6; i++) {
        cout << a[i];
    }
    cout << endl;
    vector <int> h(a.begin(), a.end());//迭代器
    printt(h);
    vector <int> niubi(100, 8);//100个元素初始为8
   // print(niubi);
    cout << endl;
    vector <int> niu(a);//拷贝复制
    printt(niu);






    //赋值
    vector<int> neww = a;
    printt(neww);
    //初始化
    vector <int >a1;
    a1.assign({ 1, 23, 44, 4 });
    printt(a1);
    //
    vector <int>a2;
    a2.assign(a.begin(), a.end());
    printt(a2);
    vector <int>v3;
    v3.assign(8, 6);
    printt(v3);


    cout << "_____________________";
    //删除
    a1.pop_back();
    printt(a1);
     vector<int> ::iterator it=a1.erase(a1.begin());
    printt(a1);
    cout << *it;
    a1.clear();
    printt(a1);


    //扩容
    vector <int> m = { 1,2,3,4 };
    m.resize(5);
    cout << m.size() << "  " << m.capacity()<<endl;

    m.resize(100);
    
    cout << m.size() << "  " << m.capacity();
    //resize 不能缩容，只能改变size




   //随机访问
    vector <int> c1 = { 9,8,5,2,1,1 };
    cout << c1[1] << endl;//不会下标检测,未定义行为
    cout << c1.at(1) << endl;//下标检测，会产生异常，后面直接白板
    cout << c1.front() << endl;
    cout << c1.back() << endl;


    //内存交换
    vector <int> b1 = { 9,8,5,6 };
    vector <int> b2 = { 2,1,1 };
    cout <<&b1 << endl << &b2 << endl;
    cout << b1.capacity() << "  " << b2.capacity()<<endl;
    b1.swap(b2);
    cout << b1.capacity() << "  " << b2.capacity() << endl;
    cout << &b1 << endl << &b2 << endl;//首地址不变

    //缩容
    vector  <int>p = { 1,3,5 };
    p.resize(20);
    p.resize(5);
    vector<int>x(p);
    cout << "xswap前" << x.capacity() << " " << x.size() << endl;
    
        x.swap(p);//vector<int>x(p).swap(p);匿名对象x
        cout << "x"<<x.capacity() <<" "<< x.size() << endl;
        printt(x);
    cout << "p"<<p.capacity() << " " << p.size() << endl;

    //清理
    vector <int>{}.swap(p);
    cout << p.capacity();
    


    //空间预留
    vector <int>tg;
    tg.reserve(100);//修改capacity
    
    cout << endl;

    //高效删除
    
    vector <int> l;
    for (int i = 0; i < 30; i++) {
        l.push_back(i);
    }
    printt(l);
    for (int i = 0; i < 20; i++) {
        remove(0,l);
    }//效率高（时间复杂度1），但是针对顺序，要求不高才行
    cout << "清理后的";
    printt(l);



	return 0;
}