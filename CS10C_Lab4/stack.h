#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 20


template <class T> class stack {
   private:
      T data[MAX_SIZE];
      int size; 
   public:
      //Constructs an empty stack
      stack() {
        size = 0;
      }

      //Inserts an element into the end of the array
      void push(T val) {
        //If the array is full then it calls an overflow error
        if (size == MAX_SIZE) {
            throw overflow_error("Called push on full stack.");
        }

        else {
            size++;
            data[size - 1] = val;
        }
      }

      //Removes the element at the end of the array
      void pop() {
        //If the array is empty then it calls an out of range error
        if (size == 0) {
            throw out_of_range("Called pop on empty stack.");
        }

        else {
            size--;
        }
      }

      //Removes the last two elements at the end of the array
      void pop_two() {
        //If the array has 1 element or is empty then an out of range error is called
        if ((size - 1) == 0) {
            throw out_of_range("Called pop_two on a stack of size 1.");
        }

        else if (size == 0) {
            throw out_of_range("Called pop_two on empty stack.");
        }

        else {
            size = size - 2;
        }
      }

      //Returns the last element in the stack
      T top() {
        //If the array is empty then an underflow error is called
        if (size == 0) {
            throw underflow_error("Called top on empty stack.");
        }

        return data[size - 1];
      }

      //Checks to see if the array is empty
      bool empty() {
        return (size == 0);
      }
};