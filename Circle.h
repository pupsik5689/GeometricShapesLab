#pragma once
#include "Object.h"
#include "Board.h"

template <class T>
class TCircle : public TObject<T>
{
public:
  TCircle();
  ~TCircle();
  virtual void Plot();
  virtual void Print();
  virtual void SetName(TString& s);

  virtual TVector<T>& operator[](int n);

  virtual TString& GetName();
  virtual int GetDim();

  int GetRad();

protected:
  TVector<T> Cp;
  TString name;
  int dim;
  T rad;
};

template<class T>
inline TCircle<T>::TCircle()
{
  std::cout << "Circle: \n";
  std::cout << "Dim of middle point \n";
  std::cin >> dim;

  TVector<T> a(dim, 3);
  Cp = a;

  std::cin >> Cp;
  std::cout << "Rad circle \n";
  std::cin >> rad;

  name = "Circle";
}

template<class T>
inline TCircle<T>::~TCircle()
{
}

template<class T>
inline void TCircle<T>::Plot()
{
  TBoard<T> a;
  a.DrCirc(Cp[0], Cp[1], rad);
  a.PrintBoard();
}

template<class T>
inline void TCircle<T>::Print()
{
  std::cout << name << "\n";
  std::cout << "Middle " << Cp << "\n";
  std::cout << "Rad " << rad << "\n";
}

template<class T>
inline void TCircle<T>::SetName(TString & s)
{
  name = s;
}

template<class T>
inline TVector<T>& TCircle<T>::operator[](int n)
{
  return Cp;
}

template<class T>
inline TString & TCircle<T>::GetName()
{
  return name;
}

template<class T>
inline int TCircle<T>::GetDim()
{
  return dim;
}

template<class T>
inline int TCircle<T>::GetRad()
{
  return rad;
}
