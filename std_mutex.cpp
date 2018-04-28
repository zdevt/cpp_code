/*
 * =====================================================================================
 *
 *       Filename:  Mutex.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年01月18日 14时23分02秒
 *  Last Modified:  2017-12-31 12:30:49
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
#include <unistd.h>

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <sys/syscall.h>


class TestData
{
  public:
    TestData()
    {
      d = 0;
    }
    ~TestData()
    {

    }

  public:
    uint8_t d;
};

volatile int count = 0;
std::mutex mtx;

void attempt_10k_increases ()
{
  for ( int i = 0; i < 10000; ++i )
  {
    if ( mtx.try_lock() )
    {
      ++count;
      mtx.unlock();
    }
  }
}

#if 0
void print_block ( int n, char c )
{
  mtx.lock();

  for ( int i = 0; i < n ; ++i )
    std::cout << c;

  std::cout << " " << syscall ( SYS_gettid ) << std::endl;

  mtx.unlock();
}
#endif


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  #if 0
  std::thread ( print_block, 30, '*' ).detach();
  std::thread ( print_block, 30, '#' ).detach();

  std::this_thread::sleep_for ( std::chrono::seconds ( 1 ) );
  #endif

  std::thread threads[10];

  for ( int i = 0; i < 10 ; ++i )
  {
    threads[i] = std::thread ( attempt_10k_increases );
    threads[i].detach();
  }

  sleep ( 1 );
  std::cout << count << std::endl;

  return 0;
}

