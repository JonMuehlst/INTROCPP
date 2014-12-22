#include <cmath>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "reference.hpp"
#include "one_up.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool a = false;
bool b = false;
bool c = false;
bool d = false;

void oneUp();

void generateSieve(vector<bool>& sieve, size_t num){
	
	if(sieve.size() < num){
		sieve.resize(num);
		std::fill (sieve.begin(),sieve.end(),true); 
	}
	
	sieve[0] = false;
	sieve[1] = false;
	
	size_t limit = sqrt(num)+1;
	size_t j = 0;
	for (size_t i = 2; i < limit; i++) {
		j = 2;
		while(j*i < num){
			sieve[i*j] = false;
			j++;
		}
	}
	
}

vector<vector<int>> primeFactorsRepresentation(int num){
	
	size_t j = 0;
	vector<vector<int>> pfr(0, vector<int>(2));
	
	static vector<bool> sieve{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	static bool isSieveInstantiated = false;
	
	if(!isSieveInstantiated){
		generateSieve(sieve, num);
		isSieveInstantiated = true;
	}
	
	for (size_t i = 2; i < sieve.size(); i++) {
		if(sieve[i]){
			vector<int> tmp(2);
			pfr.push_back(tmp);
			pfr[j][0] = i;
			pfr[j][1] = 0;
			while( (num%i == 0) && (num > 0) ){
				pfr[j][1]++;
				num /= i;
			}
			// cout << "prime factor: " << pfr[j][0] << " power: " << pfr[j][1] << endl;
			j++;
		}
	}
	
	return pfr;
		
}

int gcd(vector<vector<int>>* pfr_a, vector<vector<int>>* pfr_b){
	
	int gcd = 1;
	int power = 0;
	
	for (size_t i = 0; i < pfr_a->size(); i++) {
		power = std::min((*pfr_a)[i][1],(*pfr_b)[i][1]);
		gcd *= pow((*pfr_a)[i][0],	power);
	}
	return gcd;
}

int lcm(vector<vector<int>>* pfr_a, vector<vector<int>>* pfr_b){
	
	int lcm = 1;
	int power = 0;
	
	for (size_t i = 0; i < pfr_a->size(); i++) {
		power = std::max((*pfr_a)[i][1],(*pfr_b)[i][1]);
		lcm *= pow((*pfr_a)[i][0],	power);
	}
	return lcm;
}
	
string removeDuplicates(string str){
	
	int HELPER[26] = {0};
	int index = 0;
	string ans_str = "";
	
	for (size_t i = 0; i < str.length(); i++) {
		index = str.at(i) - 'a';
		// cout << index << endl;
		if(!HELPER[index])
			ans_str.push_back(str.at(i));
		HELPER[index]++;
	}
	
	return ans_str;
}

/*===================================================

						Tests

===================================================*/

TEST(Reference, generate_sieve){
	
	vector<bool> expected_sieve{0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
	
	vector<bool> actual_sieve  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	
	generateSieve(actual_sieve,21);
	
	for (size_t i = 0; i < expected_sieve.size(); i++) {
		// cout << "expected_sieve: " << expected_sieve[i] << '\t' << " i is: " << i << endl;
		ASSERT_TRUE(actual_sieve[i] == expected_sieve[i]);
	}
	// cout << endl;
	a = true;
}

TEST(Reference, prime_factors_representation){
	
	vector<vector<int>> pfr = primeFactorsRepresentation(45);
	
	for (size_t i = 0; i < pfr.size(); i++) {
		if( i == 1){
			ASSERT_EQ(3,pfr[i][0]);
			ASSERT_EQ(2,pfr[i][1]);
		} else if( i == 2){
			ASSERT_EQ(5,pfr[i][0]);
			ASSERT_EQ(1,pfr[i][1]);	
		} else {
			ASSERT_EQ(0,pfr[i][1]);
		}
	}
	b = true;
}

TEST(Reference, gcd){

	vector<vector<int>> pfr_a = primeFactorsRepresentation(45);
	vector<vector<int>> pfr_b = primeFactorsRepresentation(21);
	int _gcd = gcd(&pfr_a,&pfr_b);
	// cout << "GCD: " << _gcd << endl;
	ASSERT_EQ(3,_gcd);
	c = true;
}

TEST(Reference, lcm){

	vector<vector<int>> pfr_a = primeFactorsRepresentation(45);
	vector<vector<int>> pfr_b = primeFactorsRepresentation(21);
	int _lcm = lcm(&pfr_a,&pfr_b);
	// cout << "LCM: " << _lcm << endl;
	ASSERT_EQ(315,_lcm);
	d = true;
	cout << d << endl;
}

TEST(Reference, one_up){
	
	if( a && b && c && d){
		oneUp();
	}
}

TEST(Reference, remove_duplicates){
	
	string str = "aabbccdd";
	string expected_str = "abcd";
	string actual_str = removeDuplicates(str);
	// cout << actual_str << endl;
	ASSERT_TRUE(expected_str == actual_str);
}

