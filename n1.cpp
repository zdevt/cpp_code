/*
 * =====================================================================================
 *
 *       Filename:  n1.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年10月12日 11时25分57秒
 *  Last Modified:  2017年10月12日 11时25分57秒
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

#include "n1.h"
#include "n2.h"

namespace zt
{
  A::A()
  {
    std::cout << "asdf\n";
  }

  A::~A()
  {

  }
}

int main ( int argc, char* argv[] )
{
  zt::A a;
  zt::B b;

  return 0;
}

