#ifndef __BINASCII_H__
#define __BINASCII_H__

enum {BINASCII_OK = 0};

int
binascii_hexlify(unsigned char *in, int inlen, char *out);

int
binascii_unhexlify(char *in, int inlen, unsigned char *out);

#endif /* _BINASCII_H__ */

