#include "gtest/gtest.h" // google test

#include <cassert>
#include <iostream>
using namespace std;

const double DEFAULT_X_INTERSECTION= 0.0;

void print(double a, double b) {
	cout << "y == " << a << "x + " << b << endl;
}

double f(double a, double b, double x) {
	return a*x + b;
}

double findXForYZero(double a, double b) {
	return -b / a;
}

bool sameLine(double a1, double b1, double a2, double b2) {
	return (a1 == a2 && b1 == b2);
}

bool hasIntersection(double a1, double b1, double a2, double b2) {
	return (a1 != a2 || b1 == b2);
}

double xIntersection(double a1, double b1, double a2, double b2) {
	assert(hasIntersection(a1, b1, a2, b2));
	if (sameLine(a1, b1, a2, b2)) {
		// same lines - any value of x can do
		return DEFAULT_X_INTERSECTION;
	}
	return (b1 - b2) / (a2 - a1);
}

int binom(int n, int k) {
	if (n<k) return 0;
	if (k == n || k == 0) return 1;
	return (binom(n - 1, k) + binom(n - 1, k - 1));
}

TEST(LinearFunctions, f) {
	ASSERT_DOUBLE_EQ(0.3, f(0.1, 0.2, 1.0));
	ASSERT_DOUBLE_EQ(0.0, f(0.0, 0.0, 0.0));
	ASSERT_DOUBLE_EQ(3.0, f(0.0, 3.0, 0.0));
	ASSERT_DOUBLE_EQ(0.0, f(3.0, 0.0, 0.0));
	ASSERT_DOUBLE_EQ(0.0, f(1.0, -1.0, 1.0));
	ASSERT_DOUBLE_EQ(-2.0, f(1.0, -1.0, -1.0));
}

TEST(LinearFunctions, findXForYZero) {
	ASSERT_DOUBLE_EQ(-1.0, findXForYZero(1.0, 1.0));
	ASSERT_DOUBLE_EQ(0.0, findXForYZero(1.0, 0.0));
	ASSERT_DOUBLE_EQ(-0.25, findXForYZero(4.0, 1.0));
}

TEST(LinearFunctions, sameLine) {
	ASSERT_TRUE(sameLine(3.0, 3.0, 3.0, 3.0));
	EXPECT_TRUE(sameLine(3.0, 2.0, 3.0, 2.0));
	EXPECT_TRUE(sameLine(13.0, -2.0, 13.0, -2.0));
	EXPECT_FALSE(sameLine(3.0, 3.1, 3.0, 3.0));
	EXPECT_FALSE(sameLine(3.1, 3.1, 3.0, 3.0));
	EXPECT_FALSE(sameLine(53.0, 2.0, 3.0, 2.0));
	EXPECT_FALSE(sameLine(13.0, -2.0, 13.0, -2.1));
}

TEST(LinearFunctions, hasIntersection) {
	EXPECT_TRUE(hasIntersection(3.0, 3.0, 3.0, 3.0));
	EXPECT_TRUE(hasIntersection(3.0, 2.0, 3.0, 2.0));
	EXPECT_TRUE(hasIntersection(13.0, -2.0, 13.0, -2.0));
	EXPECT_TRUE(hasIntersection(3.1, 3.0, 3.0, 3.0));
	EXPECT_TRUE(hasIntersection(3.1, -3.0, 3.0, 3.0));
	EXPECT_FALSE(hasIntersection(3.1, 3.1, 3.1, 3.2));
	EXPECT_FALSE(hasIntersection(3.1, 3.1, 3.1, -3.1));
}

TEST(LinearFunctions, xIntersection) {
	EXPECT_DOUBLE_EQ(DEFAULT_X_INTERSECTION, xIntersection(3.0, 3.0, 3.0, 3.0));
	EXPECT_DOUBLE_EQ(DEFAULT_X_INTERSECTION, xIntersection(3.0, 2.0, 3.0, 2.0));
	EXPECT_DOUBLE_EQ(DEFAULT_X_INTERSECTION, xIntersection(13.0, -2.0, 13.0, -2.0));

	EXPECT_DOUBLE_EQ(0.0, xIntersection(3.0, 0.0, -3.0, 0.0));
	
	EXPECT_DOUBLE_EQ(1.0, xIntersection(1.0, 2.0, -1.0, 4.0));
}


TEST(Binom, binom) {
	for (unsigned int i = 0; i < 10; ++i) {
		EXPECT_EQ(1, binom(i, 0));
	}
	EXPECT_EQ(3, binom(3, 2));
	EXPECT_EQ(10, binom(5, 3));
}

/*

int main() {
	double a1, b1, a2, b2;
	cout << "Enter first line (a,b) y= ax+b:" << endl;
	cin >> a1; cin >> b1;
	cout << "Enter second line (a,b) y= ax+b:" << endl;
	cin >> a2; cin >> b2;

	cout << "------------------------------------" << endl;

	cout << "Two lines: " << endl;
	print(a1, b1);
	print(a2, b2);

	cout << "Intersection of the first line with the y axis: " << findXForYZero(a1, b1) << endl;
	cout << "Intersection of the second line with the y axis: " << findXForYZero(a2, b2) << endl;

	cout << "------------------------------------" << endl;

	if (hasIntersection(a1, b1, a2, b2)) {
		double x = xIntersection(a1, b1, a2, b2);
		cout << "Intersection: [" << x << "," << f(a1, b1, x) << "]" << endl;
	} else {
		cout << "There is no intersection between the lines" << endl;
	}
	return 0;
}
*/
