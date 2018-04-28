
/*
 * =========================================================================
 *
 *       FileName:  c11_funargs.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-05 13:23:53
 *  Last Modified:  2018-03-07 17:05:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt ()
 *   Organization:
 *
 * =========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <functional>

template <typename T1>
void printarg ( T1 t )
{
  std::cout << t << std::endl;
}

template <typename ...Args>
void expand ( Args... args )
{
  int arr[] = { ( printarg ( args ), 0 )...};
}

template <typename ... Args>
void Test ( Args... p )
{
  fprintf ( stderr, "num=%lu\n", sizeof... ( p ) );
}

class A
{
  public:
    A ( int a )
    {
      std::cout << a << std::endl;
    }
    ~A()
    {
    }
};

class B
{
  public:
    B ( int a, int b )
    {
      std::cout << a << " " << b << std::endl;
    }
    ~B()
    {
    }
};

template <typename T, typename... Args>
T* Instance ( Args&& ... args )
{
  return new T ( std::forward<Args> ( args )... );
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  //Test ( 1, 1 );
  //expand ( "asdf", "ss", 22, 2.0 );

  A* pa = Instance<A> ( 1 );
  B* pB = Instance<B> ( 2, 3 );

  return 0;
}

