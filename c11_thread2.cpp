/*
 * =====================================================================================
 *
 *       Filename:  thread_c11.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/10/2014 06:49:19 PM CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (),
 *        Company:
 *
 * =====================================================================================
 */

#include <iostream>
#include <thread>

using namespace std;

void foo()
{
  cout << "foo!!!!!!!!!" << endl;
}


void bar ( int x )
{
  cout << "bar  " << x << endl;
}



int main ( int argc, char* argv[] )
{

  thread first ( foo );
  thread second ( bar, 0 );


  cout << "main thread" << endl;


  first.join();
  second.join();


  cout << "all completed\n";

  return 0;
}




