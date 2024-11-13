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
#ifndef __UGUI_RGB565_H
#define __UGUI_RGB565_H

#include "ugui_config.h"

/* --------------------------------------------------------------------------------
 */
/* -- TYPEDEFS -- */
/* --------------------------------------------------------------------------------
 */
typedef struct S_OBJECT_16 UG_OBJECT_16;
typedef UG_U16 UG_COLOR_16;
typedef struct S_WINDOW_16 UG_WINDOW_16;

/* Text structure */
typedef struct
{
    char* str;
    const UG_FONT* font;
    UG_AREA a;
    UG_COLOR_16 fc;
    UG_COLOR_16 bc;
    UG_U8 align;
    UG_S16 h_space;
    UG_S16 v_space;
} UG_TEXT_16;

/* --------------------------------------------------------------------------------
 */
/* -- OBJECTS -- */
/* --------------------------------------------------------------------------------
 */
/* Object structure */
struct S_OBJECT_16
{
    UG_U8 state;       /* object state                               */
    UG_U8 touch_state; /* object touch state                         */
    void (*update)(
      UG_WINDOW_16*,
      UG_OBJECT_16*); /* pointer to object-specific update function */
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
    UG_COLOR_16 fc;
    UG_COLOR_16 bc;
    UG_COLOR_16 ifc;
    UG_COLOR_16 ibc;
    UG_U8 height;
} UG_TITLE_16;

/* Window structure */
struct S_WINDOW_16
{
    UG_U8 objcnt;
    UG_OBJECT_16* objlst;
    UG_U8 state;
    UG_COLOR_16 fc;
    UG_COLOR_16 bc;
    UG_S16 xs;
    UG_S16 ys;
    UG_S16 xe;
    UG_S16 ye;
    UG_U8 style;
    UG_TITLE_16 title;
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
    UG_OBJECT_16* obj; // to get quick accsess to self system Object from user
                       // defined components
    UG_U8 state;
    UG_U8 style;
    UG_COLOR_16 fc;
    UG_COLOR_16 bc;
    UG_COLOR_16 afc;
    UG_COLOR_16 abc;
    const UG_FONT* font;
    UG_U8 align;
    UG_S8 h_space;
    UG_S8 v_space;
    char* str;
} UG_BUTTON_16;

/* --------------------------------------------------------------------------------
 */
/* -- CHECKBOX OBJECT -- */
/* --------------------------------------------------------------------------------
 */
/* Checkbox structure */
typedef struct
{
    UG_OBJECT_16* obj;
    UG_U8 state;
    UG_U8 style;
    UG_COLOR_16 fc;
    UG_COLOR_16 bc;
    UG_COLOR_16 afc;
    UG_COLOR_16 abc;
    const UG_FONT* font;
    UG_U8 align;
    UG_S8 h_space;
    UG_S8 v_space;
    char* str;
    UG_U8 checked;
} UG_CHECKBOX_16;

/* --------------------------------------------------------------------------------
 */
/* -- TEXTBOX OBJECT -- */
/* --------------------------------------------------------------------------------
 */
/* Textbox structure */
typedef struct
{
    UG_OBJECT_16* obj;
    char* str;
    const UG_FONT* font;
    UG_U8 style;
    UG_COLOR_16 fc;
    UG_COLOR_16 bc;
    UG_U8 align;
    UG_S8 h_space;
    UG_S8 v_space;
} UG_TEXTBOX_16;

/* --------------------------------------------------------------------------------
 */
/* -- IMAGE OBJECT -- */
/* --------------------------------------------------------------------------------
 */
/* Image structure */
typedef struct
{
    UG_OBJECT_16* obj;
    void* img;
    UG_U8 type;
} UG_IMAGE_16;

/* --------------------------------------------------------------------------------
 */
/* -- µGUI CORE STRUCTURE -- */
/* --------------------------------------------------------------------------------
 */
