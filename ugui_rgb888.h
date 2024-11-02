/* --------------------------------------------------------------------------------
 */
/* -- µGUI - Generic GUI module (C)Achim Döbler, 2015 -- */
/* --------------------------------------------------------------------------------
 */
// µGUI is a generic GUI module for embedded systems.
// This is a free software that is open for education, research and commercial
// developments under license policy of following terms.
//
//  Copyright (C) 2015, Achim Döbler, all rights reserved.
//  URL: http://www.embeddedlightning.com/
//
// * The µGUI module is a free software and there is NO WARRANTY.
// * No restriction on use. You can use, modify and redistribute it for
//   personal, non-profit or commercial products UNDER YOUR RESPONSIBILITY.
// * Redistributions of source code must retain the above copyright notice.
//
/* --------------------------------------------------------------------------------
 */
#ifndef __UGUI_RGB888_H
#define __UGUI_RGB888_H

#include "ugui_config.h"

/* --------------------------------------------------------------------------------
 */
/* -- TYPEDEFS -- */
/* --------------------------------------------------------------------------------
 */
typedef struct S_OBJECT_32 UG_OBJECT_32;
typedef UG_U32 UG_COLOR_32;
typedef struct S_WINDOW_32 UG_WINDOW_32;

/* Text structure */
typedef struct
{
    char* str;
    const UG_FONT* font;
    UG_AREA a;
    UG_COLOR_32 fc;
    UG_COLOR_32 bc;
    UG_U8 align;
    UG_S16 h_space;
    UG_S16 v_space;
} UG_TEXT_32;

/* --------------------------------------------------------------------------------
 */
/* -- OBJECTS -- */
/* --------------------------------------------------------------------------------
 */
/* Object structure */
struct S_OBJECT_32
{
    UG_U8 state;       /* object state                               */
    UG_U8 touch_state; /* object touch state                         */
    void (*update)(
      UG_WINDOW_32*,
      UG_OBJECT_32*); /* pointer to object-specific update function */
    UG_AREA a_abs;    /* absolute area of the object                */
    UG_AREA a_rel;    /* relative area of the object                */
    UG_U8 type;       /* object type                                */
    UG_U8 id;         /* object ID                                  */
    UG_U8 event;      /* object-specific events                     */
    void* data;       /* pointer to object-specific data            */
};

/* --------------------------------------------------------------------------------
 */
/* -- WINDOW -- */
/* --------------------------------------------------------------------------------
 */
/* Title structure */
typedef struct
{
    char* str;
    const UG_FONT* font;
    UG_S8 h_space;
    UG_S8 v_space;
    UG_U8 align;
    UG_COLOR_32 fc;
    UG_COLOR_32 bc;
    UG_COLOR_32 ifc;
    UG_COLOR_32 ibc;
    UG_U8 height;
} UG_TITLE_32;

/* Window structure */
struct S_WINDOW_32
{
    UG_U8 objcnt;
    UG_OBJECT_32* objlst;
    UG_U8 state;
    UG_COLOR_32 fc;
    UG_COLOR_32 bc;
    UG_S16 xs;
    UG_S16 ys;
    UG_S16 xe;
    UG_S16 ye;
    UG_U8 style;
    UG_TITLE_32 title;
    void (*cb)(UG_MESSAGE*);
};

/* --------------------------------------------------------------------------------
 */
/* -- BUTTON OBJECT -- */
/* --------------------------------------------------------------------------------
 */
/* Button structure */
typedef struct
{
    UG_OBJECT_32* obj; // to get quick accsess to self system Object from user
                       // defined components
    UG_U8 state;
    UG_U8 style;
    UG_COLOR_32 fc;
    UG_COLOR_32 bc;
    UG_COLOR_32 afc;
    UG_COLOR_32 abc;
    const UG_FONT* font;
    UG_U8 align;
    UG_S8 h_space;
    UG_S8 v_space;
    char* str;
} UG_BUTTON_32;

/* --------------------------------------------------------------------------------
 */
