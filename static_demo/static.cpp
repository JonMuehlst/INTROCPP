#include <iostream>
#include "static.h"
#include "file2.h"

using std::cout;

double staticDemo::PI = 3.14159265359;
int    staticDemo::staticVariable = 0;

int GLOBAL_VARIABLE = 999;
static int FILE_GLOBAL_VARIABLE = 777;

int main(){
    
    increment();
    increment();
    increment();
    
    staticDemo a = staticDemo();
    staticDemo b = staticDemo();
    staticDemo c = staticDemo();
    
    a.printId();
    b.printId();
    c.printId();
    
    cout << "The static value of PI is: " << staticDemo::PI << std::endl;
    
    printGlobalVariable();
    printStaticGlobalVariable();

}

// ========================================================================
// 
//                          Static demo class implementation
// 
// ========================================================================


staticDemo::staticDemo(){
    
    this->id = staticDemo::staticFunction();
    
}

int staticDemo::staticFunction(){
    
    staticVariable++;
    return staticVariable;
    
}

void staticDemo::printId(){
    
    cout << "This is object #" << this->id << std::endl;
     
}


// ========================================================================
// 
//                          Static function variable
// 
// ========================================================================

void increment(){
    
    static int counter = 0;
    cout << "The value of counter is: " << counter << std::endl;
    counter++;
    
}
