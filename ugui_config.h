#ifndef __UGUI_CONFIG_H
#define __UGUI_CONFIG_H

/* --------------------------------------------------------------------------------
 */
/* -- CONFIG SECTION -- */
/* --------------------------------------------------------------------------------
 */

/* Enable needed fonts here */
#define USE_FONT_4X6
#define USE_FONT_5X8
#define USE_FONT_5X12
#define USE_FONT_6X8
#define USE_FONT_6X10
#define USE_FONT_7X12
#define USE_FONT_8X8
#define USE_FONT_8X12
// #define  USE_FONT_8X12_CYRILLIC
#define USE_FONT_8X14
#define USE_FONT_10X16
#define USE_FONT_12X16
#define USE_FONT_12X20
#define USE_FONT_16X26
#define USE_FONT_22X36
#define USE_FONT_24X40
#define USE_FONT_32X53
// #define  USE_FONT_VECTOR_CYRILLIC

/* Specify platform-dependent integer types here */

#define __UG_FONT_DATA const

typedef unsigned char UG_U8;
typedef char UG_S8;
typedef unsigned short UG_U16;
typedef short UG_S16;
typedef unsigned int UG_U32;
typedef int UG_S32;

typedef struct
{
    UG_S16 x, y;
} UG_Point, *UG_PointPtr;

/* --------------------------------------------------------------------------------
 */
/* --------------------------------------------------------------------------------
 */

/* Feature enablers */
#define USE_PRERENDER_EVENT
#define USE_POSTRENDER_EVENT

#define UG_MaxPolyPointNum 20

/* --------------------------------------------------------------------------------
 */
/* -- DEFINES -- */
/* --------------------------------------------------------------------------------
 */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* Alignments */
#define ALIGN_H_LEFT (1 << 0)
#define ALIGN_H_CENTER (1 << 1)
#define ALIGN_H_RIGHT (1 << 2)
#define ALIGN_V_TOP (1 << 3)
#define ALIGN_V_CENTER (1 << 4)
#define ALIGN_V_BOTTOM (1 << 5)
#define ALIGN_BOTTOM_RIGHT (ALIGN_V_BOTTOM | ALIGN_H_RIGHT)
#define ALIGN_BOTTOM_CENTER (ALIGN_V_BOTTOM | ALIGN_H_CENTER)
#define ALIGN_BOTTOM_LEFT (ALIGN_V_BOTTOM | ALIGN_H_LEFT)
#define ALIGN_CENTER_RIGHT (ALIGN_V_CENTER | ALIGN_H_RIGHT)
#define ALIGN_CENTER (ALIGN_V_CENTER | ALIGN_H_CENTER)
#define ALIGN_CENTER_LEFT (ALIGN_V_CENTER | ALIGN_H_LEFT)
#define ALIGN_TOP_RIGHT (ALIGN_V_TOP | ALIGN_H_RIGHT)
#define ALIGN_TOP_CENTER (ALIGN_V_TOP | ALIGN_H_CENTER)
#define ALIGN_TOP_LEFT (ALIGN_V_TOP | ALIGN_H_LEFT)

/* Default IDs */
#define OBJ_ID_0 0
#define OBJ_ID_1 1
#define OBJ_ID_2 2
#define OBJ_ID_3 3
#define OBJ_ID_4 4
#define OBJ_ID_5 5
#define OBJ_ID_6 6
#define OBJ_ID_7 7
#define OBJ_ID_8 8
#define OBJ_ID_9 9
#define OBJ_ID_10 10
#define OBJ_ID_11 11
#define OBJ_ID_12 12
#define OBJ_ID_13 13
#define OBJ_ID_14 14
#define OBJ_ID_15 15
#define OBJ_ID_16 16
#define OBJ_ID_17 17
#define OBJ_ID_18 18
#define OBJ_ID_19 19

/* --------------------------------------------------------------------------------
 */
/* -- µGUI FONTS -- */
/* -- Source: http://www.mikrocontroller.net/user/show/benedikt -- */
/* --------------------------------------------------------------------------------
 */
