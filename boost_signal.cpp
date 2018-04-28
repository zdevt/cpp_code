
/*
 * =========================================================================
 *
 *       FileName:  boost_signal.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017-12-18 17:42:16
 *  Last Modified:  2017-12-23 13:54:49
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

#include <boost/signals2.hpp>

//g++ boost_signal.cpp -o a -lboost_signals

void Helloworld()
{
  std::cout << "hello world 1\n";
  sleep ( 2 );
  std::cout << "hello world 2\n";
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  boost::signals2::signal<void() > sig;

  sig.connect ( &Helloworld );

  std::cout << "connect sig ok\n";
  sig();
  std::cout << "send sig ok\n";

  //while ( 1 )
  //{
  //sleep ( 1 );
  //}

  return 0;
}

