// written in C++11 standard    -Kris

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <queue>        // std::priority_queue
#include <string>       // std::string



int insert
(
    std::priority_queue< int, std::vector<int>, std::less<int> > &l,
    std::priority_queue< int, std::vector<int>, std::greater<int> > &r,
    int n
)
{
    
    if      ( l.empty()   )  { l.push(n); } // boundary case
    else if ( n < l.top() )  { l.push(n); } // current median is stored at l.top
    else                     { r.push(n); }
    
    // balance the sizes of the two heaps:
    if      ( l.size() < r.size() )     { l.push(r.top()); r.pop(); }
    else if ( l.size() > r.size() + 1 ) { r.push(l.top()); l.pop(); }
    
    return l.top();
}



int main ()
{
    
    std::string filename = "Median_example.txt";
    int sum = 0;
    
    // define the max-heap l ("left") and the min-heap r ("right"):
    std::priority_queue<int, std::vector<int>, std::less<int>>    l;
    std::priority_queue<int, std::vector<int>, std::greater<int>> r;
        
    
    std::ifstream file ( filename );
    
    if ( !file.is_open() ) 
    {
        std::cout << "Can't find the file \"" << filename << "\"." << std::endl; 
    }
    else 
    {
        int n;
        while (file >> n) { sum = (sum + insert(l, r, n)) % 10000; }
        file.close();
    }
    
    std::cout << sum << std::endl;
    
}


// expected output on "Median_example.txt":
// 9335

