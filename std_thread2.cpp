/*
 * =====================================================================================
 *
 *       Filename:  Thread2.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年09月22日 22时25分28秒
 *  Last Modified:  2018-03-16 11:18:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

typedef std::atomic<int> amc_int_t;

amc_int_t global_counter ( 0 );

void increase_global ( int n )
{
  for ( int i = 0; i < n; ++i )
    ++global_counter;
}

void increase_reference ( amc_int_t& val, int n )
{
  for ( int i = 0; i < n; ++i )
    ++val;
}

class C : public amc_int_t
{
  public:
    C() : amc_int_t ( 0 )
    {

    }

    void increase_member ( int n )
    {
      for ( int i = 0; i < n; ++i )
        fetch_add ( 1 );
    }

};

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::vector<std::thread> threads;
  std::cout << ".........\n";

  for ( int i = 1; i <= 50000; ++i )
    threads.push_back ( std::thread ( increase_global, 1000 ) );

  for ( auto& ele : threads )
    ele.join();

  std::cout << "global: " << global_counter << std::endl;

  return 0;
}

