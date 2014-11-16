#include <iostream>
#include "static.h"

using std::cout;


void printGlobalVariable(){
    
    cout << "The value of the multi_file global variable is: " << GLOBAL_VARIABLE << std::endl;
    
}

void printStaticGlobalVariable(){
    
    // cout << "The value of the static global variable is: " << FILE_GLOBAL_VARIABLE << std::endl;
    
}
