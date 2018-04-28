/*
 * =====================================================================================
 *
 *       Filename:  test.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年03月31日 15时40分08秒
 *  Last Modified:  2016年03月31日 15时40分08秒
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
#include <iterator>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <complex>
#include <future>

#include <unistd.h>



typedef std::complex<double> cplx_t;
typedef std::vector<cplx_t> vecomplex_t;

cplx_t cplx_tMiddle;


vecomplex_t vecomplex =
{
  { 1.1, 1.11},
  { 2.1, 2.22},
  { 3.1, 3.33},
  { 4.1, 4.44},
  { 3.5, 3.66},
  { 2.4, 2.55},
  { 1.3, 1.44},
  { 1.7, 1.33},
  { 4.7, 1.33},
  { 1.7, 5.33},
};

void GetMiddlePoint ( vecomplex_t& vecomplex, cplx_t& cplx )
{
  double re = 0;
  double im = 0;

  for ( auto& ele : vecomplex )
  {
    re += ele.real();
    im += ele.imag();
  }

  re /= vecomplex.size();
  im /= vecomplex.size();

  cplx = cplx_t ( re, im );
}


bool SortComp ( cplx_t& a, cplx_t& b )
{
  double argA = std::arg ( a - cplx_tMiddle );
  double argB = std::arg ( b - cplx_tMiddle );

  if ( std::abs ( argA - argB ) < 0.001 )
    return ( std::abs ( a - cplx_tMiddle ) > std::abs ( b - cplx_tMiddle ) );

  return ( argA > argB );
}

void Hanoi ( int diskNo, char from, char des, char temp )
{
  static int cnt = 0;

  if ( diskNo > 0 )
  {
    Hanoi ( diskNo - 1, from, temp, des );
    std::cout << "move disk " << diskNo << " form " << from << " to " << des << std::endl;
    Hanoi ( diskNo - 1, temp, des, from );
  }
}



int main ( int argc, char* argv[] )
{
  #if 0
  GetMiddlePoint ( vecomplex, cplx_tMiddle );
  std::sort ( vecomplex.begin(), vecomplex.end(), SortComp );

  //std::cout << cplx_tMiddle.real() << " " << cplx_tMiddle.imag() << std::endl;

  for ( auto& ele : vecomplex )
    std::cout << ele.real() << " " << ele.imag() << " " << std::abs ( ele ) << " " << std::arg ( ele ) << std::endl;

  #endif

  Hanoi ( 3, 'A', 'B', 'C' );

  return 0;
}


