
/*
 * =========================================================================
 *
 *       FileName:  sincos.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-10-31 11:47:30
 *  Last Modified:  2018-11-20 08:08:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt ()
 *   Organization:
 *
 * =========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <math.h>


uint16_t sincosTable[512] = { 0 };

typedef struct
{
  int32_t IQAngle;
  int32_t IQSin;
  int32_t IQCos;
} iqSinCos_t;


void  IqSinCosCale ( iqSinCos_t*  pV )
{
  uint16_t hindex = ( uint16_t ) pV->IQAngle;

  hindex >>= 5;

  uint16_t flag = hindex & 0x600;

  hindex &= 0x1FF;

  switch ( flag )
  {
    case 0x000:
      pV->IQSin = sincosTable[ ( uint16_t ) ( hindex )];
      pV->IQCos = sincosTable[ ( uint16_t ) ( 0x1FF - ( uint16_t ) hindex )];
      break;

    case 0x200:
      pV->IQSin = sincosTable[ ( uint16_t ) ( 0x1FF - ( uint16_t ) ( hindex ) )];
      pV->IQCos = -sincosTable[ ( uint16_t ) ( hindex )];
      break;

    case 0x400:
      pV->IQSin = -sincosTable[ ( uint16_t ) ( hindex )];
      pV->IQCos = -sincosTable[ ( uint16_t ) ( 0x1FF - ( uint16_t ) ( hindex ) )];
      break;

    case 0x600:
      pV->IQSin =  -sincosTable[ ( uint16_t ) ( 0x1FF - ( uint16_t ) ( hindex ) )];
      pV->IQCos =  sincosTable[ ( uint16_t ) ( hindex )];
      break;

    default:
      break;
  }
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  for ( int i = 0; i < 512; ++i )
  {
    sincosTable[i] = ( uint16_t ) ( 0x7ffe * sin ( ( 3.1415926 / 2.0 ) * i / 512.0 ) );

    if ( i % 8 == 0 && i != 0 )
      printf ( "\\\n" );

    printf ( "0x%04x, ", sincosTable[i] );
  }

  printf ( "\n" );

  iqSinCos_t a;
  a.IQAngle = 64533;;
  IqSinCosCale ( &a );

  printf ( "IQ=%d\n", a.IQAngle );
  printf ( "Sin=%d\n", a.IQSin );
  printf ( "Cos=%d\n", a.IQCos );

  return 0;
}

