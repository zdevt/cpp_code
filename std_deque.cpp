/*
 * =====================================================================================
 *
 *       Filename:  Deque.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年01月28日 09时47分08秒
 *  Last Modified:  2016年01月28日 09时47分08秒
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

#include <iostream>
#include <deque>


int main ( int argc, char* argv[] )
{
  std::deque<int> deq;

  deq.push_front ( 10 );
  deq.push_front ( 11 );
  deq.push_front ( 13 );

  deq.push_back ( 1 );
  deq.push_back ( 3 );

  for ( auto& ele : deq )
  {
    fprintf ( stderr, "%d \n", ele );
  }

  return 0;
}


