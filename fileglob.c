/*  Sarien - A Sierra AGI resource interpreter engine
 *  Copyright (C) 1999,2001 Stuart George and Claudio Matsuoka
 *  
 *  $Id: fileglob.c,v 1.2 2001/11/29 05:22:25 cmatsuoka Exp $
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; see docs/COPYING for further details.
 */

#include <stdlib.h>
#include <string.h>
#include <dos.h>
#ifdef __WATCOMC__
#include <direct.h>

/* yes this is missing from Watcom 7
   so I ended up linking with Watcom 10's libraries...
   Obviously this will conflict with version 10 maybe 8/9 as well?
*/
struct find_t {
        char reserved[21];      /* reserved for use by DOS    */
        char attrib;            /* attribute byte for file    */
        unsigned short wr_time; /* time of last write to file */
        unsigned short wr_date; /* date of last write to file */
        unsigned long  size;    /* length of file in bytes    */
        char name[13];          /* null-terminated filename   */
};
#define _find_t find_t

#endif

#include "sarien.h"
#include "agi.h"

int file_exists (char *fname)
{
	struct find_t fdata;
	return !_dos_findfirst (fname, _A_NORMAL | _A_ARCH | _A_RDONLY, &fdata);
}

int file_isthere (char *fname)
{
	struct find_t fdata;
	return !_dos_findfirst (fname, _A_NORMAL | _A_ARCH | _A_RDONLY, &fdata);
}


char* file_name (char *fname)
{
	int rc;
	struct find_t fdata;

	_D ("(\"%s\")", fname);
	fdata.name[0] = 0;
	rc = _dos_findfirst((char*)fname, _A_NORMAL, &fdata);
	while (rc == 0) {
		rc = _dos_findnext(&fdata);
		if(rc == 0) {
			strlwr (fdata.name);
			if (strstr (fdata.name, "dir.")!=NULL)
				rc = 1;
		}
	}

	return strdup (fdata.name);
}



char *fixpath (int flag, char *fname)
{
	static char path[MAX_PATH];
	char *p;

    	strcpy (path, game.dir);

	if (*path && (path[strlen(path)-1]!='\\' && path[strlen(path)-1] != '/'))
	{
		if(path[strlen(path)-1]==':')
			strcat(path, "./");
		else
			strcat(path, "/");
	}

	if (flag==1)
		strcat (path, game.name);

	strcat (path, fname);

	p = path;

	while(*p) {
		if (*p=='\\')
		    *p='/';
		p++;
	}

	return path;
}

