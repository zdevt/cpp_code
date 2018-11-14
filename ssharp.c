
/*
 * =========================================================================
 *
 *       FileName:  ssharp.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-07-15 18:59:24
 *  Last Modified:  2018-07-15 19:01:33
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

#define WTF(x) 1##x

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  printf ( "%d\n", 2 * WTF ( 3 ) );

  return 0;
}

