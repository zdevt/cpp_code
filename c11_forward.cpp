
/*
 * =========================================================================
 *
 *       FileName:  c11_forward.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-03-07 17:17:54
 *  Last Modified:  2018-03-07 17:40:11
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

void Fun ( int a )
{
  a += 1;
}

//void Fun ( int& a )
//{
//a += 1;
//}

template <typename A>
void FunA ( A&& a )
{
  Fun ( std::forward<A> ( a ) );
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  int a = 1;

  std::cout << a << std::endl;
  FunA ( a );
  std::cout << a << std::endl;

  return 0;
}

