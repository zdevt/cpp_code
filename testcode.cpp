/*
 * =====================================================================================
 *
 *       Filename:  testcode.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017年10月10日 13时37分58秒
 *  Last Modified:  2017年10月10日 13时37分58秒
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
#include <string.h>
#include <stdbool.h>
#include <iconv.h>

int unicode_to_utf8 ( char* inbuf, size_t* inlen, char* outbuf, size_t* outlen )
{
  char* encTo = "UTF-8//IGNORE";
  char* encFrom = "UNICODE";

  iconv_t cd = iconv_open ( encTo, encFrom );

  if ( cd == ( iconv_t ) - 1 )
    perror ( "iconv_open" );

  char* tmpin = inbuf;
  char* tmpout = outbuf;
  size_t insize = *inlen;
  size_t outsize = *outlen;

  /* 进行转换
   *@param cd iconv_open()产生的句柄
   *@param srcstart 需要转换的字符串
   *@param inlen 存放还有多少字符没有转换
   *@param tempoutbuf 存放转换后的字符串
   *@param outlen 存放转换后,tempoutbuf剩余的空间
   *
   * */
  size_t ret = iconv ( cd, &tmpin, inlen, &tmpout, outlen );

  if ( ret == -1 )
    perror ( "iconv" );

  iconv_close ( cd );

  return outsize - *outlen;
}

size_t utf8_to_unicode ( char* inbuf, size_t* inlen, char* outbuf, size_t* outlen )
{
  char* encTo = "UNICODE//IGNORE";
  char* encFrom = "UTF-8";

  iconv_t cd = iconv_open ( encTo, encFrom );

  if ( cd == ( iconv_t ) - 1 )
    perror ( "iconv_open" );

  int ousize = *outlen;

  size_t ret = iconv ( cd, &inbuf, inlen, &outbuf, outlen );

  if ( ret == -1 )
    perror ( "iconv" );

  iconv_close ( cd );

  return ousize - *outlen;
}

void printBuffer ( char* buff, int size )
{
  for ( int i = 0; i < size; ++i )
  {
    if ( i % 0x10 == 0 && i != 0 )
      printf ( "\n" );

    printf ( "%02x ", ( unsigned char ) buff[i] );
  }

  printf ( "\n" );

}

int main ()
{
  char text[1024] = "测试";

  size_t inlen = strlen ( text );

  char outbuf[1024] = {};
  size_t outlen = 1024;

  printBuffer ( text, inlen );

  int outsize = utf8_to_unicode ( text, &inlen, outbuf, &outlen );

  printBuffer ( outbuf, outsize );


  char out2[1024] = { 0 };
  size_t outsize2 = 1024;
  size_t insize = outsize;
  int len2 = unicode_to_utf8 ( outbuf, &insize, out2, &outsize2 );
  printBuffer ( out2, len2 );

  return 0;
}

