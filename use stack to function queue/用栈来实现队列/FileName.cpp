#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;
class MyQueue {

private:
    stack<int> s1;
    stack<int> s2;
    int size = 0;

    /** Initialize your data structure here. */
public:
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        size++;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {

        if (s2.size() == 0) {

            while (s1.size()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        size--;
        int  x = s2.top();
        s2.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {

        if (s2.size() == 0) {
            while (s1.size()) {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        int x = s2.top();
        return x;
    }


    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
}; int main() {
	








	return 0;
}