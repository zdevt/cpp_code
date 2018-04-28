/*
 * =====================================================================================
 *
 *       Filename:  sstream.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2015年04月06日 14时41分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <iostream>

using namespace std;

template<typename T>
void Test ( T a )
{
  fprintf ( stderr, "sizeof t=%d\n", sizeof ( T ) );
}

int main ( int argc, char* argv[] )
{
  string s = "21 0x10 0x40 0x5";
  stringstream ss ( s );
  cout << ss.str() << endl;

  unsigned int a, b, c;
  ss >> std::hex >> a >> b >> c;

  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  #if 0
  string s = "ccca 1 22 333";
  std::stringstream ss ( s );
  string str;

  ss >> str;
  cout << str << endl;

  ss >> str;
  cout << str << endl;

  ss >> str;
  cout << str << endl;

  ss >> str;
  cout << str << endl;

  unsigned i;
  sscanf ( "0x11122", "%x", &i );
  fprintf ( stderr, "%x\n", i );
  #endif

  return 0;
}

