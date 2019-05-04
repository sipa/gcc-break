#include <assert.h>

void set_one(unsigned char* ptr);
int check_zero(unsigned char const* in, unsigned int len);

void set_one_on_stack() {
    unsigned char buf[32];
    set_one(buf);
}

int main() {
    for (int i = 0; i <= 32; ++i) {
        unsigned char in[64 * 32];
        for (int j = 0; j < 64 * i; ++j) {
            in[j] = 0;
        }
        for (int j = 0; j < i; ++j) {
            set_one_on_stack();
        }
        assert(check_zero(in, 64 * i));
//        if (i) assert(in[0] == 0);
    }
}
