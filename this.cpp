/*
 * =====================================================================================
 *
 *       Filename:  this.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/18/2017 03:37:36 PM
 *  Last Modified:  09/18/2017 03:37:36 PM
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
  public:
    Test();
    ~Test();

  public:
    void a()
    {
      printf ( "test\n" );
    }

    static void aa()
    {
      this->a();
    }

};


int main ( int argc, char* argv[] )
{



  return 0;
}

