#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void readfile(const char*, unsigned short int*, int);
void write2file(const char*, unsigned short int*, int);

FILE* openfile(const char*, const char*);

#endif // FILE_H
