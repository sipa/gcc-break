void set_one(unsigned char* ptr);
void check_in_zero(unsigned char* out, unsigned char const* in, unsigned int len);

void set_one_on_stack(unsigned char* hash) {
    unsigned char buf[32];
    set_one(buf);
}

int main() {
    for (int i = 0; i <= 32; ++i) {
        unsigned char in[64 * 32];
        unsigned char out1[32 * 32], out2[32 * 32];
        for (int j = 0; j < 64 * i; ++j) {
            in[j] = 0;
        }
        for (int j = 0; j < i; ++j) {
            set_one_on_stack(out1 + 32 * j);
        }
        check_in_zero(out2, in, i);
    }
}
