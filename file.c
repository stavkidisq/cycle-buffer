#include "file.h"

void readfile(const char* filename, unsigned short int* buff, int index)
{
    FILE* fstream = openfile(filename, "rb");

    printf("Read file to buffer...\n");

    fread(buff, sizeof(unsigned short int), index, fstream);

    fclose(fstream);
}

void write2file(const char* filename, unsigned short int* buff, int index)
{
    FILE* fstream = openfile(filename, "wb");

    printf("Writing the buffer to a file...\n");

    fwrite(buff, sizeof(unsigned short int), index, fstream);

    fclose(fstream);
}

FILE* openfile(const char* filename, const char* mode)
{
    FILE* fstream = NULL;

    printf("Opening file...\n");

    if((fstream = fopen(filename, mode)) == NULL)
    {
        printf("No such file");
        exit(EXIT_FAILURE);
    }

    return fstream;
}
