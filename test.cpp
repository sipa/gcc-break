#include "sha.h"

class CHash256 {
private:
    CSHA256 sha;
public:
    static const size_t OUTPUT_SIZE = CSHA256::OUTPUT_SIZE;

    void Finalize(unsigned char* hash) {
        unsigned char buf[CSHA256::OUTPUT_SIZE];
        sha.Finalize(buf);
    }
};

int main() {
    for (int i = 0; i <= 32; ++i) {
        unsigned char in[64 * 32];
        unsigned char out1[32 * 32], out2[32 * 32];
        for (int j = 0; j < 64 * i; ++j) {
            in[j] = (unsigned char)(j+192);
        }
        for (int j = 0; j < i; ++j) {
            CHash256().Finalize(out1 + 32 * j);
        }
        SHA256D64(out2, in, i);
    }
}