typedef struct
{
    void (*pset)(UG_S16, UG_S16, UG_COLOR_16);
    UG_S16 x_dim;
    UG_S16 y_dim;
    UG_TOUCH touch;
    UG_WINDOW_16* next_window;
    UG_WINDOW_16* active_window;
    UG_WINDOW_16* last_window;
    struct
    {
        UG_S16 x_pos;
        UG_S16 y_pos;
        UG_S16 x_start;
        UG_S16 y_start;
        UG_S16 x_end;
        UG_S16 y_end;
        UG_COLOR_16 fore_color;
        UG_COLOR_16 back_color;
    } console;
    UG_FONT font;
    UG_S8 char_h_space;
    UG_S8 char_v_space;
    UG_COLOR_16 fore_color;
    UG_COLOR_16 back_color;
    UG_COLOR_16 desktop_color;
    UG_U8 state;
    UG_DRIVER driver[NUMBER_OF_DRIVERS];
} UG_GUI_16;

/* --------------------------------------------------------------------------------
 */
/* -- µGUI COLORS -- */
/* -- Source: http://www.rapidtables.com/web/color/RGB_Color.htm -- */
/* --------------------------------------------------------------------------------
 */
#define C_16_MAROON 0x8000
#define C_16_DARK_RED 0x8800
#define C_16_BROWN 0xA145
#define C_16_FIREBRICK 0xB104
#define C_16_CRIMSON 0xD8A7
#define C_16_RED 0xF800
#define C_16_TOMATO 0xFB09
#define C_16_CORAL 0xFBEA
#define C_16_INDIAN_RED 0xCAEB
#define C_16_LIGHT_CORAL 0xEC10
#define C_16_DARK_SALMON 0xE4AF
#define C_16_SALMON 0xF40E
#define C_16_LIGHT_SALMON 0xFD0F
#define C_16_ORANGE_RED 0xFA20
#define C_16_DARK_ORANGE 0xFC60
#define C_16_ORANGE 0xFD20
#define C_16_GOLD 0xFEA0
#define C_16_DARK_GOLDEN_ROD 0xB421
#define C_16_GOLDEN_ROD 0xDD24
#define C_16_PALE_GOLDEN_ROD 0xEF35
#define C_16_DARK_KHAKI 0xBDAD
#define C_16_KHAKI 0xEF31
#define C_16_OLIVE 0x8400
#define C_16_YELLOW 0xFFE0
#define C_16_YELLOW_GREEN 0x9E66
#define C_16_DARK_OLIVE_GREEN 0x5346
#define C_16_OLIVE_DRAB 0x6C64
#define C_16_LAWN_GREEN 0x7FC0
#define C_16_CHART_REUSE 0x7FE0
#define C_16_GREEN_YELLOW 0xAFE6
#define C_16_DARK_GREEN 0x0320
#define C_16_GREEN 0x07E0
#define C_16_FOREST_GREEN 0x2444
#define C_16_LIME 0x07E0
#define C_16_LIME_GREEN 0x3666
#define C_16_LIGHT_GREEN 0x9772
#define C_16_PALE_GREEN 0x97D2
#define C_16_DARK_SEA_GREEN 0x8DD1
#define C_16_MEDIUM_SPRING_GREEN 0x07D3
#define C_16_SPRING_GREEN 0x07EF
#define C_16_SEA_GREEN 0x344B
#define C_16_MEDIUM_AQUA_MARINE 0x6675
#define C_16_MEDIUM_SEA_GREEN 0x3D8E
#define C_16_LIGHT_SEA_GREEN 0x2595
#define C_16_DARK_SLATE_GRAY 0x328A
#define C_16_TEAL 0x0410
#define C_16_DARK_CYAN 0x0451
#define C_16_AQUA 0x07FF
#define C_16_CYAN 0x07FF
#define C_16_LIGHT_CYAN 0xDFFF
#define C_16_DARK_TURQUOISE 0x0679
#define C_16_TURQUOISE 0x46F9
#define C_16_MEDIUM_TURQUOISE 0x4E99
#define C_16_PALE_TURQUOISE 0xAF7D
#define C_16_AQUA_MARINE 0x7FFA
#define C_16_POWDER_BLUE 0xAEFC
#define C_16_CADET_BLUE 0x64F3
#define C_16_STEEL_BLUE 0x4C16
#define C_16_CORN_FLOWER_BLUE 0x64BD
#define C_16_DEEP_SKY_BLUE 0x05FF
#define C_16_DODGER_BLUE 0x249F
#define C_16_LIGHT_BLUE 0xAEBC
#define C_16_SKY_BLUE 0x867D
#define C_16_LIGHT_SKY_BLUE 0x867E
#define C_16_MIDNIGHT_BLUE 0x18CE
#define C_16_NAVY 0x0010
#define C_16_DARK_BLUE 0x0011
#define C_16_MEDIUM_BLUE 0x0019
#define C_16_BLUE 0x001F
#define C_16_ROYAL_BLUE 0x435B
#define C_16_BLUE_VIOLET 0x897B
#define C_16_INDIGO 0x4810
#define C_16_DARK_SLATE_BLUE 0x49F1
#define C_16_SLATE_BLUE 0x6AD9
#define C_16_MEDIUM_SLATE_BLUE 0x7B5D
#define C_16_MEDIUM_PURPLE 0x939B
#define C_16_DARK_MAGENTA 0x8811
#define C_16_DARK_VIOLET 0x901A
#define C_16_DARK_ORCHID 0x9999
#define C_16_MEDIUM_ORCHID 0xBABA
#define C_16_PURPLE 0x8010
#define C_16_THISTLE 0xD5FA
#define C_16_PLUM 0xDD1B
#define C_16_VIOLET 0xEC1D
#define C_16_MAGENTA 0xF81F
#define C_16_ORCHID 0xDB9A
#define C_16_MEDIUM_VIOLET_RED 0xC0B0
#define C_16_PALE_VIOLET_RED 0xDB92
#define C_16_DEEP_PINK 0xF8B2
#define C_16_HOT_PINK 0xFB56
#define C_16_LIGHT_PINK 0xFDB7
#define C_16_PINK 0xFDF9
#define C_16_ANTIQUE_WHITE 0xF75A
#define C_16_BEIGE 0xF7BB
#define C_16_BISQUE 0xFF18
#define C_16_BLANCHED_ALMOND 0xFF59
#define C_16_WHEAT 0xF6F6
#define C_16_CORN_SILK 0xFFBB
#define C_16_LEMON_CHIFFON 0xFFD9
#define C_16_LIGHT_GOLDEN_ROD_YELLOW 0xF7DA
#define C_16_LIGHT_YELLOW 0xFFFB
#define C_16_SADDLE_BROWN 0x8A22
#define C_16_SIENNA 0x9A85
#define C_16_CHOCOLATE 0xD344
#define C_16_PERU 0xCC28
#define C_16_SANDY_BROWN 0xF52C
#define C_16_BURLY_WOOD 0xDDB0
#define C_16_TAN 0xD591
#define C_16_ROSY_BROWN 0xBC71
#define C_16_MOCCASIN 0xFF16
#define C_16_NAVAJO_WHITE 0xFEF5
#define C_16_PEACH_PUFF 0xFED6
#define C_16_MISTY_ROSE 0xFF1B
#define C_16_LAVENDER_BLUSH 0xFF7E
#define C_16_LINEN 0xF77C
#define C_16_OLD_LACE 0xFFBC
#define C_16_PAPAYA_WHIP 0xFF7A
#define C_16_SEA_SHELL 0xFFBD
#define C_16_MINT_CREAM 0xF7FE
#define C_16_SLATE_GRAY 0x7412
#define C_16_LIGHT_SLATE_GRAY 0x7453
#define C_16_LIGHT_STEEL_BLUE 0xAE1B
#define C_16_LAVENDER 0xE73E
#define C_16_FLORAL_WHITE 0xFFDD
#define C_16_ALICE_BLUE 0xEFBF
#define C_16_GHOST_WHITE 0xF7BF
#define C_16_HONEYDEW 0xEFFD
#define C_16_IVORY 0xFFFD
#define C_16_AZURE 0xEFFF
#define C_16_SNOW 0xFFDE
#define C_16_BLACK 0x0000
#define C_16_DIM_GRAY 0x6B4D
#define C_16_GRAY 0x8410
#define C_16_DARK_GRAY 0xAD55
#define C_16_SILVER 0xBDF7
#define C_16_LIGHT_GRAY 0xD69A
#define C_16_GAINSBORO 0xDEDB
#define C_16_WHITE_SMOKE 0xF7BE
#define C_16_WHITE 0xFFFF

