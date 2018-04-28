
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/prctl.h>
#include <stdarg.h>

int set_thread_name ( const char* fmt, ... )
{
  char name[16] = {0};
  va_list ap;
  va_start ( ap, fmt );
  vsnprintf ( name, sizeof ( name ), fmt, ap );
  va_end ( ap );
  return prctl ( PR_SET_NAME, name );
}



void* thread_name_test ( void* p )
{

  set_thread_name ( "MyThreadTest" );

  while ( 1 )
  {
    usleep ( 5 );
    //printf("This is a test!\n");
  }

  return 0;
}


void* thread_name_test2 ( void* p )
{
  set_thread_name ( "MyThreadTest2" );

  while ( 1 )
  {
    usleep ( 1 );
  }

  return 0;
}




int main ( int argc, char* argv[] )
{
  pthread_t pid;
  pthread_t pid2;


  pthread_create ( &pid, NULL, thread_name_test, NULL );
  pthread_create ( &pid2, NULL, thread_name_test2, NULL );



  while ( 1 )
  {
    sleep ( 10 );
  }

  return 0;
}
