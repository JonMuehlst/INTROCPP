#include <cassert>
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

#include "gtest/gtest.h"

void merge(vector<int>& vec, size_t i_begin, size_t i_mid, size_t i_end) {

	assert(i_begin<i_mid);
	assert(i_mid<i_end);

	// Merge can be done inplace. 
	// That is, without extra O(n) memory. 
	// But for simplicity I use here extra memory.
	// The inplace version is complex.
	vector<int> merged(i_end-i_begin);
	
	size_t mi = 0;
	size_t i1 = i_begin;
	size_t i2 = i_mid;

	// main merge loop
	while (i1 < i_mid && i2 < i_end) {
		if (vec[i1] < vec[i2]) {
			merged[mi++] = vec[i1++];
		}
		else {
			merged[mi++] = vec[i2++];
		}
	}

	// leftovers
	while (i1 < i_mid) {
		merged[mi++] = vec[i1++];
	}
	while (i2 < i_end) {
		merged[mi++] = vec[i2++];
	}

	assert(mi == merged.size());

	// put back into vec
	for (size_t j = 0; j < merged.size(); ++j) {
		vec[i_begin + j] = merged[j];
	}

}

void merge_sort_recursive_helper(vector<int>& vec, size_t i_begin, size_t i_end) {
	
	if (i_end - i_begin <= 1) return;
	
	size_t i_mid = i_begin + ((i_end - i_begin) / 2);
	merge_sort_recursive_helper(vec, i_begin, i_mid);
	merge_sort_recursive_helper(vec, i_mid, i_end);
	merge(vec, i_begin, i_mid, i_end);

}


void merge_sort_recursive(vector<int>& vec) {
	merge_sort_recursive_helper(vec, 0, vec.size());
}




void merge_sort_for_pow2(vector<int>& vec) {
	size_t size_to_merge = 1;
	while (size_to_merge < vec.size()) {
		for (size_t i = 0; i < vec.size(); i += (size_to_merge * 2)) {
			merge(vec, i, i+size_to_merge, i+2*size_to_merge);
		}
		size_to_merge *= 2;
	}
}

size_t floor_log2(size_t n) {
	assert(n > 0);
	size_t ans = 0;
	while (n >>= 1) ++ans;
	return ans;
}

void merge_sort(vector<int>& vec) {
	
	if (vec.size() == 0) return;

	// add elements so size will be a power of 2
	size_t oldSize = vec.size();
	size_t elementsToAdd = (pow(2, floor_log2(oldSize) + 1)) - oldSize;
	while (elementsToAdd != 0) {
		vec.push_back(INT_MAX);
		--elementsToAdd;
	}

	merge_sort_for_pow2(vec);
	
	// remove elements that were added
	while (vec.size() != oldSize) {
		vec.pop_back();
	}

}


TEST(mergeTester, t1) {
	vector<int> v1{ 1, 3, 5, 4 };
	vector<int> v2{ 1, 3, 5, 4 };
	merge(v1, 0, 1, 2);
	EXPECT_EQ(v2,v1);
}

TEST(mergeTester, t2) {
	vector<int> v1{ 1, 3, 5, 4 };
	vector<int> v2{ 1, 3, 4, 5 };
	merge(v1, 2, 3, 4);
	EXPECT_EQ(v2,v1);
}

TEST(mergeTester, t3) {
	vector<int> v1{ 5, 4, 1};
	vector<int> v2{ 4, 5, 1};
	merge(v1, 0, 1, 2);
	EXPECT_EQ(v2,v1);
}

TEST(mergeTester, t4) {
	vector<int> v1{ 1, 4, 9, 4, 5, 8};
	vector<int> v2{ 1, 4, 4, 5, 8, 9};
	merge(v1, 0, 3, 6);
	EXPECT_EQ(v2,v1);
}

TEST(mergeTester, t5) {
	vector<int> v1{ 1, 4, 9, 4, 5, 8, -10, 3 };
	vector<int> v2{ 1, 4, 4, 5, 8, 9, -10, 3 };
	merge(v1, 0, 3, 6);
	EXPECT_EQ(v2,v1);
}
	
TEST(mergeTester, t6) {
	vector<int> v1{ 4, 1,  2};
	vector<int> v2{ 2, 4, 1};
	merge(v1, 0, 2, 3);
	EXPECT_EQ(v2,v1);
}

TEST(mergeTester, t7) {
	vector<int> v1{ 1, 4, 9,  3, 5 };
	vector<int> v2{ 1, 3, 4, 5, 9 };
	merge(v1, 0, 3, 5);
	EXPECT_EQ(v2,v1);
}

TEST(mergeTester, t8) {
	vector<int> v1{ 1, 4, 9,  3, 5 ,   -10};
	vector<int> v2{ 1, 3, 4, 5, 9 ,   -10};
	merge(v1, 0, 3, 5);
	EXPECT_EQ(v2,v1);
}

