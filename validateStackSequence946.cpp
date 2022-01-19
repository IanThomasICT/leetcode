#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;

    int i = 0;
    for (auto e : pushed){
        stk.push(e);
        while (!stk.empty() && stk.top() == popped[i]){
            stk.pop();
            i++;
        }
    }

    return stk.empty() ? true : false;
}

int main() {

    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {0,2,1};     
    vector<int> v3 = {3,2,1,4,5}; // true
    // vector<int> v4 = {5,4,1,2,3}; // false
    vector<int> v5 = {0,1,2}; // true 

    cout << validateStackSequences(v1,v3) << endl;



}