/* -- CHECKBOX OBJECT -- */
/* --------------------------------------------------------------------------------
 */
/* Checkbox structure */
typedef struct
{
    UG_OBJECT_32* obj;
    UG_U8 state;
    UG_U8 style;
    UG_COLOR_32 fc;
    UG_COLOR_32 bc;
    UG_COLOR_32 afc;
    UG_COLOR_32 abc;
    const UG_FONT* font;
    UG_U8 align;
    UG_S8 h_space;
    UG_S8 v_space;
    char* str;
    UG_U8 checked;
} UG_CHECKBOX_32;

/* --------------------------------------------------------------------------------
 */
/* -- TEXTBOX OBJECT -- */
/* --------------------------------------------------------------------------------
 */
/* Textbox structure */
typedef struct
{
    UG_OBJECT_32* obj;
    char* str;
    const UG_FONT* font;
    UG_U8 style;
    UG_COLOR_32 fc;
    UG_COLOR_32 bc;
    UG_U8 align;
    UG_S8 h_space;
    UG_S8 v_space;
} UG_TEXTBOX_32;

/* --------------------------------------------------------------------------------
 */
/* -- IMAGE OBJECT -- */
/* --------------------------------------------------------------------------------
 */
/* Image structure */
typedef struct
{
    UG_OBJECT_32* obj;
    void* img;
    UG_U8 type;
} UG_IMAGE_32;

/* --------------------------------------------------------------------------------
 */
/* -- µGUI CORE STRUCTURE -- */
/* --------------------------------------------------------------------------------
 */
typedef struct
{
    void (*pset)(UG_S16, UG_S16, UG_COLOR_32);
    UG_S16 x_dim;
    UG_S16 y_dim;
    UG_TOUCH touch;
    UG_WINDOW_32* next_window;
    UG_WINDOW_32* active_window;
    UG_WINDOW_32* last_window;
    struct
    {
        UG_S16 x_pos;
        UG_S16 y_pos;
        UG_S16 x_start;
        UG_S16 y_start;
        UG_S16 x_end;
        UG_S16 y_end;
        UG_COLOR_32 fore_color;
        UG_COLOR_32 back_color;
    } console;
    UG_FONT font;
    UG_S8 char_h_space;
    UG_S8 char_v_space;
    UG_COLOR_32 fore_color;
    UG_COLOR_32 back_color;
    UG_COLOR_32 desktop_color;
    UG_U8 state;
    UG_DRIVER driver[NUMBER_OF_DRIVERS];
} UG_GUI_32;

/* --------------------------------------------------------------------------------
 */
/* -- µGUI COLORS -- */
/* -- Source: http://www.rapidtables.com/web/color/RGB_Color.htm -- */
/* --------------------------------------------------------------------------------
 */
