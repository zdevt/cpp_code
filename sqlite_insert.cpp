#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

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

  /* Open database */
  rc = sqlite3_open ( "test.db", &db );

  if ( rc )
  {
    fprintf ( stderr, "Can't open database: %s\n", sqlite3_errmsg ( db ) );
    exit ( 0 );
  }
  else
  {
    fprintf ( stderr, "Opened database successfully\n" );
  }

  #if 0
  sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
        "VALUES (32, 'Paul', 32, 'California', 20000.00 ); ";
  #endif
  sql = "UPDATE COMPANY set SALARY = 28000 where ID = 1;";

  /* Execute SQL statement */
  //rc = sqlite3_exec ( db, sql, callback, 0, &zErrMsg );
  char test[] = "sfsadfasf\n";
  rc = sqlite3_exec ( db, sql, callback, test, &zErrMsg );

  if ( rc != SQLITE_OK )
  {
    fprintf ( stderr, "SQL error: %s\n", zErrMsg );
    sqlite3_free ( zErrMsg );
  }
  else
  {
    fprintf ( stdout, "Records created successfully\n" );
  }

  sqlite3_close ( db );
  return 0;
}

