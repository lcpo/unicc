//!------------------------------------------------------------
int libc_isalnum(int c){
	return libc_isalpha(c) || libc_isdigit(c);
}
//!------------------------------------------------------------
int libc_isalpha(int c)
{
	return ((unsigned)c|32)-'a' < 26;
}
//!------------------------------------------------------------
int libc_isascii(int c)
{
	return !(c&~0x7f);
}
//!------------------------------------------------------------
int libc_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
//!------------------------------------------------------------
int libc_iscntrl(int c)
{
	return (unsigned)c < 0x20 || c == 0x7f;
}
//!------------------------------------------------------------
int libc_isdigit(int c)
{
	return (unsigned)c-'0' < 10;
}
//!------------------------------------------------------------
int libc_isgraph(int c)
{
	return (unsigned)c-0x21 < 0x5e;
}
//!------------------------------------------------------------
int libc_islower(int c)
{
	return (unsigned)c-'a' < 26;
}
//!------------------------------------------------------------
int libc_isprint(int c)
{
	return (unsigned)c-0x20 < 0x5f;
}
//!------------------------------------------------------------
int libc_ispunct(int c)
{
	return libc_isgraph(c) && !libc_isalnum(c);
}
//!------------------------------------------------------------
int libc_isspace(int c)
{
	return c == ' ' || (unsigned)c-'\t' < 5;
}
//!------------------------------------------------------------
int libc_isupper(int c)
{
	return (unsigned)c-'A' < 26;
}
//!------------------------------------------------------------
int libc_iswalnum(long wc)
{
	return (unsigned)wc-'0' < 10 || libc_iswalpha(wc);
}
//!------------------------------------------------------------
int libc_iswalpha(long wc)
{
	return (32U|wc)-'a'<26;
}
//!------------------------------------------------------------
int libc_iswblank(long wc)
{
	return libc_isblank(wc);
}
//!------------------------------------------------------------
int libc_iswcntrl(long wc)
{
	return (unsigned)wc < 32
	    || (unsigned)(wc-0x7f) < 33
	    || (unsigned)(wc-0x2028) < 2
	    || (unsigned)(wc-0xfff9) < 3;
}
//!------------------------------------------------------------
#define WCTYPE_ALNUM  1
#define WCTYPE_ALPHA  2
#define WCTYPE_BLANK  3
#define WCTYPE_CNTRL  4
#define WCTYPE_DIGIT  5
#define WCTYPE_GRAPH  6
#define WCTYPE_LOWER  7
#define WCTYPE_PRINT  8
#define WCTYPE_PUNCT  9
#define WCTYPE_SPACE  10
#define WCTYPE_UPPER  11
#define WCTYPE_XDIGIT 12

long libc_iswctype(long wc, long type)
{
	switch (type) {
	case WCTYPE_ALNUM:
		return libc_iswalnum(wc);
	case WCTYPE_ALPHA:
		return libc_iswalpha(wc);
	case WCTYPE_BLANK:
		return libc_iswblank(wc);
	case WCTYPE_CNTRL:
		return libc_iswcntrl(wc);
	case WCTYPE_DIGIT:
		return libc_iswdigit(wc);
	//case WCTYPE_GRAPH:
	//	return libc_iswgraph(wc);
	//case WCTYPE_LOWER:
		//return libc_iswlower(wc);
	case WCTYPE_PRINT:
		return libc_iswprint(wc);
	case WCTYPE_PUNCT:
		return libc_iswpunct(wc);
	//case WCTYPE_SPACE:
		//return libc_iswspace(wc);
	//case WCTYPE_UPPER:
		//return libc_iswupper(wc);
	case WCTYPE_XDIGIT:
		return libc_iswxdigit(wc);
	}
	return 0;
}
/*
long libc_wctype(const char *s)
{
	int i;
	const char *p;

	static const char names[] =
		"alnum\0" "alpha\0" "blank\0"
		"cntrl\0" "digit\0" "graph\0"
		"lower\0" "print\0" "punct\0"
		"space\0" "upper\0" "xdigit";
	for (i=1, p=names; *p; i++, p+=6)
		if (*s == *p && !libc_strcmp(s, p))
			return i;
	return 0;
}*/
//!------------------------------------------------------------
int libc_iswdigit(long wc)
{
	return (unsigned)wc-'0' < 10;
}
//!------------------------------------------------------------
/*
int libc_iswgraph(long wc)
{
	return !libc_iswspace(wc) && libc_iswprint(wc);
}*/
//!------------------------------------------------------------
/*
long libc_iswlower(long wc)
{
	return (long)libc_towupper(wc) != wc;
}*/
//!------------------------------------------------------------
int libc_iswprint(long wc)
{
	unsigned c = wc;
	/* assume any non-control, non-illegal codepoint is printable */
	if (c>0x10ffff || c-0xd800<0x800 || (c&0xfffe)==0xfffe || libc_iswcntrl(c))
		return 0;
	return 1;
}
//!------------------------------------------------------------
/* The below data is derived from classes (P.|Sm) plus Pattern_Syntax */

