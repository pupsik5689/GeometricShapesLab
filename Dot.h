#pragma once
#include "Object.h"

template <class T>
class TDot : public TObject<T>
{
public:
  TDot(int d);
  ~TDot();

  virtual void Plot();
  virtual void Print();
  virtual void SetName(TString& s);

  virtual TVector<T>& operator[](int n);

  virtual TString& GetName();
  virtual int GetDim();

protected:
  TVector<T> v;
  TString name;
  int dim;
};

template<class T>
inline TDot<T>::TDot(int d)
{
  dim = d;
  TVector<T> a(dim, 3);
  v = a;
  std::cout << "dot: \n";
  std::cin >> v;
  name = "Dot";
}

template<class T>
inline TDot<T>::~TDot()
{
}

template<class T>
inline void TDot<T>::Plot()
{
  char sc[50][50];
  TVector<T> a = v;

  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      sc[i][j] = '*';

  sc[(int)a[0]][(int)a[1]] = '.';

  for (int i = 0; i < 50; i++)
  {
    std::cout << "\n";
    for (int j = 0; j < 50; j++)
      std::cout << sc[i][j];
  }
}

template<class T>
inline void TDot<T>::Print()
{
  std::cout << name << "\n";
  std::cout << v << "\n";
}

template<class T>
inline void TDot<T>::SetName(TString & s)
{
  name = s;
}

template<class T>
inline TVector<T>& TDot<T>::operator[](int n)
{
  return v;
}

template<class T>
inline TString & TDot<T>::GetName()
{
  return name;
}

template<class T>
inline int TDot<T>::GetDim()
{
  return dim;
}



