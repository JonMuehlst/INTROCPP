#include <iostream>
#include <assert.h>
#include "gtest/gtest.h"
#include "binom.h"

/* 

int main(int argc, char **argv){
    
    int n = 5, k = 3, ans = 0;
    ans = binom(n,k);
    std::cout << "n choose k equals: " << ans << std::endl;
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}

*/

int binom(int n, int k){
    
    assert( (n >= 0) && (k >= 0) );    
    
    if( n < k)
        return 0;
    if( (n == k) || (k == 0) )
        return 1;
    
    return binom(n-1,k) + binom(n-1,k-1);
    
}


/*================================================================================

                                    Tests

================================================================================*/

TEST(Binom, binom){
    
    EXPECT_EQ(10, binom(5,3));
    EXPECT_EQ(15, binom(6,2));
    EXPECT_NE(15, binom(5,3));
    
    
}