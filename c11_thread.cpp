/*
 * =====================================================================================
 *
 *       Filename:  c11thread.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年08月20日 16时12分20秒
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
#include <thread>
#include <chrono>
#include <atomic>
#include <functional>
#include <utility>

void f1 ( int n )
{
  for ( int i = 0; i < 5; ++i )
  {
    fprintf ( std::this_thread::sleep_for ( std::chrono::milliseconds ( 10 ) );
  }
}

void f2 ( int& n )
{
  for ( int i = 0 ; i < 5; ++i )
  {
    ++n;
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 10 ) );
  }

}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  int n = 0;

  std::thread t1;
  std::thread t2 ( f1, n + 1 );
  std::thread t3 ( f2, std::ref ( n ) );
  std::thread t4 ( std::move ( t3 ) );

  t2.join();
  t4.join();

  return 0;
}
