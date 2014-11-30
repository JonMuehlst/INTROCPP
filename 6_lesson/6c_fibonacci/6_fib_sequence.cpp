#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> fibVec(size_t len) {
	assert(len >= 2);
	vector<int> vec(len, 0);
	vec[0] = 0;
	vec[1] = 1;
	for (size_t i = 2; i < len; ++i) {
		vec[i] = vec[i - 2] + vec[i - 1];
	}
	return vec;
}

int main() {
	size_t len;
	cout << "Insert length: ";
	cin >> len;
	vector<int> vec = fibVec(len);
	for (auto v : vec) cout << v << " ";
	cout << endl;
	return 0;
}