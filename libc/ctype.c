
///---------------------------------------------------------------------
int libc_isalnum(int ch){
	return libc_isalpha(ch) || libc_isdigit(ch);
}
///---------------------------------------------------------------------
int libc_isalpha(int ch){
	return ((unsigned)ch|32)-'a' < 26;
}
///---------------------------------------------------------------------
int libc_iscntrl(int ch){
	return (unsigned)ch < 0x20 || ch == 0x7f;
}
///---------------------------------------------------------------------
int libc_isdigit(int ch){
	return (unsigned)ch-'0' < 10;
}
///---------------------------------------------------------------------
int libc_isgraph(int ch){
	return (unsigned)ch-0x21 < 0x5e;
}
///---------------------------------------------------------------------
int libc_islower(int ch){
	return (unsigned)ch-'a' < 26;
}
///---------------------------------------------------------------------
int libc_isprint(int ch){
	return (unsigned)ch-0x20 < 0x5f;
}
///---------------------------------------------------------------------
int libc_ispunct(int ch){
	return libc_isgraph(ch) && !libc_isalnum(ch);
}
///---------------------------------------------------------------------
int libc_isspace(int ch){
	return ch == ' ' || (unsigned)ch-'\t' < 5;
}
//!---------------------------------------------------------------------
int libc_isupper(int ch){
	return (unsigned)ch-'A' < 26;
}
//!---------------------------------------------------------------------
int isxdigit(int ch){
	return isdigit(ch) || ((unsigned)ch|32)-'a' < 6;
}
//!---------------------------------------------------------------------
int libc_tolower(int ch){
	if (libc_isupper(ch)){ return (ch | 32);}
	return ch;
}
//!---------------------------------------------------------------------
int libc_toupper(int ch){
	if (libc_islower(ch)){ return (ch & 95);}
	return ch;
}
///---------------------------------------------------------------------
