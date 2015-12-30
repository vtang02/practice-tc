/*
Problem Statement
    
Let A be a sequence of integers. We want to create this sequence as a concatenation of some (one or more) strictly increasing sequences. The LISNumber of A is the smallest number of strictly increasing sequences we need.  For example, the LISNumber of the sequence A = {1, 4, 4, 2, 6, 3} is 4, since A can be created as {1, 4} + {4} + {2, 6} + {3}, and there is no way to create A by concatenating 3 (or fewer) strictly increasing sequences.  Another example: The LISNumber of the sequence B = {10, 20, 30} is 1, since B is already a strictly increasing sequence.  Note that the optimal way of writing a sequence as a concatenation of some strictly increasing sequences is always unique.  You are given a vector <int> seq. Return the LISNumber of the sequence seq.
Definition
    
Class:
LISNumberDivTwo
Method:
calculate
Parameters:
vector <int>
Returns:
int
Method signature:
int calculate(vector <int> seq)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
seq will contain between 1 and 50 elements, inclusive.
-
Each element of seq will be between 1 and 50, inclusive.
Examples
0)

    
{1, 4, 4, 2, 6, 3}
Returns: 4
This is the example from the problem statement.
1)

    
{5, 8, 9, 12, 16, 32, 50}
Returns: 1
In this case, seq itself is already strictly increasing. Thus, the LISNumber of this sequence is 1.
  2)

    
{1, 1, 9, 9, 2, 2, 3, 3}
Returns: 6
{1, 1, 9, 9, 2, 2, 3, 3} = {1} + {1, 9} + {9} + {2} + {2, 3} + {3}
3)

    
{50, 40, 30, 20, 10}
Returns: 5

4)

    
{42}
Returns: 1

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

class LISNumberDivTwo {
public:
  int calculate(vector <int>);
};

int LISNumberDivTwo::calculate(vector <int> seq) {

  int counter = 1;

  for (unsigned i= 0; i < seq.size()-1; i++) {
    if (seq.at(i) >= seq.at(i+1)) {
      counter++;
    }
  }
  
  return counter;
  
}