/* --------------------------------------------------------------------------------
 */
/* -- PROTOTYPES -- */
/* --------------------------------------------------------------------------------
 */
/* Classic functions */
UG_S16
UG_16_Init(UG_GUI_16* g,
           void (*p)(UG_S16, UG_S16, UG_COLOR_16),
           UG_S16 x,
           UG_S16 y);
UG_S16
UG_16_SelectGUI(UG_GUI_16* g);
void
UG_16_FontSelect(const UG_FONT* font);
void
UG_16_FillScreen(UG_COLOR_16 c);
void
UG_16_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_16 c);
void
UG_16_FillRoundFrame(UG_S16 x1,
                     UG_S16 y1,
                     UG_S16 x2,
                     UG_S16 y2,
                     UG_S16 r,
                     UG_COLOR_16 c);
void
UG_16_DrawMesh(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_16 c);
void
UG_16_DrawFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_16 c);
void
UG_16_DrawRoundFrame(UG_S16 x1,
                     UG_S16 y1,
                     UG_S16 x2,
                     UG_S16 y2,
                     UG_S16 r,
                     UG_COLOR_16 c);
void
UG_16_DrawPixel(UG_S16 x0, UG_S16 y0, UG_COLOR_16 c);
void
UG_16_DrawCircle(UG_S16 x0, UG_S16 y0, UG_S16 r, UG_COLOR_16 c);
void
UG_16_FillCircle(UG_S16 x0, UG_S16 y0, UG_S16 r, UG_COLOR_16 c);
void
UG_16_DrawArc(UG_S16 x0, UG_S16 y0, UG_S16 r, UG_U8 s, UG_COLOR_16 c);
void
UG_16_DrawLine(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR_16 c);
void
UG_16_FillPoly(UG_PointPtr p, UG_U8 n, UG_U8 filled, UG_COLOR_16 color);
void
UG_16_PutString(UG_S16 x, UG_S16 y, const char* str);
void
UG_16_PutChar(char chr, UG_S16 x, UG_S16 y, UG_COLOR_16 fc, UG_COLOR_16 bc);
void
UG_16_ConsolePutString(const char* str);
void
UG_16_ConsoleSetArea(UG_S16 xs, UG_S16 ys, UG_S16 xe, UG_S16 ye);
void
UG_16_ConsoleSetForecolor(UG_COLOR_16 c);
void
UG_16_ConsoleSetBackcolor(UG_COLOR_16 c);
void
UG_16_ConsoleGetCursorPos(UG_S16* x, UG_S16* y);
void
UG_16_SetForecolor(UG_COLOR_16 c);
void
UG_16_SetBackcolor(UG_COLOR_16 c);
UG_S16
UG_16_GetXDim(void);
UG_S16
UG_16_GetYDim(void);
void
UG_16_FontSetHSpace(UG_U16 s);
void
UG_16_FontSetVSpace(UG_U16 s);
void
UG_16_GetVectFont(UG_FONT* font, UG_U16 w, UG_U16 h);