TEST(mergeTester, t9) {
	vector<int> v1{100,   1, 4, 9, 3, 5,   -10 };
	vector<int> v2{100,   1, 3, 4, 5, 9,   -10 };
	merge(v1, 1, 4, 6);
	EXPECT_EQ(v2,v1);
}

void merge_sort_recursive_test_helper(const vector<int>& exp_arr,
								vector<int> arr) { // vector<int>&& is better, but not for this course
	merge_sort_recursive(arr);
	EXPECT_EQ(exp_arr, arr);
}

TEST(mergeSortRecursiveTester, t1) {
	merge_sort_recursive_test_helper(
		{1,2},
		{2,1});
}

TEST(mergeSortRecursiveTester, t2) {
	merge_sort_recursive_test_helper(
		{-2,1},
		{-2,1});
}

TEST(mergeSortRecursiveTester, t3) {
	merge_sort_recursive_test_helper(
		{ -8, -1, 2, 10 },
		{ 2, -1, 10, -8 });
}

TEST(mergeSortRecursiveTester, t4) {
	merge_sort_recursive_test_helper(
		{ 0, 1, 2, 3, 4, 5, 6, 7 },
		{ 0, 4, 3, 2, 5, 7, 1, 6 });
}

TEST(mergeSortRecursiveTester, t5) {
	merge_sort_recursive_test_helper(
		{ 2 },
		{ 2 });
}
	
TEST(mergeSortRecursiveTester, t6) {
	merge_sort_recursive_test_helper(
		{ -3, -2, 1 },
		{ -2, 1, -3 });
}

TEST(mergeSortRecursiveTester, t7) {
	merge_sort_recursive_test_helper(
		{ -8, -1, 2, 10, 500 },		
		{ 2, -1, 10, -8, 500 });
}

TEST(mergeSortRecursiveTester, t8) {
	merge_sort_recursive_test_helper(
		{ 0, 1, 2, 3, 5, 6, 7 },
		{ 0, 3, 2, 5, 7, 1, 6 });
}

TEST(mergeSortRecursiveTester, t9_limits) {
	merge_sort_recursive_test_helper(
	{ INT_MIN, 0, 1, 2, 3, 5, 6, 7, INT_MAX },	
	{ 0, 3, INT_MIN, 2, 5, INT_MAX, 7, 1, 6 });
}

TEST(mergeSortRecursiveTester, t10_empty) {
	merge_sort_recursive_test_helper(
	{},	
	{});
}


TEST(floorLog2Test, t1) {

	EXPECT_EQ(floor_log2(1) , 0);
	EXPECT_EQ(floor_log2(2) , 1);
	EXPECT_EQ(floor_log2(3) , 1);

	size_t s;
	
	s = 4;
	for (size_t i = s; i < s * 2; ++i) EXPECT_EQ(floor_log2(i) , 2);
	
	s = s * 2;
	for (size_t i = s; i < s * 2; ++i) EXPECT_EQ(floor_log2(i) , 3);

	s = 1024;
	for (size_t i = s; i < s * 2; ++i) EXPECT_EQ(floor_log2(i) , 10);
	
}

void merge_sort_test_helper(const vector<int>& exp_arr,
							vector<int> arr) { // vector<int>&& is better, but not for this course
	merge_sort(arr);
	EXPECT_EQ(exp_arr, arr);
}

TEST(mergeSortTester, t1) {
	merge_sort_test_helper(
		{1,2},
		{2,1});
}

TEST(mergeSortTester, t2) {
	merge_sort_test_helper(
		{-2,1},
		{-2,1});
}

TEST(mergeSortTester, t3) {
	merge_sort_test_helper(
		{ -8, -1, 2, 10 },
		{ 2, -1, 10, -8 });
}

TEST(mergeSortTester, t4) {
	merge_sort_test_helper(
		{ 0, 1, 2, 3, 4, 5, 6, 7 },
		{ 0, 4, 3, 2, 5, 7, 1, 6 });
}

TEST(mergeSortTester, t5) {
	merge_sort_test_helper(
		{ 2 },
		{ 2 });
}
	
TEST(mergeSortTester, t6) {
	merge_sort_test_helper(
		{ -3, -2, 1 },
		{ -2, 1, -3 });
}

TEST(mergeSortTester, t7) {
	merge_sort_test_helper(
		{ -8, -1, 2, 10, 500 },		
		{ 2, -1, 10, -8, 500 });
}

TEST(mergeSortTester, t8) {
	merge_sort_test_helper(
		{ 0, 1, 2, 3, 5, 6, 7 },
		{ 0, 3, 2, 5, 7, 1, 6 });
}

TEST(mergeSortTester, t9_limits) {
	merge_sort_test_helper(
	{ INT_MIN, 0, 1, 2, 3, 5, 6, 7, INT_MAX },	
	{ 0, 3, INT_MIN, 2, 5, INT_MAX, 7, 1, 6 });
}

TEST(mergeSortTester, t10_empty) {
	merge_sort_test_helper(
	{},	
	{});
}
