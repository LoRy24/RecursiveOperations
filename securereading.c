//
// Created by Lorenzo Rocca on 20/02/24.
//

#include "securereading.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

void scanInteger(const char* message, const char* errMessage, int* destination) {
    int outCode;
    do {
        printf("%s", message);
        int result = scanf("%d", destination);

        if (!result) {
            printf("%s", errMessage);
            while (getchar() != '\n');
            outCode = -1;
            continue;
        }

        outCode = 0;
    } while (outCode == -1);

    while (getchar() != '\n');
}

void scanCharacter(const char* message, char* destination) {
    int outCode;
    do {
        printf("%s", message);
        int result = scanf("%c", destination);

        if (!result) {
            while (getchar() != '\n');
            outCode = -1;
            continue;
        }

        outCode = 0;
    } while (outCode == -1);

    while (getchar() != '\n');
}

#pragma clang diagnostic pop