/* Miscellaneous functions */
void
UG_16_WaitForUpdate(void);
void
UG_16_Update(void);
void
UG_16_DrawBMP(UG_S16 xp, UG_S16 yp, UG_BMP* bmp);
void
UG_16_TouchUpdate(UG_S16 xp, UG_S16 yp, UG_U8 state);

/* Driver functions */
void
UG_16_DriverRegister(UG_U8 type, void* driver);
void
UG_16_DriverEnable(UG_U8 type);
void
UG_16_DriverDisable(UG_U8 type);

/* Window functions */
UG_RESULT
UG_16_WindowCreate(UG_WINDOW_16* wnd,
                   UG_OBJECT_16* objlst,
                   UG_U8 objcnt,
                   void (*cb)(UG_MESSAGE*));
UG_RESULT
UG_16_WindowDelete(UG_WINDOW_16* wnd);
UG_RESULT
UG_16_WindowShow(UG_WINDOW_16* wnd);
UG_RESULT
UG_16_WindowHide(UG_WINDOW_16* wnd);
UG_RESULT
UG_16_WindowResize(UG_WINDOW_16* wnd,
                   UG_S16 xs,
                   UG_S16 ys,
                   UG_S16 xe,
                   UG_S16 ye);
UG_RESULT
UG_16_WindowAlert(UG_WINDOW_16* wnd);
UG_RESULT
UG_16_WindowSetForeColor(UG_WINDOW_16* wnd, UG_COLOR_16 fc);
UG_RESULT
UG_16_WindowSetBackColor(UG_WINDOW_16* wnd, UG_COLOR_16 bc);
UG_RESULT
UG_16_WindowSetTitleTextColor(UG_WINDOW_16* wnd, UG_COLOR_16 c);
UG_RESULT
UG_16_WindowSetTitleColor(UG_WINDOW_16* wnd, UG_COLOR_16 c);
UG_RESULT
UG_16_WindowSetTitleInactiveTextColor(UG_WINDOW_16* wnd, UG_COLOR_16 c);
UG_RESULT
UG_16_WindowSetTitleInactiveColor(UG_WINDOW_16* wnd, UG_COLOR_16 c);
UG_RESULT
UG_16_WindowSetTitleText(UG_WINDOW_16* wnd, char* str);
UG_RESULT
UG_16_WindowSetTitleTextFont(UG_WINDOW_16* wnd, const UG_FONT* font);
UG_RESULT
UG_16_WindowSetTitleTextHSpace(UG_WINDOW_16* wnd, UG_S8 hs);
UG_RESULT
UG_16_WindowSetTitleTextVSpace(UG_WINDOW_16* wnd, UG_S8 vs);
UG_RESULT
UG_16_WindowSetTitleTextAlignment(UG_WINDOW_16* wnd, UG_U8 align);
UG_RESULT
UG_16_WindowSetTitleHeight(UG_WINDOW_16* wnd, UG_U8 height);
UG_RESULT
UG_16_WindowSetXStart(UG_WINDOW_16* wnd, UG_S16 xs);
UG_RESULT
UG_16_WindowSetYStart(UG_WINDOW_16* wnd, UG_S16 ys);
UG_RESULT
UG_16_WindowSetXEnd(UG_WINDOW_16* wnd, UG_S16 xe);
UG_RESULT
UG_16_WindowSetYEnd(UG_WINDOW_16* wnd, UG_S16 ye);
UG_RESULT
UG_16_WindowSetStyle(UG_WINDOW_16* wnd, UG_U8 style);
UG_COLOR_16
UG_16_WindowGetForeColor(UG_WINDOW_16* wnd);
UG_COLOR_16
UG_16_WindowGetBackColor(UG_WINDOW_16* wnd);
UG_COLOR_16
UG_16_WindowGetTitleTextColor(UG_WINDOW_16* wnd);
UG_COLOR_16
UG_16_WindowGetTitleColor(UG_WINDOW_16* wnd);
UG_COLOR_16
UG_16_WindowGetTitleInactiveTextColor(UG_WINDOW_16* wnd);
UG_COLOR_16
UG_16_WindowGetTitleInactiveColor(UG_WINDOW_16* wnd);
char*
UG_16_WindowGetTitleText(UG_WINDOW_16* wnd);
UG_FONT*
UG_16_WindowGetTitleTextFont(UG_WINDOW_16* wnd);
UG_S8
UG_16_WindowGetTitleTextHSpace(UG_WINDOW_16* wnd);
UG_S8
UG_16_WindowGetTitleTextVSpace(UG_WINDOW_16* wnd);
UG_U8
UG_16_WindowGetTitleTextAlignment(UG_WINDOW_16* wnd);
UG_U8
UG_16_WindowGetTitleHeight(UG_WINDOW_16* wnd);
UG_S16
UG_16_WindowGetXStart(UG_WINDOW_16* wnd);
UG_S16
UG_16_WindowGetYStart(UG_WINDOW_16* wnd);
UG_S16
UG_16_WindowGetXEnd(UG_WINDOW_16* wnd);
UG_S16
UG_16_WindowGetYEnd(UG_WINDOW_16* wnd);
UG_U8
UG_16_WindowGetStyle(UG_WINDOW_16* wnd);
UG_RESULT
UG_16_WindowGetArea(UG_WINDOW_16* wnd, UG_AREA* a);
UG_S16
UG_16_WindowGetInnerWidth(UG_WINDOW_16* wnd);
UG_S16
UG_16_WindowGetOuterWidth(UG_WINDOW_16* wnd);
UG_S16
UG_16_WindowGetInnerHeight(UG_WINDOW_16* wnd);
UG_S16
UG_16_WindowGetOuterHeight(UG_WINDOW_16* wnd);

