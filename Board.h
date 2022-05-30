#pragma once


template <class T>
class TBoard
{
public:
  TBoard();
  void DrLine(T x1, T y1, T x2, T y2);
  void DrCirc(T x1, T y1, T R);
  void PrintBoard();

protected:
  char sc[50][50];
};

template<class T>
inline TBoard<T>::TBoard()
{
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      sc[i][j] = '*';
}

template<class T>
inline void TBoard<T>::DrLine(T x1, T y1, T x2, T y2)
{
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
}

template<class T>
inline void TBoard<T>::DrCirc(T x1, T y1, T R)
{
  int x = 0;
  int y = R;
  int d = 1 - 2 * R;
  int err = 0;
  while (y >= 0) {
    sc[x1 + x][y1 + y] = '.';
    sc[x1 + x][y1 - y] = '.';
    sc[x1 - x][y1 + y] = '.';
    sc[x1 - x][y1 - y] = '.';
    err = 2 * (d + y) - 1;
    if (d < 0 && err <= 0) {
      ++x;
      d += 2 * x + 1;
      continue;
    }
    err = 2 * (d - x) - 1;
    if (d > 0 && err > 0) {
      --y;
      d += 1 - 2 * y;
      continue;
    }
    ++x;
    d += 2 * (x - y);
    --y;
  }
}

template<class T>
inline void TBoard<T>::PrintBoard()
{
  for (int i = 0; i < 50; i++)
  {
    std::cout << "\n";
    for (int j = 0; j < 50; j++)
      std::cout << sc[i][j];
  }
}
