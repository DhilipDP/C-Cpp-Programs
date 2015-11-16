#include <iostream>
using namespace std;
 
class A
{
    public:
    A& operator=(const A&a)
    {
        cout << "Hello" << endl;
        return *this;
    }
};
 
class B
{
    A a[2];
};
 
int main()
{
    B b1, b2;
    b1 = b2;
    return 0;
}
