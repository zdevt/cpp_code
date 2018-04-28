/*
 * =====================================================================================
 *
 *       Filename:  state.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年08月08日 08时48分35秒
 *  Last Modified:  2018-01-17 16:51:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdio.h>

typedef unsigned char State;
typedef State ( *Procedure ) ( void* );

enum states
{
  s_init,
  s_count,
  s_done,
  s_default,
};

typedef struct
{
  int cnt;
} SM_VAR;

State step_init ( void* arg )
{
  SM_VAR* p = ( SM_VAR* ) arg;
  p->cnt = 0;
  printf ( "CS:init; cnt=%d; NS:count\n", p->cnt );
  return s_count;
}

State step_count ( void* arg )
{
  SM_VAR* p = ( SM_VAR* ) arg;

  if ( p->cnt < 3 )
  {
    p->cnt += 1;
    printf ( "CS:count; cnt=%d; NS:count\n", p->cnt );
    return s_count;
  }
  else
  {
    printf ( "CS:count; cnt=%d; NS:done\n", p->cnt );
    return s_done;
  }
}

State step_done ( void* arg )
{
  SM_VAR* p = ( SM_VAR* ) arg;
  printf ( "CS:init; cnt=%d; NS:init\n", p->cnt );
  return s_init;
}

State step_default ( void* arg )
{
  ( void ) arg;
  //SM_VAR* p = ( SM_VAR* ) arg;
  printf ( "Wrong State\n" );
  return s_init;
}

Procedure Steps[] =
{
  step_init,
  step_count,
  step_done,
  step_default,
};

void BestStateMachine ( void* invar )
{
  static State NS = s_init;
  NS = Steps[NS] ( invar );
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  SM_VAR var;

  int i;

  for ( i = 0 ; i < 8; ++i )
  {
    BestStateMachine ( &var );
  }

  return 0;
}


