/*
 * =====================================================================================
 *
 *       Filename:  MyIkcp.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/30/2017 11:16:04 AM
 *  Last Modified:  09/30/2017 11:16:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */

#include "MyIkcp.h"

int MyIkcp::Udpoutput ( const char* buf, int len, ikcpcb* kcp, void* user )
{
  UdpSocket* p = reinterpret_cast<UdpSocket*> ( user );
  p->Send ( reinterpret_cast<const uint8_t*> ( buf ), len );
  return 0;
}

MyIkcp::MyIkcp ( uint32_t conv, uint16_t localport, std::string remoteip, uint16_t remoteport )
  : m_conv ( conv ), m_localport ( localport ),
    m_remoteip ( remoteip ), m_remoteport ( remoteport ),
    m_ikcp ( NULL ), m_udpSocket ( NULL )
{
  Init();
}

MyIkcp::~MyIkcp()
{
  DeInit();
}

void MyIkcp::Init()
{
  m_udpSocket = new UdpSocket ( m_localport, m_remoteip, m_remoteport );

  m_ikcp = ikcp_create ( m_conv, reinterpret_cast< void* > ( m_udpSocket ) );
  m_ikcp->output = Udpoutput;

  ikcp_wndsize ( m_ikcp, 128, 128 );
  ikcp_nodelay ( m_ikcp, 1, 10, 2, 1 );
  m_ikcp->rx_minrto = 10;
  m_ikcp->fastresend = 1;
}

void MyIkcp::DeInit()
{
  ikcp_release ( m_ikcp );
  delete m_udpSocket;
}

int MyIkcp::Recv ( std::vector<uint8_t>& vecuint8 )
{
  std::vector<uint8_t> vec ( 2048, 0 );

  int len = 0;
  int readsum = 0;
  vecuint8.resize ( 0 );
  vecuint8.reserve ( 4096 );

  do
  {
    if ( ( len = m_udpSocket->Recv ( &vec[0], vec.size() ) ) > 0 )
    {
      ikcp_input ( m_ikcp, reinterpret_cast<char*> ( &vec[0] ), len );
      readsum += len;
      vecuint8.insert ( vecuint8.end(), vec.begin(), vec.begin() + len );
    }
  }
  while ( len > 0 );

  return readsum;
}

int MyIkcp::Send ( std::vector<uint8_t>& vecuint8 )
{
  int len = 0;
  int sendsum = 0;

  do
  {
    if ( ( len = ikcp_send ( m_ikcp, reinterpret_cast<char*> ( &vecuint8[0] + sendsum ), vecuint8.size() - sendsum ) ) > 0 )
      sendsum += len;
  }
  while ( len > 0 );

  return sendsum;
}

int MyIkcp::Recv ( uint8_t* buf, uint32_t size )
{
  int len = 0;
  int readsum = 0;

  do
  {
    if ( ( len = m_udpSocket->Recv ( buf, size ) ) > 0 )
    {
      ikcp_input ( m_ikcp, reinterpret_cast<char*> ( buf ), len );
      readsum += len;
    }
  }
  while ( len > 0 );

  return readsum;
}

int MyIkcp::Send ( uint8_t* buf, uint32_t size )
{
  int len = 0;
  int sendsum = 0;

  do
  {
    if ( ( len = ikcp_send ( m_ikcp, reinterpret_cast<char*> ( buf ), size ) ) > 0 )
      sendsum += len;
  }
  while ( len > 0 );

  return sendsum;
}


#ifdef TESTKCP
int main ( int argc, char* argv[] )
{
  std::vector<uint8_t> vecuint8 ;
  vecuint8.resize ( 0 );
  vecuint8.reserve ( 2048 );
  printf ( "size=%ld %ld\n", vecuint8.size(), vecuint8.capacity() );
  vecuint8.resize ( 100 );
  printf ( "size=%ld %ld\n", vecuint8.size(), vecuint8.capacity() );
  vecuint8.resize ( 200, 0 );
  printf ( "size=%ld %ld\n", vecuint8.size(), vecuint8.capacity() );
  return 0;
}
#endif

