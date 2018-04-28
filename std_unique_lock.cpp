
/*
 * =========================================================================
 *
 *       FileName:  std_unique_lock.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-03-15 14:14:00
 *  Last Modified:  2018-03-15 14:23:27
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
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <thread>
#include <mutex>
#include <map>
#include <list>
#include <string>
#include <functional>


bool flag = true;

std::mutex g_mtx1;
std::mutex g_mtx2;

void Task1()
{
  while ( flag )
  {
    std::unique_lock<std::mutex> lck1 ( g_mtx1, std::defer_lock );
    std::unique_lock<std::mutex> lck2 ( g_mtx2, std::defer_lock );
    std::lock ( lck1, lck2 );
    fprintf ( stderr, "task1 lock\n" );
    std::this_thread::sleep_for ( std::chrono::seconds ( 1 ) );
    lck1.unlock();
    fprintf ( stderr, "task1 lck1 unlock\n" );
    lck2.unlock();
    fprintf ( stderr, "task1 lck2 unlock\n" );
  }
}

void Task2()
{
  while ( flag )
  {
    std::unique_lock<std::mutex> lck1 ( g_mtx1, std::defer_lock );
    std::unique_lock<std::mutex> lck2 ( g_mtx2, std::defer_lock );
    std::lock ( lck1, lck2 );
    fprintf ( stderr, "task2 lock\n" );
    std::this_thread::sleep_for ( std::chrono::seconds ( 1 ) );
    lck1.unlock();
    fprintf ( stderr, "task2 lck1 unlock\n" );
    lck2.unlock();
    fprintf ( stderr, "task2 lck2 unlock\n" );
  }
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::thread t1 = std::thread ( Task1 );
  std::thread t2 = std::thread ( Task2 );


  sleep ( 3 );
  flag = false;

  t1.join();
  t2.join();

  return 0;
}

