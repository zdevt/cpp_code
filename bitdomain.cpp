
/*
 * =========================================================================
 *
 *       FileName:  bitdomain.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-05-22 13:31:47
 *  Last Modified:  2018-05-22 14:01:12
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

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <thread>
#include <mutex>
#include <map>
#include <list>
#include <string>
#include <functional>


//#pragma pack(push)
//#pragma pack(1)
typedef union
{
  uint32_t data;
  struct
  {
    uint32_t a: 12;
    uint32_t b: 20;
    //uint32_t : 8;
  };
} a_t;
//#pragma pack(pop)


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;


  a_t A;

  A.a = 1024;
  A.b = 1024;

  fprintf ( stderr, "%x,%x,%x\n", A.data, A.a, A.b );
  fprintf ( stderr, "sizeof=%ld\n", sizeof ( A ) );



  return 0;
}

