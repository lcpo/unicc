/*************************************************
*      Perl-Compatible Regular Expressions       *
*************************************************/
/* This file contains code from Philip Hazel's PCRE library, heavily modified
   by Stephen Turner for use in analog. See the file LICENSE in this directory
   for details. */
/* Copyright (c) 1997-2000 University of Cambridge */


#ifndef _PCRE_H
#define _PCRE_H
#define INT_MAX 2147483647

#define PCRE_MAJOR 3
#define PCRE_MINOR 4
#define PCRE_DATE  22-Aug-2000

#define SUPPORT_UTF8

#define PCRE_CASELESS        0x0001
#define PCRE_MULTILINE       0x0002
#define PCRE_DOTALL          0x0004
#define PCRE_EXTENDED        0x0008
#define PCRE_ANCHORED        0x0010
#define PCRE_DOLLAR_ENDONLY  0x0020
#define PCRE_EXTRA           0x0040
#define PCRE_NOTBOL          0x0080
#define PCRE_NOTEOL          0x0100
#define PCRE_UNGREEDY        0x0200
#define PCRE_NOTEMPTY        0x0400
#define PCRE_UTF8            0x0800

#define PCRE_ERROR_NOMATCH        (-1)
#define PCRE_ERROR_NULL           (-2)
#define PCRE_ERROR_BADOPTION      (-3)
#define PCRE_ERROR_BADMAGIC       (-4)
#define PCRE_ERROR_UNKNOWN_NODE   (-5)
#define PCRE_ERROR_NOMEMORY       (-6)
#define PCRE_ERROR_NOSUBSTRING    (-7)

#define PCRE_INFO_OPTIONS         0
#define PCRE_INFO_SIZE            1
#define PCRE_INFO_CAPTURECOUNT    2
#define PCRE_INFO_BACKREFMAX      3
#define PCRE_INFO_FIRSTCHAR       4
#define PCRE_INFO_FIRSTTABLE      5
#define PCRE_INFO_LASTLITERAL     6

typedef void pcre;
typedef void pcre_extra;

typedef int BOOL;

#undef FALSE
#define FALSE   0
#undef TRUE
#define TRUE    1


typedef unsigned char uschar;

typedef struct real_pcre {
  unsigned long int magic_number;
  size_t size;
  unsigned char *tables;
  unsigned long int options;
  unsigned char top_bracket;
  unsigned char top_backref;
  unsigned char first_char;
  unsigned char req_char;
  unsigned char code[1];
} real_pcre;


typedef struct real_pcre_extra {
  unsigned char options;
  unsigned char start_bits[32];
} real_pcre_extra;

typedef struct compile_data {
  unsigned char *lcc;
  unsigned char *fcc;
  unsigned char *cbits;
  unsigned char *ctypes;
} compile_data;

typedef struct match_data {
  int    errorcode;
  int   *offset_vector;
  int    offset_end;
  int    offset_max;
  unsigned char *lcc;
  unsigned char *ctypes;
  BOOL   offset_overflow;
  BOOL   notbol;
  BOOL   noteol;
  BOOL   utf8;
  BOOL   endonly;
  BOOL   notempty;
  unsigned char *start_pattern;
  unsigned char *start_subject;
  unsigned char *end_subject;
  unsigned char *start_match;
  unsigned char *end_match_ptr;
  int    end_offset_top;
} match_data;

//extern void *(*pcre_malloc)(size_t);
//extern void  (*pcre_free)(void *);

//extern pcre *pcre_compile(real_pcre*,char *, int, char **, int *,unsigned char *);
//extern int  pcre_exec(pcre *, pcre_extra *, char *,int, int, int, int *, int);
//extern int  pcre_fullinfo(pcre *, pcre_extra *, int, void *);



#endif  /* HAVE_PCRE */
