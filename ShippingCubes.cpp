/*
Problem Statement
    
You want to ship N cubes abroad. The size of each cube is 1 x 1 x 1. You can only ship the cubes by filling them into a single cuboid box. The cost of shipping a cuboid box with dimensions a x b x c is equal to (a+b+c).  You can't leave any empty space in the box, because the cubes would shift and get damaged during the transfer.  You are given an int N. Return the minimal cost of shipping N cubes.
Definition
    
Class:
ShippingCubes
Method:
minimalCost
Parameters:
int
Returns:
int
Method signature:
int minimalCost(int N)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
N will be between 1 and 200, inclusive.
Examples
0)

    
1
Returns: 3
The only way is to use a box with dimensions 1 x 1 x 1.
1)

    
6
Returns: 6
This time one optimal solution is to send a box with dimensions 1 x 2 x 3. The cost of sending this box is 1+2+3 = 6. Any other option is at least as expensive as this one. For example, sending a box with dimensions 6 x 1 x 1 has the cost 6+1+1 = 8.
2)

    
7
Returns: 9

3)

    
200
Returns: 18

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

class ShippingCubes {
public:
  int minimalCost(int);
};

int ShippingCubes::minimalCost(int N) {

  int min_cost = 1000;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if ((i*j) <= N) { 
	if (N % (i*j) == 0) { //there is some value, lets say k, such that k*i*j = N
	  min_cost = min(min_cost, (i+j+(N/(i*j))) );
	}
      }
    }
  }
  
  return min_cost;
  
}
