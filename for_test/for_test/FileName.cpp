#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        //准备猴子队列，并入队
        queue<int> monkey1;
        queue<int> monkey2;
        for (int i = 1; i <= n; i++) {
            monkey1.push(i);
        }
        //出队
        int tmp = m - 1;
        while (monkey1.size() + monkey2.size() > 1) {
            
            while (monkey1.size() + monkey2.size() > 1&&!monkey1.empty()) {
                if (tmp-- > 0) {
                    int x = monkey1.front();
                    monkey1.pop();
                    monkey2.push(x);
                }
                else {
                    tmp = m - 1;
                    monkey1.pop();
                }
            }
           
            while (monkey1.size() + monkey2.size() > 1&&!monkey2.empty()) {
                if (tmp-- > 0) {
                    int x = monkey2.front();
                    monkey2.pop();
                    monkey1.push(x);
                }
                else {
                    tmp = m - 1;
                    monkey2.pop();
                }
            }
        }

        if (monkey1.size() == 0) {
            cout << monkey2.front() << endl;
        }
        else {
            cout << monkey1.front() << endl;
        }
    }

}