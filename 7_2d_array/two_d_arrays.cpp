#include <cstdlib>
#include <ctime>
#include <iostream>
#include "two_d_arrays.h"
#include "gtest/gtest.h"

using std::cout;
using std::endl;


int main(int argc, char ** argv){
    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


int ** initMatrix(size_t rows,size_t cols){

 	int ** a = new int * [rows];
	
    for(size_t i = 0; i < rows; i++)
	    a[i] = new int [cols];
	
	for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            a[i][j] = 0;
        }
    }
    
    return a;
}

void deleteMatrix(int ** a,size_t rows,size_t cols){
    
    for(size_t i = 0; i < rows; i++)
        delete [] a[i];
    
    delete [] a;
    
}

int sumFlowers(int ** a,size_t rows,size_t cols){

    int sum = 0;

    for(size_t i = 1; i < rows - 1; i++){
        for(size_t j = 1; j < cols - 1; j++){
            sum += isFlower(a,i,j);
        }
    }
    
    return sum;
}

int isFlower( int ** a,size_t i,size_t j){
    
    int sum = a[i-1][j-1] + a[i-1][j+1] + a[i+1][j+1] + a[i+1][j-1];
    
    if(sum == a[i][j])
        return 1;
    
    return 0;
    
}

// Matrices are NxN
// Multiply a x b and store the result in c
void multiplyMatrix(int ** a, int ** b, int ** c,size_t N){
    
    int sum = 0;
    
    for(size_t k = 0; k < N; k++){
        for (size_t i = 0; i < N; i++) {
    		for (size_t j = 0; j < N; j++) {
    		    sum += a[k][j] * b[j][i];	
    		}
    		c[k][i] = sum;
    		sum = 0;
    	}
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

TEST(Matrix, flowers){

    int sum = 0;
    int ** a = initMatrix(4,4);

    a[0][0] = 3;
    a[0][1] = -10;
    a[0][2] = 2;
    a[0][3] = -83;
    a[1][0] = 9;
    a[1][1] = 10;
    a[1][2] = -34;
    a[1][3] = -83;
    a[2][0] = 1;
    a[2][1] = 20;
    a[2][2] = 4;
    a[2][3] = -83;
    a[3][0] = 11;
    a[3][1] = -10;
    a[3][2] = 34;
    a[3][3] = 87;
    
    printArr(a,4,4);
    
    sum = sumFlowers(a,4,4);
    
    EXPECT_EQ(3, sum);
    
    deleteMatrix(a,4,4);
}

TEST(Matrix, multi){

    int ** a = initMatrix(3,3);
    int ** b = initMatrix(3,3);
    int ** c = initMatrix(3,3);
    int ** d = initMatrix(3,3);

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;
    
    b[0][0] = 9;
    b[0][1] = 8;
    b[0][2] = 7;
    b[1][0] = 6;
    b[1][1] = 5;
    b[1][2] = 4;
    b[2][0] = 3;
    b[2][1] = 2;
    b[2][2] = 1;

//  30.000  24.000  18.000
//  84.000  69.000  54.000
// 138.000 114.000  90.000

    d[0][0] = 30;
    d[0][1] = 24;
    d[0][2] = 18;
    d[1][0] = 84;
    d[1][1] = 69;
    d[1][2] = 54;
    d[2][0] = 138;
    d[2][1] = 114;
    d[2][2] = 90;
    
    multiplyMatrix(a,b,c,3);
    
    printArr(a,3,3);
    printArr(b,3,3);
    printArr(c,3,3);
    printArr(d,3,3);
    
    for(size_t i = 0; i < 3; i++)
            for(size_t j = 0; j < 3; j++)
                EXPECT_EQ(d[i][j], c[i][j]);
    
    deleteMatrix(a,3,3);
    deleteMatrix(b,3,3);
    deleteMatrix(c,3,3);
    deleteMatrix(d,3,3);
}
