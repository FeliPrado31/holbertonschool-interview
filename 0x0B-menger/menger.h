#ifndef MENGER_SPONGE_H
#define MENGER_SPONGE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void menger(int level);
char **makeBoard(size_t size);
void freeBoard(char **sponge, size_t size);
void makeLevel(char **sponge, int level, size_t i, size_t j, short center,
                 size_t limitI, size_t limitJ);
void printBoard(char **sponge, size_t size);

#endif