
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <sqlite3.h>
#include <string.h>

static int callback ( void* NotUsed, int argc, char** argv, char** azColName )
{
  int i;

  fprintf ( stderr, "callback called\n" );

  for ( i = 0; i < argc; i++ )
  {
    printf ( "%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL" );
  }

  printf ( "\n" );
  return 0;
}

int main ( int argc, char* argv[] )
{
  sqlite3* db;
  char* zErrMsg = 0;
  int rc;
  char* sql;
  sqlite3_stmt* stmt = NULL;

  sqlite3_open ( "test.db", &db );

  #if 0
  //sql = "UPDATE COMPANY set SALARY = 28000 where ID = 1;";
  sql = "create table bList(fileName varchar(16) primary key, binData blob);";
  sqlite3_exec ( db, sql, callback, NULL, &zErrMsg );

  #else
  sql = "insert into bList values ('hex2',?);";
  uint8_t hex[16] = { 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  sqlite3_prepare ( db, sql, -1, &stmt, NULL );
  sqlite3_bind_blob ( stmt, 1, hex, 16, NULL );
  sqlite3_step ( stmt );
  sqlite3_finalize ( stmt );
  #endif

  #if 0
  uint8_t buffer[16] = { 0 };
  char* data = NULL;
  sql = "select binData from bList where fileName='hex';";
  sqlite3_prepare ( db, sql, -1, &stmt, NULL );
  sqlite3_step ( stmt );

  data = ( char* ) sqlite3_column_blob ( stmt, 0 );
  int iLen = sqlite3_column_bytes ( stmt, 0 );
  sqlite3_finalize ( stmt );
  memmove ( buffer, data, iLen );

  for ( auto& c : buffer )
    printf ( "%02x ", c );

  #endif


  sqlite3_close ( db );

  return 0;
}


