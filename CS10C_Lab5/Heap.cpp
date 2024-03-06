#include <iostream>
#include <cstdlib>
#include "Heap.h"
#include "PrintJob.h"

using namespace std;


//Constructor
Heap::Heap() {
    numItems = 0;
    arr[0] = nullptr;
}

//Destructor
Heap::~Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob* newNode) {
    //Exits function if the amount of items is larger than the max size
    if (numItems >= MAX_HEAP_SIZE) {
        return;
    }
    numItems++;
    int newIndex = numItems - 1;
    arr[newIndex] = newNode;

    //If there is more than one array value, when enquing it 
    //it checks to see if the child elements priority is higher than the 
    //parents priority and if so then it is swapped to mantain max heap properties
    if (newIndex != 0) {
        int parentIndex = (newIndex - 1)/2;
        while (arr[parentIndex]->getPriority() < arr[newIndex]->getPriority()) {
            swap(arr[parentIndex], arr[newIndex]);
            newIndex = parentIndex;
            parentIndex = (newIndex - 1)/2;
        }
    }
}

void Heap::dequeue() {
    //If the array is empty then the function is exited
    if (numItems == 0) {
        return;
    }

    arr[0] = arr[numItems - 1];
    numItems--;
    trickleDown(0);
}

PrintJob* Heap::highest() {
    if (numItems == 0) {
        return nullptr;
    }
    //Finds the first value in the array as long as the array is not empty
    return arr[0];
}

void Heap::trickleDown(int currIndex) {
    //Finds the right and left childs of the parent
    int leftIndex = 2 * (currIndex + 1);
    int rightIndex = 2 * (currIndex + 2);

    int largerIndex = leftIndex;
    //Finds if the right or left value is the larger one
    if (rightIndex < numItems && arr[rightIndex]->getPriority() > arr[leftIndex]->getPriority()) {
        largerIndex = rightIndex;
    }

    //if the larger elements priority is
    // higher than the parent elements priority then they are swaped
    if (arr[largerIndex]->getPriority() > arr[currIndex]->getPriority()) {
        swap(arr[currIndex], arr[largerIndex]);
        trickleDown(largerIndex);
    }
}

void Heap::print() {
    //Prints the highest elements priority,
    // job number, and number of pages as long as the array is not empty
    if (numItems == 0) {
      return;
    }

    PrintJob* firstNode = highest();
    cout << "Priority: " << firstNode->getPriority() << ", ";
    cout << "Job Number: " << firstNode->getJobNumber() << ", ";
    cout << "Number of Pages: " << firstNode->getPages() << endl;
}