
/*
 * =========================================================================
 *
 *       FileName:  std_atomint.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-10 17:18:55
 *  Last Modified:  2018-01-10 17:24:56
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
#include <map>
#include <list>
#include <string>
#include <atomic>


std::atomic_int32_t num = { 0 };

void run()
{
  for ( int i = 0; i < 10000000; ++i )
  {
    ++num;
  }
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::thread t1 ( run );
  std::thread t2 ( run );
  t1.join();
  t2.join();

  std::cout << "num:" << num << std::endl;

  return 0;
}

