
/*
 * =========================================================================
 *
 *       FileName:  my_list_test.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018-07-05 11:42:15
 *  Last Modified:  2018-07-05 13:17:35
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


class Node
{
  public:
    Node ( int v )
    {
      a = v;
      next = NULL;
    }
    ~Node() {}

    Node* next;
    int a;
};

Node* Reverse ( Node* head )
{
  if ( !head )
    return NULL;

  if ( !head->next )
    return head;

  Node* pre = head;
  Node* cur = head->next;
  Node* next = NULL;

  pre->next = NULL;

  do
  {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  while ( cur->next );

  cur->next = pre;

  return cur;
}


int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;

  Node* p = NULL;
  p = new Node ( 0 );
  Node* head = p;

  for ( int i = 1; i < 10; ++i )
  {
    p->next = new Node ( i );
    p = p->next;
  }

  p->next = NULL;

  p = head;

  do
  {
    printf ( "%d ", p->a );
    p = p->next;
  }
  while ( p != NULL );

  printf ( "\n" );

  Node* r = Reverse ( head );

  p = r;

  do
  {
    printf ( "%d ", p->a );
    p = p->next;
  }
  while ( p != NULL );


  return 0;
}

