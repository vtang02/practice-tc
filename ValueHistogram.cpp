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

class ValueHistogram {
public:
  vector <string> build(vector <int>);
};

vector <string> ValueHistogram::build(vector <int> values) {
  
  //build an array of 0-9 telling how many of each are in the array
  int occurences[10];
  for (int i = 0; i < 10; i++) { //initialize to 0
    occurences[i] = 0;
  }
  for (unsigned i = 0; i < values.size(); i++) {
    int num = values.at(i);
    occurences[num]++;
  }
  
  //find the max occurences
  int max = -1;
  for (int j = 0; j < 10; j++) {
    cout << j << " has " << occurences[j] << " occurences" << endl;
    if (occurences[j] > max) {
      max = occurences[j];
    }
  }
  cout << "max is: " << max << endl;
  
  //make a 2D array and fill with dots
  char hist[max+1][10];
  for (int r = 0; r <max+1; r++) {
    for (int c = 0; c < 10; c++) {
      hist[r][c] = '.';
    }
  }
  
  //go back and fill with Xs
  for(int c = 0; c < 10; c++) {
    int num_Xs = occurences[c];
    cout << "num_Xs is: " << num_Xs << endl;
    for (int r = max; r >= (max+1)-num_Xs; r--) {
      hist[r][c] = 'X';
    }
  }
  
  //format the 2D array into vector form
  vector<string> histogram;
  for (int i = 0;  i < max+1; i++) {
    vector<char> temp;
    for (int j = 0; j < 10; j++) {
      fprintf(stderr, "%c", hist[i][j]);
      temp.push_back(hist[i][j]);
    }
    string temp_string(temp.begin(), temp.end());
    histogram.push_back(temp_string);
  }
  return histogram;
}
