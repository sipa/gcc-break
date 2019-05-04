#include "hash.h"
#include "sha.h"

#include <assert.h>

int main() {
    for (int i = 0; i <= 32; ++i) {
        unsigned char in[64 * 32];
        unsigned char out1[32 * 32], out2[32 * 32];
        for (int j = 0; j < 64 * i; ++j) {
            in[j] = (unsigned char)(j+192);
        }
        for (int j = 0; j < i; ++j) {
            CHash256().Write(in + 64 * j, 64).Finalize(out1 + 32 * j);
        }
        SHA256D64(out2, in, i);
    }
}
