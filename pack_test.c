





#include <stdio.h>
#include <stdlib.h>

#define	PACKED	__attribute__((__packed__))


struct _test
{
  char b;
  int a;
  short c;
} PACKED;

typedef struct _test test_t;

struct _test1
{
  char b;
  int a;
  short c;
};
typedef struct _test1 test1_t;





int main ( int argc, char* argv[] )
{
  test_t a;
  test1_t b;
  unsigned char* p = NULL;

  a.b = 0xa5;
  a.a = 0x12345678;
  a.c = 0xaa55;

  p = ( unsigned char* ) &a;

  printf ( "0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x \n",
           *p, * ( p + 1 ), * ( p + 2 ), * ( p + 3 ), * ( p + 4 ), * ( p + 5 ), * ( p + 6 ) );

  printf ( "test_t %d\n", sizeof ( test_t ) );
  printf ( "test1_t %d\n", sizeof ( test1_t ) );



  return 0;
}


