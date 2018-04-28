/*
 * =====================================================================================
 *
 *       Filename:  forstr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年09月17日 15时27分42秒
 *  Last Modified:  2017-12-31 12:16:14
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

#include <string.h>

#include <string>

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::string str = "1233444";
  char a[] = "1233444";

  for ( auto ele : str )
    printf ( "%c ", ele );

  printf ( " size = %ld \n", str.size() );
  printf ( "strlen = %ld\n", strlen ( str.c_str() ) );
  printf ( "strlen = %ld\n", sizeof ( str.c_str() ) );
  printf ( "strlen a = %ld\n", strlen ( a ) );
  printf ( "strlen a = %ld\n", sizeof ( a ) );


  return 0;
}

