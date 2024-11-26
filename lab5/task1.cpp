
#include <stack>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    //Task 1A:
    vector<int> vec;
    int x;
    stack<int> mystack;

    while(cin >> x) {
        vec.push_back(x);
    }
    //print out the vector in order
    sort(vec.begin(),vec.end());
    for(size_t i = 0; i < vec.size();i++) {
        cout << "Vector:" <<  vec[i] << endl;
        mystack.push(vec[i]);
    }
    
    while(mystack.empty() == false) {
        int t = mystack.top();
        cout <<"Stack:" << t << endl;
        mystack.pop();
        // t = mystack.top();
        // cout << t << endl;
    }
return 0;
} 

