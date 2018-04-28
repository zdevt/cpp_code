/*
 * =====================================================================================
 *
 *       Filename:  acl.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/09/2017 03:15:55 PM
 *  Last Modified:  2017-11-27 19:47:45
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
#include <iostream>

#include "acl_cpp/lib_acl.hpp"

static void test_redis_string ( acl::redis& cmd, const char* key )
{
  acl::string val ( "test_value" );

  // call redis-server: SET key value
  if ( cmd.set ( key, val.c_str() ) == false )
  {
    printf ( "redis set error\r\n" );
    return;
  }

  // clear the string buf space
  val.clear();

  // reset the redis command object for reusing it
  cmd.clear();

  // call redis-server: GET key
  if ( cmd.get ( key, val ) == false )
    printf ( "get key error\r\n" );
}

static void test_redis_key ( acl::redis& cmd, const char* key )
{
  if ( cmd.exists ( key ) == false )
    printf ( "key not exists\r\n" );
  else
    printf ( "key exists\r\n" );
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  acl::acl_cpp_init();

  const char* redis_addr = "127.0.0.1:6379";
  int conn_timeout = 10, rw_timeout = 10, max_conns = 100;

  acl::redis_client_cluster cluster;
  cluster.set ( redis_addr, max_conns, conn_timeout, rw_timeout );

  acl::redis cmd;

  cmd.set_cluster ( &cluster, max_conns );

  const char* key = "test_key1";

  test_redis_string ( cmd, key );
  test_redis_key ( cmd, key );

  return 0;
}

