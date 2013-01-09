/* This is a public domain Python binascii C implementation written by WEI Zhicheng. */

#include <ctype.h>

#include "binascii.h"

/* this code is stolen from CPython binascii module */

static char hexdigits[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f'
};

static int
to_int(int c)
{
        if (isdigit(c))
                return c - '0';
        else {
                if (isupper(c))
                        c = tolower(c);
                if (c >= 'a' && c <= 'f')
                        return c - 'a' + 10;
        }
        return -1;
}

/* caller need be sure out is enough for hex (inlen*2) */
int
binascii_hexlify(unsigned char in[], int inlen, char out[])
{
	int i, j;
	for (i = j = 0; i < inlen; i++) {
		int top = (in[i] >> 4) & 0xF;
		int bot = in[i] & 0xF;
		out[j++] = hexdigits[top];
		out[j++] = hexdigits[bot];
	}
	return BINASCII_OK;
}

/* caller need be sure out is enough for hex (inlen/2) */
/* inlen % 2 == 0, or behavior undefined */
int
binascii_unhexlify(char in[], int inlen, unsigned char out[])
{
        int i, j;
        for (i = j = 0; i < inlen; i += 2) {
                int top = to_int(in[i] & 0xFF);
                int bot = to_int(in[i+1] & 0xFF);
                if (top == -1 || bot == -1)
                        return -1;
                out[j++] = (top << 4) + bot;
        }
	return BINASCII_OK;
}

