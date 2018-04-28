/*
 * =====================================================================================
 *
 *       Filename:  SigleInstance.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月24日 10时30分58秒
 *  Last Modified:  2018-03-09 08:20:23
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


class Test
{
  private:
    Test()
    {
      printf ( "Test() %p\n", this );
    }

    ~Test()
    {
      printf ( "~Test() %p\n", this );
    }

  public:
    static Test* Get()
    {
      static Test test;
      return &test;
    }

  public:
    void Show()
    {
      printf ( "%p\n", this );
    }
};


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  Test* a = Test::Get();
  a->Show();

  return 0;
}

