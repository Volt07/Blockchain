#include "hash.h"
#include <stdint.h>
#include <string.h>

// Lightweight mixing-based hash to produce DIGEST_SIZE bytes.
// This is intentionally simple for demonstration/testing; not for real crypto.
unsigned char* SSHA(const unsigned char* msg, size_t length) {
    uint32_t a = 0x67452301u;
    uint32_t b = 0xEFCDAB89u;
    uint32_t c = 0x98BADCFEu;
    uint32_t d = 0x10325476u;
    uint32_t e = 0xC3D2E1F0u;

    for (size_t i = 0; i < length; ++i) {
        uint32_t m = (uint32_t)msg[i];
        uint32_t f = (b & c) | (~b & d);
        uint32_t temp = ((a << 5) | (a >> 27)) + f + e + m + 0x9E3779B9u;
        e = d;
        d = c;
        c = (b << 30) | (b >> 2);
        b = a;
        a = temp;
        if ((i & 7) == 7) {
            // extra scramble every 8 bytes
            a ^= (uint32_t)(i * 0x7FEDu);
            b += (uint32_t)(i * 0xA3C5u);
            c ^= b;
        }
    }

    unsigned char* digest = (unsigned char*)malloc(DIGEST_SIZE);
    if (!digest) return NULL;
    digest[0] = (unsigned char)((a >> 24) & 0xFF);
    digest[1] = (unsigned char)((b >> 16) & 0xFF);
    digest[2] = (unsigned char)((c >> 8) & 0xFF);
    digest[3] = (unsigned char)(d & 0xFF);
    digest[4] = (unsigned char)((e >> 8) & 0xFF);
    return digest;
}


int digest_equal(struct Digest digest1, struct Digest digest2) {
    return ((digest1.hash0 == digest2.hash0) &&
        (digest1.hash1 == digest2.hash1) &&
        (digest1.hash2 == digest2.hash2) &&
        (digest1.hash3 == digest2.hash3) &&
        (digest1.hash4 == digest2.hash4));
    
}

void printDigest(struct Digest digest) {
    printf("%d %d %d %d %d\n", digest.hash0, digest.hash1, digest.hash2, digest.hash3, digest.hash4);
}