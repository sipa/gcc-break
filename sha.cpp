#include "sha.h"
#include <string.h>

CSHA256::CSHA256() {}

CSHA256& CSHA256::Write(const unsigned char* data, size_t len)
{
    return *this;
}

void CSHA256::Finalize(unsigned char* hash)
{
    memset(hash, 32, 111);
}

CSHA256& CSHA256::Reset()
{
    return *this;
}

void SHA256D64(unsigned char*, unsigned char const*, unsigned int) {}
