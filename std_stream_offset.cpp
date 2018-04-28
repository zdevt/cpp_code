/*
 * =====================================================================================
 *
 *       Filename:  stream_offset.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年11月18日 15时53分46秒
 *  Last Modified:  2015年11月18日 15时53分46秒
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


char buffer[1024] = { 0 };

int main ( int argc, char* argv[] )
{
  std::ifstream ifs ( "a.bin", std::ifstream::binary );

  ifs.seekg ( 0x10, ifs.beg );
  ifs.read ( buffer, 0x10 );

  for ( int i = 0; i < 0x10; ++i )
  {
    printf ( "%2x ", buffer[i] );
  }

  return 0;
}

