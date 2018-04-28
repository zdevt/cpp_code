/*
 * =====================================================================================
 *
 *       Filename:  lamada.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/26/2017 08:35:08 AM
 *  Last Modified:  2018-01-19 16:22:31
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
#include <functional>


std::function<int ( ) > Test ( int i )
{
  return [&]()
  {
    return i++;
  };
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  auto a = Test ( 5 );

  std::cout << a() << std::endl;
  std::cout << a() << std::endl;

  //int c = 1;
  //auto f = [&] ( int& a )
  //{
  //a = 5;
  //};
  //std::cout << c << std::endl;
  //f ( c );
  //std::cout << c << std::endl;

  return 0;
}

