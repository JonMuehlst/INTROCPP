#include <cmath>
#include <cassert>
#include <iostream>
#include <iomanip>

#include <random>
#include <chrono>

using namespace std;


// this function returns a random double between min_val and max_val
// You do not need to understand how in this course
double rand_double(double min_val, double max_val) {
	static std::default_random_engine generator;
	static bool init = false;
	if (!init) {
		generator.seed(std::chrono::system_clock::now().time_since_epoch().count());
		init = true;
	}

	std::uniform_real_distribution<double> distribution(min_val, max_val);
	return distribution(generator);
}

double compute_pi_monte_carlo(unsigned int iterationsNum) {
	
	assert(iterationsNum > 0);

	// middle point= (0,0), radius = 1.0;

	unsigned int hits = 0;
	for (unsigned int i = 0; i < iterationsNum; ++i) {
		double x = rand_double(-1.0, 1.0);
		double y = rand_double(-1.0, 1.0);
		double dist_pow2 = (x*x + y*y);
		if (dist_pow2 < 1.0) ++hits;
	}

	// The area of the circle is   pi*radius^2
	// The area of the rectangle is 4*radius^2
	// so: circle_area/rectangle_area==pi/4
	// circle_area/rectangle_area is approximated by hits/iterationsNum
	return 4.0*(double)hits/iterationsNum;
}

//(4 / 1) - (4 / 3) + (4 / 5) - (4 / 7) + (4 / 9) - (4 / 11) + (4 / 13) - (4 / 15)
double compute_pi_Gregory_Leibniz(unsigned int iterationsNum) {

	assert(iterationsNum > 0);

	double pi = 0.0;
	double four_signed = 4.0;
	for (unsigned int i = 1; i < iterationsNum + 1; i += 2){
		pi += (four_signed / i);
		four_signed *= -1;
	}
	return pi;

}

int main() {
	unsigned int iterationsNum = 1000000;
	cout << setprecision(10);

	cout << "Pi defined in cmath==\t" << M_PI << endl;
	cout << "Pi monte carlo==\t" << compute_pi_monte_carlo(iterationsNum) << endl;
	cout << "Pi Gregory-Leibniz==\t" << compute_pi_Gregory_Leibniz(iterationsNum) << endl;
	return 0;
}

