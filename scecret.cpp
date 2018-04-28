/*
 * =====================================================================================
 *
 *       Filename:  scecret.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年04月27日 08时59分48秒
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

#define XOR_MASK 	(0xa0)
#define XOR_MASK2 (0x05)

void decEnc ( unsigned char* data, unsigned int len )
{
  unsigned char* p = data;

  for ( unsigned int i = 0; i < len; i++ )
  {
    * ( p + i ) = * ( p + i ) ^ ( 0xa0 );
    * ( p + i ) = * ( p + i ) ^ ( 0x05 );
  }
}

int main ( int argc, char* argv[] )
{
  unsigned char buffer[10] = { 1, 3, 2, 6, 7, 0x11, 0x22, 0x44, 0x67, 0xf0};

  for ( int i = 0; i < 10 ; ++i )
    printf ( "%02x ", buffer[i] );

  printf ( "\n" );

  decEnc ( buffer, 10 );

  for ( int i = 0; i < 10 ; ++i )
    printf ( "%02x ", buffer[i] );

  printf ( "\n" );

  decEnc ( buffer, 10 );

  for ( int i = 0; i < 10 ; ++i )
    printf ( "%02x ", buffer[i] );

  printf ( "\n" );
  return 0;
}

