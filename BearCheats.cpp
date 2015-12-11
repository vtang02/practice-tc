/*
Problem Statement
    
Limak is an old brown bear. Because of his bad eyesight he sometimes has to visit his doctor, Dr. Carrot. Today is one such day.
 
Dr. Carrot has a blackboard in his office. There is a number A written on the blackboard. In order to examine Limak's eyesight, Dr. Carrot asked him to read the number. Limak couldn't see the number really well. He could determine the number of digits correctly, but he was not sure what the individual digits are. Finally, he decided to announce the number B to the doctor. The doctor then left the office for a short while.
 
Limak really doesn't want to wear glasses, so he has decided to cheat. As soon as the doctor left the room, Limak went to the blackboard to read the correct number A. Before the doctor returns, Limak has the time to change one of the digits of A to any different digit. (Note that he may not add any new digits to A and he may not completely erase any digits of A. He may only change at most one of the digits.) Limak hopes that he can deceive the doctor by changing the number A into his number B.
 
You are given the ints A and B. Return the string "happy" (quotes for clarity) if Limak can convince the doctor that his eyesight is good. Otherwise, return the string "glasses".
Definition
    
Class:
BearCheats
Method:
eyesight
Parameters:
int, int
Returns:
string
Method signature:
string eyesight(int A, int B)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
256
Stack limit (MB):
256
Constraints
-
A and B will be between 1 and 999,999, inclusive.
-
A and B will have the same number of digits. 
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

class BearCheats {
public:
	string eyesight(int, int);
};

//start time 2:15pm
//end time:
//can you change int A to int B by only changing one digit?

//if A == B, done
//count the number of different digits between A and B
//mod by 10 to get last digit
//div by 10 to get the rest of the number, chop off the last dig

string BearCheats::eyesight(int A, int B) {

	int dif_digits = 0; //counter for the number of differing digits

	cout << "Limak's numbers are: " << A << " and " << B << endl;
	int lastdig_A = -1;
	int lastdig_B = -1;
	while (A > 0) { //while we have not chopped off all the digits of A (and B)

		lastdig_A = A % 10;
		cout << "lastdig_A: " << lastdig_A << endl;
		A = A / 10;
		cout << "A is: " << A << endl;
	
		lastdig_B = B % 10;
		cout << "lastdig_B: " << lastdig_B << endl;
		B = B / 10;
		cout << "B is: " << B << endl;
		
		if (lastdig_A != lastdig_B) {
			dif_digits++;
			cout << "lastdigs were not equal" << endl;
		}
	}
	
	cout << "dig_digits is: " << dif_digits << endl;
	if (dif_digits > 1) {
		return "glasses";
	} else {
		return "happy";
	}
	
}

