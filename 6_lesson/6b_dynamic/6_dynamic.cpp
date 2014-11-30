#include <vector>
#include <iostream>
using namespace std;




int main() {
	
	int arrSize;
	cout << "Please insert size of array: ";
	cin >> arrSize;
	
	//----------------------------------------------------------
	// primitive dynamic array
	//----------------------------------------------------------
	int* arr = new int[arrSize];
	for (size_t i = 0; i < arrSize; ++i) {
		arr[i] = i;
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // must clean! otherwise leak of memory
	//----------------------------------------------------------
		
	//----------------------------------------------------------
	// modern dynamic array
	//----------------------------------------------------------
	vector<int> vec(arrSize);
	for (size_t i = 0; i < vec.size(); ++i) {
		vec[i] = i;
		cout << vec[i] << " ";
	}
	cout << endl;
	vec.push_back(300); // can grow, primitives cannot
	for (auto v : vec) cout << v << " ";
	cout << endl;
	//----------------------------------------------------------


	//----------------------------------------------------------
	// modern dynamic array of arrays
	//----------------------------------------------------------
	vector< vector<int> > vecOfVec = { { 2, 1, 3 }, { 30, 10 } };
	for (auto& vec : vecOfVec) {
		for (auto& v : vec) {
			cout << v << "\t";
		}
		cout << endl;
	}

	vector< vector<int> > vecOfVec2(arrSize, vector<int>(arrSize));
	for (size_t i = 0; i < arrSize; ++i) {
		for (size_t j = 0; j < arrSize; ++j) {
			vecOfVec2[i][j] = i*j;
		}
	}
	for (auto& vec : vecOfVec2) {
		for (auto& v : vec) {
			cout << v << "\t";
		}
		cout << endl;
	}
	//----------------------------------------------------------


	return 0;
}