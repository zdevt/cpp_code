/*
 * =====================================================================================
 *
 *       Filename:  fstream.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月16日 10时13分53秒
 *  Last Modified:  2019-09-03 00:04:35
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

#include <fstream>

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::ofstream ofs ( "a.bin", std::ios::binary );

  if ( !ofs )
    return -1;

  ofs.close();
  return 0;
}

