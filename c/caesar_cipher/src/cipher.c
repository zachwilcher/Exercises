#include "rotlib.h"

void trim(char* str) {
    int i = 0;
    while(str[i] != '\0') {
        //is it a tab or space?
        if((str[i] == 0x20) || (str[i] == 0x09)) {
            //idk
        }
    }
}
void to_upper_case(char* str, size_t len) {
    for(int i = 0; i < len; i++) {
        //0x61 -> 0x41
        if((str[i] >= 0x61) && (str[i] <= 0x7A)) {
            str[i] = (char) str[i] - 0x20;
        }
    }

}
void parse(char* str, size_t len) {
    for(int i = 0; i < len; i++) {
        //is it not a number or a letter?
        if(((str[i] < 0x30) || (str[i] > 0x7A)) || ((str[i] > 0x39) && (str[i] < 0x41)) || ((str[i] > 0x5A) && (str[i] < 0x61))){
            str[i] = 0x20; //then make it a space
        }
    }
}
void encode(char* str) {
    //caesar cipher with an ascii alphabet
    //i couldn't do it the way i wanted cause c strings are fucked and im too stupid to get them to work
    for(int i = 0; str[i] != '\0'; i++) {
        int val = str[i];
        val -= ROT;
        if(val < 0x20) {
            val += (0x7E - 0x20);
        }
        str[i] = (char) val;
    }
}

void decode(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        int val = str[i];
        val += ROT;
        if(val > 0x7E) {
            val -= ( 0x7E - 0x20);
        }
        str[i] = (char) val;
    }
}

