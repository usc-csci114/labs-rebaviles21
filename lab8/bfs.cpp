

// There are N vertexs. The first column is the vertex name. The row then contains `0` (zero) if an edge does not exist between or it
// contains the vertex name if an edge does exist. You should store the graph in a `std::map<char, set<char> >` where the key is the 
//vertex name and the set contains the vertex names of the vertex's neighbors. 

// Once you have read in the graph tell the user "Processed file {file}. Found {N} vertexs: {...}" where {file} is the name of the 
//file and {N} is the number of vertexs and {...} is the vertex names. For example the above graph will print:

// ```
// Processed file graph1.txt. Found 8 vertex: a, b, c, d, e, f, g, h
// ```

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char* argv[]) 
{

    string file = argv[1]; // the command line argument (first one)
    ifstream ifile(file) ;
    string line;
    char numbers;
    char vertex;
    set<char> vertexNeighbors; // empty set char for the vertex names
    std::map <char, set<char> > bfs; 

    //error implementation?? 
    if(argc < 2) {
        cout << "No file found. Try again " << endl;
        return 1;
    }
    while(getline(ifile,line)) { // goes thorugh the whole graph
        set <char> rows;
        stringstream ss(line); //[arses the indiviidual stringstream]
        ss >> vertex; //reads in the 
        vertexNeighbors.insert(vertex);
        while(ss>> numbers) { // goes theough the row of numbers 
            if(numbers != '0') {
                rows.insert(numbers); // the numbers and their associated
            }  
        }
        bfs[vertex] = rows;
    }
    ifile.close();
    cout << "Processed file " << file << "Found N " << vertexNeighbors.size() << "vertexs: "; 
    for(int i =0; i < vertexNeighbors.size();i++) {
        cout<< vertex;
    }
    // //bfs search
    
    queue<char> Q; //queue
    set<char> visited;
    char s; //starting vertex
    int cnt = 0;

    cout << "Which vertex do you want to start. To end: press 'q' " << endl;
    cin >> s;
    while(s != 'q') {
        //initialize bfs
        Q.push(s); // searches bfs starting location
        visited.insert(s); //beginning of the nodes
        
        while (!Q.empty()){
            char v = Q.front();
            Q.pop();
        auto it = bfs[vertex].begin();
            while (it != bfs[vertex].end()) {
                char n = *it;
                if (visited.count(n) == 0) {
                    Q.push(n);
                    visited.insert(n);
                }
                it++;
            }
        }  
        cnt++; 
        cout << "BFS starting at" << s;
        auto iteratorForVisit = visited.begin();
        while(iteratorForVisit != visited.end()) {
            cout << *iteratorForVisit << ": " << cnt << endl; 
        }

        cout << "Which vertex do you want to start. To end: press 'q' " << endl;
        cin>> s;    
    }
    
return 0;
}

//question needed: 
// - vertex 