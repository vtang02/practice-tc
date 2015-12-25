/*
Problem Statement
    
Here at [topcoder], we call a contestant a "target" if their rating is 3000 or more. In the arena, the targets have a red icon with a small target on it. Do you want to become a target as well? Sure you do. But before you get there, let's start with something easier: drawing a target.   The target you need to draw consists of nested squares. The innermost square is just a single '#' character. The larger squares use alternatingly the character ' ' (space) and the character '#'. Here is an example in which the side of the largest square is n = 5:   
#####
#   #
# # #
#   #
#####
  And here is an example for n = 9:  
#########
#       #
# ##### #
# #   # #
# # # # #
# #   # #
# ##### #
#       #
#########
   You will be given an int n. Your method must return a vector <string> which contains a drawing of the target with side n. More precisely, each element of the returned vector <string> must be one row of the drawing, in order. Therefore, the returned vector <string> will consist of n elements, each with n characters. (See the examples below for clarification.)   The value of n will be such that a target like the ones above can be drawn: 5, 9, 13, and so on. Formally, n will be of the form 4k+1, where k is a positive integer.
Definition
    
Class:
Target
Method:
draw
Parameters:
int
Returns:
vector <string>
Method signature:
vector <string> draw(int n)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
-
n will be between 5 and 49, inclusive.
-
n mod 4 will be 1.
Examples
0)

    
5
Returns: {"#####", "#   #", "# # #", "#   #", "#####" }

1)

    
9
Returns: 
{"#########",
 "#       #",
 "# ##### #",
 "# #   # #",
 "# # # # #",
 "# #   # #",
 "# ##### #",
 "#       #",
 "#########" }

2)

    
13
Returns: 
{"#############",
    "#           #",
    "# ######### #",
    "# #       # #",
    "# # ##### # #",
    "# # #   # # #",
    "# # # # # # #",
    "# # #   # # #",
    "# # ##### # #",
    "# #       # #",
    "# ######### #",
    "#           #",
    "#############" }

3)

    
17
Returns: 
{"#################",
    "#               #",
    "# ############# #",
    "# #           # #",
    "# # ######### # #",
    "# # #       # # #",
    "# # # ##### # # #",
    "# # # #   # # # #",
    "# # # # # # # # #",
    "# # # #   # # # #",
    "# # # ##### # # #",
    "# # #       # # #",
    "# # ######### # #",
    "# #           # #",
    "# ############# #",
    "#               #",
    "#################" }

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
#include <cstring>

using namespace std;

class Target {
public:
  vector <string> draw(int);
};

vector <string> Target::draw(int n) {
  vector <string> target;
  
  char f[n][n];
  
  bool pound = true;
  int row = 0;
  int col = 0;
  int side = n;
  
  while (side > 0) {
    
    for (int i = row; i < row + side; i++) {
      for (int j = col; j < col + side; j++) {
	if (pound == true) {
	  f[i][j] = '#';
	} else {
	  f[i][j] = ' ';
	}
      }
    }
    
    side = side - 2;
    pound = !pound;
    row++;
    col++;
  }
  
  for (int i = 0; i < n; i++) {
    vector <char> temp;
    for (int j = 0; j < n; j++) {
      fprintf(stderr, "%c ", f[i][j]);
      temp.push_back(f[i][j]);
    }
    string temp_string(temp.begin(), temp.end());
    target.push_back(temp_string);
  }
  
  return target;
}
