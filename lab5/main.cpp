#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main(){
	
	int size = 2000000;
	for(int i = 1; i < 20;i++)
	{
		vector<int> v;
		v.resize(size*i);
        //call fillrandom() with 
		void fillrand(vector<int>& v);
        //create priority queue with v ; 

		const auto start = std::chrono::steady_clock::now();
        //while loop to empty out priority queue
		const auto end = std::chrono::steady_clock::now();
		const std::chrono::duration<double> diff = end - start;
		cout << "Inserting at v.begin() for size " << v.size() << " " << diff.count() << endl;
	}	
}

// const auto--- what is it... type returned is time point representing the current point in time
// const -- not changing (auto-- easier way to grab the std:: )


* Write a function that can fill a vector with random numbers. To make your program faster, use the following signature (we'll learn more about C++ references later):

```
void fillrand(vector<int>& v);
```
* This function will fill the vector in-place with random number without making a copy. Do not change the size of the vector.
* Now write a `main()` that creates a `vector<int>` of size 100. Fill the vector with random numbers.
* Create a STL `priority_queue<int>` using the syntax seen above from the vector.
* Create an empty STL `list<int>`
* Write a loop that calls `top()` on the priority queue to get the next item. By default the STL priority queue is a max-heap, so the max value will come first. Push this item into your `list<int>` with `push_front()`. Then call `pop()` on the priority queue to remove this value.
* The loop should run while the priority queue is not empty.
* Now, print out the list (using iterators) to prove you sorted the values.

Following the above steps you should be able to sort a vector of size 100.

Now modify your code using the ideas from lab 4 to increase the size of the vector while measuring the time it takes to sort the vector. You still need to fill the vector with random numbers, but for this part you do not need to push the values into a list, just call `pop()` until the priority queue is empty.

Use the (size, time) data points to prove heap-sort is O(n log n).