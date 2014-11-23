#include <cassert>
#include <iostream>
#include "gtest/gtest.h"
#include "selection_sort.h"

using std::cin;
using std::cout;
using std::endl;


size_t getArrayFromInput(int arr[], size_t max_arr_size) {
	size_t arr_size;
	while (true) {
		cout << "\n enter the number of values: ";
		cin >> arr_size;
		if (arr_size <= MAX_ARR_SIZE && arr_size >= 1) break;
		cout << "given arr_size is too big or too small! should be >=1 and <= " << MAX_ARR_SIZE << endl;
	}
	for (size_t i = 0; i<arr_size; ++i){
		cout << "\n enter value #" << i << " : ";
		cin >> arr[i];
	}
	return arr_size;
}

void printArr(int arr[], size_t start, size_t end) {
	cout << "printing array [" << start << "," << end << ")";
	for (size_t i = start; i<end; ++i) {
		cout << arr[i] << " , ";
	}
	cout << endl;
}

size_t findSmallestIndex(int arr[], size_t start, size_t end) {
	size_t ans = start;
	for (size_t i = start + 1; i<end; ++i) {
		if (arr[i] < arr[ans]) ans = i;
	}
	return ans;
}

void swap(int arr[], size_t i, size_t j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void sort(int arr[], size_t size) {
	for (size_t i = 0; i<size - 1; ++i)  {
		size_t min_pos = findSmallestIndex(arr, i, size);
		swap(arr, i, min_pos);
	}
}

/*

int main() {
	int arr[MAX_ARR_SIZE]; // static allocation 
	
	int arr_size= getArrayFromInput(arr, MAX_ARR_SIZE);
	
	printArr(arr, 0, arr_size);
	
	sort(arr, arr_size);
	
	printArr(arr, 0, arr_size);

	return 0;
}

*/


/*================================================================================

                                    Tests

================================================================================*/

TEST(Selection_sort, selection_sort){
    
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    
    sort(arr, MAX_ARR_SIZE);
    
    for(size_t i = 0; i < MAX_ARR_SIZE - 1; i++){
        EXPECT_LE(arr[i], arr[i+1]);   
    }
    
}