#pragma once
#include "Object.h"
#include "Dot.h"


template <class T>
class TLine : public TObject<T>
{
public:
  TLine();
  ~TLine();
  virtual void Plot();
  virtual void Print();
  virtual void SetName(TString& s);

  virtual TVector<T>& operator[](int n);

  virtual TString& GetName();
  virtual int GetDim();

protected:
  TVector<T> Fp, Sp;
  TString name;
  int dim;
};

template<class T>
inline TLine<T>::TLine()
{
  std::cout << "Line: \n";
  std::cout << "Dim of 1st point \n";
  std::cin >> dim;

  TVector<T> a1(dim, 3);
  Fp = a1;

  std::cin >> Fp;
  std::cout << "\n";
  std::cout << "Dim of 2nd point \n";
  std::cin >> dim;

  TVector<T> a2(dim, 3);
  Sp = a2;

  std::cin >> Sp;
  dim = Fp.GetLen();
  if (Fp.GetLen() != Sp.GetLen()) throw "error";
  name = "Line";
}

template<class T>
inline TLine<T>::~TLine()
{
}

template<class T>
inline void TLine<T>::Plot()
{
  char sc[50][50];
  TVector<T> a1 = Fp;
  TVector<T> a2 = Sp;
  int x1 = (int)a1[0];
  int x2 = (int)a2[0];
  int y1 = (int)a1[1];
  int y2 = (int)a2[1];
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      sc[i][j] = '*';

  const int dX = (int)abs(x2 - x1);
  const int dY = (int)abs(y2 - y1);
  const int signX = x1 < x2 ? 1 : -1;
  const int signY = y1 < y2 ? 1 : -1;

  int err = dX - dY;
  sc[x2][y2] = '.';

  while (x1 != x2 || y1 != y2)
  {
    sc[x1][y1] = '.';
    int err2 = err * 2;
    if (err2 > -dY)
    {
      err -= dY;
      x1 += signX;
    }
    if (err2 < dX)
    {
      err += dX;
      y1 += signY;
    }
  }
  for (int i = 0; i < 50; i++)
  {
    std::cout << "\n";
    for (int j = 0; j < 50; j++)
      std::cout << sc[i][j];
  }
}

template<class T>
inline void TLine<T>::Print()
{
  std::cout << name << "\n";
  std::cout << "1st point " << Fp << "\n";
  std::cout << "2nd point " << Sp << "\n";
}

template<class T>
inline void TLine<T>::SetName(TString & s)
{
  name = s;
}

template<class T>
inline TVector<T>& TLine<T>::operator[](int n)
{
  if (n == 0)
  {
    return Fp;
  }
  else
    return Sp;
}

template<class T>
inline TString & TLine<T>::GetName()
{
  return name;
}

template<class T>
inline int TLine<T>::GetDim()
{
  return dim;
}
