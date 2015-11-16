#include<vector>
#include<iostream>
#include<stack>
using namespace std ;

class MinStack {
    int i=1,mini;
    stack<int> stk;
    stack<int> m_stk;
public:
    void push(int x) {
        stk.push(x);
        cout<<"hi"<<endl;
        if(i==1)
            mini = x;
        else if(mini < x)
            mini = x;
        m_stk.push(mini);
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return m_stk.top() ;
    }
};


int main(){
	MinStack s ;
	s.push(-3);
	cout<<s.getMin();
}
