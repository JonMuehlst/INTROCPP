#include <cassert>
#include <cmath>
#include "gtest/gtest.h"
#include "interlude.hpp"

// defined in the header
// #define MAT_SIZE 5

using std::cout;
using std::endl;

void matDiagSum(int a[][MAT_SIZE], int rows, int cols){
	
	for(int i = 0; i < rows - 1; i++){
		for(int j = 1; j < cols - i; j++){
			if(i == 0)
				a[j][j] = a[j - 1][j - 1] + a[j][j];
			else {
				a[i+j][j] = a[i+j - 1][j - 1] + a[i+j][j];
				a[j][i+j] = a[j - 1][i+j - 1] + a[j][i+j];
			}
		}
	}
	
}

				// 1 	2 	3 	4 	5			1 	2 	3 	4 	5
				// 6 	7 	8 	9 	10			6 	8 	10 	12 	14
				// 11 	12	13	14	15			11 	18	21	24	27
				// 16	17	18	19	20			16	28	36	40	44
				// 21	22	23	24	25			21	38	51	60	65 
				
				// 0,0	0,1	0,2 0,3	0,4
				// 1,0	1,1	1,2 1,3	1,4
				// 2,0	2,1	2,2 2,3	2,4
				// 3,0	3,1	3,2 3,3	3,4
				// 4,0	4,1	4,2 4,3	4,4

void printArr(int arr[][MAT_SIZE], int rows, int cols) {
	cout << "The two dimensional array:" << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int digitMultiSeq(int n){

	int ans = 1;
	
	for(int i = 1; i < n; i++){
		ans += multiplyDigits(ans);
	}
	
	return ans;
}

int multiplyDigits(int a){
	int ans = 1;
	
	while(a){
		ans *= a%10;
		a /= 10;
	}
	
	return ans;
}

bool isPermutation(unsigned int n, unsigned int m){
	
	const size_t DECIMAL_DIGITS = 10;
	int HELPER[DECIMAL_DIGITS] = {0};
	int n_res = 0, m_res = 0;
	
	while(n){
		n_res = n%10;
		n /= 10;
		HELPER[n_res]++;
		
		m_res = m%10;
		m /= 10;
		HELPER[m_res]--;
	}
	
	for(size_t i = 0; i < 10; i++)
		if(HELPER[i] != 0)  
			return false; 
		
	return true;
}

// From http://www.doc.ic.ac.uk/~wjk/C++Intro/RobMillerE3.html#Q3
double standardDeviation(double values[], int length, int size){
	// The formula for standard deviation
	// a is the avarage of of the values r1 ... rN
	// sqrt( ( ((r1 - a) x (r1 - a)) + ((r2-a) x (r2-a)) + ... + ((rN - a) x (rN - a)) ) / N )
	
	assert(length <= size);
	
	double a = average(values,length,size);
	double sigma = 0;
	
	for(int i = 0; i < length; i++){
		sigma += (values[i] - a)*(values[i] - a);
	}
	
	return sqrt(sigma/length);
	
}

// From http://www.doc.ic.ac.uk/~wjk/C++Intro/RobMillerL6.html#S6-2
double average(double list[], int length, int size){
		
		double total = 0;
		int count;
		for (count = 0 ; count < length ; count++)
			total += list[count];
		return (total / length);
		
}
	
/*===================================================

						Tests

===================================================*/

TEST(Functions, digit_multi_seq){

	EXPECT_EQ(38, digitMultiSeq(8));
	EXPECT_EQ(62, digitMultiSeq(9));
	EXPECT_EQ(74, digitMultiSeq(10));

}

TEST(Functions, multiply_digits){
	
	int a = 1234;
	
	EXPECT_EQ(24, multiplyDigits(a));
}

TEST(Matrix, mat_diag_sum){
	
	int mat[MAT_SIZE][MAT_SIZE] = { { 1, 2, 3, 4, 5},			
									{ 6, 7, 8, 9, 10},			
									{ 11, 12, 13, 14, 15},			
									{ 16, 17, 18, 19, 20},			
									{ 21, 22, 23, 24, 25}};			 
				
	int ans[MAT_SIZE][MAT_SIZE] = { {1, 2, 3, 4, 5},
									{6, 8, 10, 12, 14},
									{11, 18,21, 24, 27},
									{16, 28, 36, 40, 44},
									{21, 38, 51, 60, 65}};
				
	matDiagSum(mat,MAT_SIZE,MAT_SIZE);
	
	printArr(mat,MAT_SIZE,MAT_SIZE);
	printArr(ans,MAT_SIZE,MAT_SIZE);
	
	for(int i = 0; i < MAT_SIZE; i++){
		for(int j = 0; j < MAT_SIZE; j++){
			EXPECT_EQ(ans[i][j], mat[i][j]);
		}
	}
}

TEST(Arrays, is_permutation){
	
	int n = 1234;
	int m = 4231;
	
	int n2 = 456723;
	int m2 = 456724;
	
	int n3 = 45647235;
	int m3 = 45657234;
	
	EXPECT_TRUE(isPermutation(n,m));
	EXPECT_FALSE(isPermutation(n2,m2));
	EXPECT_TRUE(isPermutation(n3,m3));	
}

TEST(Functions, average){
	
	int length = 5;
	int size = 5;
	double list[] = {2.51, 5.468, 89.12, 546.49, 65489.877};
	
	EXPECT_DOUBLE_EQ(13226.693, average(list,length,size));
	
}

TEST(Arrays, standard_deviation){
	
	int length = 5;
	int size = 5;
	double list[] = {2.51, 5.468, 89.12, 546.49, 65489.877};
	
	double epsilon = 0.001;
	
	EXPECT_TRUE( abs(26132.36913 - standardDeviation(list,length,size)) <= epsilon);
}