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
#include <iomanip>

using namespace std;

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  uint8_t temp[42] = { 0x1, 0x2, 0x3, 0x5, 0x99};
  uint8_t pDmdHsg[42] = { 0x11, 0x2, 0x3, 0x5, 0x99};

  stringstream sx, sd;

  for ( int j = 0; j < 42; ++j )
  {
    sx << "0x" << std::hex << std::setw ( 2 ) << std::setfill ( '0' ) << ( int ) temp[j] << " ";
    sd << "0x" << std::hex << std::setw ( 2 ) << std::setfill ( '0' ) << ( int ) pDmdHsg[j] << " ";
  }

  cout << sx.str() << endl;
  cout << sd.str() << endl;

  return 0;
}