#define R(a,b) { (b), (b)-(a) }

static const struct range2 {
	uint32_t base:20;
	uint32_t len:12;
} ranges2[] = {
R(0x21, 0x2f),
R(0x3a, 0x40),
R(0x5b, 0x60),
R(0x7b, 0x7e),
R(0xa1, 0xa7),
R(0xa9, 0xa9),
R(0xab, 0xac),
R(0xae, 0xae),
R(0xb0, 0xb1),
R(0xb6, 0xb7),
R(0xbb, 0xbb),
R(0xbf, 0xbf),
R(0xd7, 0xd7),
R(0xf7, 0xf7),
R(0x37e, 0x37e),
R(0x387, 0x387),
R(0x3f6, 0x3f6),
R(0x55a, 0x55f),
R(0x589, 0x58a),
R(0x5be, 0x5be),
R(0x5c0, 0x5c0),
R(0x5c3, 0x5c3),
R(0x5c6, 0x5c6),
R(0x5f3, 0x5f4),
R(0x606, 0x60a),
R(0x60c, 0x60d),
R(0x61b, 0x61b),
R(0x61e, 0x61f),
R(0x66a, 0x66d),
R(0x6d4, 0x6d4),
R(0x700, 0x70d),
R(0x7f7, 0x7f9),
R(0x964, 0x965),
R(0x970, 0x970),
R(0xdf4, 0xdf4),
R(0xe4f, 0xe4f),
R(0xe5a, 0xe5b),
R(0xf04, 0xf12),
R(0xf3a, 0xf3d),
R(0xf85, 0xf85),
R(0xfd0, 0xfd4),
R(0x104a, 0x104f),
R(0x10fb, 0x10fb),
R(0x1361, 0x1368),
R(0x166d, 0x166e),
R(0x1680, 0x1680),
R(0x169b, 0x169c),
R(0x16eb, 0x16ed),
R(0x1735, 0x1736),
R(0x17d4, 0x17d6),
R(0x17d8, 0x17da),
R(0x1800, 0x180a),
R(0x180e, 0x180e),
R(0x1944, 0x1945),
R(0x19de, 0x19df),
R(0x1a1e, 0x1a1f),
R(0x1b5a, 0x1b60),
R(0x1c3b, 0x1c3f),
R(0x1c7e, 0x1c7f),
R(0x2010, 0x2027),
R(0x2030, 0x205e),
R(0x207a, 0x207e),
R(0x208a, 0x208e),
R(0x2140, 0x2144),
R(0x214b, 0x214b),
R(0x2190, 0x245f),
R(0x2500, 0x2775),
R(0x2794, 0x2bff),
R(0x2cf9, 0x2cfc),
R(0x2cfe, 0x2cff),
R(0x2e00, 0x2e7f),
R(0x3001, 0x3003),
R(0x3008, 0x3020),
R(0x3030, 0x3030),
R(0x303d, 0x303d),
R(0x30a0, 0x30a0),
R(0x30fb, 0x30fb),
R(0xa60d, 0xa60f),
R(0xa874, 0xa877),
R(0xa8ce, 0xa8cf),
R(0xa92e, 0xa92f),
R(0xa95f, 0xa95f),
R(0xfb29, 0xfb29),
R(0xfd3e, 0xfd3f),
R(0xfe10, 0xfe19),
R(0xfe30, 0xfe52),
R(0xfe54, 0xfe66),
R(0xfe68, 0xfe68),
R(0xfe6a, 0xfe6b),
R(0xff01, 0xff03),
R(0xff05, 0xff0f),
R(0xff1a, 0xff20),
R(0xff3b, 0xff3d),
R(0xff3f, 0xff3f),
R(0xff5b, 0xff65),
R(0xffe2, 0xffe2),
R(0xffe9, 0xffec),
R(0x10100, 0x10101),
R(0x1039f, 0x1039f),
R(0x103d0, 0x103d0),
R(0x1091f, 0x1091f),
R(0x1093f, 0x1093f),
R(0x10a50, 0x10a58),
R(0x12470, 0x12473),
R(0x1d6c1, 0x1d6c1),
R(0x1d6db, 0x1d6db),
R(0x1d6fb, 0x1d6fb),
R(0x1d715, 0x1d715),
R(0x1d735, 0x1d735),
R(0x1d74f, 0x1d74f),
R(0x1d76f, 0x1d76f),
R(0x1d789, 0x1d789),
R(0x1d7a9, 0x1d7a9),
R(0x1d7c3, 0x1d7c3),
};