typedef enum
{
    FONT_TYPE_1BPP,
    FONT_TYPE_8BPP,
    FONT_TYPE_VECTOR_1BPP
} FONT_TYPE;

#ifdef USE_FONT_VECTOR_CYRILLIC
typedef struct
{
    const char* p[256];
    UG_S16 char_code_width;
    UG_S16 char_code_height;
} UG_VECT_FONT;
#endif

typedef struct
{
    unsigned char* p;
    FONT_TYPE font_type;
    UG_S16 char_width;
    UG_S16 char_height;
    UG_U16 start_char;
    UG_U16 end_char;
    UG_U8* widths;
} UG_FONT;

#include "ugui_fontList.h"

typedef UG_U8 UG_RESULT;

/* --------------------------------------------------------------------------------
 */
/* -- FUNCTION RESULTS -- */
/* --------------------------------------------------------------------------------
 */
#define UG_RESULT_FAIL (UG_U8)(-1)
#define UG_RESULT_OK (UG_U8)(0)

/* --------------------------------------------------------------------------------
 */
/* -- UNIVERSAL STRUCTURES -- */
/* --------------------------------------------------------------------------------
 */
/* Area structure */
typedef struct
{
    UG_S16 xs;
    UG_S16 ys;
    UG_S16 xe;
    UG_S16 ye;
} UG_AREA;

/* --------------------------------------------------------------------------------
 */
/* -- BITMAP -- */
/* --------------------------------------------------------------------------------
 */
typedef struct
{
    void* p;
    UG_U16 width;
    UG_U16 height;
    UG_U8 bpp;
    UG_U8 colors;
} UG_BMP;

#define BMP_BPP_1 (1 << 0)
#define BMP_BPP_2 (1 << 1)
#define BMP_BPP_4 (1 << 2)
#define BMP_BPP_8 (1 << 3)
#define BMP_BPP_16 (1 << 4)
#define BMP_BPP_32 (1 << 5)
#define BMP_RGB888 (1 << 0)
#define BMP_RGB565 (1 << 1)
#define BMP_RGB555 (1 << 2)

/* --------------------------------------------------------------------------------
 */
/* -- MESSAGE -- */
/* --------------------------------------------------------------------------------
 */
/* Message structure */
typedef struct
{
    UG_U8 type;
    UG_U8 id;
    UG_U8 sub_id;
    UG_U8 event;
    void* src;
} UG_MESSAGE;

/* Message types */
#define MSG_TYPE_NONE 0
#define MSG_TYPE_WINDOW 1
#define MSG_TYPE_OBJECT 2

/* --------------------------------------------------------------------------------
 */
/* -- TOUCH -- */
/* --------------------------------------------------------------------------------
 */
/* Touch structure */
typedef struct
{
    UG_U8 state;
    UG_S16 xp;
    UG_S16 yp;
} UG_TOUCH;

#define TOUCH_STATE_PRESSED 1
#define TOUCH_STATE_RELEASED 0

/* Currently supported objects */
#define OBJ_TYPE_NONE 0
#define OBJ_TYPE_BUTTON 1
#define OBJ_TYPE_TEXTBOX 2
#define OBJ_TYPE_IMAGE 3
#define OBJ_TYPE_CHECKBOX 4

/* Standard object events */
#define OBJ_EVENT_NONE 0
#define OBJ_EVENT_CLICKED 1
#ifdef USE_PRERENDER_EVENT
#define OBJ_EVENT_PRERENDER 2
#endif
#ifdef USE_POSTRENDER_EVENT
#define OBJ_EVENT_POSTRENDER 3
#endif
#define OBJ_EVENT_PRESSED 4
#define OBJ_EVENT_RELEASED 5

/* Object states */
#define OBJ_STATE_FREE (1 << 0)
#define OBJ_STATE_VALID (1 << 1)
#define OBJ_STATE_BUSY (1 << 2)
#define OBJ_STATE_VISIBLE (1 << 3)
#define OBJ_STATE_ENABLE (1 << 4)
#define OBJ_STATE_UPDATE (1 << 5)
#define OBJ_STATE_REDRAW (1 << 6)
#define OBJ_STATE_TOUCH_ENABLE (1 << 7)
#define OBJ_STATE_INIT (OBJ_STATE_FREE | OBJ_STATE_VALID)