#define C_32_MAROON 0x800000
#define C_32_DARK_RED 0x8B0000
#define C_32_BROWN 0xA52A2A
#define C_32_FIREBRICK 0xB22222
#define C_32_CRIMSON 0xDC143C
#define C_32_RED 0xFF0000
#define C_32_TOMATO 0xFF6347
#define C_32_CORAL 0xFF7F50
#define C_32_INDIAN_RED 0xCD5C5C
#define C_32_LIGHT_CORAL 0xF08080
#define C_32_DARK_SALMON 0xE9967A
#define C_32_SALMON 0xFA8072
#define C_32_LIGHT_SALMON 0xFFA07A
#define C_32_ORANGE_RED 0xFF4500
#define C_32_DARK_ORANGE 0xFF8C00
#define C_32_ORANGE 0xFFA500
#define C_32_GOLD 0xFFD700
#define C_32_DARK_GOLDEN_ROD 0xB8860B
#define C_32_GOLDEN_ROD 0xDAA520
#define C_32_PALE_GOLDEN_ROD 0xEEE8AA
#define C_32_DARK_KHAKI 0xBDB76B
#define C_32_KHAKI 0xF0E68C
#define C_32_OLIVE 0x808000
#define C_32_YELLOW 0xFFFF00
#define C_32_YELLOW_GREEN 0x9ACD32
#define C_32_DARK_OLIVE_GREEN 0x556B2F
#define C_32_OLIVE_DRAB 0x6B8E23
#define C_32_LAWN_GREEN 0x7CFC00
#define C_32_CHART_REUSE 0x7FFF00
#define C_32_GREEN_YELLOW 0xADFF2F
#define C_32_DARK_GREEN 0x006400
#define C_32_GREEN 0x00FF00
#define C_32_FOREST_GREEN 0x228B22
#define C_32_LIME 0x00FF00
#define C_32_LIME_GREEN 0x32CD32
#define C_32_LIGHT_GREEN 0x90EE90
#define C_32_PALE_GREEN 0x98FB98
#define C_32_DARK_SEA_GREEN 0x8FBC8F
#define C_32_MEDIUM_SPRING_GREEN 0x00FA9A
#define C_32_SPRING_GREEN 0x00FF7F
#define C_32_SEA_GREEN 0x2E8B57
#define C_32_MEDIUM_AQUA_MARINE 0x66CDAA
#define C_32_MEDIUM_SEA_GREEN 0x3CB371
#define C_32_LIGHT_SEA_GREEN 0x20B2AA
#define C_32_DARK_SLATE_GRAY 0x2F4F4F
#define C_32_TEAL 0x008080
#define C_32_DARK_CYAN 0x008B8B
#define C_32_AQUA 0x00FFFF
#define C_32_CYAN 0x00FFFF
#define C_32_LIGHT_CYAN 0xE0FFFF
#define C_32_DARK_TURQUOISE 0x00CED1
#define C_32_TURQUOISE 0x40E0D0
#define C_32_MEDIUM_TURQUOISE 0x48D1CC
#define C_32_PALE_TURQUOISE 0xAFEEEE
#define C_32_AQUA_MARINE 0x7FFFD4
#define C_32_POWDER_BLUE 0xB0E0E6
#define C_32_CADET_BLUE 0x5F9EA0
#define C_32_STEEL_BLUE 0x4682B4
#define C_32_CORN_FLOWER_BLUE 0x6495ED
#define C_32_DEEP_SKY_BLUE 0x00BFFF
#define C_32_DODGER_BLUE 0x1E90FF
#define C_32_LIGHT_BLUE 0xADD8E6
#define C_32_SKY_BLUE 0x87CEEB
#define C_32_LIGHT_SKY_BLUE 0x87CEFA
#define C_32_MIDNIGHT_BLUE 0x191970
#define C_32_NAVY 0x000080
#define C_32_DARK_BLUE 0x00008B
#define C_32_MEDIUM_BLUE 0x0000CD
#define C_32_BLUE 0x0000FF
#define C_32_ROYAL_BLUE 0x4169E1
#define C_32_BLUE_VIOLET 0x8A2BE2
#define C_32_INDIGO 0x4B0082
#define C_32_DARK_SLATE_BLUE 0x483D8B
#define C_32_SLATE_BLUE 0x6A5ACD
#define C_32_MEDIUM_SLATE_BLUE 0x7B68EE
#define C_32_MEDIUM_PURPLE 0x9370DB
#define C_32_DARK_MAGENTA 0x8B008B
#define C_32_DARK_VIOLET 0x9400D3
#define C_32_DARK_ORCHID 0x9932CC
#define C_32_MEDIUM_ORCHID 0xBA55D3
#define C_32_PURPLE 0x800080
#define C_32_THISTLE 0xD8BFD8
#define C_32_PLUM 0xDDA0DD
#define C_32_VIOLET 0xEE82EE
#define C_32_MAGENTA 0xFF00FF
#define C_32_ORCHID 0xDA70D6
#define C_32_MEDIUM_VIOLET_RED 0xC71585
#define C_32_PALE_VIOLET_RED 0xDB7093
#define C_32_DEEP_PINK 0xFF1493
#define C_32_HOT_PINK 0xFF69B4
#define C_32_LIGHT_PINK 0xFFB6C1
#define C_32_PINK 0xFFC0CB
#define C_32_ANTIQUE_WHITE 0xFAEBD7
#define C_32_BEIGE 0xF5F5DC
#define C_32_BISQUE 0xFFE4C4
#define C_32_BLANCHED_ALMOND 0xFFEBCD
#define C_32_WHEAT 0xF5DEB3
#define C_32_CORN_SILK 0xFFF8DC
#define C_32_LEMON_CHIFFON 0xFFFACD
#define C_32_LIGHT_GOLDEN_ROD_YELLOW 0xFAFAD2
#define C_32_LIGHT_YELLOW 0xFFFFE0
#define C_32_SADDLE_BROWN 0x8B4513
#define C_32_SIENNA 0xA0522D
#define C_32_CHOCOLATE 0xD2691E
#define C_32_PERU 0xCD853F
#define C_32_SANDY_BROWN 0xF4A460
#define C_32_BURLY_WOOD 0xDEB887
#define C_32_TAN 0xD2B48C
#define C_32_ROSY_BROWN 0xBC8F8F
#define C_32_MOCCASIN 0xFFE4B5
#define C_32_NAVAJO_WHITE 0xFFDEAD
#define C_32_PEACH_PUFF 0xFFDAB9
#define C_32_MISTY_ROSE 0xFFE4E1
#define C_32_LAVENDER_BLUSH 0xFFF0F5
#define C_32_LINEN 0xFAF0E6
#define C_32_OLD_LACE 0xFDF5E6
#define C_32_PAPAYA_WHIP 0xFFEFD5
#define C_32_SEA_SHELL 0xFFF5EE
#define C_32_MINT_CREAM 0xF5FFFA
#define C_32_SLATE_GRAY 0x708090
#define C_32_LIGHT_SLATE_GRAY 0x778899
#define C_32_LIGHT_STEEL_BLUE 0xB0C4DE
#define C_32_LAVENDER 0xE6E6FA
#define C_32_FLORAL_WHITE 0xFFFAF0
#define C_32_ALICE_BLUE 0xF0F8FF
#define C_32_GHOST_WHITE 0xF8F8FF
#define C_32_HONEYDEW 0xF0FFF0
#define C_32_IVORY 0xFFFFF0
#define C_32_AZURE 0xF0FFFF
#define C_32_SNOW 0xFFFAFA
#define C_32_BLACK 0x000000
#define C_32_DIM_GRAY 0x696969
#define C_32_GRAY 0x808080
#define C_32_DARK_GRAY 0xA9A9A9
#define C_32_SILVER 0xC0C0C0
#define C_32_LIGHT_GRAY 0xD3D3D3
#define C_32_GAINSBORO 0xDCDCDC
#define C_32_WHITE_SMOKE 0xF5F5F5
#define C_32_WHITE 0xFFFFFF

