/*
 * =====================================================================================
 *
 *       Filename:  bit.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2016年03月16日 15时06分33秒
 *  Last Modified:  2016年03月16日 15时06分33秒
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
#include <vector>

unsigned char test[] =
{
  0xaa, 0xaa, 0xaa, 0xaa, 0x6a,
  0xaa, 0xaa, 0xaa, 0xaa, 0x7a,
  0xaa, 0xaa, 0xaa, 0xaa, 0x8a,
  0xaa, 0xaa, 0xaa, 0xaa, 0x9a,
};

unsigned char test2[128] = { 0 };


int BitSet ( unsigned char* data, int pos, unsigned char bitval )
{
  if ( bitval )
    data[pos / 8] |= ( 1 << ( pos % 8 ) );
  else
    data[pos / 8] &= ~ ( 1 << ( pos % 8 ) );

  return 0;
}


int BitBit ( unsigned char* input, unsigned char* output, int linecnt, int lineBit, int validLineBit )
{
  for ( int i = 0; i < linecnt; ++i )
  {
    for ( int j = 0; j < validLineBit; ++j )
      BitSet ( output, validLineBit * i + j,  input[ i * ( lineBit / 8 ) + j / 8 ] & ( 1 << ( j % 8 ) ) );
  }

  return 0;
}


int main ( int argc, char* argv[] )
{
  for ( int i = 0; i < 20; ++i )
  {
    if ( ! ( i % 0x5 ) && i )
      printf ( "\n" );

    printf ( "%02x ", test[i] );
  }

  printf ( "\n" );

  printf ( "\n" );

  //BitSet ( test, 17, 0 );
  BitBit ( test, test2, 4, 40, 36 );

  for ( int i = 0; i < 20; ++i )
  {
    if ( ! ( i % 0x5 ) && i )
      printf ( "\n" );

    printf ( "%02x ", test2[i] );
  }

  printf ( "\n" );

  return 0;
}

