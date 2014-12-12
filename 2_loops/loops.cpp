#include <iostream>
#include <limits.h>
#include <bitset>
#include <cassert>
#include "gtest/gtest.h"

using std::cout;
using std::endl;


int main(int argc, char ** argv){
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}

unsigned char reverseByte(unsigned char byte){
    
    unsigned char t = 0;     // t will have the reversed bits of 'byte'
    size_t i = 0;
    
    for (i = 0 ; i < (sizeof(byte) * 8); i++, byte >>= 1){
      t = (t << 1) | (byte & 1);
      std::cout << "i: " << i << " t int val: " << (int)t << " byte int val: " << (int)byte << std::endl;
    }
    
    
    return t;
}

void pyramid1(){
    int i,j,rows = 5;
    for(i=1;i<=rows;++i)
    {
        for(j=1;j<=i;++j)
        {
           cout<<"* ";
        }
        cout<<"\n";
    }
}

void pyramid2(){
    int i,j,rows = 5;
    for(i=rows;i>=1;--i)
    {
        for(j=1;j<=i;++j)
        {
           cout<<"* ";
        }
        cout<<"\n";
    }
}

void pyramid3(){
    
    int i,space,rows = 5,k = 0;
    for(i=1;i<=rows;++i)
    {
        for(space=1;space<=rows-i;++space)
        {
           cout<<"  ";
        }
        while(k!=2*i-1)
        {
           cout<<"* ";
           ++k;
        }
        k=0;
        cout<<"\n";
    }
}

void pyramid4(){
    int rows = 5,i,j,space;
    for(i=rows;i>=1;--i)
    {
        for(space=0;space<rows-i;++space)
           cout<<"  ";
        for(j=i;j<=2*i-1;++j)
           cout<<"* ";
        for(j=0;j<i-1;++j)
           cout<<"* ";
        cout<<endl;
    }
}


/*================================================================================

                                    Tests

================================================================================*/

TEST(Loops, reverse_byte){
    
    unsigned char byte = (char)1;
    std::cout << "char: " << byte << " int: " << (int)byte << std::endl;
    EXPECT_EQ(128,(int)reverseByte(byte));
    
}

TEST(Loops, pyramids){
    pyramid1();
    pyramid2();
    pyramid3();
    pyramid4();
    
}