#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char ** argv){
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}

int abs(int val){
    
    if(val < 0)
        return -val;
    
    return val;
}

int max(int a, int b){
    if(a > b)
        return a;
        
    return b;
}

void printSong(int place){

    switch(place){
    
        case 1:
            std::cout << "The Days - Avicii feat. Robbie Williams" << std::endl;
            break;
        case 2:
            std::cout << "All About that Bass - Meghan Trainor" << std::endl;
            break;
        case 3:
            std::cout << "Blame - Calvin Harris feat. John Newman" << std::endl;
            break;
        case 4:
            std::cout << "Don't - Ed Sheeran" << std::endl;
            break;
        case 5:
            std::cout << "Maps - Maroon 5" << std::endl;
            break;
        case 6:
            std::cout << "Shake it Off - Taylor Swift" << std::endl;
            break;
        case 7:
            std::cout << "Dangerous - David Guetta feat. Sam Martin" << std::endl;
            break;
        case 8:
            std::cout << "Every Breaking Wave - U2" << std::endl;
            break;
        case 9:
            std::cout << "Habits -(Stay High) Remix Tove Lo" << std::endl;
            break;
        case 10:
            std::cout << "Yellow Flicker Beat - Lorde" << std::endl;
            break;
        default:
            std::cout << "Please select a value between 1-10" << std::endl;
    }
}

int factorial(int num){
    int fact = 1;
    for(int i = 1; i <= num; i++){
        fact *= i;
    }
    
    return fact;
}

int gcd(int a, int b){
    
    a = abs(a);
    b = abs(b);
    int tmp;
    
    while(b > 0){
        tmp = a;
        a = b;
        b = tmp % a;
    }
    
    return a;
}


/*================================================================================

                                    Tests

================================================================================*/

TEST(Functions, abs){
    
    int val = -10;
    
    EXPECT_EQ(10,abs(val));
    
}

TEST(Functions, max){
    
    int a = 5;
    int b = 10;
    
    EXPECT_EQ(b, max(a,b));
    
}

TEST(Functions, printSong){
    
    for(int i = 0; i <= 10; i++)
        printSong(i);
    
}

TEST(Functions, factorial){
    
    int fact = factorial(5);
    
    EXPECT_EQ(120,fact);
}

TEST(Functions, gcd){
    
    EXPECT_EQ(7,gcd(21,14));
    
}