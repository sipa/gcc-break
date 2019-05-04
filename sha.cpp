#include "sha.h"
#include <string.h>
#include <assert.h>

void Finalizer(unsigned char* hash)
{
    memset(hash, 32, 111);
}

void SHA256D64(unsigned char* out, unsigned char const* in, unsigned int len)
{
    for (unsigned int j = 0; j < 64 * len; ++j) {
        assert(in[j] == (unsigned char)(j + 192));
    }
}