/* Object touch states */
#define OBJ_TOUCH_STATE_CHANGED (1 << 0)
#define OBJ_TOUCH_STATE_PRESSED_ON_OBJECT (1 << 1)
#define OBJ_TOUCH_STATE_PRESSED_OUTSIDE_OBJECT (1 << 2)
#define OBJ_TOUCH_STATE_RELEASED_ON_OBJECT (1 << 3)
#define OBJ_TOUCH_STATE_RELEASED_OUTSIDE_OBJECT (1 << 4)
#define OBJ_TOUCH_STATE_IS_PRESSED_ON_OBJECT (1 << 5)
#define OBJ_TOUCH_STATE_IS_PRESSED (1 << 6)
#define OBJ_TOUCH_STATE_CLICK_ON_OBJECT (1 << 7)
#define OBJ_TOUCH_STATE_INIT 0

/* Window states */
#define WND_STATE_FREE (1 << 0)
#define WND_STATE_VALID (1 << 1)
#define WND_STATE_BUSY (1 << 2)
#define WND_STATE_VISIBLE (1 << 3)
#define WND_STATE_ENABLE (1 << 4)
#define WND_STATE_UPDATE (1 << 5)
#define WND_STATE_REDRAW_TITLE (1 << 6)

/* Window styles */
#define WND_STYLE_2D (0 << 0)
#define WND_STYLE_3D (1 << 0)
#define WND_STYLE_HIDE_TITLE (0 << 1)
#define WND_STYLE_SHOW_TITLE (1 << 1)

/* Default button IDs */
#define BTN_ID_0 OBJ_ID_0
#define BTN_ID_1 OBJ_ID_1
#define BTN_ID_2 OBJ_ID_2
#define BTN_ID_3 OBJ_ID_3
#define BTN_ID_4 OBJ_ID_4
#define BTN_ID_5 OBJ_ID_5
#define BTN_ID_6 OBJ_ID_6
#define BTN_ID_7 OBJ_ID_7
#define BTN_ID_8 OBJ_ID_8
#define BTN_ID_9 OBJ_ID_9
#define BTN_ID_10 OBJ_ID_10
#define BTN_ID_11 OBJ_ID_11
#define BTN_ID_12 OBJ_ID_12
#define BTN_ID_13 OBJ_ID_13
#define BTN_ID_14 OBJ_ID_14
#define BTN_ID_15 OBJ_ID_15
#define BTN_ID_16 OBJ_ID_16
#define BTN_ID_17 OBJ_ID_17
#define BTN_ID_18 OBJ_ID_18
#define BTN_ID_19 OBJ_ID_19

/* Button states */
#define BTN_STATE_RELEASED (0 << 0)
#define BTN_STATE_PRESSED (1 << 0)
#define BTN_STATE_ALWAYS_REDRAW (1 << 1)

/* Button style */
#define BTN_STYLE_2D (0 << 0)
#define BTN_STYLE_3D (1 << 0)
#define BTN_STYLE_TOGGLE_COLORS (1 << 1)
#define BTN_STYLE_USE_ALTERNATE_COLORS (1 << 2)
#define BTN_STYLE_NO_BORDERS (1 << 3)
#define BTN_STYLE_NO_FILL (1 << 4)

/* Button events */
#define BTN_EVENT_CLICKED OBJ_EVENT_CLICKED

/* Default checkbox IDs */
#define CHB_ID_0 OBJ_ID_0
#define CHB_ID_1 OBJ_ID_1
#define CHB_ID_2 OBJ_ID_2
#define CHB_ID_3 OBJ_ID_3
#define CHB_ID_4 OBJ_ID_4
#define CHB_ID_5 OBJ_ID_5
#define CHB_ID_6 OBJ_ID_6
#define CHB_ID_7 OBJ_ID_7
#define CHB_ID_8 OBJ_ID_8
#define CHB_ID_9 OBJ_ID_9
#define CHB_ID_10 OBJ_ID_10
#define CHB_ID_11 OBJ_ID_11
#define CHB_ID_12 OBJ_ID_12
#define CHB_ID_13 OBJ_ID_13
#define CHB_ID_14 OBJ_ID_14
#define CHB_ID_15 OBJ_ID_15
#define CHB_ID_16 OBJ_ID_16
#define CHB_ID_17 OBJ_ID_17
#define CHB_ID_18 OBJ_ID_18
#define CHB_ID_19 OBJ_ID_19

