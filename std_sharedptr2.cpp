/*
 * =====================================================================================
 *
 *       Filename:  shareptr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年04月06日 22时13分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory>

class A
{
  public:
    A ( std::string a )
      : m_str ( a )
    {
      fprintf ( stderr, "A construct %s\n", m_str.c_str() );
    }

    ~A()
    {
      fprintf ( stderr, "A destruct %s\n", m_str.c_str() );
    }

    static std::shared_ptr<A> GetObj ( std::string a )
    {
      return std::make_shared<A> ( a );
    }

    std::string m_str;
};

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  std::shared_ptr<A> a = A::GetObj ( "fuck" );

  a =  A::GetObj ( "cao" );

  //while ( 1 );

  return 0;
}

