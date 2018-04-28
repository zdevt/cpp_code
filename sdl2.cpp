
/*
 * =========================================================================
 *
 *       FileName:  sdl2.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2017-11-25 10:53:37
 *  Last Modified:  2017-12-09 13:58:44
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

#include <SDL2/SDL.h>

int main()
{
  SDL_Window* window = 0;
  SDL_Renderer* render = 0;
  SDL_Init ( SDL_INIT_EVERYTHING );
  window = SDL_CreateWindow ( "hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN );
  render = SDL_CreateRenderer ( window, -1, 0 );
  SDL_SetRenderDrawColor ( render, 0, 255, 0, 255 );
  SDL_RenderClear ( render );
  SDL_RenderPresent ( render );
  SDL_Delay ( 5000 );
  SDL_DestroyWindow ( window );
  SDL_DestroyRenderer ( render );
  SDL_Quit();
  return 0;
}

