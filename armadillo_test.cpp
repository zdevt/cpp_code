
/*
 * =========================================================================
 *
 *       FileName:  armadillo_test.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017-12-16 09:08:33
 *  Last Modified:  2017-12-26 21:22:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt ()
 *   Organization:
 *
 * =========================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

#include <armadillo>


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  arma::mat A ( 3, 3, arma::fill::eye );
  A ( 2 ) = 4.5; //delta x
  A ( 5 ) = 5.5; //delta y
  //A.print();

  arma::mat B ( 1, 3, arma::fill::zeros );
  B ( 0 ) = 1;
  B ( 1 ) = 2;
  B ( 2 ) = 1;
  //B.print();

  float theta = 0.5;
  arma::mat C ( 3, 3, arma::fill::eye );
  C ( 0 ) = cos ( theta );
  C ( 1 ) = -1.0 * sin ( theta );
  C ( 3 ) = sin ( theta );
  C ( 4 ) = cos ( theta );

  ( B * A * C ).print();
  ( B * C * A ).print();


  //arma::mat A = arma::randu<arma::mat> ( 5, 5 );
  //arma::mat A ( 3, 3 );
  //arma::mat B;
  //arma::mat C;

  //for ( unsigned long i = 0; i < A.size(); ++i )
  //A ( i ) = i;

  //A.print();
  //std::cout << std::endl;
  //B = A.row ( 1 );
  //C = A.col ( 1 );
  //B.print();
  //C.print();

  return 0;
}

