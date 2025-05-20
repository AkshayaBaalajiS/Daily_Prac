#include <iostream>
#include <sstream>
using namespace std;

class createExceptionClass : public exception
{
    // string vari;
    public :
    string vari;
    mutable string vari_1;
    
        createExceptionClass()
        {
            cout<<"createExceptionClass class constructor called \n";
        }
        
        // the below wont be called from exception class cause the function declaration not matches the what function type   
        // string what()
        // {
        //     ostringstream oss;
        //     oss<<"This is the custom what function from the createExceptionClass \n";
        //     return oss.str();
        // }
    
        const char* what() const noexcept override
        {
            ostringstream oss;
            oss<<"This is the custom what function from the createExceptionClass \n";
            // vari = oss.str();
            // the above cant be done cause in const function non mutable member cant be changed 
            vari_1 = oss.str(); // mutable member can be changed 
            
            // cout<<vari<<"++++++++++\n";
            const char * some_val = vari_1.c_str();
            // cout<<some_val<<"-----\n";
            // return (oss.str()).c_str();
            return some_val; // issue is with temp string used 
        }
};

int main()
{
    cout<<"This is the code to understand how the class becomes exception code works \n";
    
    try
    {
        createExceptionClass obj;
        throw(obj);
    }
   
    catch(std::exception & exception)
    {
        cout<<"Exception is  : " << exception.what()<<endl;
    }
}
