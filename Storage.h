#pragma once
#include "Object.h"
#include "Dot.h"
#include "Line.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

template <class T>
class TStorage
{
public:
  TStorage();
  ~TStorage();

  void Print();
  void Plot();
  void Plot(int n);
  void Print(int n);
  void AddShape(TObject<T>* _shape);
  void DeleteShape(int n);

protected:
  int count;
  TObject<T>** mas;
};

template<class T>
inline TStorage<T>::TStorage()
{
  count = 0;
  mas = 0;
}

template<class T>
inline TStorage<T>::~TStorage()
{
  if (mas != nullptr)
    delete[] mas;
}

template<class T>
inline void TStorage<T>::Print()
{
  for (int i = 0; i < count; i++)
    mas[i]->Print();
}

template<class T>
inline void TStorage<T>::Plot()
{
  for (int i = 0; i < count; i++)
  {
    mas[i]->Plot();
    std::cout << "\n";
  }
}

template<class T>
inline void TStorage<T>::Plot(int n)
{
  if ((n >= 0) && (n <= count))
    mas[n]->Plot();
}

template<class T>
inline void TStorage<T>::Print(int n)
{
  if ((n >= 0) && (n <= count))
    mas[n]->Print();
}

template<class T>
inline void TStorage<T>::AddShape(TObject<T>* _shape)
{
  if (count == 0)
  {
    count = 1;
    mas = new TObject<T> *[1];
    mas[0] = _shape;
  }
  else
  {
    TObject<T>** a = new TObject<T> * [count + 1];
    for (int i = 0; i < count; i++)
      a[i] = mas[i];

    delete[] mas;
    mas = a;
    mas[count] = _shape;
    count++;
  }
}

template<class T>
inline void TStorage<T>::DeleteShape(int n)
{
  if (mas != 0)
  {
    TObject<T>** a = new TObject<T>*[count - 1];
    
    for (int i = 0; i < count - 1; i++)
    {
      if (i == n)
      {
        mas[i] = 0;
        for (int j = i; j < count; j++)
          mas[j] = mas[j + 1];
      }
      a[i] = mas[i];
    }

    delete[] mas;
    mas = 0;
    count--;
    mas = new TObject<T>*[count];
    
    for (int j = 0; j < count; j++)
      mas[j] = a[j];
  }
}
