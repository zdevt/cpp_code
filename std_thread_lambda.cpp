
/*
 * =========================================================================
 *
 *       FileName:  std_thread_lambda.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-03-16 14:12:42
 *  Last Modified:  2018-03-16 14:28:06
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
#include <atomic>


bool ProcessData ( double i )
{
  ( void ) i;
  std::chrono::milliseconds d ( 1 );
  std::this_thread::sleep_for ( d );
  return true;
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  const int samples = 1000;
  std::vector<double> data;
  std::atomic<int> result ( 0 );
  std::atomic<int> currentIndex ( 0 );
  std::vector<std::thread> threads;

  for ( int i = 0; i < samples; ++i )
    data.push_back ( i );

  fprintf ( stderr, "i=%d\n", std::thread::hardware_concurrency() );

  for ( unsigned int i = 0; i < std::thread::hardware_concurrency(); ++i )
  {
    threads.push_back ( std::thread ( [&]()
    {
      while ( 1 )
      {
        int index = currentIndex.fetch_add ( 1 );

        if ( index >= samples )
          break;

        if ( ProcessData ( data[index] ) )
          result++;
      }
    } ) );
  }

  for ( auto& t : threads )
    t.join();

  std::cout << result << std::endl;
  return 0;
}

