
/*
 * =========================================================================
 *
 *       FileName:  std_thread_lock_free_shared_ptr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-07-16 13:25:17
 *  Last Modified:  2018-07-16 14:20:42
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

class Test
{
  public:
    Test ( int v )
    {
      a = v;
      b = v;
    }

    //int a;
    std::atomic_int32_t a;
    std::atomic_int32_t b;
};


std::mutex mtx;

void ThreadFun ( std::shared_ptr<Test> p )
{
  int c = 10000000;

  while ( c-- )
  {
    //std::lock_guard<std::mutex> lk ( mtx );
    p->a += 1;
    p->b += 2;
  }
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::shared_ptr<Test> p = std::make_shared<Test> ( 0 );
  //std::shared_ptr<Test> p;
  //std::atomic_store ( &p, std::make_shared<Test> ( 0 ) );

  std::thread t1 ( ThreadFun, p );
  std::thread t2 ( ThreadFun, p );

  t1.join();
  t2.join();

  std::cout << "a= " << p->a << " " << "b=" << p->b << std::endl;

  return 0;
}

