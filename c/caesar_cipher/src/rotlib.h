#ifndef ROTLIB_H
#define ROTLIB_H
#include <stdio.h>
#define ROT 3

void trim(char* str);

void to_upper_case(char* str, size_t len);

void parse(char* str, size_t len);

void encode(char* str);

void decode(char* str);
#endif
