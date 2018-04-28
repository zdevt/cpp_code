
/*
 * =========================================================================
 *
 *       FileName:  std_timed_mutex.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-01-17 16:37:39
 *  Last Modified:  2018-01-17 16:39:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt ()
 *   Organization:
 *
 * =========================================================================
 */

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <sstream>

std::mutex cout_mutex; // control access to std::cout
std::timed_mutex mutex;

void job ( int id )
{
  using Ms = std::chrono::milliseconds;
  std::ostringstream stream;

  for ( int i = 0; i < 3; ++i )
  {
    if ( mutex.try_lock_for ( Ms ( 100 ) ) )
    {
      stream << "success ";
      std::this_thread::sleep_for ( Ms ( 100 ) );
      mutex.unlock();
    }
    else
    {
      stream << "failed ";
    }

    std::this_thread::sleep_for ( Ms ( 100 ) );
  }

  std::lock_guard<std::mutex> lock ( cout_mutex );
  std::cout << "[" << id << "] " << stream.str() << "\n";
}

int main()
{
  std::vector<std::thread> threads;

  for ( int i = 0; i < 4; ++i )
    threads.emplace_back ( job, i );

  for ( auto& i : threads )
    i.join();
}
