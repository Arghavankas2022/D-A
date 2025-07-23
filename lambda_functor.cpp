#include <iostream>
#include <vector>
//remove // to use functions
// Practicing functors and lamda expression
//Q1- Functor 
//class Multiplicationby3 {

    //public : 
    //int operator() (int x) const {
        //return x*3;
    //}
//};

//Q2- Functor
//class Filter_Even {

    //public :
    //bool operator() (int x) const {
        //return x%2==0;
    //}
//};

template<typename T, typename F>
void filter (const T& collection, F predicate) {
    for (auto element: collection)
    if (predicate(element))
    std::cout <<element<<" ";
    std::cout<< "\n";
}

//Q3-Functor 

//class GreaterThan {

    //int value;
    //public :
    //GreaterThan(int x) : value{x}{} //Member initialiser list : use argument to initlaise the value member 

    //bool operator() (int par) const {
        //return par> value;
    //}
//};

//Q4-Functor 

class Square {

    public:
    int operator () (int x) const {
        return x*x;
    }
};
 


int main() {
    //Lambda
    std::vector<int> v = {1,2,3,4,5,6,7,8};
    //filter(v,Filter_Even());
    // Q1- Lambda
    auto m =[] (int x) {return x*3;};
    std::cout<<m(5);
    std::cout<< "\n";
    // Q2-Lamda
    std::for_each (v.begin(), v.end(), [=](int x){if (x % 2 == 0) std::cout << x << " ";});
    std::cout<< "\n";
    int value = 2;
    //filter(v,GreaterThan(value));
    //Q3- Lambda
    filter(v, [value] (int x) {return x>value;});

    Square b;
    std::cout << b(3);
    std::cout<< "\n";

    //Q4-Lambda
    auto s = [] (int x) {return x*x;};
    std::cout<<s(5);
}