
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


char* l_opt_test = NULL;
char* const short_options = "abcd:";

struct option long_opts[] =
{
  {"atest",	0,	NULL,	'a'	},
  {"btest",	0,	NULL,	'b'	},
  {"ctest",	0,	NULL,	'c'	},
  {	0,			0,	0,		0		},
};


int parse_opt ( int argc, char* argv[] )
{
  int c = 0;

  while ( ( c = getopt_long ( argc, argv, short_options, long_opts, NULL ) ) != -1 )
  {
    switch ( c )
    {
      case 'a':
        printf ( "This is atest\n" );
        break;

      case 'b':
        printf ( "This is btest\n" );
        break;

      case 'c':
        printf ( "This is ctest\n" );
        break;

      default:
        printf ( "arg error!\n" );
        return -1;
    }
  }

  return 0;
}



int main ( int argc, char* argv[] )
{
  parse_opt ( argc, argv );
  return 0;
}
