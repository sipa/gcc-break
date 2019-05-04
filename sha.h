#ifndef _SHA_H_
#define _SHA_H_ 1

void Finalizer(unsigned char* hash);
void SHA256D64(unsigned char* output, const unsigned char* input, unsigned int blocks);

#endif
