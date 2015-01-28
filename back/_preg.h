#ifndef _MY_PREG_C_HEAD
#define _MY_PREG_C_HEAD
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
*/

#define _(x) _preg_ ## x

typedef struct{
	union
	{
		struct
		{
			long frm;
			long end;
		};
		long unt[8];
	};
	char typ;
}_(token);

typedef struct{
	long  cycle;
	long  alter;
	long  chain;
	long  match;
	long *point;
}_(track);

typedef struct{
	long l,r;
	long i,o;
}_(solve);

typedef struct
{
	long (*unt)[8];
	long   len;
}_(table);

typedef struct{
	_(track) *trk;
	long      len;
	long      etr;
	long      out;
}_(NFA);

typedef struct{
	long *chr;
	long *end;
	long *tbl;
	long  wid;
	long  len;
}_(DFA);

typedef struct{
	char    bgn;
	_(DFA) *dfa;
	char    end;
}regex;

typedef struct{
	long pos;
	long len;
}group;

static void _(SetAs)(long *a,const long *b,long l){
	while(l){--l,a[l] = b[l];}
}
static void _(SetAsNot)(long *a,const long *b,long l){
	while(l){--l,a[l] = ~b[l];}
}
static void _(SetBoth)(long *a,const long *b,const long *c,long l)
{
	while(l){--l,a[l] = b[l] & c[l];}
}
static void _(SetBothNot)(long *a,const long *b,const long *c,long l)
{
	while(l){--l,a[l] = b[l] & ~c[l];}
}
static void _(SetJoin)(long *a,const long *b,const long *c,long l)
{
	while(l){--l,a[l] = b[l] | c[l];}
}
static void _(SetJoinNot)(long *a,const long *b,const long *c,long l)
{
	while(l){--l,a[l] = b[l] | ~c[l];}
}
static char _(Exist)(const long *a,long l)
{
	while(l){--l;if(a[l] != 0)return 1;}return 0;
}
static char _(GetBoth)(const long *a,const long *b,long l)
{
	while(l){--l;if(a[l] & b[l])return 1;}return 0;
}
static char _(GetSame)(const long *a,const long *b,long l)
{
	while(l){--l;if(a[l] != b[l])return 0;}return 1;
}
static void _(SetBit)(long *a,long n,char t)
{
	if(t)a[n/32]|=1<<(n%32);else a[n/32]&=~(1<<(n%32));
}
static char _(GetBit)(const long *a,long n)
{
	return ((a[n/32])&(1<<(n%32)))!=0;
}
static char _(IsNum)(char c)
{
	return c>='0' && c<='9';
}
static long _(Dec)(long *t,const char *str)
{
	const char *p=str;
	long i=0;
	for(;*p>='0' && *p<='9';++p)i=i*10+(*p-'0');
	*t=i;
	return p-str;
}
static long _(Hex)(long *t,const char *str)
{
	const char *p=str;
	long i=0;
	for(;;++p)
	{
		if(*p>='0' && *p<='9'){i=i*16+(*p-'0'+ 0);continue;}
		if(*p>='a' && *p<='f'){i=i*16+(*p-'a'+10);continue;}
		if(*p>='A' && *p<='F'){i=i*16+(*p-'A'+10);continue;}
		break;
	}
	*t=i;
	return p-str;
}
static long _(Read)(long *c,const char *str,long *u)
{
	static long space[8]={0x00002e00,0x00000001,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};
	static long digit[8]={0x00000000,0x03ff0000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000};
	static long alpha[8]={0x00000000,0x00000000,0x07fffffe,0x07fffffe,0x00000000,0x00000000,0x00000000,0x00000000};
	static long label[8]={0x00000000,0x03ff0000,0x87fffffe,0x07fffffe,0x00000000,0x00000000,0x00000000,0x00000000};
	long i=0,t;
	if(*str=='\\')
	{
		i=2,*c=-1,++str;
		switch(*str)
		{
			case  0 :i=0;
			break;
			case 'd':_(SetJoin)(u,u,digit,8);
			break;
			case 'D':_(SetJoinNot)(u,u,digit,8);
			break;
			case 'c':_(SetJoin)(u,u,alpha,8);
			break;
			case 'C':_(SetJoinNot)(u,u,alpha,8);
			break;
			case 'w':_(SetJoin)(u,u,label,8);
			break;
			case 'W':_(SetJoinNot)(u,u,label,8);
			break;
			case 's':_(SetJoin)(u,u,space,8);
			break;
			case 'S':_(SetJoinNot)(u,u,space,8);
			break;
			default:
				switch(*str)
				{
					case 't':t='\t';
					break;
					case 'n':t='\n';
					break;
					case 'v':t='\v';
					break;
					case 'f':t='\f';
					break;
					case 'r':t='\r';
					break;
					case 'x':if(_(Hex)(&t,str+1)==2)i=4;else t='x';
					break;
					case 'u':if(_(Hex)(&t,str+1)==4)i=6;else t='u';
					break;
					default :t=*str;
					break;
				}
				if(t<256)*c=t;else{_(SetBit)(u,t/256,1);*c=t%256;}
				_(SetBit)(u,*c,1);
			break;
		}
	}
	else if(*str)
	{
		i=1,*c=(unsigned int)*str;
		_(SetBit)(u,*c,1);
	}
	return i;
}
static _(token) *_(Occupy)(const char *str)
{
	long i,j,k,t,u,c;
	_(token) *p,*q;
	q=(_(token)*)malloc(sizeof(_(token))*(strlen(str)+1));
	for(p=q,t=1;*str && t;str+=t,++p)
	{
		switch(*str)
		{
			case '(':
			case '|':
			case ')':
			case '?':
			case '*':
			case '+':
				p->typ=*str,t=1;
			break;
			case '{':
				p->typ='{';
				if(_(IsNum)(str[1]))
				{
					i=1+_(Dec)(&j,str+1);
					if(str[i]==',')
					{
						if(_(IsNum)(str[++i]))
						{
							i+=_(Dec)(&k,str+i);
							if(str[i]!='}')goto failed;
							if(j<k)p->frm=j,p->end=k;else p->frm=k,p->end=j;
						}
						else
						{
							if(str[i]!='}')goto failed;
							p->frm=j,p->end=-1;
						}
					}
					else
					{
						if(str[i]!='}')goto failed;
						p->frm=p->end=j;
					}
				}
				else
				{
					if(str[1]!=',' || _(IsNum)(str[2])==0)goto failed;
					i=2+_(Dec)(&k,str+2);
					if(str[i]!='}')goto failed;
					p->frm=0,p->end=k;
				}
				t=i+1;
			break;
			case '[':
				p->typ='c',u=(int)(str[1]=='^');
				memset(p->unt,0,sizeof(long)*8);
				for(i=u+1,j=0,k=1,c=-1;str[i]!=']' && k;i+=k)
				{
					if(str[i]=='-')
					{
						if(j)
						{
							if(c!=-1)
							{
								for(;c<='-';++c)_(SetBit)(p->unt,c,1);
								c=-1,j=0;
							}
							else
							{
								c='-';
								_(SetBit)(p->unt,'-',1);
							}
						}
						else j=1;
						k=1;
					}
					else
					{
						t=c,k=_(Read)(&c,str+i,p->unt);
						if(j)
						{
							j=0;
							if(c!=-1 && t!=-1)
							{
								for(;t<=c;++t)_(SetBit)(p->unt,t,1);
								c=-1;
							}
							else
							{
								_(SetBit)(p->unt,'-',1);
							}
						}
					}
				}
				if(str[i]!=']')goto failed;
				if(j)_(SetBit)(p->unt,'-',1);
				if(u)_(SetAsNot)(p->unt,p->unt,8);
				_(SetBit)(p->unt,0,0);
				t=i+1;
			break;
			case '.':
				p->typ='c',t=1;
				memset(p->unt,-1,sizeof(long)*8);
				_(SetBit)(p->unt,0,0);
			break;
			default :
				p->typ='c';
				memset(p->unt,0,sizeof(long)*8);
				t=_(Read)(&c,str,p->unt);
				_(SetBit)(p->unt,0,0);
			break;
		}
	}
	p->typ=0;
	return q;
	failed:
	free(q);
	return NULL;
}
static long _(lenMBR)(const _(token) *tk)
{
	long i=0;
	for(;tk->typ;++tk)i+=(tk->typ=='c');
	return i;
}
static long _(lenNFA)(const _(token) *tk)
{
	long mb[64];
	char op[64];
	int i,j,k,t;

	for(i=j=-1,k=t=1;tk->typ;tk+=t,t=1)
	{
		if(k)
		{
			switch(tk->typ)
			{
				case 'c':++i,mb[i]=2,k=0;
				break;
				case '(':++j,op[j]='(';
				break;
				default :return 0;
				break;
			}
		}
		else
		{
			switch(tk->typ)
			{
				case '?':
				case '+':mb[i]+=1;
				break;
				case '*':mb[i]+=2;
				break;
				case '{':mb[i]=mb[i]*(tk->frm<tk->end ? tk->end : tk->frm)+(tk->end<0 || tk->frm==0);
				break;
				case ')':
				case '|':
					for(;j>=0 && op[j]!='(';--j)
					{
						--i,mb[i]+=mb[i+1]+(op[j]=='&' ? 0 : 3);
					}
					if(tk->typ==')')--j;else ++j,op[j]='|',k=1;
				break;
				default :
					for(;j>=0 && op[j]=='&';--j)
					{
						--i,mb[i]+=mb[i+1];
					}
					++j,op[j]='&',k=1,t=0;
				break;
			}
		}
	}
	for(;j>=0 && op[j]!='(';--j)
	{
		--i,mb[i]+=mb[i+1]+(op[j]=='&' ? 0 : 3);
	}
	return j<0 && i==0 ? *mb : 0;
}
static _(table) *_(Isolate)(const _(token) *tk)
{
	long x[8],y[8],z[8];
	long (*u)[8];
	long  i,j;
	_(table) *tb;

	u=(long(*)[8])malloc(sizeof(long[8])*(_(lenMBR)(tk)+1));
	memset(z,-1,sizeof(long)*8);
	for(i=0;tk->typ;++tk)
	{
		if(tk->typ=='c')
		{
			_(SetAs)(x,tk->unt,8);
			_(SetBothNot)(z,z,tk->unt,8);
			for(j=i-1;j>=0;--j)
			{
				_(SetBoth)(y,u[j],x,8);
				if(_(Exist)(y,8))
				{
					if(!_(GetSame)(y,u[j],8))
					{
						_(SetBothNot)(u[j],u[j],y,8);
						_(SetAs)(u[i++],y,8);
					}
					_(SetBothNot)(x,x,y,8);
				}
			}
			if(_(Exist)(x,8))
			{
				_(SetAs)(u[i++],x,8);
			}
		}
	}
	if(_(Exist)(z,8))
	{
		_(SetAs)(u[i++],z,8);
	}
	tb=(_(table)*)malloc(sizeof(_(table)));
	tb->unt=u,tb->len=i;
	return tb;
}
static _(NFA) *_(Analyse)(const _(token) *tk)
{
	long a,b,c,d,e,u;
	_(solve) ml,mr,*p;
	long  i,j,k,t;
	_(solve) el[64];
	char  op[64];
	_(track) *mdi;
	_(NFA) *nfa;

	t=sizeof(_(track))*_(lenNFA)(tk);
	if(t == 0)return NULL;
	mdi=(_(track)*)malloc(t);
	memset(mdi,0,t);
	for(i=j=-1,k=0,t=1,p=el-1;tk[k].typ;++k)
	{
		if(t)
		{
			switch(tk[k].typ)
			{
				case 'c':
					++p,t=0;
					++i,p->l=p->i=i;
					mdi[i].point=(long*)tk[k].unt,mdi[i].match=1;
					++i,p->r=p->o=i;
				break;
				case '(':
					++j,op[j]='(';
				break;
				default :
					goto failed;
				break;
			}
		}
		else
		{
			switch(tk[k].typ)
			{
				case '+':
					mr=*p;
					++i,p->o=p->r=i;
					mdi[mr.o].cycle=mr.i-mr.o;
					mdi[mr.o].chain=p->o-mr.o;
				break;
				case '?':
					mr=*p;
					++i,p->i=p->r=i;
					mdi[p->i].chain=mr.i-p->i;
					mdi[mr.i].alter=mr.o-mr.i;
				break;
				case '*':
					mr=*p;
					++i,p->i=i;
					++i,p->o=p->r=i;
					mdi[p->i].chain=mr.i-p->i;
					mdi[mr.o].chain=p->o-mr.o;
					mdi[mr.i].alter=mr.o-mr.i;
					mdi[mr.o].cycle=mr.i-mr.o;
				break;
				case '{':
					mr=*p;
					a=mr.l,b=mr.r;
					c=mr.i,d=mr.o;
					e=mr.r-mr.l+1;
					if(tk[k].frm > 0)
					{
						for(u=1;u < tk[k].frm;u++)
						{
							memcpy(mdi+b+1,mdi+a,sizeof(_(track))*e);
							mdi[d].chain=(c+e)-d;
							a+=e,b+=e,c+=e,d+=e;
						}
						if(tk[k].end > 0)
						{
							for(;u < tk[k].end;u++)
							{
								memcpy(mdi+b+1,mdi+a,sizeof(_(track))*e);
								mdi[d].chain=(c+e)-d;
								a+=e,b+=e,c+=e,d+=e;
								mdi[c].alter=d-c;
							}
						}
						else
						{
							mdi[d].cycle=c-d,b++;
							mdi[d].chain=b-d,d=b;
						}
					}
					else if(tk[k].end > 0)
					{
						mdi[c].alter=d-c;
						for(u=1;u < tk[k].end;u++)
						{
							memcpy(mdi+b+1,mdi+a,sizeof(_(track))*e);
							mdi[d].chain=(c+e)-d;
							a+=e,b+=e,c+=e,d+=e;
						}
						b++,p->i=b;
						mdi[p->i].chain=mr.i-p->i;
					}
					i=p->r=b,p->o=d;
				break;
				case ')':
				case '|':
					for(;j>=0 && op[j]!='(';--j)
					{
						mr=*p,--p,ml=*p;
						if(op[j]=='&')
						{
							mdi[ml.o].chain=mr.i-ml.o;
							p->r=mr.r,p->o=mr.o;
						}
						else
						{
							++i;
							mdi[i].chain=ml.i-i;
							mdi[i].alter=mr.i-i;
							++i,p->i=i;
							mdi[i].chain=-1;
							++i,p->o=p->r=i;
							mdi[ml.o].chain=mr.o-ml.o;
							mdi[mr.o].chain=p->o-mr.o;
							mdi[p->o].alter=ml.o-p->o;
						}
					}
					if(tk[k].typ==')')--j;else ++j,op[j]='|',t=1;
				break;
				default :
					for(;j>=0 && op[j]=='&';--j)
					{
						mr=*p,--p;
						mdi[p->o].chain=mr.i-p->o;
						p->r=mr.r,p->o=mr.o;
					}
					++j,op[j]='&',t=1,--k;
				break;
			}
		}
	}
	for(;j>=0 && op[j]!='(';--j)
	{
		mr=*p,--p,ml=*p;
		if(op[j]=='&')
		{
			mdi[ml.o].chain=mr.i-ml.o;
			p->r=mr.r,p->o=mr.o;
		}
		else
		{
			++i;
			mdi[i].chain=ml.i-i;
			mdi[i].alter=mr.i-i;
			++i,p->i=i;
			mdi[i].chain=-1;
			++i,p->o=p->r=i;
			mdi[ml.o].chain=mr.o-ml.o;
			mdi[mr.o].chain=p->o-mr.o;
			mdi[p->o].alter=ml.o-p->o;
		}
	}
	if(j<0 && p==el)
	{
		nfa=(_(NFA)*)malloc(sizeof(_(NFA)));
		nfa->len=p->r+1;
		nfa->etr=p->i;
		nfa->out=p->o;
		nfa->trk=mdi;
		return nfa;
	}
	failed:
	free(mdi);
	return NULL;
}
static void _(Extend)(long *u,const _(NFA) *nfa)
{
	long i,j,k,t;
	long s[128];
	for(i=j=0;i<nfa->len;i++)
		if(_(GetBit)(u,i))s[j++]=i;
	for(i=0;i<j;i++)
	{
		k=s[i];
		if((t=nfa->trk[k].alter)!=0)
		{
			if(_(GetBit)(u,k+t)==0)
			{
				_(SetBit)(u,k+t,1);
				s[j++]=k+t;
			}
		}
		if((t=nfa->trk[k].chain)!=0)
		{
			if(_(GetBit)(u,k+t)==0)
			{
				_(SetBit)(u,k+t,1);
				s[j++]=k+t;
			}
		}
		if((t=nfa->trk[k].cycle)!=0)
		{
			if(_(GetBit)(u,k+t)==0)
			{
				_(SetBit)(u,k+t,1);
				s[j++]=k+t;
			}
		}
	}
}
static _(DFA) *_(Translate)(const _(NFA) *nfa,const _(table) *evr)
{
	long i,j,k,t,a;
	long *p,*q;
	_(DFA) *dfa;

	t=nfa->len/32+(nfa->len%32!=0);
	q=(long*)malloc(sizeof(long)*t);
	p=(long*)malloc(sizeof(long)*nfa->len*t);

	dfa=(_(DFA)*)malloc(sizeof(_(DFA)));
	dfa->wid=evr->len;
	dfa->len=nfa->len/2+1;
	dfa->chr=(long*)malloc(sizeof(long)*256);
	dfa->end=(long*)malloc(sizeof(long)*dfa->len);
	dfa->tbl=(long*)malloc(sizeof(long)*dfa->len*dfa->wid);

	memset(p,0,sizeof(long)*nfa->len*t);
	_(SetBit)(p,nfa->etr,1);
	_(Extend)(p,nfa);
	for(j=i=0;j<=i;j++)
	{
		for(k=0;k<evr->len;k++)
		{
			memset(q,0,sizeof(long)*t);
			for(a=0;a<nfa->len;a++)
			{
				if(_(GetBit)(p+j*t,a))
				{
					if(nfa->trk[a].match)
					{
						if(_(GetBoth)(evr->unt[k],nfa->trk[a].point,8))
						{
							_(SetBit)(q,a+nfa->trk[a].match,1);
						}
					}
				}
			}
			if(_(Exist)(q,t))
			{
				_(Extend)(q,nfa);
				for(a=0;a<=i;a++)
				{
					if(_(GetSame)(p+a*t,q,t))break;
				}
				if(a>i)
				{
					++i;
					_(SetAs)(p+i*t,q,t);
				}
				dfa->tbl[dfa->wid*j+k]=a;
			}
			else
			{
				dfa->tbl[dfa->wid*j+k]=-1;
			}
		}
	}
	dfa->len=i+1;
	for(j=0;j<=i;j++)
	{
		dfa->end[j]=_(GetBit)(p+j*t,nfa->out) ? 1 : 0;
	}
	for(i=0;i<evr->len;++i)
	{
		for(j=0;j<256;j++)
		{
			if(_(GetBit)(evr->unt[i],j))dfa->chr[j]=i;
		}
	}
	free(p);
	free(q);
	return dfa;
}
static long _(More)(const _(DFA) *dfa,const char *str)
{
	const char *p=str,*q=p-1;
	long i,j;
	for(i=0;;i=j,++p)
	{
		if(dfa->end[i])q=p;
		j=dfa->chr[(unsigned char)(*p)];
		j=dfa->tbl[i*dfa->wid+j];
		if(j<0)break;
	}
	return q-str;
}
static long _(Less)(const _(DFA) *dfa,const char *str)
{
	const char *p=str;
	long i,j;
	for(i=0;;i=j,++p)
	{
		if(dfa->end[i])return p-str;
		j=dfa->chr[(unsigned char)(*p)];
		j=dfa->tbl[i*dfa->wid+j];
		if(j<0)break;
	}
	return -1;
}
extern regex *preg_make(const char *str)
{
	regex *reg;
	_(token) *tkn;
	_(table) *evr;
	_(NFA) *nfa;
	_(DFA) *dfa;
	char  *mdi;
	long   i;

	reg=(regex*)malloc(sizeof(regex));
	i=strlen(str)-1;
	reg->end=(str[i]=='$' && str[i-1]!='\\');
	reg->bgn=(str[0]=='^');
	i+=1-reg->bgn-reg->end;
	mdi=(char*)malloc(i+1);
	strncpy(mdi,str+reg->bgn,i);
	mdi[i]=0;
	tkn=_(Occupy)(mdi);
	if(tkn)
	{
		nfa=_(Analyse)(tkn);
		if(nfa)
		{
			evr=_(Isolate)(tkn);
			dfa=_(Translate)(nfa,evr);
			free(nfa->trk);
			free(nfa);
			free(evr->unt);
			free(evr);
			reg->dfa=dfa;
			return reg;
		}
		free(tkn);
	}
	free(mdi);
	free(reg);
	return NULL;
}
extern long preg_more(const regex *reg,const char *str)
{
	long l;
	if(reg==NULL)return  -1;
	l=_(More)(reg->dfa,str);
	if(l>=0)
	{
		if((reg->end==0)||(str[l]=='\n' || str[l]=='\r' || str[l]=='\0'))return l;
	}
	return -1;
}
extern long preg_less(const regex *reg,const char *str)
{
	long l;
	if(reg==NULL)return  -1;
	l=_(Less)(reg->dfa,str);
	if(l>=0)
	{
		if((reg->end==0)||(str[l]=='\n' || str[l]=='\r' || str[l]=='\0'))return l;
	}
	return -1;
}
extern group preg_find(const regex *reg,const char *str)
{
	group ans;
	long  i,j;
	if(reg==NULL)goto failed;
	if(reg->bgn)
	{
		for(i=0;;++i)
		{
			j=_(More)(reg->dfa,str+i);
			if(j>=0)
			{
				if((reg->end==0)||(str[i+j]=='\n' || str[i+j]=='\r' || str[i+j]=='\0'))
				{
					ans.pos=i,ans.len=j;
					return ans;
				}
			}
			for(;;++i)
			{
				if(str[i]=='\r' || str[i]=='\n')break;
				if(str[i]=='\0')goto failed;
			}
		}
	}
	else
	{
		for(i=0;str[i];++i)
		{
			j=_(More)(reg->dfa,str+i);
			if(j>=0)
			{
				if((reg->end==0)||(str[i+j]=='\n' || str[i+j]=='\r' || str[i+j]=='\0'))
				{
					ans.pos=i,ans.len=j;
					return ans;
				}
			}
		}
	}
	failed:
	ans.pos=ans.len=-1;
	return ans;
}
/*
extern void preg_show(const regex *reg,long typ)
{
	long i,j,t;
	if(reg==NULL)return;
	t=reg->dfa->wid;
	if(typ)
	{
		printf("char :\n");
		for(i=0;i<t-(typ>0);i++)
		{
			printf("    [%02ld] ",i);
			for(j=0;j<256;j++)
			{
				if(reg->dfa->chr[j]==i)printf("%c",(char)(j));
			}
			printf("\n");
		}
	}
	printf("table :\n         ");
	for(i=0;i<reg->dfa->wid;i++)printf("[%02ld]",i);
	printf("\n");
	for(i=0;i<reg->dfa->len;i++)
	{
		printf("    [%02ld] ",i);
		for(j=0;j<reg->dfa->wid;j++)
		{
			t=reg->dfa->tbl[i*reg->dfa->wid+j];
			if(t>=0)printf(" %02ld ",t);else printf(" -- ");
		}
		printf("\n");
	}
	printf("exit :\n    ");
	for(i=0;i<reg->dfa->len;i++)
	{
		if(reg->dfa->end[i])printf("%ld ",i);
	}
	printf("\n");
	printf("head : %d\n",(int)reg->bgn);
	printf("tail : %d\n",(int)reg->end);
}*/
extern void preg_free(regex *reg)
{
	if(reg==NULL)return;
	free(reg->dfa->chr);
	free(reg->dfa->end);
	free(reg->dfa->tbl);
	free(reg->dfa);
	free(reg);
}

#undef _

#endif
