//!---------------------------------------------------------------------
size_t 		hiddenCount(void** v) {
    size_t i=0;
    while (v[i]!=NULL) {
        ++i;
    }
    return i;
}
//!---------------------------------------------------------------------
size_t 		hiddenStrlen(char *str) {
    register char *s;
    for (s = str; *s; ++s);
    return(s - str);
}
//!---------------------------------------------------------------------
uni 		hiddenSch(char* str, char ch) {
    uni i=0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            return 1;
        }
        ++i;
    }
    return 0;
}
//!---------------------------------------------------------------------
uni 		hiddenScmp(char* str1, char* str2) {
    uni si1=hiddenStrlen(str1);
    uni si2=hiddenStrlen(str2);
    if (si1>si2) {
        return 1;
    }
    if (si1<si2) {
        return -1;
    }
    if (si1==si2) {
        uni i;
        for (i=0;i<si1;i++) {
            if (str1[i]!=str2[i]) {
                return 0;
            }
        }
    }
    return 2;
}
//!---------------------------------------------------------------------
char * 		hiddenStrstr(char *string, char *substring) {
    register char *a, *b;
    b = substring;
    if (*b == 0) {
        return string;
    }
    for ( ; *string != 0; string += 1) {
        if (*string != *b) {
            continue;
        }
        a = string;
        while (1) {
            if (*b == 0) {
                return string;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = substring;
    }
    return (char *) 0;
}
//!---------------------------------------------------------------------
uni 		hiddenStrnpos(char* str, char* sub, int ot) {
    int pFind = 0, pos = 0;
    str=str+ot;
    if (hiddenStrstr(str,sub)) {
        pFind= hiddenStrlen(hiddenStrstr(str, sub));
        pos = hiddenStrlen(str+pFind);
    }
    return pos;
}
//!---------------------------------------------------------------------
uni 		hiddenSubstr_count(char* str_s, char* sub_s) {
    uni count_sub=0;
    str_s = hiddenStrstr(str_s,sub_s);
    while (str_s!=0) {
        str_s=str_s+hiddenStrlen(sub_s);
        str_s = hiddenStrstr(str_s,sub_s);
        count_sub++;
    }
    return count_sub;
}
//!---------------------------------------------------------------------
void *		hiddenMemcpy (void *dest, void *src, size_t n) {
    register char *r1 = dest;
    register char *r2 = src;
    while (n) {
        *r1++ = *r2++;
        --n;
    }
    return dest;
}
//!---------------------------------------------------------------------
int 		hiddenStrncmp(char* s1, char* s2, size num) {
    if (num == 0) {
        return 0;
    }
    do {
        if (*s1 != *s2++) {
            return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
        }
        if (*s1++ == 0) {
            break;
        }
    } while (--num != 0);
    return 0;
}
char * 		hiddenString_replace(char *string, char *delimiter, char *replacement) {
    if (!hiddenStrstr(string,delimiter)) {
        return string;
    }
    int bret = 0, ldel=hiddenStrlen(delimiter), lrep=hiddenStrlen(replacement), i=0,j=0;
    char* ret = out_Hstr_rep;
    while (string[i] != '\0') {
        if (!hiddenStrncmp(&string[i], delimiter, ldel)) {
            i += ldel;
            j += lrep;
            bret = 1;
        } else {
            i++;
            j++;
        }
    }
    i = 0;
    j = 0;
    while (string[i] != '\0') {
        if (!hiddenStrncmp(&string[i], delimiter, ldel)) {
            hiddenMemcpy(&ret[j], replacement, lrep);
            i += ldel;
            j += lrep;
        } else {
            ret[j] = string[i];
            i++;
            j++;
        }
    }
    ret[j] = '\0';
    return ret;
}
//!---------------------------------------------------------------------
char * 		hiddenUtos(uni n) {
    *_Hslong+=0;
    uni i, sign,j;
    uni num=n;
    uni l = 0;
    if (num==0) {
        l++;
    }
    if (num<0) {
        num= -num;
        l++;
    }
    while (num) {
        num/=10;
        ++l;
    }
    if ((sign = n) < 0) {
        n = -n;
        l++;
    }
    i = 0;
    do {
        _Hslong[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        _Hslong[i++] = '-';
        l--;
    }
    _Hslong[i] = '\0';
    i = 0;
    j=l-1;
    while (j>i) {
        swap(_Hslong[i],_Hslong[j]);
        i++;
        j--;
    }
    return _Hslong;
}
//!---------------------------------------------------------------------
int 		hiddenIs_num(char* str) {
    int i=0, pr=0;
    while (str[i]!=0) {
        switch (str[i]) {
        case '-':
            pr++;
            break;
        case '0':
            pr++;
            break;
        case '1':
            pr++;
            break;
        case '2':
            pr++;
            break;
        case '3':
            pr++;
            break;
        case '4':
            pr++;
            break;
        case '5':
            pr++;
            break;
        case '6':
            pr++;
            break;
        case '7':
            pr++;
            break;
        case '8':
            pr++;
            break;
        case '9':
            pr++;
            break;
        default :
            pr=-1;
            break;
        }
        i++;
    }
    if (i==pr) {
        return 1;
    } else {
        return 0;
    }
}
//!---------------------------------------------------------------------
void fun_null(void){return;}

