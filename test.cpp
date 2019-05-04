#include "sha.h"

class CHash256 {
private:
    CSHA256 sha;
public:
    static const size_t OUTPUT_SIZE = CSHA256::OUTPUT_SIZE;

    void Finalize(unsigned char* hash) {
        unsigned char buf[CSHA256::OUTPUT_SIZE];
        sha.Finalize(buf);
        sha.Reset().Write(buf, CSHA256::OUTPUT_SIZE).Finalize(hash);
    }

    CHash256& Write(const unsigned char *data, size_t len) {
        sha.Write(data, len);
        return *this;
    }

    CHash256& Reset() {
        sha.Reset();
        return *this;
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
            CHash256().Write(in + 64 * j, 64).Finalize(out1 + 32 * j);
        }
        SHA256D64(out2, in, i);
    }
}
