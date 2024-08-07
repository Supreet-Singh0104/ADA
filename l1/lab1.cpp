#include <iostream>
#include <vector>
using namespace std;
class base{
    public:
    void displaybase(){
        cout<<"base class"<<endl;
    }
};
class intermediate: public base{// single inheritance
    public:
    void displayintermediate(){
        cout<<"intermediate class"<<endl;
    }
};
class derived: public intermediate{ // multiple inheritance
    public:
    void displayderived(){
        cout<<"derived class"<<endl;
    }
};

class Base1{
    public:
    void displaybase1(){
        cout<<"base class 1"<<endl;
}
};
class Base2{
    public:
    void displaybase2(){
        cout<<"base class 2"<<endl;
    }
};
class multiple: public Base1, public Base2{ // multiple inheritance
    public:
    void displaymultiple(){
        displaybase1();
        displaybase2();
        cout<<"MultipleDerived class print function."<<endl;
    }
};

class HierarchicalDerived1 : public base {// Hierarchical Inheritance
public:
    void hierarchicalShow1() {
        cout << "HierarchicalDerived1 class show function." << endl;
    }
};

class HierarchicalDerived2 : public base {
public:
    void hierarchicalShow2() {
        cout << "HierarchicalDerived2 class show function." << endl;
    }
};


class HybridDerived1 : public base {// Hybrid Inheritance
public:
    void hybridShow1() {
        cout << "HybridDerived1 class show function." << endl;
    }
};

class HybridDerived2 : public base {
public:
    void hybridShow2() {
        cout << "HybridDerived2 class show function." << endl;
    }
};

class Hybrid : public HybridDerived1, public HybridDerived2 {
public:
    void hybridFunction() {
        cout << "Hybrid class function." << endl;
    }
};


int main(){
    // Single Inheritance
    intermediate inter;
    inter.displaybase();
    inter.displayintermediate();

    cout<<endl;

    // Multilevel Inheritance
    derived multilevel;
    multilevel.displaybase();
    multilevel.displayintermediate();
    multilevel.displayderived();
    cout<<endl;

    // Multiple Inheritance
    multiple multi;
    multi.displaymultiple();
    cout<<endl;


        // Hierarchical Inheritance
    HierarchicalDerived1 hierarchicalObj1;
    HierarchicalDerived2 hierarchicalObj2;
    hierarchicalObj1.displaybase();
    hierarchicalObj1.hierarchicalShow1();
    hierarchicalObj2.displaybase();
    hierarchicalObj2.hierarchicalShow2();

    cout << endl;

    // Hybrid Inheritance
    Hybrid hybridObj;
    hybridObj.hybridShow1();
    hybridObj.hybridShow2();
    hybridObj.hybridFunction();
    return 0;
}