int libc_iswpunct(long wc)
{
	unsigned c = wc;
	int a = 0;
	int n = sizeof ranges2 / sizeof ranges2[0];
	do {
		n >>= 1;
		a += n+1 & (signed)(ranges2[a+n].base-c)>>31;
	} while (n);
	return ranges2[a].base-c <= ranges2[a].len;
}
//!------------------------------------------------------------
/*
int libc_iswspace(long wc)
{
	static const long spaces[] = {
		' ', '\t', '\n', '\r', 11, 12,  0x0085,
		0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005,
		0x2006, 0x2008, 0x2009, 0x200a, 0x200b,
		0x2028, 0x2029, 0x2050, 0x3000, 0
	};
	if (libc_wcschr(spaces, wc)) return 1;
	return 0;
}*/
//!------------------------------------------------------------
/*
long libc_iswupper(long wc)
{
	return libc_towlower(wc) != wc;
}*/
//!------------------------------------------------------------
int libc_iswxdigit(long wc)
{
	return (unsigned)(wc-'0') < 10 || (unsigned)((wc|32)-'a') < 6;
}
//!------------------------------------------------------------
int libc_isxdigit(int c)
{
	return isdigit(c) || ((unsigned)c|32)-'a' < 6;
}
//!------------------------------------------------------------
/* nonsense function that should NEVER be used! */
int libc_toascii(int c)
{
	return c & 0x7f;
}
//!------------------------------------------------------------
int libc_tolower(int c)
{
	if (libc_isupper(c)) return c | 32;
	return c;
}
//!------------------------------------------------------------
int libc_toupper(int c)
{
	if (libc_islower(c)) return c & 0x5f;
	return c;
}
//!------------------------------------------------------------
#define CASEMAP(u1,u2,l) { (u1), (l)-(u1), (u2)-(u1)+1 }
#define CASELACE(u1,u2) CASEMAP((u1),(u2),(u1)+1)

