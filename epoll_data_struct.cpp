/*
 * =====================================================================================
 *
 *       Filename:  epoll_data_struct.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/01/2017 09:08:51 AM
 *  Last Modified:  09/01/2017 09:08:51 AM
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

#include <sys/epoll.h>


int main ( int argc, char* argv[] )
{
  epoll_data_t e;
  e.ptr = ( void* ) 0x12345678;
  e.fd = 0x33333333;

  printf ( "sizeof = %d\n", sizeof ( e ) );
  printf ( "0x%x 0x%x\n", e.ptr, e.fd );
  printf ( "0x%x 0x%x\n", e.u32, e.u64 );

  return 0;
}

