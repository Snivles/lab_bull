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

//Инверсия
// 101001110
// 010110001 (т е если встретили 1 то меняем на 0 и наоборот)
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



// установка k-того разряда
// 110111 , хочу вместо 0 поставить 1 , тогда мне нужно сделать маску где я сдвину в ней одну 1 на k мест, т.e. 001000 применить сложение логи
void set_bit_1(unsigned char *vec, size_t len,size_t k)
{   if (k < len){
    int byte = 0;
    unsigned char mask = 1;
    byte = k/8; //номер  ячейки
    int bit = k%8; // номер разряда  в ячейке
    mask = mask << bit;
    vec[byte] = vec[byte] | mask;}
}
// сброс k-того разряда
// 111111 хочу на том же месте убрать 1, тогда мне надо сделать маску где я сдвину в ней одну 1 на k мест, t.e 001000 инвертирую 110111
// и сделаю лог умнож( ИЛИ это (искл или) но да ладно)
void sbros_bit_1(unsigned char *vec, size_t len,size_t k)
{   if (k < len){
    int byte = 0;
    unsigned char mask = 1;
    byte = k/8; //номер  ячейки
    int bit = k%8; // номер разряда  в ячейке
    mask = mask << bit;
    vec[byte] = vec[byte] ^ mask;}
}



unsigned char *convertStrtoLongBv(char *str, int*cells){
  if(str && cells){
    int len = 0, ix = 0;
    len = strlen(str);
    *cells = ((len-1)/8 + 1);
    unsigned char *vec = (unsigned char*)malloc(sizeof(unsigned char) * (*cells));
    for (int i = 0; i < *cells; i++) {vec[i] = 0;}
    for (int i = 0; i < *cells; i++)
      {
        for (int j = 0; j < 8 && (ix < len); j++){
              vec[i] = vec[i] << 1;

              if(str[ix] != '0'){
                      vec[i] = vec[i] | 1;}
              ix++;}}
  return vec;}
  return NULL;}


char *convertLongBvToStr(unsigned char *vec, size_t sz){
  int ix = 0;
  unsigned char mask =1;
  char* str = NULL;
  if (vec){
    int len = 8 * sz + 1;
    str =(char*)malloc(len);
    if (str){
        for (size_t i = 0; i < sz; i++){
            mask = 1;
            for (int j = 0; j < 8 && (ix < len); j++){
                if ((vec[i]&mask)!=0){str[ix] = '1';}
                else{str[ix]='0';}
                ix++;
                mask = mask << 1;}}
        str[ix] = '\0';
      }
    }
  return str;
}




int main()
{
  char *strA = "10100111";
  char *strB = "01011000";

  int cellsA, cellsB;
  unsigned char *vecA = convertStrtoLongBv(strA, &cellsA);
  unsigned char *vecB = convertStrtoLongBv(strB, &cellsB);
}
