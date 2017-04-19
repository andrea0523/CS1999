/*  Requirements for this MP

 You must implement 3 classes with constructors and destructors to mimic the print statements listed below.
 You may not modify any of the constructors or member variables in the Base class, however, you will have to add additional methods. You should write a derived class, a derived class that has a constructor with paramters , and a doubly derived class. You must also write a makefile (which should be fairly simple) to compile this project.
 You must only print in your constructors and destructors and cout<< must not appear outside of them.
 Your doubly derived class should inherit from the Derived class, and it must not be able to access any of Derived class's members (Hint class DoubleDerived: ... ). You also must fix any memory leaks.
 Check Piazza for the hint if your ouput is funky!

 * How to test your code:   Once it compiles you can diff it with the provided example output intialized with 17 as x and 76 as y.
 * How to diff: run your file as you would normally, however redirect the output to a file by running
 ./EXENAME > output.txt
 * Then run diff output.txt exampleoutput.txt if nothing is printed by the diff it works for the example output.
 *
 *  Grading: I will substitute my own main method and pipe the output into a file and diff it.
 *              I will also check for the use of classes. As a sanity check. You should have a derived class that has its own child and a derived class without any children (4 classes in total including the one I gave you). Finally you should fix any memory leaks.
 */




/*

 You might need to include some things

 */
#include "base.hpp"

class D2 : public Base {
public:
  D2():Base(){
    cout << "Derived Constructor called" << endl;
  }
  D2(int x, int y):Base(x, y) {
    cout << "DerivedParameter Constructor called" << endl;
    //cout << "X: " << this->x << " Y: " << this->y << endl;
  }
  ~D2() {
    cout << "DerivedParameter Destructor called" << endl;
    Base::del();
  }
};

class D1 : public Base {
public:
  D1():Base(){
    cout << "Derived Constructor called" << endl;
  }
  D1(int x, int y):Base(x, y) {
    cout << "DerivedParameter Constructor called" << endl;
    //cout << "X: " << this->x << " Y: " << this->y << endl;
  }
  ~D1() {
    cout << "Derived Destructor called" << endl;
    Base::del();
  }
};

class DD1 : public D1 {
public:
  DD1():D1(){
    cout << "DoubleDerived Constructor called" << endl;
  }
  ~DD1(){
    cout << "DoubleDerived Destructor called" << endl;
    Base::del();
  }
};

int main() {
    D2 * a = new D2(17, 76);
    cout << "X: " << a->get_x() << " Y: " << a->get_y() << endl;
    delete a;
    DD1 * b = new DD1();
    delete b;
    return 0;
}


//BaseXY Constructor called
//DerivedParameter Constructor called
//X: 17 Y: 76
//DerivedParameter Destructor called
//Base Destructor called
//
//Base Constructor called
//Derived Constructor called
//DoubleDerived Constructor called
//DoubleDerived Destructor called
//Derived Destructor called
//Base Destructor called
//
