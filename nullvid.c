/*  Sarien - A Sierra AGI resource interpreter engine
 *  Copyright (C) 1999-2001 Stuart George and Claudio Matsuoka
 *  
 *  $Id: pcvga.c,v 1.5 2002/11/16 01:20:21 cmatsuoka Exp $
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; see docs/COPYING for further details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "sarien.h"
#include "graphics.h"

extern struct gfx_driver *gfx;
extern struct sarien_options opt;

UINT8	*exec_name;
static UINT8	*screen_buffer;

static int	pc_init_vidmode	(void);
static int	pc_deinit_vidmode	(void);
static void	pc_put_block		(int, int, int, int);
static void	pc_put_pixels		(int, int, int, UINT8 *);
static void	pc_timer		(void);
static int	pc_get_key		(void);
static int	pc_keypress		(void);


#define TICK_SECONDS 18

static struct gfx_driver gfx_pcvga = {
	pc_init_vidmode,
	pc_deinit_vidmode,
	pc_put_block,
	pc_put_pixels,
	pc_timer,
	pc_keypress,
	pc_get_key
};

static void pc_timer ()
{
	static UINT32 cticks = 0;

	while (cticks == clock_ticks);
	cticks = clock_ticks;
}


int init_machine (int argc, char **argv)
{
	gfx = &gfx_pcvga;
	return err_OK;
}


int deinit_machine ()
{
	return err_OK;
}


static int pc_init_vidmode ()
{
	int i;

	clock_count = 0;
	clock_ticks = 0;

	screen_buffer = calloc (GFX_WIDTH, GFX_HEIGHT);

	return err_OK;
}


static int pc_deinit_vidmode ()
{
	free (screen_buffer);

	return err_OK;
}


/* blit a block onto the screen */
static void pc_put_block (int x1, int y1, int x2, int y2)
{

}


static void pc_put_pixels(int x, int y, int w, UINT8 *p)
{
	UINT8 *s;
 	for (s = &screen_buffer[y * 320 + x]; w--; *s++ = *p++);
}


static int pc_keypress ()
{
}


static int pc_get_key ()
{
	UINT16 key;

	key=0;
	return key;
}

	