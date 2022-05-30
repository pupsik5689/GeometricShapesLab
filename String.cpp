#include "String.h"
#include <string.h>
#include <iostream>

TString::TString()
{
  len = 0;
  str = new char[1];
  str[0] = '\0';
}

TString::TString(int _len, char c)
{
  len = _len;
  str = new char[len + 1];

  for (int i = 0; i < _len; i++)
    str[i] = c;

  str[len] = '\0';
}

TString::TString(const TString & a)
{
  len = a.len;
  str = new char[len + 1];

  for (int i = 0; i < len; i++)
    str[i] = a.str[i];
  str[len] = '\0';
}

TString::TString(const char * s)
{
  if (s == nullptr)
  {
    len = 0;
    str = new char[1];
    str[0] = '\0';
  }
  else
  {
    len = strlen(s);
    str = new char[len + 1];

    for (int i = 0; i < len; i++)
      str[i] = s[i];
    str[len] = '\0';
  }
}

TString::~TString()
{
  delete[] str;
}



int TString::GetLen()
{
  return len;
}

char* TString::GetStr()
{
  char* a = new char[len];
  for (int i = 0; i <= len; i++)
    a[i] = str[i];
  return a;
}



TString TString::operator+(TString & other)
{
  int tlen = len + other.len;
  TString total(tlen, 0);

  for (int i = 0; i < len; i++)
    total.str[i] = str[i];

  for (int i = len; i < tlen; i++)
    total.str[i] = other.str[i - len];

  str[tlen] = '\0';
  return total;
}

TString TString::operator=(const TString & other)
{
  if (str != nullptr)
  {
    delete[] str;
    str = nullptr;
  }

  len = other.len;
  str = new char[len + 1];

  for (int i = 0; i < len; i++)
    str[i] = other.str[i];

  str[len] = '\0';

  return *this;
}

bool TString::operator==(TString & other)
{
  if (len == other.len)
  {
    for (int i = 0; i < len; i++)
      if (str[i] == other.str[i])
      {
      }
      else
        return false;

    return true;
  }

  return false;
}

bool TString::operator<(const TString & other)
{
  if (len < other.len)
  {
    return true;
  }
  else
    if (len > other.len)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < len; i++)
      {
        if (str[i] < other.str[i])
        {
          return true;
        }
        else
          if (str[i] > other.str[i])
            return false;
      }
    }
  return false;
}

bool TString::operator>(const TString & other)
{
  if (len > other.len)
  {
    return true;
  }
  else
    if (len < other.len)
    {
      return false;
    }
    else
    {
      for (int i = 0; i < len; i++)
      {
        if (str[i] > other.str[i])
        {
          return true;
        }
        else
          if (str[i] < other.str[i])
            return false;
      }
    }
  return false;
}

char TString::operator[](int i)
{
  if ((i >= 0) && (i <= len))
  {
    return str[i];
  }
  else
  {
    throw ("Error");
  }
}



int TString::FWord(const char* _str)
{
  int lp = strlen(_str);
  bool f;

  for (int i = 0; i <= len - lp; i++)
  {
    f = true;

    if (str[i] == _str[0])
    {
      for (int j = 1; j < lp; j++)
      {
        if (str[i + j] == _str[j])
        {
          f = true;
        }
        else
        {
          f = false;
          break;
        }
      }

      if (f == true)
      {
        return i + 1;
      }
    }
  }

  return -1;
}

int TString::FSymb(char c)
{
  for (int i = 0; i < len; i++)
    if (str[i] == c)
      return i;

  return -1;
}



void TString::KStr(int k)
{
  for (int i = 0; i < k; i++)
  {
    std::cout << str << "\n";
  }
}

void TString::IndsWord(const char* _str)
{
  int lp = strlen(_str);
  bool f;
  bool f1 = false;
  for (int i = 0; i <= len - lp; i++)
  {
    f = true;

    if (str[i] == _str[0])
    {
      for (int j = 1; j < lp; j++)
      {
        if (str[i + j] == _str[j])
        {
          f = true;
        }
        else
        {
          f = false;
          break;
        }
      }

      if (f == true)
      {
        std::cout << i + 1 << " ";
        f1 = true;
      }
    }
  }
  if (f1 == false)
    std::cout << "No result";
}

void TString::CountLetter()
{
  char* a = new char[len];
  int count[512];
  bool c;
  int indx = 0;

  a[len] = '\0';

  for (int i = 0; i < len; i++)
  {
    a[i] = '0';
    count[i] = 0;
  }

  for (int i = 0; i < len; i++)
  {
    c = false;

    for (int j = 0; j < len; j++)
    {
      if (str[i] == a[j])
      {
        c = true;
        count[j] += 1;
      }
    }

    if (c == false)
    {
      a[indx] = str[i];
      count[indx] = 1;
      indx += 1;
    }

  }

  a[indx] = '\0';

  for (int i = 0; i < indx; i++)
  {
    std::cout << a[i] << " - " << count[i] << "\t";
  }

}



char TString::MostCommonSymb()
{
  int a[512];
  char c = '0';
  for (int i = 0; i < 512; i++)
    a[i] = 0;
  for (int i = 0; i < len; i++)
    a[char(str[i])]++;
  for (int i = 0; i < 512; i++)
    if (a[i] > a[int(char(c))])
      c = char(i);
  return char(c);
}

char * TString::WithoutRepeat()
{
  char* a = new char[len];
  int count[512];
  bool c;
  int indx = 0;

  a[len] = '\0';

  for (int i = 0; i < len; i++)
  {
    a[i] = '0';
    count[i] = 0;
  }

  for (int i = 0; i < len; i++)
  {
    c = false;

    for (int j = 0; j < len; j++)
    {
      if (str[i] == a[j])
      {
        c = true;
        count[j] += 1;
      }
    }

    if (c == false)
    {
      a[indx] = str[i];
      count[i] = 1;
      indx += 1;
    }

  }

  a[indx] = '\0';
  return a;
}



std::ostream & operator<<(std::ostream & ostr, const TString & other)
{
  other.str[other.len] = '\0';
  ostr << other.str;
  return ostr;
}

std::istream & operator>>(std::istream & istr, TString & other)
{
  other.str = nullptr;

  char* tot = new char[1024];
  istr >> tot;

  TString a(strlen(tot), ' ');

  for (int i = 0; i < strlen(tot); i++)
    a.str[i] = tot[i];

  other = a;

  return istr;
}