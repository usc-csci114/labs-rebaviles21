// Then insert N keys, where the keys
//   are the numbers 0 to N-1 and the values are a random number (see the
//    provided test code for an example of how to get a random value). 
//    Measure how long just the inserts take. Then increase N and repeat. 
//    If you take 10-20 data points with fairly large values for N you 
//    should be able to show a linear relationship between N and the r
//    untime.

#include <iostream>
#include <chrono>
#include <utility>
#include <vector>
#include <map>
#include <random>
#include <stdexcept>
#include "hashtable.h"

using namespace std;

int main(int argc, char* argv[]) {
    HashTable<int, int> key;
    //int N = 100000;
    std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 1000);  

    for(int N = 100000; N < 10000000; N *= 1.2)
    {
    const auto start = std::chrono::steady_clock::now();

	for(int i = 0; i < N; i++) {
        int val = distribution(generator);
        key.insert(i, val);
    }
	const auto end = std::chrono::steady_clock::now();
	const std::chrono::duration<double> diff = end - start;
    std:: cout << "N:" << N << ", runtime:" << diff.count() << endl;
    }
return 0; 
}