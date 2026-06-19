#include<iostream>
using namespace std;

template <class T1=int, class T2=float>
class myClass {
    public:
    T1 a;
    T2 b;
    
    myClass(T1 x, T2 y) {
        a = x;
        b = y;
    }
    
    void display() {
        cout << "value od a is:" <<a<< endl;
        cout << "value of b is: "<<b<< endl;
    }
};

int main() {
    myClass<> h(1,2.1);
    h.display();
    cout<<endl;
    myClass<char,int>g('c',1);
    g.display();
    return 0;
}