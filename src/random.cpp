#include "random.h"
#include <random>

RandomNumbers::RandomNumbers(unsigned long int s)
:seed(s)
{
	if (seed == 0) {
        std::random_device rd;
        seed = rd();
    }
    rng = std::mt19937(seed);	
}


void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper){
	int size = vec.size();
	std::uniform_real_distribution<double> distribution_u(lower,upper);
	for (int i(0); i<size; i++){
		vec[i]= distribution_u(rng);
	}
}

double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<double> distribution_u(lower,upper);
	return distribution_u(rng);
}


void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd){
	int size = vec.size();
	std::normal_distribution<double> distribution_n(mean,sd);
	for (int i(0); i<size; i++){
		vec[i]= distribution_n(rng);
	}
}

double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<double> distribution_n(mean,sd);
	return distribution_n(rng);
}


void RandomNumbers::poisson(std::vector<int>& vec, double mean){
	int size = vec.size();
	std::poisson_distribution<int> distribution_p(mean);
	for (int i(0); i<size; i++){
		vec[i]=distribution_p(rng);
	}	
}

int RandomNumbers::poisson(double mean){
	std::poisson_distribution<int> distribution_p(mean);
	return distribution_p(rng);	
}
