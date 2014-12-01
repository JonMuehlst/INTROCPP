/*
        
        void printCenterOfMass();
        int printIsSumPossible();
    
        are taken from the following presentation:
        http://webcourse.cs.technion.ac.il/234114/Winter2014-2015/ho/WCFiles/Tutorial5.pdf
    
    
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "two_d_arrays.h"
#include "gtest/gtest.h"

using std::cout;
using std::cin;
using std::endl;


int main(int argc, char ** argv){
    
    // Local variable & array declaration
    
	int arr[][ARR_COLS] = { { 1, 2, 3, 4 }, { 2, 2, 10, 40 }, { 3, 10, 3, -33 }, { 4, 40, -33, 4 } };
 	int ** arr2 = new int *[ARR_COLS];
	double arr3[N][3];
	double COMASS[3];
// 	int arr4[N];
	//-----------------------------------
	
  	//rand() seed
	srand(time(0));
	
    // Array initialization
	for(int i = 0; i < 4; i++)
	    arr2[i] = new int [ARR_COLS];
	    
	for(int i = 0; i < 4; i++)
	    for(int j = 0; j < 4; j++)
	        arr2[i][j] = (int)(rand() % 200 + 1 - 100);
	
	
	for(int i = 0; i < N; i++)
	    for(int j = 0; j < 3; j++)
	        arr3[i][j] = (rand() % 200 + 1 - 100);


    // for(int i = 0; i < N; i++)
        // arr4[i] = (int)(rand() % 100 + 1);
    //------------------------------------

    centerOfMass(arr3, COMASS);

    
    printArr(arr,4,4);
    cout << "-------------------------------------" << endl;
    
	cout << "The sum of the secondary diagonal is: " << sumSecDiagonal(arr) << endl;
	cout << "-------------------------------------" << endl;

    if(isMatSymmetric(arr,4,4))
        cout << "mat is symmetric" << endl << endl;
    else
        cout << "mat is not symmetric" << endl << endl;
    
    printArr(arr2,4,4);
    cout << "-------------------------------------" << endl;
    
    transposeMat(arr2,4,4);
    cout << "After transpose" << endl;
    
    printArr(arr2,4,4);
    cout << "-------------------------------------" << endl;
    
    // Deleting dynamically allocated matrix
    for(int i = 0; i < 4; i++)
	    delete [] arr2[i];
	
    delete [] arr2;
    //-------------------------------------
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void centerOfMass(double points[N][3], double centerOfMass[3]){
    
    centerOfMass[0] = centerOfMass[1] = centerOfMass[2] = 0.0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            centerOfMass [j] += points[i][j]/N;
        }
    }
    
    cout << "c.m. = (" << centerOfMass[0] << ", " << centerOfMass[1] << ", " << centerOfMass[2] << ")" << endl; 

}

bool isSumPossible(int a[], int k, int cand_a, int cand_b){
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (((a[i] == cand_a) && (a[j] == cand_b)) || ((a[i] == cand_b) && (a[j] == cand_a))) 
                if (a[i] + a[j] == k){
                    cout << "Found " << a[i] << " and " << a[j] << endl;
                    return true;
            }
        }
    }
    
    cout << "The sum is not possible." << endl;
    return false;
}

int sumSecDiagonal(int arr[][ARR_COLS]) {
	
	int sum = 0, j = ARR_COLS - 1;
	
	for (int i = 0; i < ARR_COLS; i++){
	    sum += arr[i][j];
	    j--;
    }
	    
	return sum;
}

bool isMatSymmetric(int arr[][ARR_COLS], size_t rows, size_t cols){
    
    bool flag = true;
    
    for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < i; ++j) {
		    if(arr[i][j] != arr[j][i]){
		        flag = false;
		    }
	    }
    }
	
	return flag;
    
}

void transposeMat(int ** arr, size_t rows, size_t cols) {
	
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < i; ++j) {
		    swap(arr[i][j], arr[j][i]);
		}
	}
	
}

void transposeMat(int arr[][ARR_COLS], size_t rows, size_t cols) {
	
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < i; ++j) {
		    swap(arr[i][j], arr[j][i]);
		}
	}
	
}

void swap(int & a,int & b){
    
    int tmp = a;
    a = b;
    b = tmp;
    
}

void printArr(int arr[][ARR_COLS], size_t rows, size_t cols) {
	cout << "The two dimensional array:" << endl;
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void printArr(int ** arr, size_t rows, size_t cols) {
	cout << "The two dimensional array:" << endl;
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

/*================================================================================

                    Tests

================================================================================*/

TEST(Matrix, center_of_mass){
    
    double a[N][3] = { {0, 1, 2}, 
                       {10, 11, 12}, 
                       {20, 21, 22}, 
                       {30, 31, 32}, 
                       {40, 41, 42}, 
                       {50, 51, 52}, 
                       {60, 61, 62}, 
                       {70, 71, 72}, 
                       {80, 81, 82}, 
                       {90, 91, 92} };
    
    double com[3] = {0};
    
    centerOfMass(a, com);
    
    EXPECT_DOUBLE_EQ(45, com[0]);
    EXPECT_DOUBLE_EQ(46, com[1]);
    EXPECT_DOUBLE_EQ(47, com[2]);
    
}

TEST(Matrix, is_sum_possible){
    
    int a[N] = {1, 2, 3, 3, 5, 6, 7, 8, 9, 10};
    int b[N] = {3, 3, 3, 3, 3, 6, 7, 8, 9, 10};
    
    int k1 = 6;
    int k2 = 7;
    
    int cand_a1 = 3;
    int cand_b1 = 3;
    
    int cand_a2 = 3;
    int cand_b2 = 4;
    
    EXPECT_TRUE(isSumPossible(a,k1, cand_a1, cand_b1));
    EXPECT_FALSE(isSumPossible(b,k2, cand_a2, cand_b2));

}


TEST(Matrix, sum_of_secondary_diagonal){
    
    int a[ARR_COLS][ARR_COLS] = { {1, 2, 3, 4}, 
                                  {5, 6, 7, 8}, 
                                  {9, 10, 11, 12}, 
                                  {13, 14, 15, 16} };
    
    EXPECT_EQ(34, sumSecDiagonal(a));

}

TEST(Matrix, is_matrix_symmetric){

    int a[ARR_COLS][ARR_COLS] = { { 1, 2, 3, 4 },
                                  { 2, 2, 10, 40 }, 
                                  { 3, 10, 3, -33 }, 
                                  { 4, 40, -33, 4 } };
                                  
    EXPECT_TRUE(isMatSymmetric(a,4,4));

}

TEST(Matrix, transpose){

    int a[ARR_COLS][ARR_COLS] = { {9, -10, -34, -83},
                                 {-97, -82, -76, -49},
                                 {97, -8, 18, 65},
                                 {70, 0, 12, -34} };

    int b[ARR_COLS][ARR_COLS] = { {9, -10, -34, -83},
                                 {-97, -82, -76, -49},
                                 {97, -8, 18, 65},
                                 {70, 0, 12, -34} };

    transposeMat(a,4,4);
    
    for(size_t i = 0; i < 4; i++)
        for(size_t j = 0; j < i; j++)
            EXPECT_EQ(b[i][j], a[j][i]);
}