/* --------------------------------------------------------------------------------
 */
/* -- PROTOTYPES -- */
/* --------------------------------------------------------------------------------
 */
/* Classic functions */
UG_S16
UG_32_Init(UG_GUI_32* g,
           void (*p)(UG_S16, UG_S16, UG_COLOR_32),
           UG_S16 x,
           UG_S16 y);
UG_S16
UG_32_SelectGUI(UG_GUI_32* g);
void
UG_32_FontSelect(const UG_FONT* font);
void
UG_32_FillScreen(UG_COLOR_32 c);
void
UG_32_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_32 c);
void
UG_32_FillRoundFrame(UG_S16 x1,
                     UG_S16 y1,
                     UG_S16 x2,
                     UG_S16 y2,
                     UG_S16 r,
                     UG_COLOR_32 c);
void
UG_32_DrawMesh(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_32 c);
void
UG_32_DrawFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_32 c);
void
UG_32_DrawRoundFrame(UG_S16 x1,
                     UG_S16 y1,
                     UG_S16 x2,
                     UG_S16 y2,
                     UG_S16 r,
                     UG_COLOR_32 c);
void
UG_32_DrawPixel(UG_S16 x0, UG_S16 y0, UG_COLOR_32 c);
void
UG_32_DrawCircle(UG_S16 x0, UG_S16 y0, UG_S16 r, UG_COLOR_32 c);
void
UG_32_FillCircle(UG_S16 x0, UG_S16 y0, UG_S16 r, UG_COLOR_32 c);
void
UG_32_DrawArc(UG_S16 x0, UG_S16 y0, UG_S16 r, UG_U8 s, UG_COLOR_32 c);
void
UG_32_DrawLine(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_32 c);
void
UG_32_FillPoly(UG_PointPtr p, UG_U8 n, UG_U8 filled, UG_COLOR_32 color);
void
UG_32_PutString(UG_S16 x, UG_S16 y, const char* str);
void
UG_32_PutChar(char chr, UG_S16 x, UG_S16 y, UG_COLOR_32 fc, UG_COLOR_32 bc);
void
UG_32_ConsolePutString(const char* str);
void
UG_32_ConsoleSetArea(UG_S16 xs, UG_S16 ys, UG_S16 xe, UG_S16 ye);
void
UG_32_ConsoleSetForecolor(UG_COLOR_32 c);
void
UG_32_ConsoleSetBackcolor(UG_COLOR_32 c);
void
UG_32_ConsoleGetCursorPos(UG_S16* x, UG_S16* y);
void
UG_32_SetForecolor(UG_COLOR_32 c);
void
UG_32_SetBackcolor(UG_COLOR_32 c);
UG_S16
UG_32_GetXDim(void);
UG_S16
UG_32_GetYDim(void);
void
UG_32_FontSetHSpace(UG_U16 s);
void
UG_32_FontSetVSpace(UG_U16 s);
void
UG_32_GetVectFont(UG_FONT* font, UG_U16 w, UG_U16 h);

