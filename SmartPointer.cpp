///////////////////////////////////////////////////////////////////////////////
//                       Copyright (c) 2011 - 2012 by                        //
//                                Simon Pratt                                //
//                           (All rights reserved)                           //
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// FILE:    SmartPointer.cpp                                                 //
//                                                                           //
// MODULE:  Smart Pointer                                                    //
//                                                                           //
// NOTES:   None.                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef SMARTPOINTER_CPP
#define SMARTPOINTER_CPP

#include "SmartPointer.hpp"

using namespace smart_ptr;

template <class T>
SmartPointer<T>::SmartPointer()
  : _address(NULL), _references(NULL)
{
}

template <class T>
SmartPointer<T>::SmartPointer(T* a)
  : _address(a), _references(new int(0))
{
  incReferences();
}

template <class T>
SmartPointer<T>::SmartPointer(SmartPointer<T>& toCopy)
  : _address(toCopy._address), _references(toCopy._references)
{
  incReferences();
}

template <class T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& toCopy)
  : _address(toCopy._address), _references(toCopy._references)
{
  incReferences();
}

template <class T>
const SmartPointer<T>& SmartPointer<T>::operator=(T* address) {
  decReferences();
  _address = address;
  _references = 0;
  incReferences();
  return *this;
}

template <class T>
const SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T>& toCopy) {
  decReferences();
  _address = toCopy._address;
  _references = toCopy._references;
  incReferences();
  return *this;
}

template <class T>
const SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& toCopy) {
  decReferences();
  _address = toCopy._address;
  _references = toCopy._references;
  incReferences();
  return *this;
}

template <class T>
SmartPointer<T>::~SmartPointer() {
  // one less reference
  decReferences();
}

template <class T>
void SmartPointer<T>::incReferences() {
  if(_references == NULL)
    return;
  
  ++(*_references);
}

template <class T>
void SmartPointer<T>::decReferences() {
  if(_references == NULL)
    return;
  
  --(*_references);

  // no more references
  if((*_references) < 1) {
    delete _references;
    if(_address != NULL)
      delete _address;
  }
}

template <class T>
T& SmartPointer<T>::operator*() {
  if(_address == NULL)
    throw "Tried to dereference a NULL pointer";
  
  return *_address;
}

template <class T>
T* SmartPointer<T>::operator->() {
  if(_address == NULL)
    throw "Tried to dereference a NULL pointer";

  return _address;
}

template <class T>
bool SmartPointer<T>::operator==(const SmartPointer<T>& other) {
  return _address == other._address;
}

template <class T>
bool SmartPointer<T>::operator==(const T* other) {
  return _address == other;
}

template <class T>
bool SmartPointer<T>::operator!=(const SmartPointer<T>& other) {
  // defer to == operator
  return !(this->operator==(other));
}

template <class T>
bool SmartPointer<T>::operator!=(const T* other) {
  // defer to == operator
  return !(this->operator==(other));
}

#endif
