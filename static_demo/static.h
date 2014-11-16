#ifndef STATIC_H
#define STATIC_H

extern int GLOBAL_VARIABLE;
// extern int FILE_GLOBAL_VARIABLE;

void increment();

class staticDemo{
    
    private:
        int id;
        
    public:
        staticDemo();
        static double PI;
        static int staticVariable;
        static int staticFunction();
        void printId();
        
};

#endif