static const struct {
	unsigned short upper;
	signed char lower;
	unsigned char len;
} casemaps[] = {
	CASEMAP('A','Z','a'),
	CASEMAP(0xc0,0xde,0xe0),

	CASELACE(0x0100,0x012e),
	CASELACE(0x0132,0x0136),
	CASELACE(0x0139,0x0147),
	CASELACE(0x014a,0x0176),
	CASELACE(0x0179,0x017d),

	CASELACE(0x370,0x372),
	CASEMAP(0x391,0x3a1,0x3b1),
	CASEMAP(0x3a3,0x3ab,0x3c3),
	CASEMAP(0x400,0x40f,0x450),
	CASEMAP(0x410,0x42f,0x430),

	CASELACE(0x460,0x480),
	CASELACE(0x48a,0x4be),
	CASELACE(0x4c1,0x4cd),
	CASELACE(0x4d0,0x50e),

	CASEMAP(0x531,0x556,0x561),

	CASELACE(0x01a0,0x01a4),
	CASELACE(0x01b3,0x01b5),
	CASELACE(0x01cd,0x01db),
	CASELACE(0x01de,0x01ee),
	CASELACE(0x01f8,0x021e),
	CASELACE(0x0222,0x0232),
	CASELACE(0x03d8,0x03ee),

	CASELACE(0x1e00,0x1e94),
	CASELACE(0x1ea0,0x1efe),

	CASEMAP(0x1f08,0x1f0f,0x1f00),
	CASEMAP(0x1f18,0x1f1d,0x1f10),
	CASEMAP(0x1f28,0x1f2f,0x1f20),
	CASEMAP(0x1f38,0x1f3f,0x1f30),
	CASEMAP(0x1f48,0x1f4d,0x1f40),

	CASEMAP(0x1f68,0x1f6f,0x1f60),
	CASEMAP(0x1f88,0x1f8f,0x1f80),
	CASEMAP(0x1f98,0x1f9f,0x1f90),
	CASEMAP(0x1fa8,0x1faf,0x1fa0),
	CASEMAP(0x1fb8,0x1fb9,0x1fb0),
	CASEMAP(0x1fba,0x1fbb,0x1f70),
	CASEMAP(0x1fc8,0x1fcb,0x1f72),
	CASEMAP(0x1fd8,0x1fd9,0x1fd0),
	CASEMAP(0x1fda,0x1fdb,0x1f76),
	CASEMAP(0x1fe8,0x1fe9,0x1fe0),
	CASEMAP(0x1fea,0x1feb,0x1f7a),
	CASEMAP(0x1ff8,0x1ff9,0x1f78),
	CASEMAP(0x1ffa,0x1ffb,0x1f7c),

	CASELACE(0x246,0x24e),
	CASELACE(0x510,0x512),
	CASEMAP(0x2160,0x216f,0x2170),
	CASEMAP(0x2c00,0x2c2e,0x2c30),
	CASELACE(0x2c67,0x2c6b),
	CASELACE(0x2c80,0x2ce2),

	CASELACE(0xa722,0xa72e),
	CASELACE(0xa732,0xa76e),
	CASELACE(0xa779,0xa77b),
	CASELACE(0xa77e,0xa786),

	CASEMAP(0xff21,0xff3a,0xff41),
	{ 0,0,0 }
};

