/* $Id: zz_pointer.c,v 1.1.1.1 2000/06/27 01:48:01 amura Exp $ */
/**************************************
*  ZZ_POINTER.C  08/05/90
*  Written by Timm Martin
*  This source code is public domain.
***************************************/

/*
 * $Log: zz_pointer.c,v $
 * Revision 1.1.1.1  2000/06/27 01:48:01  amura
 * import to CVS
 *
 */

#ifndef	AMIGA_STDIO

#include <exec/memory.h>
#include <exec/types.h>
#ifndef SAS6
# ifndef __GNUC__
#  ifndef _DCC
#   include <functions.h>
#  endif
# endif
#endif
#include "zz_pointer.h"

/**********************
*  POINTER IMAGE DATA
***********************/

#define POINTER_DATA 54
#define POINTER_SIZE (long)(POINTER_DATA*2)

USHORT zz_pointer_data[POINTER_DATA] =
{
  0x0000, 0x0000,

  0x0000, 0x0FE0,
  0x0F60, 0x1090,
  0x1FF0, 0x6008,
  0x3FF0, 0x4008,
  0x7FF8, 0x8F04,
  0x7FFC, 0x8202,
  0x7FFC, 0x8402,
  0x3FFE, 0x4F01,
  0x7FFE, 0x8001,
  0x7FFE, 0x80F1,
  0x3FFC, 0x4022,
  0x7FFE, 0x8041,
  0x7FFE, 0x80F1,
  0x3FFE, 0x4001,
  0x1FFC, 0x2002,
  0x07F8, 0x1804,
  0x00F0, 0x0708,
  0x0780, 0x0870,
  0x0FE0, 0x1010,
  0x07C0, 0x0820,
  0x0000, 0x0FE0,
  0x01C0, 0x0220,
  0x03E0, 0x0410,
  0x00E0, 0x0310,
  0x0000, 0x00E0,

  0x0000, 0x0000
};

USHORT *zz_pointer = NULL;  /* GLOBAL */

/********************
*  ZZ POINTER CLOSE
*********************/

/*
This procedure frees the CHIP RAM memory used by the ZZ pointer.
*/

void zz_pointer_close( void )
{
  if (zz_pointer)
  {
    FreeMem( zz_pointer, POINTER_SIZE );
    zz_pointer = NULL;
  }
}

/*******************
*  ZZ POINTER OPEN
********************/

/*
This function attempts to copy the ZZ pointer image data into CHIP RAM.  It
returns TRUE or FALSE whether memory was allocated.
*/

BOOL zz_pointer_open( void )
{
  /* if could allocate CHIP RAM to hold pointer data */
  if (zz_pointer = (USHORT *)AllocMem( POINTER_SIZE, MEMF_CHIP ))
    CopyMemQuick( zz_pointer_data, zz_pointer, POINTER_SIZE );

  return (zz_pointer != NULL );
}

#endif	/* AMIGA_STDIO */
