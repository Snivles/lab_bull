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
    size_t size_byte = ((lenA +7) / 8);
    result = (unsigned char*)malloc(size_byte);

    if (result) {
        for (size_t i = 0; i < size_byte; i++) {
            result[i] = vecA[i] | vecB[i];}}
    return result;}
  return NULL;}


//логическое умножение
// 101001110 - 1 вектор
// 010110001 - 2 вектор
// 000000000 - ответ(т е если в 1 векторе бит равен 1 , а в другом 1, то ставим 1 в других случаях 0) !! обратное искл или

unsigned char *log_ymnojenie(unsigned char *vecA, int lenA,unsigned char *vecB, int lenB) {
    if((lenA==lenB) && vecA && vecB ){
    unsigned char *result = NULL;
    size_t size_byte = ((lenA +7) / 8);
    result = (unsigned char*)malloc(size_byte);

    if (result) {
        for (size_t i = 0; i < size_byte; i++) {
            result[i] = vecA[i] & vecB[i];}}
    return result;}
  return NULL;}


//Искл или(Сумма по модулю 2)
// 101001110 - 1 вектор
// 010110001 - 2 вектор
// 111111111 - ответ(т е если в 1 векторе бит равен 1 , а в другом 0, то ставим 1)
unsigned char *sumMod2(unsigned char *vecA, int lenA,unsigned char *vecB, int lenB) {
    if((lenA==lenB) && vecA && vecB ){
    unsigned char *result = NULL;
    size_t size_byte = ((lenA +7) / 8);
    result = (unsigned char*)malloc(size_byte);

    if (result) {
        for (size_t i = 0; i < size_byte; i++) {
            result[i] = vecA[i] ^ vecB[i];}}
    return result;}
  return NULL;}


unsigned char *invertor(unsigned char *vec, int len) {
    if (vec){
    unsigned char *result = NULL;
    size_t size_byte = ((len +7) / 8);
    result = (unsigned char*)malloc(size_byte);
    if (result) {
        for (size_t i = 0; i < size_byte; i++) {
            result[i] = ~vec[i];

        if (i == size_byte && (len % 8 != 0)) { // очистка хвоста путем определения его длины сдвига маски и лог умножения
            int ostat = len % 8;
            unsigned char clean = (1 << ostat) - 1;
            result[i] = result[i] & clean;}}}
    return result;}
    return NULL;}

int main()
{
    printf("Hello World!\n");
    return 0;
}