static const unsigned short pairs[][2] = {
	{ 'I',    0x0131 },
	{ 'S',    0x017f },
	{ 0x0130, 'i'    },
	{ 0x0178, 0x00ff },
	{ 0x0181, 0x0253 },
	{ 0x0182, 0x0183 },
	{ 0x0184, 0x0185 },
	{ 0x0186, 0x0254 },
	{ 0x0187, 0x0188 },
	{ 0x0189, 0x0256 },
	{ 0x018a, 0x0257 },
	{ 0x018b, 0x018c },
	{ 0x018e, 0x01dd },
	{ 0x018f, 0x0259 },
	{ 0x0190, 0x025b },
	{ 0x0191, 0x0192 },
	{ 0x0193, 0x0260 },
	{ 0x0194, 0x0263 },
	{ 0x0196, 0x0269 },
	{ 0x0197, 0x0268 },
	{ 0x0198, 0x0199 },
	{ 0x019c, 0x026f },
	{ 0x019d, 0x0272 },
	{ 0x019f, 0x0275 },
	{ 0x01a6, 0x0280 },
	{ 0x01a7, 0x01a8 },
	{ 0x01a9, 0x0283 },
	{ 0x01ac, 0x01ad },
	{ 0x01ae, 0x0288 },
	{ 0x01af, 0x01b0 },
	{ 0x01b1, 0x028a },
	{ 0x01b2, 0x028b },
	{ 0x01b7, 0x0292 },
	{ 0x01b8, 0x01b9 },
	{ 0x01bc, 0x01bd },
	{ 0x01c4, 0x01c6 },
	{ 0x01c4, 0x01c5 },
	{ 0x01c5, 0x01c6 },
	{ 0x01c7, 0x01c9 },
	{ 0x01c7, 0x01c8 },
	{ 0x01c8, 0x01c9 },
	{ 0x01ca, 0x01cc },
	{ 0x01ca, 0x01cb },
	{ 0x01cb, 0x01cc },
	{ 0x01f1, 0x01f3 },
	{ 0x01f1, 0x01f2 },
	{ 0x01f2, 0x01f3 },
	{ 0x01f4, 0x01f5 },
	{ 0x01f6, 0x0195 },
	{ 0x01f7, 0x01bf },
	{ 0x0220, 0x019e },
	{ 0x0386, 0x03ac },
	{ 0x0388, 0x03ad },
	{ 0x0389, 0x03ae },
	{ 0x038a, 0x03af },
	{ 0x038c, 0x03cc },
	{ 0x038e, 0x03cd },
	{ 0x038f, 0x03ce },
	{ 0x0399, 0x0345 },
	{ 0x0399, 0x1fbe },
	{ 0x03a3, 0x03c2 },
	{ 0x03f7, 0x03f8 },
	{ 0x03fa, 0x03fb },
	{ 0x1e60, 0x1e9b },

	{ 0x1f59, 0x1f51 },
	{ 0x1f5b, 0x1f53 },
	{ 0x1f5d, 0x1f55 },
	{ 0x1f5f, 0x1f57 },
	{ 0x1fbc, 0x1fb3 },
	{ 0x1fcc, 0x1fc3 },
	{ 0x1fec, 0x1fe5 },
	{ 0x1ffc, 0x1ff3 },

	{ 0x23a, 0x2c65 },
	{ 0x23b, 0x23c },
	{ 0x23d, 0x19a },
	{ 0x23e, 0x2c66 },
	{ 0x241, 0x242 },
	{ 0x243, 0x180 },
	{ 0x244, 0x289 },
	{ 0x245, 0x28c },
	{ 0x3f4, 0x3b8 },
	{ 0x3f9, 0x3f2 },
	{ 0x3fd, 0x37b },
	{ 0x3fe, 0x37c },
	{ 0x3ff, 0x37d },
	{ 0x4c0, 0x4cf },

	{ 0x2126, 0x3c9 },
	{ 0x212a, 'k' },
	{ 0x212b, 0xe5 },
	{ 0x2132, 0x214e },
	{ 0x2183, 0x2184 },
	{ 0x2c60, 0x2c61 },
	{ 0x2c62, 0x26b },
	{ 0x2c63, 0x1d7d },
	{ 0x2c64, 0x27d },
	{ 0x2c6d, 0x251 },
	{ 0x2c6e, 0x271 },
	{ 0x2c6f, 0x250 },
	{ 0x2c72, 0x2c73 },
	{ 0x2c75, 0x2c76 },

	{ 0xa77d, 0x1d79 },

	/* bogus greek 'symbol' letters */
	{ 0x376, 0x377 },
	{ 0x39c, 0xb5 },
	{ 0x392, 0x3d0 },
	{ 0x398, 0x3d1 },
	{ 0x3a6, 0x3d5 },
	{ 0x3a0, 0x3d6 },
	{ 0x39a, 0x3f0 },
	{ 0x3a1, 0x3f1 },
	{ 0x395, 0x3f5 },
	{ 0x3cf, 0x3d7 },

	{ 0,0 }
};


