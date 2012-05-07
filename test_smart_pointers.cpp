#include <cassert>
#include <iostream>
#include "SmartPointer.hpp"

using namespace std;

int main(int argc, char** argv) {
  SmartPointer<int> ptrToInt1(new int(55));
  cout << "My pointer: " << *ptrToInt1 << endl;

  cout << "Copying pointer...";
  SmartPointer<int> ptrToInt2(ptrToInt1);
  assert(*ptrToInt2 == *ptrToInt1);
  cout << "success." << endl;
  
  SmartPointer<int> ptrToAnotherInt(new int(44));
  cout << "Other pointer: " << *ptrToAnotherInt << endl;

  cout << "Changing reference of other pointer...";
  ptrToAnotherInt = ptrToInt1;
  assert(*ptrToAnotherInt == *ptrToInt1);
  cout << "success." << endl;

  // success
  return 0;
}
