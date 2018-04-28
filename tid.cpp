
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>

static pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
static int i = 0;

long int gettid()
{
  return syscall ( SYS_gettid );
}

void* fun1 ( void* p )
{
  while ( 1 )
  {
    pthread_mutex_lock ( &g_mutex );
    fprintf ( stderr, "tid=%lu i=%d\n", gettid(), ++i );
    pthread_mutex_unlock ( &g_mutex );
    sleep ( 1 );
  }
}

void* fun2 ( void* p )
{
  while ( 1 )
  {
    pthread_mutex_lock ( &g_mutex );
    fprintf ( stderr, "tid=%lu i=%d\n", gettid(), ++i );
    pthread_mutex_unlock ( &g_mutex );
    sleep ( 3 );
  }
}

int main ( int argc, char* argv[] )
{
  #if 1
  pthread_t tid;
  pthread_create ( &tid, NULL, fun1, NULL );
  pthread_create ( &tid, NULL, fun2, NULL );
  #endif

  while ( 1 )
    sleep ( 1 );

  return 0;
}

