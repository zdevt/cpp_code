/*
 * =====================================================================================
 *
 *       Filename:  MyIkcp.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/30/2017 11:16:10 AM
 *  Last Modified:  09/30/2017 11:16:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  zt (),
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef  MYIKCP_INC
#define  MYIKCP_INC

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <mutex>
#include <thread>
#include <vector>
#include <time.h>
#include <sys/time.h>

#include "ikcp.h"
#include "UdpSocket.h"

static inline void itimeofday ( long* sec, long* usec )
{
  struct timeval time;
  gettimeofday ( &time, NULL );

  if ( sec )
    *sec = time.tv_sec;

  if ( usec )
    *usec = time.tv_usec;
}

static inline int64_t iclock64 ( void )
{
  long s, u;
  int64_t value;
  itimeofday ( &s, &u );
  value = ( ( int64_t ) s ) * 1000 + ( u / 1000 );
  return value;
}

static inline uint32_t iclock()
{
  return ( uint32_t ) ( iclock64() & 0xfffffffful );
}

class MyIkcp
{
  public:
    MyIkcp ( uint32_t conv, uint16_t localport, std::string remoteip, uint16_t remoteport );
    virtual  ~MyIkcp();

  public:
    void Init();
    void DeInit();

    int Recv ( std::vector<uint8_t>& vecuint8 );
    int Send ( std::vector<uint8_t>& vecuint8 );

    int Recv ( uint8_t* buf, uint32_t size );
    int Send ( uint8_t* buf, uint32_t size );

    static int Udpoutput ( const char* buf, int len, ikcpcb* kcp, void* user );

  private:
    uint32_t m_conv;
    ikcpcb* m_ikcp;
    UdpSocket* m_udpSocket;

    uint16_t m_localport;
    std::string m_remoteip;
    uint16_t m_remoteport;
};

#endif   /* ----- #ifndef MyIkcp.h ----- */

