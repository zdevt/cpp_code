/*
 * =====================================================================================
 *
 *       Filename:  inet_addr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/12/2017 10:38:07 AM
 *  Last Modified:  2018-01-08 08:26:16
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

#include <netinet/in.h>
#include <arpa/inet.h>


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  uint32_t s1 = ( uint16_t ) ( inet_addr ( "172.16.129.252" ) >> 16 );
  uint32_t s2 = ( uint16_t ) ( inet_addr ( "172.16.129.25" ) >> 16 );

  printf ( "%04x %04x\n", s1, s2 );

  return 0;
}

