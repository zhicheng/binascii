#include <stdio.h>
#include <string.h>

#include "binascii.h"

int
main(void)
{
	unsigned char hello[] = "hello";
	char hex[sizeof(hello) * 2 + 1];
	bzero(hex, sizeof(hex));

	binascii_hexlify(hello, sizeof(hello), hex);
	printf("hexlify: %s\n", hex);

	bzero(hello, sizeof(hello));
	binascii_unhexlify(hex, sizeof(hex), hello);
	printf("unhexlify: %s\n", hello);

	return 0;
}

