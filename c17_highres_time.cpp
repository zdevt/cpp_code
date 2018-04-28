
/*
 * =========================================================================
 *
 *       FileName:  c11_highres_time.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-25 11:18:01
 *  Last Modified:  2018-01-25 11:19:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt ()
 *   Organization:
 *
 * =========================================================================
 */

#include <iostream>
#include <chrono>
#include <thread>

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  using namespace std::chrono_literals;
  std::cout << "Hello waiter" << std::endl; // flush is intentional
  auto start = std::chrono::high_resolution_clock::now();
  std::this_thread::sleep_for ( 2s );
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end - start;
  std::cout << "Waited " << elapsed.count() << " ms\n";
}

