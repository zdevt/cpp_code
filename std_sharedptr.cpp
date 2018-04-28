/*
 * =====================================================================================
 *
 *       Filename:  shared_ptr_std.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/20/2014 02:57:08 AM EST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *        Company:
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory>


class A
{
  public:
    A()
    {
      printf ( "A\n" );
    };
    ~A()
    {
      printf ( "~A\n" );
    }

    void Test ( void )
    {
      printf ( "aaaaaaaa\n" );
    }
};


std::shared_ptr<int> GetIntPtr()
{
  return std::make_shared<int> ( 5 );
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::shared_ptr<int> sp ( new int[32], [] ( int* p )
  {
    delete p;
  } );

  int* p = sp.get();

  for ( auto i = 0; i < 32; i++ )
  {
    p[i] = i;
  }

  for ( auto i = 0; i < 32; i++ )
  {
    printf ( "%d ", * ( p++ ) );
  }

  printf ( "\n" );


  {
    std::shared_ptr<A> sa = std::make_shared<A>();
    sa->Test();

    sa.get()->Test();
  }


  printf ( "test\n" );

  int* pI = GetIntPtr().get();
  printf ( "*pI=%d\n", *pI );

  return 0;
}

