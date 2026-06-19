
#include<iostream>
using namespace std;

// //function template 

template <class T1, class T2>
T1 funcAvg(T1 a, T2 b) {
    return static_cast<float>(a + b) / 2;  // Explicit type casting for accuracy
}

int main() {
    int x = 5;
    double y = 7.5;

    cout << "Average: " << funcAvg(x, y) << endl; // Calls function template
    return 0;
}


//template function overloading 
template<class T>

class Harry{
    public:
    T data;
    Harry(T a){
        data=a;
    }
    void display();
};

template<class T>
void func(T a){
    cout<<"first function"<<endl;
}

template<class T>
void funct1(T a){
    cout <<"I am templatised function"<<a<<endl;
}

template <class T>
void Harry<T>::display(){
    cout<<data<<endl;
}

int main(){
    // Harry<int> obj(2);
    // obj.display();
    // return 0;
    func(4); //same name case m exact match phle execute hoga mtlb template function phle execute nhi hoga like function overlaoding 
}