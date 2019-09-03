/*
 * =====================================================================================
 *
 *       Filename:  glog.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/29/2017 02:11:47 PM
 *  Last Modified:  2019-09-03 00:21:58
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
#include <glog/logging.h>

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  google::InitGoogleLogging ( ( const char* ) argv[0] );
  google::SetLogDestination ( google::GLOG_INFO, "./a.log" );

  LOG ( WARNING ) << "thiasdfasf";

  return 0;
}


