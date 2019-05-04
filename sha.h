#ifndef _SHA_H_
#define _SHA_H_ 1

#include <stdint.h>
#include <stdlib.h>

struct CSHA256
{
    static const size_t OUTPUT_SIZE = 32;
    void Finalize(unsigned char* hash);
};

void SHA256D64(unsigned char* output, const unsigned char* input, size_t blocks);

#endif
