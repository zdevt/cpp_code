/*
 * =====================================================================================
 *
 *       Filename:  sstream.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年04月06日 14时41分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>

using namespace std;

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  uint8_t aa[42] = { 0x1, 0x2, 0x3, 0x5, 0x99};

  stringstream sa;

  for ( int i = 0; i < 42; ++i )
    sa << std::hex << ( int ) aa[i] << " ";

  cout << sa.str() << endl;

  return 0;
}

