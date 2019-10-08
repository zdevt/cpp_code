
#include <stdio.h>
#include <stdlib.h>

#include "test.h"
#include "ikcp.c"
#include "UdpSocket.cpp"

UdpSocket* pls1 = NULL;
UdpSocket* pls2 = NULL;

void printbuff ( uint8_t* buf, int len )
{
  printf ( "____________________\n" );

  for ( int i = 0 ; i < len; ++i )
  {
    if ( i % 0x10 == 0 && i != 0 )
      printf ( "\n" );

    printf ( "0x%02x ", buf[i] );
  }

  printf ( "\n____________________\n" );
}

int udp_output_zt ( const char* buf, int len, ikcpcb* kcp, void* user )
{
  ( void ) kcp;
  UdpSocket* p = reinterpret_cast<UdpSocket*> ( user );
  p->Send ( reinterpret_cast<const uint8_t*> ( buf ), len );
  return 0;
}

// 测试用例
void test()
{
  ikcpcb* kcp1 = ikcp_create ( 0x11223344, ( void* ) pls1 );
  ikcpcb* kcp2 = ikcp_create ( 0x11223344, ( void* ) pls2 );

  kcp1->output = udp_output_zt;
  kcp2->output = udp_output_zt;

  IUINT32 current = iclock();
  IUINT32 slap = current + 20;
  IUINT32 index = 0;
  IUINT32 next = 0;
  int count = 0;

  ikcp_wndsize ( kcp1, 128, 128 );
  ikcp_wndsize ( kcp2, 128, 128 );

  ikcp_nodelay ( kcp1, 1, 10, 2, 1 );
  ikcp_nodelay ( kcp2, 1, 10, 2, 1 );
  kcp1->rx_minrto = 10;
  kcp1->fastresend = 1;

  char buffer[2000];
  int hr;

  while ( 1 )
  {
    isleep ( 1 );
    current = iclock();
    ikcp_update ( kcp1, iclock() );
    ikcp_update ( kcp2, iclock() );

    for ( ; current >= slap; slap += 20 )
    {
      ( ( IUINT32* ) buffer ) [0] = index++;
      ( ( IUINT32* ) buffer ) [1] = current;

      ikcp_send ( kcp1, buffer, 8 );
    }

    while ( 1 )
    {
      hr = pls2->Recv ( reinterpret_cast<uint8_t*> ( buffer ), 2000 );

      if ( hr < 0 )
        break;


      ikcp_input ( kcp2, buffer, hr );
    }

    while ( 1 )
    {
      hr = pls1->Recv ( reinterpret_cast<uint8_t*> ( buffer ), 2000 );

      if ( hr < 0 )
        break;

      printbuff ( reinterpret_cast<uint8_t*> ( buffer ), hr );

      ikcp_input ( kcp1, buffer, hr );
    }

    while ( 1 )
    {
      hr = ikcp_recv ( kcp2, buffer, 10 );

      if ( hr < 0 )
        break;

      ikcp_send ( kcp2, buffer, hr );
    }

    while ( 1 )
    {
      hr = ikcp_recv ( kcp1, buffer, 10 );

      if ( hr < 0 )
        break;

      IUINT32 sn = * ( IUINT32* ) ( buffer + 0 );
      IUINT32 ts = * ( IUINT32* ) ( buffer + 4 );

      if ( sn != next )
      {
        printf ( "ERROR sn %d<->%d\n", ( int ) count, ( int ) next );
        return;
      }

      next++;
      count++;

    }

    if ( next > 2 )
      break;
  }

  ikcp_release ( kcp1 );
  ikcp_release ( kcp2 );
}

int main ( int argc, char* argv[] )
{
  ( void ) argc;
  ( void ) argv;
  pls1 = new UdpSocket ( 32345, "127.0.0.1", 32346 );
  pls2 = new UdpSocket ( 32346, "127.0.0.1", 32345 );

  test();
  return 0;
}

