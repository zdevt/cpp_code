/*
 * =====================================================================================
 *
 *       Filename:  sqlite3.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/13/2017 03:07:51 PM
 *  Last Modified:  09/13/2017 03:07:51 PM
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
#include <sqlite3.h>

static int callback ( void* NotUsed, int argc, char** argv, char** azColName )
{
  int i = 0;

  for ( i = 0; i < argc; ++i )
  {
    printf ( "%s=%s\n", azColName[i], argv[i] ? argv[i] : "NULL" );
  }

  printf ( "\n" );

  return 0;
}


int main ( int argc, char* argv[] )
{
  sqlite3* db = NULL;
  char* zErrMsg = 0;
  int rc;

  rc = sqlite3_open ( "test.db", &db );

  if ( rc )
  {
    fprintf ( stderr, "cant't open database: %s\n", sqlite3_errmsg ( db ) );
    exit ( 0 );
  }
  else
  {
    fprintf ( stdout, "open ok\n" );
  }

  char sql[] = "CREATE TABLE COMPANY("\
               "ID INT PRIMARY KEY NOT NULL,"\
               "NAME TEXT NOT NULL,"\
               "AGE INT NOT NULL,"\
               "ADDRESS CHAR(50),"\
               "SALARY REAL);";

  rc = sqlite3_exec ( db, sql, callback, 0, &zErrMsg );

  if ( rc != SQLITE_OK )
  {
    fprintf ( stderr, "SQL error:%s\n", zErrMsg );
    sqlite3_free ( zErrMsg );
  }
  else
  {
    fprintf ( stdout, "ok!!!\n" );
  }

  sqlite3_close ( db );

  return 0;
}

