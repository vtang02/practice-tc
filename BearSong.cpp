/*
Problem Statement
    
Bear Limak has recently learned about musical notes. He then listened to a song and noticed that some notes appeared less often than others. In fact, some notes were so rare that they appeared in the song only once!
 
Limak now wants to look for such notes in other songs. Write a program that will look for the rare notes.
 
You are given a vector <int> notes that describes a song. Each number in notes represents one note of the song. Different numbers represent different notes, equal numbers represent equal notes.
 
Compute and return the number of notes that occur exactly once in the given song.
Definition
    
Class:
BearSong
Method:
countRareNotes
Parameters:
vector <int>
Returns:
int
Method signature:
int countRareNotes(vector <int> notes)
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
notes will contain between 1 and 50 elements, inclusive.
-
Each element in notes will be between 1 and 1000, inclusive.
Examples
0)

    
{9,10,7,8,9}
Returns: 3
The rare notes are the notes 7, 8, and 10. Each of these notes occurs exactly once in the whole song. The note 9 occurs twice, so it is not a rare note
1)

    
{8,8,7,6,7,3,5,10,9,3}
Returns: 4
Each of the notes 5, 6, 9, and 10 occurs exactly once in this song.
2)

    
{234,462,715,596,906}
Returns: 5

3)

    
{17}
Returns: 1

4)

    
{1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}
Returns: 0

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

class BearSong {
public:
  int countRareNotes(vector <int>);
};

//start at first element and find all copies of it in the vector, keeping track of how many copies, and removing them
//if num copies == 1, increment the iterator
//keep going until the vector is empty

int BearSong::countRareNotes(vector <int> notes) { //9, 10, 7, 8, 9


  std::cout << "notes1 contains:";
  for (unsigned x=0; x<notes.size(); ++x) {
    cout << ' ' << notes[x]; 
  }
  cout << '\n';

  int total = 0; //keep track of how many notes appear once
  for (int i = 0; notes.size() != 0; i++) { //outer loop to get current note we are checking
    
    cout << "big for loop!" << endl;
    cout << "notes.size() is: "  << notes.size() << endl;
    
    int current = notes[0];
    notes.erase(notes.begin());
    
    std::cout << "notes2 contains:";
    for (unsigned x=0; x<notes.size(); ++x) {
      cout << ' ' << notes[x]; 
    }
    cout << '\n';
    
    cout << "current is: " << current << endl;
    
    int counter = 1; //keep track of how many times a notes appears
    for (int j = 0; j < notes.size(); j++) { //inner loop to check that note
      cout << "notes[i] is: " << notes[j] << endl;
      if (current == notes[j]) {
	counter++;
	notes.erase(notes.begin()+j);
	cout << "j is: " << j << " inside current == notes" << endl;
      }
      cout << "j is: " << j << " outside current == notes" << endl;
      cout << "i is: " << i << " wtf i" << endl;
      
    }
    cout << "counter is: " << counter << endl;
    if (counter == 1) {
      total++;
    }
    counter = 0;
  }
  cout << "total is: " << total << endl;
  return total;

}
