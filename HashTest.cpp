/*
 * =====================================================================================
 *
 *       Filename:  HashTest.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月16日 11时10分48秒
 *  Last Modified:  2015年09月16日 11时10分48秒
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

unsigned int cryptTable[0x500];

void PrepareCryptTable()
{
  unsigned int seed = 0x00100001;
  unsigned int index1 = 0;
  unsigned int index2 = 0;
  unsigned int i = 0;

  for ( index1 = 0; index1 < 0x100; ++index1 )
  {
    for ( index2 = index1, i = 0; i < 5; ++i, index2 += 0x100 )
    {
      unsigned int temp1, temp2;
      seed = ( seed * 125 + 3 ) % 0x2aaab;
      temp1 = ( seed & 0xffff ) << 0x10;

      seed = ( seed * 125 + 3 ) % 0x2aaab;
      temp2 = ( seed & 0xffff );
      cryptTable[index2] = ( temp1 | temp2 );
    }
  }
}

int main ( int argc, char* argv[] )
{
  PrepareCryptTable();

  for ( auto ele : cryptTable )
    printf ( "0x%x ", ele );

  return 0;
}

