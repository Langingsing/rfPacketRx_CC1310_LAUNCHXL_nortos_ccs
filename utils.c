#include "utils.h"
#include <stdlib.h>
#include <string.h>

size_t utils_long2str(long val, char *buffer, int radix) {
    register int i = 2;
    long quot;
#define BUFSIZE (sizeof(long) * 8 + 1)
    char *tail, *head = buffer, buf[BUFSIZE];

    if (36 < radix || 2 > radix)
        radix = 10;                    /* can only use 0-9, A-Z        */
    tail = &buf[BUFSIZE - 1];           /* last character position      */
    *tail-- = '\0';
#undef BUFSIZE

    if (10 == radix && val < 0L) {
        *head = '-';
        head++;
        quot = -val;
    } else
        quot = val;

    if (quot) {
        for (i = 1; quot; ++i) {
            register ldiv_t r = ldiv(quot, radix);

            *tail = r.rem + ((9L < r.rem) ?
                             ('A' - 10L) : '0');
            tail--;
            quot = r.quot;
        }
    } else
        *tail-- = '0';

    memcpy(head, tail + 1, i);
    return head - buffer + i - 1;
}
