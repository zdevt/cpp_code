/*
 * =====================================================================================
 *
 *       Filename:  bridge.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/20/2014 02:51:18 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *        Company:
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <memory>
#include <assert.h>
#include <boost/smart_ptr.hpp>
using namespace boost;

class A
{
  private:
    class B;
    std::shared_ptr<B> p;

  public:
    A();
    void test();
};

class A::B
{
  public:
    void test()
    {
      fprintf ( stderr, "test A::B\n" );
    }
};


A::A()
  : p ( std::make_shared<B>() )
{
}

void A::test()
{
  p->test();
}


int main ( int argc, char* argv[] )
{
  (void)argc;
  (void)argv;

  A a;
  a.test();

  return 0;
}

