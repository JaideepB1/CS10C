// PROFPAT: by convention, we sort the include by name here
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

// ZYBOOKS: You are given a function that creates a vector of
// ZYBOOKS: characters with random size. You just need to put the
// ZYBOOKS: following piece of code in your main.cpp file as is:
vector<char> createVector() {
  int vecSize = rand() % 26;
  char c = 'a';
  vector<char> vals;
  for(int i = 0; i < vecSize; i++)
    {
      vals.push_back(c);
      c++;
    }
  return vals;
}

// Passes in an index of type int and a vector of type T (T could be
// string, double, int or whatever). The function returns the index
// of the min value starting from "index" to the end of the "vector".
// PROFPAT: How do we define the "template" type T here?
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index) {
  //Creates a new variable names minVal that is the index value in the vector vals
  T minVal = vals.at(index);
  unsigned minIndex = index;
  
  //Loops through the vector vals starting from the index until the end and 
  //continues to change the minVal value and the index when the current value is 
  //found to be less than the previous min value
  for (unsigned i = index; i < vals.size(); i++) {
    if (vals.at(i) < minVal) {
      minVal = vals.at(i);
      minIndex = i;
    }
  }

  return minIndex;
}

// PROFPAT: Note that vals is passed by reference, but not const
// PROFPAT: reference.  So this function will change the vector
// PROFPAT: back in main when we call it
// Passes in a vector of type T and sorts them based on the selection
// sort method. This function should utilize the min_index function
// to find the index of the min value in the unsorted portion of the
// vector.
// PROFPAT: How do we define the "template" type T here?
template<typename T>
void selection_sort(vector<T> &vals) {
  T tempVal;
  //Loops through the vector vals and if the current value is found to be greater than that of the 
  //minimum value from the remaining elements then it switches the two values
  for (unsigned i = 0; i < vals.size(); i++) {
    unsigned minIndex = min_index(vals, i);

    if (vals.at(i) > vals.at(minIndex)) {
      tempVal = vals.at(i);
      vals.at(i) = vals.at(minIndex);
      vals.at(minIndex) = tempVal;
    }
  }
}

// PROFPAT: I updated the argument passing to const&.  The function
// PROFPAT: returns a copy -- not what I would have picked (I would
// PROFPAT: return a const T& here), but hey Zybooks will do it Zybooks
// PROFPAT: way :-)
// 
// Passes in a vector of type T (T could be string, double or int) and
// an index of type int. The function returns the element located at
// the index of the vals.
// PROFPAT: How do we define the "template" type T here?
template<typename T>
T getElement(const vector<T>& vals, int index) {
  // PROFPAT: This is a stub.  Just returns a default value of type T
  // PROFPAT: Should return the value or throw out_of_range.
  // PROFPAT: Question:  Should you use .at() or [] here?
  //returns the element that is in the vector vals at the given index
  T element = vals.at(index);
  return element;
}

// PROFPAT: Make this and then run with % ./a.out < test.txt
// ZYBOOKS: You should write up a try catch block in main function 
// ZYBOOKS: so that when the index is out of the range of the
// ZYBOOKS: vector, the "std::outofrange" exception will be caught 
// ZYBOOKS: by the catch(const std::outofrange& excpt).
// ZYBOOKS: Once the exception is caught, it
// ZYBOOKS: should output "out of range exception occured" followed by a
// ZYBOOKS: new line.
// ZYBOOKS: 
// ZYBOOKS: You should come up with test harnesses to test your
// ZYBOOKS: selection_sort function.
int main() {
  
  // Seeding the random number generator so we get a different
  // run every time.
  srand(time(0));

  // Fill in a vector of some random size with some random
  // characters
  vector<char> vals = createVector();
  int numOfRuns = 10;
  while(--numOfRuns >= 0){
    cout << "Enter a number: " << endl;
    // PROFPAT: Just because zybooks doesn't think it is important
    // PROFPAT: to check inputs doesn't mean you should skip it
    unsigned index;
    if (not (cin >> index)) {
      throw runtime_error("could not read the index");
    }

    if (index < 0 || index >= vals.size()) {
      throw out_of_range("index is out of range");
    }

    // PROFPAT: We will use a try/catch block here to "protect"
    // PROFPAT: the call to getElement() otherwise the program
    // PROFPAT: will terminate on the throw.  Remember!  The
    // PROFPAT: throw happens where we detect the issue.  The
    // PROFPAT: try/catch occurs where we want to handle it!!!!
    char curChar = getElement(vals,index);
    cout << "Element located at " << index << ": is " << curChar << endl;
  }

  // PROFPAT:  You should test selection sort here!!!!
  //This creates a vector of the int type
  vector<int> intVals = {3, 7, 2, 10, 9, 15};

  //The vector is then sorted using the selection sort method
  selection_sort(intVals);

  cout << intVals.at(0);

  //The vector is then printed out
  for (unsigned i = 1; i < intVals.size(); i++) {
      cout << " " << intVals.at(i);
  }

  cout << endl;

  //This creates a vector of the double type
  vector<double> doubleVals = {2.5, 5.0, 3.7, 10.1, 8.6};

  //The vector is once again sorted using the selection sort method
  selection_sort(doubleVals);

  cout << doubleVals.at(0);

  //The vector is printed
  for (unsigned i = 1; i < doubleVals.size(); i++) {
      cout << " " << doubleVals.at(i);
  }

  cout << endl;
  
  //A vector of characters is created
  vector<char> charVals = {'s', 'r', 'b', 'a', 'k', 'j', 'i'};

  selection_sort(charVals);

  cout << charVals.at(0);

  for (unsigned i = 1; i < charVals.size(); i++) {
      cout << " " << charVals.at(i);
  }

  cout << endl;
  
  return 0;
}
