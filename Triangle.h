#pragma once
#include "Object.h"
#include "Board.h"


template <class T>
class TTriangle : public TObject<T>
{
public:
  TTriangle();
  ~TTriangle();
  virtual void Plot();
  virtual void Print();
  virtual void SetName(TString& s);

  virtual TVector<T>& operator[](int n);

  virtual TString& GetName();
  virtual int GetDim();

protected:
  TVector<T> Fp, Sp, Tp;
  TString name;
  int dim;
};

template<class T>
inline TTriangle<T>::TTriangle()
{
  std::cout << "Triangle: \n";
  std::cout << "Dim of 1st point \n";
  std::cin >> dim;

  TVector<T> a(dim, 3);
  Fp = a;
  std::cin >> Fp;
  std::cout <<"\n";
  std::cout << "Dim of second point\n";
  std::cin >> dim;
  TVector<T> a2(dim, 3);
  Sp = a2;
  std::cin >> Sp;
  std::cout << "Dim of third point\n";
  std::cin >> dim;
  TVector<T> a3(dim, 3);
  Tp = a3;
  std::cin >> Tp;
  dim = Fp.GetLen();
  if ((Fp.GetLen() != Sp.GetLen()) || (Fp.GetLen() != Tp.GetLen()) || (Sp.GetLen() != Tp.GetLen())) throw "error";
  name = "Triangle";
}

template<class T>
inline TTriangle<T>::~TTriangle()
{
}

template<class T>
inline void TTriangle<T>::Plot()
{
  TBoard<T> sc;
  sc.DrLine(Fp[0], Fp[1], Sp[0], Sp[1]);
  sc.DrLine(Sp[0], Sp[1], Tp[0], Tp[1]);
  sc.DrLine(Tp[0], Tp[1], Fp[0], Fp[1]);
  sc.PrintBoard();
}

template<class T>
inline void TTriangle<T>::Print()
{
  std::cout << name << "\n";
  std::cout << "2st vertex " << Fp << "\n";
  std::cout << "2nd vertex " << Sp << "\n";
  std::cout << "3rd vertex " << Tp << "\n";
}

template<class T>
inline void TTriangle<T>::SetName(TString & s)
{
  name = s;
}

template<class T>
inline TVector<T>& TTriangle<T>::operator[](int n)
{
  if (n == 0)
  {
    return Fp;
  }
  else
    if (n == 1)
    {
      return Sp;
    }
    else
      if (n == 2) return Tp;
}

template<class T>
inline TString & TTriangle<T>::GetName()
{
  return name;
}

template<class T>
inline int TTriangle<T>::GetDim()
{
  return dim;
}
