#include <iostream>
#include <string>
using namespace std;
//   If a derived constructor does not explicitly call a base-class constructor,
// C++ automatically inserts a call to the base class default constructor.
class A {
public:
string name;
int marks;
   
   
    // A(string name ,int marks) { cout << "parent constructor\n"; 
    // this->name=name;
    // this->marks=marks;
    
    // }
   virtual void print(){
        cout<<"hello from parent"<<endl;
    }

};

class B : public A {
public:
int rollno;
//    B(string name,int marks ,int rollno ):A(name,marks){
//     this->rollno=1;
//    }
 void print(){
    cout<<"hello from child"<<endl;
 }

     
};

int main() {
A *obj1;
B obj2;
obj1=&obj2;
obj1->print();
return 0;
}
