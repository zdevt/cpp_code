/*
 * =====================================================================================
 *
 *       Filename:  StableSort.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年03月02日 16时10分11秒
 *  Last Modified:  2017-11-23 10:50:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>


bool compare_as_ints ( double i, double j )
{
  return ( int ( i ) < int ( j ) );
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  double mydoubles[] =
  { 3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58};

  std::vector<double> myvector;
  myvector.assign ( mydoubles, mydoubles + sizeof ( double ) );

  std::stable_sort ( myvector.begin(), myvector.end() );

  for ( auto& ele : myvector )
    std::cout << ' ' << ele;

  std::cout << std::endl;


  return 0;
}



