
/*
 * =========================================================================
 *
 *       FileName:  class_muti_inherit.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-03-08 09:57:51
 *  Last Modified:  2018-03-08 14:13:18
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

class A
{
  public:
    A()
    {
    }
    ~A()
    {
    }

    void FunA()
    {
      std::cout << "FunA" << std::endl;
    }

};

class B
{
  public:
    B()
    {
    }
    ~B()
    {
    }

    void FunB()
    {
      std::cout << "FunB" << std::endl;
    }
};

class C : public A, public B
{
  public:
    C()
    {
    }
    ~C()
    {
    }
    void FunC()
    {
      std::cout << "FunC" << std::endl;
    }
};

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  C c;
  c.FunA();
  c.FunB();
  c.FunC();


  return 0;
}

