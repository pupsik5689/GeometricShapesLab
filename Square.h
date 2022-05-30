#pragma once
#include "Object.h"


template <class T>
class TSquare : public TObject<T>
{
public:
  TSquare();
  ~TSquare();
  virtual void Plot();
  virtual void Print();
  virtual void SetName(TString& s);

  virtual TVector<T>& operator[](int n);

  virtual TString& GetName();
  virtual int GetDim();

  T GetLength();

protected:
  TVector<T> Fp;
  TString name;
  int dim;
  T length;
};

template<class T>
inline TSquare<T>::TSquare()
{
  std::cout << "Square: \n";
  std::cout << "Dim of 1st point \n";
  std::cin >> dim;

  TVector<T> a(dim, 3);
  Fp = a;

  std::cin >> Fp;
  std::cout << "\nLength square \n";
  std::cin >> length;
  name = "Square";
}

template<class T>
inline TSquare<T>::~TSquare()
{
}

template<class T>
inline void TSquare<T>::Plot()
{
  char sc[50][50];
  TVector<T> a = Fp;
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      sc[i][j] = '*';

  sc[(int)a[0]][(int)a[1]] = '.';

  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    {
      if ((sc[i][j] == '.') && (j < length + (int)a[0]))
        sc[i][j + 1] = '.';
      if ((sc[i][j] == '.') && (j == length + (int)a[0]) && (i < length + (int)a[0]))
        sc[i + 1][j] = '.';
    }

  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
    {
      if ((sc[i][j] == '.') && (j == (int)a[0]) && (i < length + (int)a[0]))
        sc[i + 1][j] = '.';
      if ((sc[i][j] == '.') && (i == length + (int)a[0]) && (j < length + (int)a[0]))
        sc[i][j + 1] = '.';
    }

  for (int i = 0; i < 50; i++)
  {
    std::cout <<"\n";
    for (int j = 0; j < 50; j++)
      std::cout << sc[i][j];
  }
}

template<class T>
inline void TSquare<T>::Print()
{
  std::cout << name;
  std::cout << "\nFirst vertex " << Fp;
  std::cout << "\nLength square " << length << "\n";
}

template<class T>
inline void TSquare<T>::SetName(TString & s)
{
  name = s;
}

template<class T>
inline TVector<T>& TSquare<T>::operator[](int n)
{
  return Fp;
}

template<class T>
inline TString & TSquare<T>::GetName()
{
  return name;
}

template<class T>
inline int TSquare<T>::GetDim()
{
  return dim;
}

template<class T>
inline T TSquare<T>::GetLength()
{
  return length;
}
