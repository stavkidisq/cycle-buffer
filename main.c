#include <stdio.h>
#include <stdlib.h>

#include "file.cpp"

const int BUFF_SIZE = 32000;
const int N = 5;
const int BUFF_COUNT = 32000 / sizeof(unsigned short int);

void fillbuff(unsigned short int*);
void rfillbuff(unsigned short int*);

void swap_buff_items(unsigned short int*);
void reverse(unsigned short int*, int, int);

void cyclic_shift(unsigned short int*);

unsigned short int* initbuff();

/*
    Имя программы: cycle-buffer.
    Назначение программы: циклический сдвиг буффера.
    Автор: Рабцевич Александр.
    Дата создания: 31.10.22.
*/
int main()
{
    unsigned short int* buff = initbuff();
    unsigned short int* rotate_buff = initbuff();
    unsigned short int* straight_buff = initbuff();

    fillbuff(buff);
    write2file("file-1.bin", buff, BUFF_COUNT);

    rfillbuff(buff);
    write2file("file-2.bin", buff, BUFF_COUNT);

    readfile("file-1.bin", straight_buff, BUFF_COUNT);
    readfile("file-2.bin", rotate_buff, BUFF_COUNT);

    swap_buff_items(straight_buff);
    swap_buff_items(rotate_buff);

    cyclic_shift(straight_buff);
    cyclic_shift(rotate_buff);

    write2file("file-3.bin", straight_buff, BUFF_COUNT);
    write2file("file-4.bin", rotate_buff, BUFF_COUNT);

    free(buff);
    free(straight_buff);
    free(rotate_buff);

    printf("Program was exit.");

    return 0;
}

void fillbuff(unsigned short int* buff)
{
    printf("Filling the buffer...\n");

    for (unsigned short int i = 0; i < BUFF_COUNT; i++)
    {
        buff[i] = i;
    }
}

void rfillbuff(unsigned short int* buff)
{
    printf("Rotate filling...\n");

    unsigned int imax = BUFF_COUNT - 1;

    for (unsigned short int i = 0; i <= imax; i++)
    {
        buff[i] = imax - i;
    }
}

void cyclic_shift(unsigned short int* buff)
{
    reverse(buff, 0, N - 1);
    reverse(buff, N, BUFF_COUNT - 1);
    reverse(buff, 0, BUFF_COUNT - 1);
}

void reverse(unsigned short int* buff, int left, int right)
{
    unsigned short int temp;

    while(left < right)
    {
        temp = buff[left];
        buff[left] = buff[right];
        buff[right] = temp;

        left++;
        right--;
    }
}

void swap_buff_items(unsigned short int* buff)
{
    unsigned short int temp;

    for(unsigned short int i = 1; i < BUFF_COUNT; i+=2)
    {
        temp = buff[i];
        buff[i] = buff[i-1];
        buff[i-1] = temp;
    }
}

unsigned short int* initbuff()
{
    printf("Buffer initialization...\n");

    unsigned short int* buff = (unsigned short int*)malloc(BUFF_SIZE);

    if(buff == NULL)
    {
        printf("Failed to allocate, aborting...\n");
        exit(-1);
    }

    return buff;
}
