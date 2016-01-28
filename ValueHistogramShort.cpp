#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 

class ValueHistogram  
{ 
public: 
  vector <string> build(vector <int> values) 
  { 
    int max_value = 0; 
    
    //initialize with zeros
    vector<int> occurences(10, 0); 

    for(size_t i = 0; i < values.size(); i++) 
    { 
      //figure out how many occurences of each num there are
      //find max num of occurences as well
      occurences[values[i]]++; //can use [] notation with vectors
      max_value = max(max_value, occurences[values[i]]); 
    } 

    //hist has all dots
    vector <string> hist(max_value + 1, ".........."); 
    for(int i = 0; i < 10; i++) {  //go across each row
      for(int j = 0; j < occurences[i]; j++) { //fill with Xs
        //can treat the string vector like a 2D array
        hist[max_value - j][i] = 'X'; 
      } 
    } 

    return hist; 
  } 

}; 