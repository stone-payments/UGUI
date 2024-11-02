#include "ugui.h"

static UGUI_COLOR_DEPTH ugui_colordepth;
static UG_GUI_16* fb_16;
static UG_GUI_32* fb_32;

void*
UG_PreInit(UGUI_COLOR_DEPTH colordepth,
           UG_GUI_16* framebuffer_16,
           UG_GUI_32* framebuffer_32)
{
    ugui_colordepth = colordepth;
    if (colordepth == UGUI_COLOR_DEPTH_RGB_565) {
        fb_16 = framebuffer_16;
        return framebuffer_16;
    } else {
        fb_32 = framebuffer_32;
        return framebuffer_32;
    }
}

UG_S16
UG_Init(void* g, void (*p)(UG_S16, UG_S16, unsigned int), UG_S16 x, UG_S16 y)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        return UG_16_Init(g, (void (*)(UG_S16, UG_S16, UG_COLOR_16))p, x, y);
    else
        return UG_32_Init(g, (void (*)(UG_S16, UG_S16, UG_COLOR_32))p, x, y);
}

void
UG_ConsoleSetArea(UG_S16 xs, UG_S16 ys, UG_S16 xe, UG_S16 ye)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_ConsoleSetArea(xs, ys, xe, ye);
    else
        UG_32_ConsoleSetArea(xs, ys, xe, ye);
}

UG_S16
UG_GetXDim()
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        return fb_16->x_dim;
    else
        return fb_32->x_dim;
}

UG_S16
UG_GetYDim()
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        return fb_16->y_dim;
    else
        return fb_32->y_dim;
}

void
UG_SetBackcolor(unsigned int color)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_SetBackcolor(color);
    else
        UG_32_SetBackcolor(color);
}

void
UG_SetForecolor(unsigned int color)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_SetForecolor(color);
    else
        UG_32_SetForecolor(color);
}

void
UG_ConsoleSetBackcolor(unsigned int color)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_ConsoleSetBackcolor(color);
    else
        UG_32_ConsoleSetBackcolor(color);
}

void
UG_ConsoleSetForecolor(unsigned int color)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_ConsoleSetForecolor(color);
    else
        UG_32_ConsoleSetForecolor(color);
}

void
UG_FontSelect(const UG_FONT* font)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_FontSelect(font);
    else
        UG_32_FontSelect(font);
}

void
UG_FontSetHSpace(UG_U16 s)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_FontSetHSpace(s);
    else
        UG_32_FontSetHSpace(s);
}

void
UG_FontSetVSpace(UG_U16 s)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_FontSetVSpace(s);
    else
        UG_32_FontSetVSpace(s);
}

void
UG_FillScreen(unsigned int color)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_FillScreen(color);
    else
        UG_32_FillScreen(color);
}

void
UG_SetConsoleYPos(UG_S16 pos)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        fb_16->console.y_pos = pos;
    else
        fb_32->console.y_pos = pos;
}

UG_S16
UG_GetConsoleYStart()
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        return fb_16->console.y_start;
    else
        return fb_32->console.y_start;
}

void
UG_DrawFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, unsigned int c)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_DrawFrame(x1, y1, x2, y2, c);
    else
        UG_32_DrawFrame(x1, y1, x2, y2, c);
}

void
UG_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, unsigned int c)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_FillFrame(x1, y1, x2, y2, c);
    else
        UG_32_FillFrame(x1, y1, x2, y2, c);
}

void
UG_PutString(UG_S16 x, UG_S16 y, const char* str)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_PutString(x, y, str);
    else
        UG_32_PutString(x, y, str);
}

void
UG_ConsolePutString(const char* str)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_ConsolePutString(str);
    else
        UG_32_ConsolePutString(str);
}

unsigned int
UG_GetColor(UGUI_COLOR color)
{
    switch (color) {
        case UGUI_COLOR_BLACK:
            if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
                return C_16_BLACK;
            else
                return C_32_BLACK;
            break;

        case UGUI_COLOR_RED:
            if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
                return C_16_RED;
            else
                return C_32_RED;
            break;

        case UGUI_COLOR_LIME:
            if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
                return C_16_LIME;
            else
                return C_32_LIME;
            break;

        case UGUI_COLOR_WHITE:
        default:
            if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
                return C_16_WHITE;
            else
                return C_32_WHITE;
            break;
    }
}

void
UG_ConsoleGetCursorPos(UG_S16* x, UG_S16* y)
{
    if (ugui_colordepth == UGUI_COLOR_DEPTH_RGB_565)
        UG_16_ConsoleGetCursorPos(x, y);
    else
        UG_32_ConsoleGetCursorPos(x, y);
}
