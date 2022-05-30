#pragma once
#include "Complex.h"
#include "String.h"
#include "Vector.h"

template <class T>
class TObject
{
public:
  virtual void Plot() = 0;
  virtual void Print() = 0;
  virtual void SetName(TString& s) = 0;

  virtual TVector<T>& operator[](int n) = 0;

  virtual TString& GetName() = 0;
  virtual int GetDim() = 0;
};