#include<iostream>
#include<stack>

using namespace std ;


stack<int> elementStack;
        stack<int> minimumStack;
       
     
       void push(int x) {
           if(elementStack.empty())
                 {
                        elementStack.push(x);
                        minimumStack.push(x);
                }
           else
                {
      elementStack.push(x);
       int y = minimumStack.top();
      
        if( x < y )
          minimumStack.push(x);
        else
          minimumStack.push(y);
    }
        }

        void pop() {
            if(!elementStack.empty()){
                elementStack.pop() ;
                minimumStack.pop() ;
            }
        }
        int top() {
            if (elementStack.empty()) 
                return -1;
            return elementStack.top();
        }
        
           int getMin() {
            if (minimumStack.empty()) 
                return -1;
            return minimumStack.top();
        }


int main()
{
	cout<<getMin() ;	
}
