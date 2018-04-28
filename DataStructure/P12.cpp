/*
 * =====================================================================================
 *
 *       Filename:  P12.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年03月31日 11时27分45秒
 *  Last Modified:  2016年03月31日 11时27分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

template<typename T>
bool Make2dArray ( T**& a, int numberOfRows, T*& b )
{
  a = new T* [numberOfRows];

  for ( int i = 0; i < numberOfRows; ++i )
    a[i] = new T [b[i]];

  return false;
}

class a
{
  public:
    a() {}
    ~a() {}

  public:
    friend std::ostream& operator<< ( std::ostream& out, const a& x )
    {
      out << "asd:" << 1.2 << std::endl;
      return out;
    }

};


int main ( int argc , char* argv[] )
{
  a aa;
  std::cout << aa;

  return 0;
}




