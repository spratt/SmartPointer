#include <cassert>
#include <iostream>
#include <vector>
#include "SmartPointer.hpp"

using namespace std;

int main(int argc, char** argv) {
  SmartPointer<int> ptrToInt1(new int(55));
  assert(ptrToInt1 == ptrToInt1);
  cout << "My pointer: " << *ptrToInt1 << endl;

  cout << "Copying pointer...";
  SmartPointer<int> ptrToInt2(ptrToInt1);
  assert(*ptrToInt1 == *ptrToInt2);
  assert(ptrToInt1 == ptrToInt2);
  cout << "success." << endl;
  
  SmartPointer<int> ptrToAnotherInt(new int(44));
  assert(ptrToInt1 != ptrToAnotherInt);
  cout << "Other pointer: " << *ptrToAnotherInt << endl;

  cout << "Changing reference of other pointer...";
  ptrToAnotherInt = ptrToInt1;
  assert(*ptrToAnotherInt == *ptrToInt1);
  assert(ptrToAnotherInt == ptrToInt1);
  cout << "success." << endl;

  cout << "Creating a null pointer...";
  SmartPointer<int> nullPtr;
  assert(nullPtr == NULL);
  cout << "success." << endl;

  cout << "Creating a vector pointer...";
  SmartPointer<vector<int> > vectorPtr(new vector<int>());
  assert(vectorPtr->empty());
  cout << "success." << endl;

  cout << "Exercising methods on a vector pointer...";
  vectorPtr->push_back(0);
  vectorPtr->push_back(1);
  vectorPtr->push_back(2);
  vectorPtr->push_back(3);
  assert(vectorPtr->at(0) == 0);
  assert(vectorPtr->at(1) == 1);
  assert(vectorPtr->at(2) == 2);
  assert(vectorPtr->at(3) == 3);
  cout << "success." << endl;

  // success
  return 0;
}
