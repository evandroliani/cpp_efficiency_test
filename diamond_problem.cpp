/* The diamond problem happens when a base class A is inherited by 2 subclasses B and C, which are then both inherited by D */
/* C++ solution is to declare both inheritance from A as virtual, in order to avoid ambiguity */
/* An alternative way is to rename the functions in the subclasses, though this is a less elegant and more difficult to maintain solution */
#include<iostream>
using namespace std;

class A{
    public:
        void print(){cout<<"A"<<endl;}
};
class B: public virtual A{};
class C: public virtual A{};
class D: public B, public C{};
int main(){
    D d;
    d.print();
    return 0;
}