/* Checkbox states */
#define CHB_STATE_RELEASED (0 << 0)
#define CHB_STATE_PRESSED (1 << 0)
#define CHB_STATE_ALWAYS_REDRAW (1 << 1)

/* Checkbox style */
#define CHB_STYLE_2D (0 << 0)
#define CHB_STYLE_3D (1 << 0)
#define CHB_STYLE_TOGGLE_COLORS (1 << 1)
#define CHB_STYLE_USE_ALTERNATE_COLORS (1 << 2)
#define CHB_STYLE_NO_BORDERS (1 << 3)
#define CHB_STYLE_NO_FILL (1 << 4)

/* Checkbox events */
#define CHB_EVENT_CLICKED OBJ_EVENT_CLICKED

/* Default textbox IDs */
#define TXB_ID_0 OBJ_ID_0
#define TXB_ID_1 OBJ_ID_1
#define TXB_ID_2 OBJ_ID_2
#define TXB_ID_3 OBJ_ID_3
#define TXB_ID_4 OBJ_ID_4
#define TXB_ID_5 OBJ_ID_5
#define TXB_ID_6 OBJ_ID_6
#define TXB_ID_7 OBJ_ID_7
#define TXB_ID_8 OBJ_ID_8
#define TXB_ID_9 OBJ_ID_9
#define TXB_ID_10 OBJ_ID_10
#define TXB_ID_11 OBJ_ID_11
#define TXB_ID_12 OBJ_ID_12
#define TXB_ID_13 OBJ_ID_13
#define TXB_ID_14 OBJ_ID_14
#define TXB_ID_15 OBJ_ID_15
#define TXB_ID_16 OBJ_ID_16
#define TXB_ID_17 OBJ_ID_17
#define TXB_ID_18 OBJ_ID_18
#define TXB_ID_19 OBJ_ID_19

/* Default image IDs */
#define IMG_ID_0 OBJ_ID_0
#define IMG_ID_1 OBJ_ID_1
#define IMG_ID_2 OBJ_ID_2
#define IMG_ID_3 OBJ_ID_3
#define IMG_ID_4 OBJ_ID_4
#define IMG_ID_5 OBJ_ID_5
#define IMG_ID_6 OBJ_ID_6
#define IMG_ID_7 OBJ_ID_7
#define IMG_ID_8 OBJ_ID_8
#define IMG_ID_9 OBJ_ID_9
#define IMG_ID_10 OBJ_ID_10
#define IMG_ID_11 OBJ_ID_11
#define IMG_ID_12 OBJ_ID_12
#define IMG_ID_13 OBJ_ID_13
#define IMG_ID_14 OBJ_ID_14
#define IMG_ID_15 OBJ_ID_15
#define IMG_ID_16 OBJ_ID_16
#define IMG_ID_17 OBJ_ID_17
#define IMG_ID_18 OBJ_ID_18
#define IMG_ID_19 OBJ_ID_19

/* Image types */
#define IMG_TYPE_BMP (1 << 0)

/* --------------------------------------------------------------------------------
 */
/* -- µGUI DRIVER -- */
/* --------------------------------------------------------------------------------
 */
typedef struct
{
    void* driver;
    UG_U8 state;
} UG_DRIVER;

#define DRIVER_REGISTERED (1 << 0)
#define DRIVER_ENABLED (1 << 1)

/* Supported drivers */
#define NUMBER_OF_DRIVERS 3
#define DRIVER_DRAW_LINE 0
#define DRIVER_FILL_FRAME 1
#define DRIVER_FILL_AREA 2

#define UG_SATUS_WAIT_FOR_UPDATE (1 << 0)

#endif
