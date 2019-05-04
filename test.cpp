#include <assert.h>

void set_one(unsigned char* ptr);
int check_zero(unsigned char const* in, unsigned int len);

void set_one_on_stack() {
    unsigned char buf[1];
    set_one(buf);
}

int main() {
    for (int i = 0; i <= 4; ++i) {
        unsigned char in[4];
        for (int j = 0; j < i; ++j) {
            in[j] = 0;
        }
        for (int j = 0; j < i; ++j) {
            set_one_on_stack(); // Apparently modifies in[0]
        }
        assert(check_zero(in, i));
    }
}