/* Miscellaneous functions */
void
UG_32_WaitForUpdate(void);
void
UG_32_Update(void);
void
UG_32_DrawBMP(UG_S16 xp, UG_S16 yp, UG_BMP* bmp);
void
UG_32_TouchUpdate(UG_S16 xp, UG_S16 yp, UG_U8 state);

/* Driver functions */
void
UG_32_DriverRegister(UG_U8 type, void* driver);
void
UG_32_DriverEnable(UG_U8 type);
void
UG_32_DriverDisable(UG_U8 type);

/* Window functions */
UG_RESULT
UG_32_WindowCreate(UG_WINDOW_32* wnd,
                   UG_OBJECT_32* objlst,
                   UG_U8 objcnt,
                   void (*cb)(UG_MESSAGE*));
UG_RESULT
UG_32_WindowDelete(UG_WINDOW_32* wnd);
UG_RESULT
UG_32_WindowShow(UG_WINDOW_32* wnd);
UG_RESULT
UG_32_WindowHide(UG_WINDOW_32* wnd);
UG_RESULT
UG_32_WindowResize(UG_WINDOW_32* wnd,
                   UG_S16 xs,
                   UG_S16 ys,
                   UG_S16 xe,
                   UG_S16 ye);
UG_RESULT
UG_32_WindowAlert(UG_WINDOW_32* wnd);
UG_RESULT
UG_32_WindowSetForeColor(UG_WINDOW_32* wnd, UG_COLOR_32 fc);
UG_RESULT
UG_32_WindowSetBackColor(UG_WINDOW_32* wnd, UG_COLOR_32 bc);
UG_RESULT
UG_32_WindowSetTitleTextColor(UG_WINDOW_32* wnd, UG_COLOR_32 c);
UG_RESULT
UG_32_WindowSetTitleColor(UG_WINDOW_32* wnd, UG_COLOR_32 c);
UG_RESULT
UG_32_WindowSetTitleInactiveTextColor(UG_WINDOW_32* wnd, UG_COLOR_32 c);
UG_RESULT
UG_32_WindowSetTitleInactiveColor(UG_WINDOW_32* wnd, UG_COLOR_32 c);
UG_RESULT
UG_32_WindowSetTitleText(UG_WINDOW_32* wnd, char* str);
UG_RESULT
UG_32_WindowSetTitleTextFont(UG_WINDOW_32* wnd, const UG_FONT* font);
UG_RESULT
UG_32_WindowSetTitleTextHSpace(UG_WINDOW_32* wnd, UG_S8 hs);
UG_RESULT
UG_32_WindowSetTitleTextVSpace(UG_WINDOW_32* wnd, UG_S8 vs);
UG_RESULT
UG_32_WindowSetTitleTextAlignment(UG_WINDOW_32* wnd, UG_U8 align);
UG_RESULT
UG_32_WindowSetTitleHeight(UG_WINDOW_32* wnd, UG_U8 height);
UG_RESULT
UG_32_WindowSetXStart(UG_WINDOW_32* wnd, UG_S16 xs);
UG_RESULT
UG_32_WindowSetYStart(UG_WINDOW_32* wnd, UG_S16 ys);
UG_RESULT
UG_32_WindowSetXEnd(UG_WINDOW_32* wnd, UG_S16 xe);
UG_RESULT
UG_32_WindowSetYEnd(UG_WINDOW_32* wnd, UG_S16 ye);
UG_RESULT
UG_32_WindowSetStyle(UG_WINDOW_32* wnd, UG_U8 style);
UG_COLOR_32
UG_32_WindowGetForeColor(UG_WINDOW_32* wnd);
UG_COLOR_32
UG_32_WindowGetBackColor(UG_WINDOW_32* wnd);
UG_COLOR_32
UG_32_WindowGetTitleTextColor(UG_WINDOW_32* wnd);
UG_COLOR_32
UG_32_WindowGetTitleColor(UG_WINDOW_32* wnd);
UG_COLOR_32
UG_32_WindowGetTitleInactiveTextColor(UG_WINDOW_32* wnd);
UG_COLOR_32
UG_32_WindowGetTitleInactiveColor(UG_WINDOW_32* wnd);
char*
UG_32_WindowGetTitleText(UG_WINDOW_32* wnd);
UG_FONT*
UG_32_WindowGetTitleTextFont(UG_WINDOW_32* wnd);
UG_S8
UG_32_WindowGetTitleTextHSpace(UG_WINDOW_32* wnd);
UG_S8
UG_32_WindowGetTitleTextVSpace(UG_WINDOW_32* wnd);
UG_U8
UG_32_WindowGetTitleTextAlignment(UG_WINDOW_32* wnd);
UG_U8
UG_32_WindowGetTitleHeight(UG_WINDOW_32* wnd);
UG_S16
UG_32_WindowGetXStart(UG_WINDOW_32* wnd);
UG_S16
UG_32_WindowGetYStart(UG_WINDOW_32* wnd);
UG_S16
UG_32_WindowGetXEnd(UG_WINDOW_32* wnd);
UG_S16
UG_32_WindowGetYEnd(UG_WINDOW_32* wnd);
UG_U8
UG_32_WindowGetStyle(UG_WINDOW_32* wnd);
UG_RESULT
UG_32_WindowGetArea(UG_WINDOW_32* wnd, UG_AREA* a);
UG_S16
UG_32_WindowGetInnerWidth(UG_WINDOW_32* wnd);
UG_S16
UG_32_WindowGetOuterWidth(UG_WINDOW_32* wnd);
UG_S16
UG_32_WindowGetInnerHeight(UG_WINDOW_32* wnd);
UG_S16
UG_32_WindowGetOuterHeight(UG_WINDOW_32* wnd);

