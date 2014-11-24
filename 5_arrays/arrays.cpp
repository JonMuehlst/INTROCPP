#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gtest/gtest.h"
#include "arrays.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char ** argv){
    
    int a[10];
    fillArrayRandomly(a, 10);
    printArray(a, 10);
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

double arraySum(double a[], size_t a_size){
    
    double sum = 0;
    
    for(size_t i = 0; i < a_size; i++){
        
        sum += a[i];
        
    }
    
    return sum;
    
}

void bubbleSort(double * a, size_t a_size){
    
    for(size_t i = 0; i < a_size; i++){
        
        for(size_t j = 0; j < a_size - i - 1; j++){
            
            if (a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
            
        }
        
    }
    
}

void swap(double * a, double * b){
    
    double tmp = *a;
    *a = *b;
    *b = tmp;
    
}

int stringLength(char str[ ]){
    
     size_t i = 0;
     
     while (str[ i ] != '\0')
         i++;
     
     return i;
     
}

void printArray(int * a, size_t a_size){
    
    cout << endl;
    
	for (size_t i = 0; i < a_size; i++)
		cout << a[i] << "\t";
	
	cout << endl << endl;
	
}

void fillArrayRandomly(int * a, size_t a_size){

    srand(time(0));

	for (size_t i = 0; i < a_size; i++)
		a[i] = rand()%100 + 1;
		
}

int getMax(int * a, size_t a_size){
	
	int max = a[0];
	
	for (size_t i = 0; i < a_size; i++)
		if(a[i] > max)
			max = a[i];
	
	return max;
	
}

int * find(int * a, size_t a_size, int num){
    
    
	for (size_t i = 0; i < a_size; i++)
		if (a[i] == num)
			return &a[i];
	
	return NULL;
}


/*================================================================================

                                    Tests

================================================================================*/

TEST(Arrays, array_sum){
    
    double a[100];
    
    for(size_t i = 0; i < 100; i++){
        a[i] = i+1;
    }
    
    EXPECT_DOUBLE_EQ(5050, arraySum(a, 100));
    
}

TEST(Arrays, bubble_sort){
    
    double a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    
    bubbleSort(a, 10);
    
    for(size_t i = 0; i < 10 - 1; i++){
        EXPECT_LE(a[i], a[i+1]);   
    }
    
}

TEST(Arrays, string_length){
    
    char str[] = "string length is 19";
    
    EXPECT_EQ(19, stringLength(str));
    
}

TEST(Arrays, get_max){
    
    int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 100 };
    
    EXPECT_EQ(100, getMax(a, 10));
}

TEST(Arrays, find_num){
    
    int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 100 };
    
    int * ans = find(a, 10, 5);
    EXPECT_TRUE(5 == *ans);
    
    ans = find(a, 10, 75);
    EXPECT_TRUE(NULL == ans);
    
}