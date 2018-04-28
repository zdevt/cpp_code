/*
 * =====================================================================================
 *
 *       Filename:  boost_lockfree_stack.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年05月21日 16时44分54秒
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
#include <boost/thread/thread.hpp>
#include <boost/lockfree/stack.hpp>
#include <iostream>

#include <boost/atomic.hpp>

//g++ boost_lockfree_stack.cpp -o a -std=c++11 -lboost_thread-mt -lboost_system

boost::atomic_int producer_count ( 0 );
boost::atomic_int consumer_count ( 0 );

boost::lockfree::stack<int> stack ( 128 );


const int iterations = 1000000;
const int producer_thread_count = 4;
const int consumer_thread_count = 4;

void producer ( void )
{
  for ( int i = 0; i != iterations; ++i )
  {
    int value = ++producer_count;

    while ( ! stack.push ( value ) );
  }
}

boost::atomic<bool> done ( false );

void consumer ( void )
{
  int value;

  while ( !done )
  {
    while ( stack.pop ( value ) )
      ++consumer_count;
  }

  while ( stack.pop ( value ) )
    ++consumer_count;
}



int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  using namespace std;
  cout << " ..............";

  if ( !stack.is_lock_free() )
    cout << " not ";

  cout << "lockfree" << endl;
  boost::thread_group producer_threads, consumer_threads;

  for ( int i = 0; i != producer_thread_count; ++i )
    producer_threads.create_thread ( producer );

  for ( int i = 0; i != producer_thread_count; ++i )
    consumer_threads.create_thread ( consumer );

  producer_threads.join_all();
  done = true;
  consumer_threads.join_all();
  cout << " pr = " << producer_count << endl;
  cout << " co = " << consumer_count << endl;
  return 0;
}

