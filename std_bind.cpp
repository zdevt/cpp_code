
/*
 * =========================================================================
 *
 *       FileName:  std_bind.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-19 13:53:26
 *  Last Modified:  2018-01-19 14:21:47
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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <vector>
#include <map>


void func ( int x, int y )
{
  std::cout << x << " " << y << std::endl;
}

void mytest()
{
  func ( 1, 2 );

  std::bind ( func, 11, 12 ) ();
  std::bind ( func, std::placeholders::_1, 22 ) ( 21 );

  // std::placeholders 表示的是占位符
  // std::placeholders::_1是一个占位符，代表这个位置将在函数调用时，被传入的第一个参数所替代。
  std::bind ( func, 32, std::placeholders::_1 ) ( 31 );
  std::bind ( func, 42, std::placeholders::_2 ) ( 41, 42 );
  std::bind ( func, std::placeholders::_1, std::placeholders::_2 ) ( 51, 52 );
  std::bind ( func, std::placeholders::_3, std::placeholders::_2 ) ( 61, 62, 63 );

  //std::bind(func, 2, std::placeholders::_2)(1); // err, 调用时没有第二个参数

  return;
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  mytest();

  sleep ( 1 );

  return 0;
}

