
/*
 * =========================================================================
 *
 *       FileName:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-06-01 13:16:43
 *  Last Modified:  2019-09-03 00:17:36
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


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  test();

  return 0;
}

