#ifndef __UGUI_H
#define __UGUI_H

#include "ugui_config.h"
#include "ugui_rgb565.h"
#include "ugui_rgb888.h"

typedef enum
{
    UGUI_COLOR_DEPTH_RGB_565,
    UGUI_COLOR_DEPTH_RGB_888
} UGUI_COLOR_DEPTH;

typedef enum
{
    UGUI_COLOR_WHITE,
    UGUI_COLOR_RED,
    UGUI_COLOR_LIME,
    UGUI_COLOR_BLACK,
} UGUI_COLOR;

void*
UG_PreInit(UGUI_COLOR_DEPTH colordepth,
           UG_GUI_16* framebuffer_16,
           UG_GUI_32* framebuffer_32);

UG_S16
UG_Init(void* g, void (*p)(UG_S16, UG_S16, unsigned int), UG_S16 x, UG_S16 y);

void
UG_ConsoleSetArea(UG_S16 xs, UG_S16 ys, UG_S16 xe, UG_S16 ye);

UG_S16
UG_GetXDim();

UG_S16
UG_GetYDim();

void
UG_SetBackcolor(unsigned int color);

void
UG_SetForecolor(unsigned int color);

void
UG_ConsoleSetBackcolor(unsigned int color);

void
UG_ConsoleSetForecolor(unsigned int color);

void
UG_FontSelect(const UG_FONT* font);

void
UG_FontSetHSpace(UG_U16 s);

void
UG_FontSetVSpace(UG_U16 s);

void
UG_FillScreen(unsigned int color);

void
UG_SetConsoleYPos(UG_S16 pos);

UG_S16
UG_GetConsoleYStart();

void
UG_DrawFrame(UG_S16 x1, UG_S16 y1RED, UG_S16 x2, UG_S16 y2, unsigned int c);

void
UG_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, unsigned int c);

void
UG_PutString(UG_S16 x, UG_S16 y, const char* str);

void
UG_ConsolePutString(const char* str);

unsigned int
UG_GetColor(UGUI_COLOR color);

void
UG_ConsoleGetCursorPos(UG_S16* x, UG_S16* y);

#endif