#include <cassert>
#include <iostream>
#include <vector>
#include "SmartPointer.hpp"

using namespace std;

int main(int argc, char** argv) {

  /////////////////////////////////////////////////////////////////////////////
  // Stack Allocation                                                        //
  /////////////////////////////////////////////////////////////////////////////
  
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

  /////////////////////////////////////////////////////////////////////////////
  // Heap Allocation                                                         //
  /////////////////////////////////////////////////////////////////////////////

  cout << "Allocating smart pointers to the same object on the heap...";
  SmartPointer<int>* sp1 = new SmartPointer<int>(new int(1));
  assert(**sp1 == 1);
  SmartPointer<int>* sp2 = new SmartPointer<int>(new int(2));
  assert(**sp2 == 2);
  SmartPointer<int>* sp3 = new SmartPointer<int>(); // null
  assert(*sp3 == NULL);
  cout << "success." << endl;

  cout << "Intentionally leaving dangling references...";
  *sp3 = *sp1;
  assert(**sp3 == 1);
  *sp3 = *sp2;
  assert(**sp3 == 2);
  *sp2 = *sp1;
  *sp3 = *sp1;
  cout << "success." << endl;

  cout << "Deallocating smart pointers from heap...";
  delete sp1;
  delete sp2;
  delete sp3;
  cout << "success." << endl;
  
  // success
  return 0;
}
