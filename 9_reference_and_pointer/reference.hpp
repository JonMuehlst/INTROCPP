#ifndef REFERENE_HPP
#define REFERENE_HPP

void generateSieve(std::vector<bool>& sieve, size_t num);

std::vector<std::vector<int>> primeFactorsRepresentation(int num);

int gcd(std::vector<std::vector<int>>* pfr_a, std::vector<std::vector<int>>* pfr_b);
int lcm(std::vector<std::vector<int>>* pfr_a, std::vector<std::vector<int>>* pfr_b);

extern bool a;
extern bool b;
extern bool c;
extern bool d;

std::string removeDuplicates(std::string str);

#endif