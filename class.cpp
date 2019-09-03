/*
 * =====================================================================================
 *
 *       Filename:  class.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/02/2017 03:44:36 PM
 *  Last Modified:  2019-09-03 00:17:20
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

#pragma pack(push)
#pragma pack(1)
class A
{
  public:
    void a()
    {
      cout << "a" << endl;
    }
  protected:
    void b()
    {
      cout << "b" << endl;
    }

  public:
    uint8_t m_a;
    uint8_t m_b;
    uint8_t m_c;
    uint32_t m_d;
};

class B : public A
{
  public:
    void ba()
    {
      b();
    }
};

class C
{
  public:
    C()
    {
      a = 1;
      b = 2;
      c = 3;
    }
    void Print()
    {
      //int* p = reinterpret_cast<int*> ( this );
      //printf ( "%d sizeof(C)=%d\n", *p, ( int ) sizeof ( *this ) );
      printf ( "this=%p\n", this );
    }

    int a;
    char b;
    short c;
};
#pragma pack(pop)

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  //A a;
  //a.a();
  //B b;
  //b.ba();

  //fprintf ( stderr, "sizeof A=%d\n", ( int ) sizeof ( a ) );
  //uint8_t* p = reinterpret_cast<uint8_t*> ( &a );
  //memset ( p, 0x55, sizeof ( a ) );
  //fprintf ( stderr, "%02x %02x %02x %04x\n", a.m_a, a.m_b, a.m_c, a.m_d );

  C c;
  c.Print();
  printf ( "instance = %p\n", &c );
  return 0;
}