/* Button functions */
UG_RESULT
UG_16_ButtonCreate(UG_WINDOW_16* wnd,
                   UG_BUTTON_16* btn,
                   UG_U8 id,
                   UG_S16 xs,
                   UG_S16 ys,
                   UG_S16 xe,
                   UG_S16 ye);
UG_RESULT
UG_16_ButtonDelete(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_ButtonShow(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_ButtonHide(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_ButtonSetForeColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 fc);
UG_RESULT
UG_16_ButtonSetBackColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 bc);
UG_RESULT
UG_16_ButtonSetAlternateForeColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 afc);
UG_RESULT
UG_16_ButtonSetAlternateBackColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 abc);
UG_RESULT
UG_16_ButtonSetText(UG_WINDOW_16* wnd, UG_U8 id, char* str);
UG_RESULT
UG_16_ButtonSetFont(UG_WINDOW_16* wnd, UG_U8 id, const UG_FONT* font);
UG_RESULT
UG_16_ButtonSetStyle(UG_WINDOW_16* wnd, UG_U8 id, UG_U8 style);
UG_RESULT
UG_16_ButtonSetHSpace(UG_WINDOW_16* wnd, UG_U8 id, UG_S8 hs);
UG_RESULT
UG_16_ButtonSetVSpace(UG_WINDOW_16* wnd, UG_U8 id, UG_S8 vs);
UG_RESULT
UG_16_ButtonSetAlignment(UG_WINDOW_16* wnd, UG_U8 id, UG_U8 align);
UG_COLOR_16
UG_16_ButtonGetForeColor(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_ButtonGetBackColor(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_ButtonGetAlternateForeColor(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_ButtonGetAlternateBackColor(UG_WINDOW_16* wnd, UG_U8 id);
char*
UG_16_ButtonGetText(UG_WINDOW_16* wnd, UG_U8 id);
UG_FONT*
UG_16_ButtonGetFont(UG_WINDOW_16* wnd, UG_U8 id);
UG_U8
UG_16_ButtonGetStyle(UG_WINDOW_16* wnd, UG_U8 id);
UG_S8
UG_16_ButtonGetHSpace(UG_WINDOW_16* wnd, UG_U8 id);
UG_S8
UG_16_ButtonGetVSpace(UG_WINDOW_16* wnd, UG_U8 id);
UG_U8
UG_16_ButtonGetAlignment(UG_WINDOW_16* wnd, UG_U8 id);

/* Checkbox functions */
UG_RESULT
UG_16_CheckboxCreate(UG_WINDOW_16* wnd,
                     UG_CHECKBOX_16* btn,
                     UG_U8 id,
                     UG_S16 xs,
                     UG_S16 ys,
                     UG_S16 xe,
                     UG_S16 ye);
UG_RESULT
UG_16_CheckboxDelete(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_CheckboxShow(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_CheckboxHide(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_CheckboxSetCheched(UG_WINDOW_16* wnd, UG_U8 id, UG_U8 ch);
UG_RESULT
UG_16_CheckboxSetForeColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 fc);
UG_RESULT
UG_16_CheckboxSetBackColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 bc);
UG_RESULT
UG_16_CheckboxSetAlternateForeColor(UG_WINDOW_16* wnd,
                                    UG_U8 id,
                                    UG_COLOR_16 afc);
UG_RESULT
UG_16_CheckboxSetAlternateBackColor(UG_WINDOW_16* wnd,
                                    UG_U8 id,
                                    UG_COLOR_16 abc);
UG_RESULT
UG_16_CheckboxSetText(UG_WINDOW_16* wnd, UG_U8 id, char* str);
UG_RESULT
UG_16_CheckboxSetFont(UG_WINDOW_16* wnd, UG_U8 id, const UG_FONT* font);
UG_RESULT
UG_16_CheckboxSetStyle(UG_WINDOW_16* wnd, UG_U8 id, UG_U8 style);
UG_RESULT
UG_16_CheckboxSetHSpace(UG_WINDOW_16* wnd, UG_U8 id, UG_S8 hs);
UG_RESULT
UG_16_CheckboxSetVSpace(UG_WINDOW_16* wnd, UG_U8 id, UG_S8 vs);
UG_RESULT
UG_16_CheckboxSetAlignment(UG_WINDOW_16* wnd, UG_U8 id, UG_U8 align);
UG_U8
UG_16_CheckboxGetChecked(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_CheckboxGetForeColor(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_CheckboxGetBackColor(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_CheckboxGetAlternateForeColor(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_CheckboxGetAlternateBackColor(UG_WINDOW_16* wnd, UG_U8 id);
char*
UG_16_CheckboxGetText(UG_WINDOW_16* wnd, UG_U8 id);
UG_FONT*
UG_16_CheckboxGetFont(UG_WINDOW_16* wnd, UG_U8 id);
UG_U8
UG_16_CheckboxGetStyle(UG_WINDOW_16* wnd, UG_U8 id);
UG_S8
UG_16_CheckboxGetHSpace(UG_WINDOW_16* wnd, UG_U8 id);
UG_S8
UG_16_CheckboxGetVSpace(UG_WINDOW_16* wnd, UG_U8 id);
UG_U8
UG_16_CheckboxGetAlignment(UG_WINDOW_16* wnd, UG_U8 id);

/* Textbox functions */
UG_RESULT
UG_16_TextboxCreate(UG_WINDOW_16* wnd,
                    UG_TEXTBOX_16* txb,
                    UG_U8 id,
                    UG_S16 xs,
                    UG_S16 ys,
                    UG_S16 xe,
                    UG_S16 ye);
UG_RESULT
UG_16_TextboxDelete(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_TextboxShow(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_TextboxHide(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_TextboxSetForeColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 fc);
UG_RESULT
UG_16_TextboxSetBackColor(UG_WINDOW_16* wnd, UG_U8 id, UG_COLOR_16 bc);
UG_RESULT
UG_16_TextboxSetText(UG_WINDOW_16* wnd, UG_U8 id, char* str);
UG_RESULT
UG_16_TextboxSetFont(UG_WINDOW_16* wnd, UG_U8 id, const UG_FONT* font);
UG_RESULT
UG_16_TextboxSetHSpace(UG_WINDOW_16* wnd, UG_U8 id, UG_S8 hs);
UG_RESULT
UG_16_TextboxSetVSpace(UG_WINDOW_16* wnd, UG_U8 id, UG_S8 vs);
UG_RESULT
UG_16_TextboxSetAlignment(UG_WINDOW_16* wnd, UG_U8 id, UG_U8 align);
UG_COLOR_16
UG_16_TextboxGetForeColor(UG_WINDOW_16* wnd, UG_U8 id);
UG_COLOR_16
UG_16_TextboxGetBackColor(UG_WINDOW_16* wnd, UG_U8 id);
char*
UG_16_TextboxGetText(UG_WINDOW_16* wnd, UG_U8 id);
UG_FONT*
UG_16_TextboxGetFont(UG_WINDOW_16* wnd, UG_U8 id);
UG_S8
UG_16_TextboxGetHSpace(UG_WINDOW_16* wnd, UG_U8 id);
UG_S8
UG_16_TextboxGetVSpace(UG_WINDOW_16* wnd, UG_U8 id);
UG_U8
UG_16_TextboxGetAlignment(UG_WINDOW_16* wnd, UG_U8 id);

/* Image functions */
UG_RESULT
UG_16_ImageCreate(UG_WINDOW_16* wnd,
                  UG_IMAGE_16* img,
                  UG_U8 id,
                  UG_S16 xs,
                  UG_S16 ys,
                  UG_S16 xe,
                  UG_S16 ye);
UG_RESULT
UG_16_ImageDelete(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_ImageShow(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_ImageHide(UG_WINDOW_16* wnd, UG_U8 id);
UG_RESULT
UG_16_ImageSetBMP(UG_WINDOW_16* wnd, UG_U8 id, const UG_BMP* bmp);

#endif //__UGUI_RGB565_H
