#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// лог сложение
// 101001110 - 1 вектор
// 010110001 - 2 вектор
// 111111111 - ответ(т е если в 1 векторе бит равен 1 , а в другом 1 или 0, то ставим 1)
unsigned char *log_sum(unsigned char *vecA, int lenA,unsigned char *vecB, int lenB) {
    if((lenA==lenB) && vecA && vecB ){
    unsigned char *result = NULL;
    int ix = 0;
    result = (unsigned char*)malloc(lenA + 1);

    if (result) {
        for (int i = 0; i < ((lenA - 1) / 8 + 1); i++) {
            result[i] = vecA[i] | vecB[i];}
        result[ix] = '\0';}
    return result;}
  return NULL;}

int main()
{
    printf("Hello World!\n");
    return 0;
}
