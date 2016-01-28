/*
Problem Statement
    
A histogram of a given collection of numbers graphically represents the frequency of each value in the collection. We are given several numbers ranging from 0 to 9 as a vector <int> values. The goal is to build their histogram according to the following rules.  1) The width of the histogram should be exactly 10.  2) The height of the histogram should equal to H+1, where H is the number of times the most frequent element occurs in values.  3) The i-th (0-based) column of the histogram corresponds to the value i. Let X(i) be the frequency of value i in values. Then the last X(i) characters in the column should be 'X's and the other ones should be '.'s. For example, if value i was not present in values, the column should be filled with '.' characters. If i was present once, the last element of the column should be 'X' and and the other ones should be '.'s. If i was present twice, the last two elements should be 'X's and and the other ones should be '.'s, and so on.  Build the histogram and return it as a vector <string>.
Definition
    
																																																							       Class:
ValueHistogram
																																																							       Method:
build
																																																							       Parameters:
																																																							       vector <int>
																																																							       Returns:
																																																							       vector <string>
																																																							       Method signature:
																																																							       vector <string> build(vector <int> values)
  (be sure your method is public)
Limits
    
  Time limit (s):
2.000
  Memory limit (MB):
64
Constraints
-
  values will contain between 1 and 50 elements, inclusive.
-
  Each element of values will be between 0 and 9, inclusive.
Examples
  0)

    
{2, 3, 5, 5, 5, 2, 0, 8}
Returns: {"..........", ".....X....", "..X..X....", "X.XX.X..X." }
The most frequent value is 5, which occurs 3 times. Hence the height of the histogram is 4. It looks as follows:
..........
.....X....
..X..X....
X.XX.X..X.
  1)

    
{9, 9, 9, 9}
Returns: {"..........", ".........X", ".........X", ".........X", ".........X" }
..........
.........X
.........X
.........X
.........X
2)

    
{6, 4, 0, 0, 3, 9, 8, 8}
Returns: {"..........", "X.......X.", "X..XX.X.XX" }
..........
X.......X.
X..XX.X.XX
3)

    
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
Returns: {"..........", "XXXXXXXXXX" }
..........
XXXXXXXXXX
4)

    
{6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3}
Returns: {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX" }
..........
...X......
..XX......
..XX......
XXXXX.XXXX
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

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
