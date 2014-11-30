#include <cassert>
#include <iostream>
using namespace std;

#define ARR_COLS 4

int maxVal(int arr[][ARR_COLS], size_t rows, size_t cols) {
	assert(cols <= ARR_COLS);
	int ans = arr[0][0];
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			if (arr[i][j]>ans) ans = arr[i][j];
		}
	}
	return ans;
}

int sum(int arr[][ARR_COLS], size_t rows, size_t cols) {
	assert(cols <= ARR_COLS);
	int ans = 0;
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			ans+= arr[i][j];
		}
	}
	return ans;
}

void printSumOfRows(int arr[][ARR_COLS], size_t rows, size_t cols) {
	assert(cols <= ARR_COLS);
	cout << "Rows sum:" << endl;
	for (size_t i = 0; i < rows; ++i) {
		int ans = 0;
		for (size_t j = 0; j < cols; ++j) {
			ans += arr[i][j];
		}
		cout << ans << endl;
	}
}

void printSumOfCols(int arr[][ARR_COLS], size_t rows, size_t cols) {
	assert(cols <= ARR_COLS);
	cout << "Cols sum:" << endl;
	for (size_t j = 0; j < cols; ++j) {
		int ans = 0;
		for (size_t i = 0; i < rows; ++i) {
			ans += arr[i][j];
		}
		cout << ans << "\t";
	}
	cout << endl;
}

int sumDiagonal(int arr[][ARR_COLS], size_t size) {
	assert(size <= ARR_COLS);
	int sum = 0;
	for (int i = 0; i < size; ++i) sum += arr[i][i];
	return sum;
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





void sumOfRows(int arr[][ARR_COLS], size_t rows, size_t cols, int sumRowsArr[]) {
	assert(cols <= ARR_COLS);
	for (size_t i = 0; i < rows; ++i) {
		sumRowsArr[i] = 0;
		for (size_t j = 0; j < cols; ++j) {
			sumRowsArr[i] += arr[i][j];
		}
	}
}




int main() {
	
	int arr[][ARR_COLS] = { { 1, 2, 3, 4 }, { 20, 30, 10, 40 }, { 44, 11, 22, -33 } };
	//int arr[][ARR_COLS] = { { 1, 1, 1, 1 }, { 2, 2, 2, 2 }, { 1, 2, 3, 4 }, { 20, 30, 10, 40 }, { 44, 11, 22, -33 } };

	cout << "Max value of arr == " << maxVal(arr, sizeof(arr)/sizeof(*arr), ARR_COLS) << endl;
	cout << "-------------------------------------" << endl;

	cout << "sum of arr == " << sum(arr, sizeof(arr)/sizeof(*arr), ARR_COLS) << endl;
	cout << "-------------------------------------" << endl;

	printSumOfRows(arr, sizeof(arr)/sizeof(*arr), ARR_COLS);
	cout << "-------------------------------------" << endl;
	
	printSumOfCols(arr, sizeof(arr)/sizeof(*arr), ARR_COLS);
	cout << "-------------------------------------" << endl;
	
	size_t minSize = sizeof(arr)/sizeof(*arr);
	if (ARR_COLS < minSize) minSize = ARR_COLS;
	cout << "sum of " << minSize << "x" << minSize << " submatrix of arr diagonal == " << sumDiagonal(arr, minSize) << endl;
	cout << "-------------------------------------" << endl;

	printArr(arr, sizeof(arr)/sizeof(*arr), ARR_COLS);
	cout << "-------------------------------------" << endl;

	

	int sumRowsArr[sizeof(arr) / sizeof(*arr)];
	sumOfRows(arr, sizeof(arr) / sizeof(*arr), ARR_COLS, sumRowsArr);
	cout << "Rows sum, again:" << endl;
	for (auto v : sumRowsArr) cout << v << endl; // shortcut for:
	// for (size_t i = 0; i < sizeof(sumRowsArr) / sizeof(*sumRowsArr); ++i) cout << sumRowsArr[i] << endl;
	cout << "-------------------------------------" << endl;
	
	return 0;
}
