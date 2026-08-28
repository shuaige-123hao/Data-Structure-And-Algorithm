#include <iostream>
#include <queue>
using namespace std;
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        int x1 = q1.front();
        q1.pop();
        while (q2.size()) {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
        return x1;
    }

    int top() {
        while (q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        int x = q1.front();
        q2.push(x);
        q1.pop();
        while (q2.size()) {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
        return x;
    }

    bool empty() {
        return q1.empty();
    }
};
int main() {

    MyStack q;
    q.push(1);
    q.push(2);
    cout << q.pop();
       //cout<< endl<<q.pop()<<endl;
        cout << q.empty();
    
    return 0;
}