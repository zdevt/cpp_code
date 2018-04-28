/*
 * =====================================================================================
 *
 *       Filename:  Thread2.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年09月22日 22时25分28秒
 *  Last Modified:  2017-12-28 14:46:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <unistd.h>

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

#include <sys/prctl.h>

class Test5
{
  public:
    Test5()
    {
      std::thread ( &Test5::output, this ).detach();
    }

    void output()
    {
      prctl ( PR_SET_NAME, "adfadf" );

      while ( 1 )
      {
        std::cout << "asdf \n";
        sleep ( 1 );
      }
    }
};


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  Test5 test5;

  while ( 1 )
  {
    sleep ( 1 );
  }

  return 0;
}

