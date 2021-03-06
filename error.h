/*
**
** netsend - a high performance filetransfer and diagnostic tool
** http://netsend.berlios.de
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#ifndef NETSEND_ERR_HDR_
#define NETSEND_ERR_HDR_

/* error handling macros */
#define err_msg(format, args...) \
	do { \
		x_err_ret(__FILE__, __LINE__,  format , ## args); \
	} while (0)

#define err_sys(format, args...) \
	do { \
		x_err_sys(__FILE__, __LINE__,  format , ## args); \
	} while (0)

#define err_sys_die(exitcode, format, args...) \
	do { \
		x_err_sys(__FILE__, __LINE__, format , ## args); \
		exit( exitcode ); \
	} while (0)

#define err_msg_die(exitcode, format, args...) \
	do { \
		x_err_ret(__FILE__, __LINE__,  format , ## args); \
		exit( exitcode ); \
	} while (0)

enum {
	QUITSCENT = 0,
	GENTLE,
	LOUDISH,
	STRESSFUL
};

/*** Interface ***/

/* error.c */
void x_err_ret(const char *file, int line_no, const char *, ...);
void x_err_sys(const char *file, int line_no, const char *, ...);
void msg(const int, const char *, ...);
void print_bt(void);


#endif /* NETSEND_ERR_HDR_ */

