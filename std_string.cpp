/*
 * =====================================================================================
 *
 *       Filename:  String.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年03月02日 16时25分04秒
 *  Last Modified:  2018-11-02 13:54:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  std::string str = "FILENAMEJKLMNOPQskkk";

  std::size_t fd = str.find ( "Q" );
  std::size_t rfd = str.rfind ( "Q" );

  printf ( "fd=%ld rfd=%ld sz=%ld\n", fd, rfd, str.size() );
  str.erase(fd); 
  std::cout<<str<<std::endl;

  #if 0

  //str.replace ( str.find ( "sssa" ), strlen ( "sssa" ), "kkk" );
  for ( auto iter = str.rbegin(); iter != str.rend(); ++iter )
    std::cout << *iter;

  std::cout << std::endl;

  for ( auto& ele : str )
    std::cout << ele;

  std::cout << std::endl;

  std::ifstream file ( "a.txt", std::ios::in );

  if ( file )
  {
    while ( !file.eof() )
      str.push_back ( file.get() );
  }

  std::cout << str << std::endl;
  #endif

  return 0;
}