static long libc___towcase(long wc, int lower)
{
	int i;
	int lmul = 2*lower-1;
	int lmask = lower-1;
	if ((unsigned)wc - 0x10400 < 0x50)
		return wc + lmul*0x28;
	/* no letters with case in these large ranges */
	if (!libc_iswalpha(wc)
	 || (unsigned)wc - 0x0600 <= 0x0fff-0x0600
	 || (unsigned)wc - 0x2e00 <= 0xa6ff-0x2e00
	 || (unsigned)wc - 0xa800 <= 0xfeff-0xa800)
		return wc;
	/* special case because the diff between upper/lower is too big */
	if ((unsigned)wc - 0x10a0 < 0x26 || (unsigned)wc - 0x2d00 < 0x26)
		return wc + lmul*(0x2d00-0x10a0);
	for (i=0; casemaps[i].len; i++) {
		int base = casemaps[i].upper + (lmask & casemaps[i].lower);
		if ((unsigned)wc-base < casemaps[i].len) {
			if (casemaps[i].lower == 1)
				return wc + lower - ((wc-casemaps[i].upper)&1);
			return wc + lmul*casemaps[i].lower;
		}
	}
	for (i=0; pairs[i][1-lower]; i++) {
		if (pairs[i][1-lower] == wc)
			return pairs[i][lower];
	}
	if ((unsigned)wc - 0x10428 + (lower<<5) + (lower<<3) < 0x28)
		return wc - 0x28 + (lower<<10) + (lower<<6);
	return wc;
}
/*
long libc_towupper(long wc)
{
	return (long)libc___towcase(wc, 0);
}
*/
long libc_towlower(long wc)
{
	return (long)libc___towcase(wc, 1);
}
//!------------------------------------------------------------
int libc_wcswidth(const long *wcs, size_t n)
{
	int l=0, k=0;
	for (; n-- && *wcs && (k = libc_wcwidth(*wcs)) >= 0; l+=k, wcs++);
	return (k < 0) ? k : l;
}
//!------------------------------------------------------------
/*
long libc_wctrans(const char *class)
{
	if (!libc_strcmp(class, "toupper")) return 1;
	if (!libc_strcmp(class, "tolower")) return 2;
	return 0;
}

long libc_towctrans(long wc, long trans)
{
	if (trans == 1) return (long)libc_towupper(wc);
	if (trans == 2) return (long)libc_towlower(wc);
	return wc;
}*/
//!------------------------------------------------------------
#define __R(a,b,w) { (b), (w)/2, (b)-(a) }

