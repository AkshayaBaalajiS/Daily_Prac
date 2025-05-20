// Abstract Class in C++
// Sample code for Abstract class and derived class 
#include <iostream>
using namespace std;

class AbstractClass
{
    public:
        AbstractClass()
        {
            cout<<"AbstractClass Constructor\n";
        }
        void nFunctionToDoSomething()
        {
            cout<<"This is the normal function of the Abstract class \n";
        }
        
        virtual void aFunctionToDoSomething_1() = 0;
        virtual void aFunctionToDoSomething_2() = 0;
        virtual void aFunctionToDoSomething_3() = 0;
};
class DerivedClass : public AbstractClass
{
    public :
        DerivedClass()
        {
            cout<<"DerivedClass constructor \n";
        }
        void aFunctionToDoSomething_1() 
        {
            cout<<"virtual void aFunctionToDoSomething_1() THis is the abstract class function to do something \n ";
        }
        void aFunctionToDoSomething_2()
        {
            cout<<"virtual void aFunctionToDoSomething_2() THis is the abstract class function to do something \n ";
        }
        void aFunctionToDoSomething_3()
        {
            cout<<"virtual void aFunctionToDoSomething_3() THis is the abstract class function to do something \n ";
        }
        
};

//
//So without override mentioned the compiler automatically override the functions of abstract class from derived class 
//

int main()
{
    cout<<"This is the program to see the understanding of the Abstract class in C++\n";
    
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++\n";
    DerivedClass * obj = new DerivedClass();
    
    obj->nFunctionToDoSomething();
    
    obj->aFunctionToDoSomething_1();
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++\n";
    
    AbstractClass * ptr =  new DerivedClass();
    ptr->nFunctionToDoSomething();
    
    ptr->aFunctionToDoSomething_1();
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++\n";
    
    //
    // The below line will create error cause we cant create the object for the abstract class 
    //AbstractClass absObject;
    //
    
    // The below can be done cause we are just creating a pointer to the Abstract class 
    AbstractClass * absPtr;
    
}
