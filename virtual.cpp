/*
 * =====================================================================================
 *
 *       Filename:  virtual.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/19/2015 04:30:08 AM EST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *        Company:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class A
{
  public:
    A()
    {
    }
    virtual ~A()
    {
    }

  private:
    virtual void Test ( const char* p ) = 0;

  public:
    void Test2()
    {
      Test ( "asdf" );
    }

  private:
};

class B : public A
{
  public:
    B()
    {
    }
    virtual ~B()
    {
    }

  private:
    virtual void Test ( const char* p )
    {
      fprintf ( stderr, "B: %s\n", p );
    }

};

class C : public A
{
  public:
    C()
    {
    }
    virtual ~C()
    {
    }

  private:
    virtual void Test ( const char* p )
    {
      fprintf ( stderr, "C: %s\n", p );
    }

};


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  A* ac = new C;
  A* ab = new B;

  ac->Test2();
  ab->Test2();

  return 0;
}