static const struct range {
	uint32_t base:20;
	uint32_t width:1;
	uint32_t len:11;
} ranges[] = {
	__R(0x0300, 0x036F, 0),
	__R(0x0483, 0x0486, 0),
	__R(0x0488, 0x0489, 0),
	__R(0x0591, 0x05BD, 0),
	__R(0x05BF, 0x05BF, 0),
	__R(0x05C1, 0x05C2, 0),
	__R(0x05C4, 0x05C5, 0),
	__R(0x05C7, 0x05C7, 0),
	__R(0x0600, 0x0603, 0),
	__R(0x0610, 0x0615, 0),
	__R(0x064B, 0x065E, 0),
	__R(0x0670, 0x0670, 0),
	__R(0x06D6, 0x06E4, 0),
	__R(0x06E7, 0x06E8, 0),
	__R(0x06EA, 0x06ED, 0),
	__R(0x070F, 0x070F, 0),
	__R(0x0711, 0x0711, 0),
	__R(0x0730, 0x074A, 0),
	__R(0x07A6, 0x07B0, 0),
	__R(0x07EB, 0x07F3, 0),
	__R(0x0901, 0x0902, 0),
	__R(0x093C, 0x093C, 0),
	__R(0x0941, 0x0948, 0),
	__R(0x094D, 0x094D, 0),
	__R(0x0951, 0x0954, 0),
	__R(0x0962, 0x0963, 0),
	__R(0x0981, 0x0981, 0),
	__R(0x09BC, 0x09BC, 0),
	__R(0x09C1, 0x09C4, 0),
	__R(0x09CD, 0x09CD, 0),
	__R(0x09E2, 0x09E3, 0),
	__R(0x0A01, 0x0A02, 0),
	__R(0x0A3C, 0x0A3C, 0),
	__R(0x0A41, 0x0A42, 0),
	__R(0x0A47, 0x0A48, 0),
	__R(0x0A4B, 0x0A4D, 0),
	__R(0x0A70, 0x0A71, 0),
	__R(0x0A81, 0x0A82, 0),
	__R(0x0ABC, 0x0ABC, 0),
	__R(0x0AC1, 0x0AC5, 0),
	__R(0x0AC7, 0x0AC8, 0),
	__R(0x0ACD, 0x0ACD, 0),
	__R(0x0AE2, 0x0AE3, 0),
	__R(0x0B01, 0x0B01, 0),
	__R(0x0B3C, 0x0B3C, 0),
	__R(0x0B3F, 0x0B3F, 0),
	__R(0x0B41, 0x0B43, 0),
	__R(0x0B4D, 0x0B4D, 0),
	__R(0x0B56, 0x0B56, 0),
	__R(0x0B82, 0x0B82, 0),
	__R(0x0BC0, 0x0BC0, 0),
	__R(0x0BCD, 0x0BCD, 0),
	__R(0x0C3E, 0x0C40, 0),
	__R(0x0C46, 0x0C48, 0),
	__R(0x0C4A, 0x0C4D, 0),
	__R(0x0C55, 0x0C56, 0),
	__R(0x0CBC, 0x0CBC, 0),
	__R(0x0CBF, 0x0CBF, 0),
	__R(0x0CC6, 0x0CC6, 0),
	__R(0x0CCC, 0x0CCD, 0),
	__R(0x0CE2, 0x0CE3, 0),
	__R(0x0D41, 0x0D43, 0),
	__R(0x0D4D, 0x0D4D, 0),
	__R(0x0DCA, 0x0DCA, 0),
	__R(0x0DD2, 0x0DD4, 0),
	__R(0x0DD6, 0x0DD6, 0),
	__R(0x0E31, 0x0E31, 0),
	__R(0x0E34, 0x0E3A, 0),
	__R(0x0E47, 0x0E4E, 0),
	__R(0x0EB1, 0x0EB1, 0),
	__R(0x0EB4, 0x0EB9, 0),
	__R(0x0EBB, 0x0EBC, 0),
	__R(0x0EC8, 0x0ECD, 0),
	__R(0x0F18, 0x0F19, 0),
	__R(0x0F35, 0x0F35, 0),
	__R(0x0F37, 0x0F37, 0),
	__R(0x0F39, 0x0F39, 0),
	__R(0x0F71, 0x0F7E, 0),
	__R(0x0F80, 0x0F84, 0),
	__R(0x0F86, 0x0F87, 0),
	__R(0x0F90, 0x0F97, 0),
	__R(0x0F99, 0x0FBC, 0),
	__R(0x0FC6, 0x0FC6, 0),
	__R(0x102D, 0x1030, 0),
	__R(0x1032, 0x1032, 0),
	__R(0x1036, 0x1037, 0),
	__R(0x1039, 0x1039, 0),
	__R(0x1058, 0x1059, 0),
	__R(0x1100, 0x115F, 2),
	__R(0x1160, 0x11FF, 0),
	__R(0x135F, 0x135F, 0),
	__R(0x1712, 0x1714, 0),
	__R(0x1732, 0x1734, 0),
	__R(0x1752, 0x1753, 0),
	__R(0x1772, 0x1773, 0),
	__R(0x17B4, 0x17B5, 0),
	__R(0x17B7, 0x17BD, 0),
	__R(0x17C6, 0x17C6, 0),
	__R(0x17C9, 0x17D3, 0),
	__R(0x17DD, 0x17DD, 0),
	__R(0x180B, 0x180D, 0),
	__R(0x18A9, 0x18A9, 0),
	__R(0x1920, 0x1922, 0),
	__R(0x1927, 0x1928, 0),
	__R(0x1932, 0x1932, 0),
	__R(0x1939, 0x193B, 0),
	__R(0x1A17, 0x1A18, 0),
	__R(0x1B00, 0x1B03, 0),
	__R(0x1B34, 0x1B34, 0),
	__R(0x1B36, 0x1B3A, 0),
	__R(0x1B3C, 0x1B3C, 0),
	__R(0x1B42, 0x1B42, 0),
	__R(0x1B6B, 0x1B73, 0),
	__R(0x1DC0, 0x1DCA, 0),
	__R(0x1DFE, 0x1DFF, 0),
	__R(0x200B, 0x200F, 0),
	__R(0x202A, 0x202E, 0),
	__R(0x2060, 0x2063, 0),
	__R(0x206A, 0x206F, 0),
	__R(0x20D0, 0x20EF, 0),
	__R(0x2329, 0x232A, 2),
	__R(0x2E80, 0x3029, 2),
	__R(0x302A, 0x302F, 0),
	__R(0x3030, 0x303E, 2),
	__R(0x3099, 0x309A, 0),
	__R(0xA806, 0xA806, 0),
	__R(0xA80B, 0xA80B, 0),
	__R(0xA825, 0xA826, 0),
	__R(0xF900, 0xFAFF, 2),
	__R(0xFB1E, 0xFB1E, 0),
	__R(0xFE00, 0xFE0F, 0),
	__R(0xFE20, 0xFE23, 0),
	__R(0xFE30, 0xFE6F, 2),
	__R(0xFEFF, 0xFEFF, 0),
	__R(0xFF00, 0xFF60, 2),
	__R(0xFFE0, 0xFFE6, 2),
	__R(0x10A01, 0x10A03, 0),
	__R(0x10A05, 0x10A06, 0),
	__R(0x10A0C, 0x10A0F, 0),
	__R(0x10A38, 0x10A3A, 0),
	__R(0x10A3F, 0x10A3F, 0),
	__R(0x1D167, 0x1D169, 0),
	__R(0x1D173, 0x1D182, 0),
	__R(0x1D185, 0x1D18B, 0),
	__R(0x1D1AA, 0x1D1AD, 0),
	__R(0x1D242, 0x1D244, 0),
	__R(0xE0001, 0xE0001, 0),
	__R(0xE0020, 0xE007F, 0),
	__R(0xE0100, 0xE01EF, 0),
};

/* Note: because the len field is only 10 bits, we must special-case
 * the two huge ranges of full width characters and exclude them
 * from the binary search table. */

int libc_wcwidth(long wc)
{
	int a, n;
	uint32_t c = wc;

	if (c-0x20 < 0x5f) return 1;
	if (!libc_iswprint(c)) return wc ? -1 : 0;
	if (c-0x20000 < 0x20000) return 2;

	/* The following code is a branchless binary search. */
	a = 0;
	n = sizeof ranges / sizeof ranges[0];
	do {
		n >>= 1;
		a += n+1 & (signed)(ranges[a+n].base-c)>>31;
	} while (n);
	if (ranges[a].base-c <= ranges[a].len)
		return 2*ranges[a].width;
	return 1 + (c-0x3040 < 0xd800-0x3040);
}
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
//!------------------------------------------------------------
