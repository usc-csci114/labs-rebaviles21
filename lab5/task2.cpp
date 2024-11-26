// Write a function that can fill a vector with random numbers. To make your program faster, use the following signature (we'll learn more about C++ references later):
// void fillrand(vector<int>& v);

// Write a loop that calls top() on the priority queue to get the next item. By default the STL priority queue is a max-heap, so the max value will come first. Push this item into your list<int> with push_front(). Then call pop() on the priority queue to remove this value.
// The loop should run while the priority queue is not empty.
// Now, print out the list (using iterators) to prove you sorted the values.
// Following the above steps you should be able to sort a vector of size 100.

// Now modify your code using the ideas from lab 4 to increase the size of the vector while measuring the time it takes to sort the vector. You still need to fill the vector with random numbers, but for this part you do not need to push the values into a list, just call pop() until the priority queue is empty.

// Use the (size, time) data points to prove heap-sort is O(n log n).
// Use the (size, time) data points to prove heap-sort is O(n log n).

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <random>
#include <cmath>

using namespace std;

void fillrand(vector<int> v);

void fillrand(vector<int> v){
    std::default_random_engine generator;
    for(size_t i = 0; i < v.size();i++) {
	    std::uniform_int_distribution<int> distribution(1, 1000); 
        v[i] = distribution(generator);
    }
}

int main() {
    // vector<int> v = {3,213,524,757,23,124,6,357};
    // list<int> newList;
    // priority_queue<int> pq(v.begin(), v.end());
    // //now we have a vector, put the values into a pq
    // while(pq.empty() == false) {// should not be empty
    //     int nextItem = pq.top();
    //     newList.push_front(nextItem);
    //     pq.pop();
    // }
    // for(auto it = newList.begin();it != newList.end();++it) {
    //     cout << *it << endl;
    // }
    // const auto end = std::chrono::steady_clock::now();
	// 	const std::chrono::duration<double> diff = end - start;
	// 	cout << "Heapsort for size " << v.size() << " " << diff.count() << endl;
    //     size = size*1.2;
    

    // Now modify your code using the ideas from lab 4 to increase the size of the vector while 
    // measuring the time it takes to sort the vector. You still need to fill the vector with random numbers, but for 
    // this part you do not need to push the values into a list, just call `pop()` until the priority queue is empty.
    // Use the (size, time) data points to prove heap-sort is O(n log n).
    int size = 200000;
    vector<int> v(100);
    list<int> newList;
	for(int i = 1; i < 20;i++)
	{   
		v.resize(size);
        //fill v with random values
        fillrand(v);
		const auto start = std::chrono::steady_clock::now();
		//make the pq with v
        priority_queue<int> runtime (v.begin(), v.end());
        //write a while loop that calls pop() until pq is empty
        while (runtime.empty() == false) {
            runtime.pop();
        }
        for(auto it = newList.begin();it != newList.end();++it) {
            std::cout << *it << endl;
        }
		const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;
        double diffTime = (diff.count())/log(v.size());
		//std::cout << "Heapsort for size " << v.size() << " " << diff.count() << endl;
        std::cout << "mod size:  " << v.size() << " mod time:  "  << diffTime << std::endl;
        size = size*1.2;
	}	
return 0;
}
    
