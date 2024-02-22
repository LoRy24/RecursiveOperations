//
// Created by Lorenzo Rocca on 20/02/24.
//

#ifndef STAMENU_SECUREREADING_H
#define STAMENU_SECUREREADING_H

#include <stdio.h>

void scanInteger(const char* message, const char* errMessage, int* destination);
void scanCharacter(const char* message, char* destination);

#endif //STAMENU_SECUREREADING_H
