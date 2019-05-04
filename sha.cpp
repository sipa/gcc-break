#include <assert.h>

void set_one(unsigned char* ptr)
{
    *ptr = 1;
}

void check_in_zero(unsigned char* out, unsigned char const* in, unsigned int len)
{
    for (unsigned int i = 0; i < 64 * len; ++i) {
        assert(in[i] == 0);
    }
}
