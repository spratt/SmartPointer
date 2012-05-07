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

namespace smart_ptr {
  template <class T>
  class SmartPointer{
  public:
    SmartPointer(T* address);
    SmartPointer(SmartPointer<T>& toCopy);
    ~SmartPointer();
    const SmartPointer& operator=(SmartPointer<T>& toCopy);
    T& operator*();
  private:
    T* _address;
    int* _references;

    void incReferences();
    void decReferences();
  };
}

#include "SmartPointer.cpp"

#endif
