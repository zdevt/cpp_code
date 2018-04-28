/*
 * =====================================================================================
 *
 *       Filename:  virtualTable.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/31/2017 10:16:22 AM
 *  Last Modified:  08/31/2017 10:16:22 AM
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

using namespace std;


class Base
{
  private:
    virtual void f()
    {
      cout << "Base::f" << endl;
    }

    virtual void g()
    {
      cout << "Base::g" << endl;
    }

    virtual void h()
    {
      cout << "Base::h" << endl;
    }
};

typedef void ( *Fun ) ( void );




int main ( int argc, char* argv[] )
{
  Base b;
  Fun pFun = NULL;

  cout << "virtual table addr:" << ( int* ) &b << endl;
  cout << "virtual table -first fun addr:" << ( int* ) * ( int* ) ( &b ) << endl;

  //pFun = ( Fun ) * ( ( int* ) ( * ( int* ) ( &b ) ) );
  pFun = ( Fun ) * ( int* ) ( * ( int* ) ( &b ) );
  pFun();

  pFun = ( Fun ) * ( ( int* ) ( * ( int* ) ( &b ) ) + sizeof ( Fun ) / sizeof ( int ) );
  pFun();

  return 0;
}

