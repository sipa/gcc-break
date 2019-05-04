void Finalizer(unsigned char* hash);
void SHA256D64(unsigned char* output, const unsigned char* input, unsigned int blocks);

struct CHash256 {
    void Finalize(unsigned char* hash) {
        unsigned char buf[32];
        Finalizer(buf);
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