/* Button functions */
UG_RESULT
UG_32_ButtonCreate(UG_WINDOW_32* wnd,
                   UG_BUTTON_32* btn,
                   UG_U8 id,
                   UG_S16 xs,
                   UG_S16 ys,
                   UG_S16 xe,
                   UG_S16 ye);
UG_RESULT
UG_32_ButtonDelete(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_ButtonShow(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_ButtonHide(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_ButtonSetForeColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 fc);
UG_RESULT
UG_32_ButtonSetBackColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 bc);
UG_RESULT
UG_32_ButtonSetAlternateForeColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 afc);
UG_RESULT
UG_32_ButtonSetAlternateBackColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 abc);
UG_RESULT
UG_32_ButtonSetText(UG_WINDOW_32* wnd, UG_U8 id, char* str);
UG_RESULT
UG_32_ButtonSetFont(UG_WINDOW_32* wnd, UG_U8 id, const UG_FONT* font);
UG_RESULT
UG_32_ButtonSetStyle(UG_WINDOW_32* wnd, UG_U8 id, UG_U8 style);
UG_RESULT
UG_32_ButtonSetHSpace(UG_WINDOW_32* wnd, UG_U8 id, UG_S8 hs);
UG_RESULT
UG_32_ButtonSetVSpace(UG_WINDOW_32* wnd, UG_U8 id, UG_S8 vs);
UG_RESULT
UG_32_ButtonSetAlignment(UG_WINDOW_32* wnd, UG_U8 id, UG_U8 align);
UG_COLOR_32
UG_32_ButtonGetForeColor(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_ButtonGetBackColor(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_ButtonGetAlternateForeColor(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_ButtonGetAlternateBackColor(UG_WINDOW_32* wnd, UG_U8 id);
char*
UG_32_ButtonGetText(UG_WINDOW_32* wnd, UG_U8 id);
UG_FONT*
UG_32_ButtonGetFont(UG_WINDOW_32* wnd, UG_U8 id);
UG_U8
UG_32_ButtonGetStyle(UG_WINDOW_32* wnd, UG_U8 id);
UG_S8
UG_32_ButtonGetHSpace(UG_WINDOW_32* wnd, UG_U8 id);
UG_S8
UG_32_ButtonGetVSpace(UG_WINDOW_32* wnd, UG_U8 id);
UG_U8
UG_32_ButtonGetAlignment(UG_WINDOW_32* wnd, UG_U8 id);

/* Checkbox functions */
UG_RESULT
UG_32_CheckboxCreate(UG_WINDOW_32* wnd,
                     UG_CHECKBOX_32* btn,
                     UG_U8 id,
                     UG_S16 xs,
                     UG_S16 ys,
                     UG_S16 xe,
                     UG_S16 ye);
UG_RESULT
UG_32_CheckboxDelete(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_CheckboxShow(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_CheckboxHide(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_CheckboxSetCheched(UG_WINDOW_32* wnd, UG_U8 id, UG_U8 ch);
UG_RESULT
UG_32_CheckboxSetForeColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 fc);
UG_RESULT
UG_32_CheckboxSetBackColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 bc);
UG_RESULT
UG_32_CheckboxSetAlternateForeColor(UG_WINDOW_32* wnd,
                                    UG_U8 id,
                                    UG_COLOR_32 afc);
UG_RESULT
UG_32_CheckboxSetAlternateBackColor(UG_WINDOW_32* wnd,
                                    UG_U8 id,
                                    UG_COLOR_32 abc);
UG_RESULT
UG_32_CheckboxSetText(UG_WINDOW_32* wnd, UG_U8 id, char* str);
UG_RESULT
UG_32_CheckboxSetFont(UG_WINDOW_32* wnd, UG_U8 id, const UG_FONT* font);
UG_RESULT
UG_32_CheckboxSetStyle(UG_WINDOW_32* wnd, UG_U8 id, UG_U8 style);
UG_RESULT
UG_32_CheckboxSetHSpace(UG_WINDOW_32* wnd, UG_U8 id, UG_S8 hs);
UG_RESULT
UG_32_CheckboxSetVSpace(UG_WINDOW_32* wnd, UG_U8 id, UG_S8 vs);
UG_RESULT
UG_32_CheckboxSetAlignment(UG_WINDOW_32* wnd, UG_U8 id, UG_U8 align);
UG_U8
UG_32_CheckboxGetChecked(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_CheckboxGetForeColor(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_CheckboxGetBackColor(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_CheckboxGetAlternateForeColor(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_CheckboxGetAlternateBackColor(UG_WINDOW_32* wnd, UG_U8 id);
char*
UG_32_CheckboxGetText(UG_WINDOW_32* wnd, UG_U8 id);
UG_FONT*
UG_32_CheckboxGetFont(UG_WINDOW_32* wnd, UG_U8 id);
UG_U8
UG_32_CheckboxGetStyle(UG_WINDOW_32* wnd, UG_U8 id);
UG_S8
UG_32_CheckboxGetHSpace(UG_WINDOW_32* wnd, UG_U8 id);
UG_S8
UG_32_CheckboxGetVSpace(UG_WINDOW_32* wnd, UG_U8 id);
UG_U8
UG_32_CheckboxGetAlignment(UG_WINDOW_32* wnd, UG_U8 id);

/* Textbox functions */
UG_RESULT
UG_32_TextboxCreate(UG_WINDOW_32* wnd,
                    UG_TEXTBOX_32* txb,
                    UG_U8 id,
                    UG_S16 xs,
                    UG_S16 ys,
                    UG_S16 xe,
                    UG_S16 ye);
UG_RESULT
UG_32_TextboxDelete(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_TextboxShow(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_TextboxHide(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_TextboxSetForeColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 fc);
UG_RESULT
UG_32_TextboxSetBackColor(UG_WINDOW_32* wnd, UG_U8 id, UG_COLOR_32 bc);
UG_RESULT
UG_32_TextboxSetText(UG_WINDOW_32* wnd, UG_U8 id, char* str);
UG_RESULT
UG_32_TextboxSetFont(UG_WINDOW_32* wnd, UG_U8 id, const UG_FONT* font);
UG_RESULT
UG_32_TextboxSetHSpace(UG_WINDOW_32* wnd, UG_U8 id, UG_S8 hs);
UG_RESULT
UG_32_TextboxSetVSpace(UG_WINDOW_32* wnd, UG_U8 id, UG_S8 vs);
UG_RESULT
UG_32_TextboxSetAlignment(UG_WINDOW_32* wnd, UG_U8 id, UG_U8 align);
UG_COLOR_32
UG_32_TextboxGetForeColor(UG_WINDOW_32* wnd, UG_U8 id);
UG_COLOR_32
UG_32_TextboxGetBackColor(UG_WINDOW_32* wnd, UG_U8 id);
char*
UG_32_TextboxGetText(UG_WINDOW_32* wnd, UG_U8 id);
UG_FONT*
UG_32_TextboxGetFont(UG_WINDOW_32* wnd, UG_U8 id);
UG_S8
UG_32_TextboxGetHSpace(UG_WINDOW_32* wnd, UG_U8 id);
UG_S8
UG_32_TextboxGetVSpace(UG_WINDOW_32* wnd, UG_U8 id);
UG_U8
UG_32_TextboxGetAlignment(UG_WINDOW_32* wnd, UG_U8 id);

/* Image functions */
UG_RESULT
UG_32_ImageCreate(UG_WINDOW_32* wnd,
                  UG_IMAGE_32* img,
                  UG_U8 id,
                  UG_S16 xs,
                  UG_S16 ys,
                  UG_S16 xe,
                  UG_S16 ye);
UG_RESULT
UG_32_ImageDelete(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_ImageShow(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_ImageHide(UG_WINDOW_32* wnd, UG_U8 id);
UG_RESULT
UG_32_ImageSetBMP(UG_WINDOW_32* wnd, UG_U8 id, const UG_BMP* bmp);

#endif //__UGUI_RGB888_H
