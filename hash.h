#ifndef _HASH_H_
#define _HASH_H_ 1

#include "sha.h"

class CHash256 {
private:
    CSHA256 sha;
public:
    void Finalize(unsigned char* hash) {
        unsigned char buf[32];
        sha.Finalize(buf);
        sha.Reset().Write(buf, 32).Finalize(hash);
    }
};

#endif
