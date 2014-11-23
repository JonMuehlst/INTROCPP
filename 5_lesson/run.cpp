#include <iostream>
#include "binom.h"
#include "selection_sort.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    
    /*
        Selection sort
    */
    
	int arr[MAX_ARR_SIZE]; // static allocation 
	
	int arr_size= getArrayFromInput(arr, MAX_ARR_SIZE);
	
	printArr(arr, 0, arr_size);
	
	sort(arr, arr_size);
	
	printArr(arr, 0, arr_size);

    /*
        Binom
    */
    
    int n = 5, k = 3, ans = 0;
    ans = binom(n,k);
    std::cout << "n choose k equals: " << ans << std::endl;
    
    /*
        run tests
    */
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}