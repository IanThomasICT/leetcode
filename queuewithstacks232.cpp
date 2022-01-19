#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> inqueue;
    stack<int> outqueue;
public:
    MyQueue();
    
    void push(int x) {
        inqueue.push(x);
    }
    
    int pop() {
        if (!outqueue.empty()){
            int tmp = outqueue.top();
            outqueue.pop();
            return tmp;
        } else {
            while (!inqueue.empty()){
                outqueue.push(inqueue.top());
                inqueue.pop();
            }

            int tmp = outqueue.top();
            outqueue.pop();
            return tmp;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (!outqueue.empty()){
            return outqueue.top();
        } else {
            while (!inqueue.empty()){
                outqueue.push(inqueue.top());
                inqueue.pop();
            }

            return outqueue.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inqueue.empty() && outqueue.empty();
    }
};

int main() {


}