/*
 * =====================================================================================
 *
 *       Filename:  cppPython.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/26/2017 05:01:58 PM
 *  Last Modified:  2018-01-08 08:19:21
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
#include <python2.7/Python.h>
#include <iostream>

//g++ cppPython.cpp -o a  -lpython2.7

void HelloWorld()
{
  Py_Initialize();
  PyObject* pModule = NULL;
  PyObject* pFunc = NULL;
  pModule = PyImport_ImportModule ( "test" );

  if ( pModule )
    pFunc = PyObject_GetAttrString ( pModule, "hello" );
  else
    std::cout << "pModule " << pModule << std::endl;

  if ( pFunc )
    PyEval_CallObject ( pFunc, NULL );
  else
    std::cout << "pFunc " << pFunc << std::endl;

  Py_Finalize();
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  HelloWorld();

  return 0;
}

