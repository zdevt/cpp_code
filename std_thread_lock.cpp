
/*
 * =========================================================================
 *
 *       FileName:  std_thread_lock.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-07-16 11:50:05
 *  Last Modified:  2018-07-16 11:51:02
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

int i = 0;
std::mutex mut;

void Iplus()
{
  int c = 1000000;

  while ( c-- )
  {
    mut.lock();
    ++i;
    mut.unlock();
  }
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::thread t1 ( Iplus );
  std::thread t2 ( Iplus );

  t1.join();
  t2.join();

  std::cout << "i= " << i << std::endl;


  return 0;
}

