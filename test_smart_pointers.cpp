#include <cassert>
#include <iostream>
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

  SmartPointer<int> nullPtr;
  assert(nullPtr == NULL);
  cout << "Created a null pointer." << endl;

  // success
  return 0;
}
