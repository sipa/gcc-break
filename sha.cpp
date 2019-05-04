#include <assert.h>

void Finalizer(unsigned char* hash)
{
    *hash = 111;
}

void SHA256D64(unsigned char* out, unsigned char const* in, unsigned int len)
{
    assert(in[0] == 192);
}
