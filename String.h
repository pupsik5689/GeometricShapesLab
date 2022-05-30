#pragma once
#include <iostream>


class TString
{
public:
  TString();
  TString(int _len, char c);
  TString(const TString& a);
  TString(const char* s);
  ~TString();


  int GetLen();
  char* GetStr();

  TString operator+(TString &other);
  TString operator=(const TString &other);
  bool operator==(TString &other);
  bool operator<(const TString &other);
  bool operator>(const TString &other);
  char operator[](int i);
  friend std::ostream& operator<<(std::ostream& ostr, const TString& other);
  friend std::istream& operator>>(std::istream& istr, TString& other);

  int FWord(const char* _str);
  int FSymb(char c);

  void KStr(int k);
  void IndsWord(const char* _str);
  void CountLetter();

  char MostCommonSymb();
  char* WithoutRepeat();


protected:
  char* str;
  int len;

};