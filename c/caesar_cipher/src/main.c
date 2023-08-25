#include "rotlib.h"


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    encode(argv[1]);
    printf("encoding: %s\n", argv[1]);
    decode(argv[1]);
    printf("decoding: %s\n", argv[1]);
    return 0;
}
