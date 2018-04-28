/*
 * =====================================================================================
 *
 *       Filename:  MapSharedPtr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/04/2017 04:42:27 PM
 *  Last Modified:  2018-01-08 08:18:53
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
#include <memory>
#include <map>


class A
{
  public:
    A()
    {
      std::cout << "construct A" << std::endl;
    }

    ~A()
    {
      std::cout << "deconstruct A" << std::endl;
    }

  public:
    virtual void test()
    {
      std::cout << "A test" << std::endl;
    }

};

class B : public A
{
  public:
    B()
    {
      std::cout << "construct B" << std::endl;
    }

    ~B()
    {
      std::cout << "deconstruct B" << std::endl;
    }


  public:
    virtual void test()
    {
      std::cout << "A B test" << std::endl;
    }
};


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::map<int, std::shared_ptr<A> > a;
  a.insert ( std::pair<int, std::shared_ptr<A> > ( 1, std::make_shared<A>() ) );
  //a.insert ( std::pair<int, std::shared_ptr<A> > ( 2, std::make_shared<B>() ) );
  a.insert ( {2, std::make_shared<B>() } );

  a.erase ( 2 );

  sleep ( 3 );

  return 0;
}


