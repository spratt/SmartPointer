///////////////////////////////////////////////////////////////////////////////
//                       Copyright (c) 2011 - 2012 by                        //
//                                Simon Pratt                                //
//                           (All rights reserved)                           //
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// FILE:    SmartPointer.hpp                                                 //
//                                                                           //
// MODULE:  Smart Pointers                                                   //
//                                                                           //
// PURPOSE: To manage references to an object and automatically              //
//          deallocate when there are no more references.                    //
//                                                                           //
// NOTES:   None.                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
// Public Variable:                     Description:                         //
// ----------------                     ------------                         //
///////////////////////////////////////////////////////////////////////////////
//                             Public Methods:                               //
///////////////////////////////////////////////////////////////////////////////
#ifndef SMARTPOINTER_HPP
#define SMARTPOINTER_HPP

#include <cstddef>

namespace smart_ptr {
  template <class T>
  class SmartPointer{
  public:
    SmartPointer(void);
    SmartPointer(T* address);
    SmartPointer(SmartPointer<T>& toCopy);
    SmartPointer(const SmartPointer<T>& toCopy);
    ~SmartPointer();
    const SmartPointer& operator=(T* address);
    const SmartPointer& operator=(SmartPointer<T>& toCopy);
    const SmartPointer& operator=(const SmartPointer<T>& toCopy);
    T& operator*();
    T* operator->();
    bool operator==(const SmartPointer<T>& other);
    bool operator==(const T* other);
    bool operator!=(const SmartPointer<T>& other);
    bool operator!=(const T* other);
  private:
    T* _address;
    int* _references;

    void incReferences();
    void decReferences();
  };
}

#include "SmartPointer.cpp"

#endif
