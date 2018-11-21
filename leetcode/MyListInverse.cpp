
/*
 * =========================================================================
 *
 *       FileName:  l.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-11-21 09:42:30
 *  Last Modified:  2018-11-21 09:54:49
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
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <thread>
#include <mutex>
#include <map>
#include <list>
#include <string>
#include <functional>

using namespace std;

class MyList
{
  public:
    MyList ( int v )
    {
      val = v;
      next = NULL;
    }

    MyList ( int v, MyList* n )
    {
      val = v;
      next = n;
    }

    ~MyList()
    {
    }

    int val;
    MyList* next;
};

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  MyList* head = new MyList ( 100 );
  MyList* p = head;

  for ( int i = 0; i < 5; ++i )
  {
    p->next = new MyList ( i );
    p = p->next;
  }

  for ( auto i = head; i != NULL; i = i->next )
    cout << "i=" << i->val << " ";

  cout << endl;

  MyList* l = head;
  MyList* ln = l->next;
  MyList* lnn = NULL;
  l->next = NULL;

  while ( ln )
  {
    lnn = ln->next;
    ln->next = l;

    l = ln;
    ln = lnn;
  }

  for ( auto i = l; i != NULL; i = i->next )
    cout << "i=" << i->val << " ";

  cout << endl;

  return 0;
}

