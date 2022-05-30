#include <iostream>
#include "Storage.h"

int main()
{
  //TDot<int> A(2);
  //TLine<int> l1;
  //TCircle<int> C1;
  //TTriangle<int> t;
  TSquare<int> sq;
 
  TStorage<int> book;
  //book.AddShape(&A);
  //book.AddShape(&l1);
  //book.AddShape(&C1);
  //book.AddShape(&t);
  book.AddShape(&sq);

  //book.DeleteShape(0);
  book.Print();
  book.Plot();
  return 0;
}