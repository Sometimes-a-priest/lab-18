#pragma once
#ifndef INC_STRING__H
#define INC_STRING__H

#include < stdint.h >
#include < assert.h >
#include < memory.h >
#include < stdio.h >
#include < stdbool.h >
#include <stdlib.h>
#include <malloc.h>
#include < ctype.h >

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef struct WordDescriptor {
	char* begin; // позиция начала слова
	char* end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
	WordDescriptor words[MAX_N_WORDS_IN_STRING];
	size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
	FIRST_WORD_WITH_A,
	NOT_FOUND_A_WORD_WITH_A,
	WORD_FOUND,
	EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

BagOfWords _bag;
BagOfWords _bag2;

//возвращает количество символов в строке
size_t strlen_(const char* begin);

//возвращает указатель на первый элемент с кодом ch
char* find(char* begin, char* end, int ch);

//возвращает указатель на первый символ, отличный от пробельных.
//если символ не найден, возвращается адрес первого ноль-символа
char* findNonSpace(char* begin);

//возвращает указатель на первый пробельный символ
//или на первый ноль - символ
char* findSpace(char* begin);

//возвращает указатель на первый справа символ, отличный от пробельных 
// если символ не найден, возвращается адрес rend
char* findNonSpaceReverse(char* rbegin, const char* rend);

//возвращает указатель на первый пробельный символ справа 
//если символ не найден,возвращается адрес rend
char* findSpaceReverse(char* rbegin, const char* rend);

//возвращает значение > 0 если lhs > rhs
//если lhs == rhs - 0, иначе < 0 
int strcmp(const char* lhs, const char* rhs);

//возвращает указатель на следующий свободный фрагмент памяти в destination
//записывает по адресу beginDestination фрагмент памяти, 
//начиная с адреса beginSource до endSource
char* copy(const char* beginSource, const char* endSource,
	char* beginDestination);

//возвращает указатель на следующий свободный для записи фрагмент в памяти
//записывает по адресу beginDestination элементы из фрагмента памяти 
//начиная с beginSource заканчивая endSource, 
//удовлетворяющие функции - предикату f
char* copyIf(char* beginSource, const char* endSource,
	char* beginDestination, int (*f)(int));

//возвращает значение beginDestination записывает по адресу beginDestination 
// элементы из фрагмента памяти начиная с rbeginSource заканчивая rendSource,
// удовлетворяющие функции - предикату f
char* copyIfReverse(char* rbeginSource, const char* rendSource,
	char* beginDestination, int (*f)(int));

//возвращает конец строки
char* getEndOfString(char* s);

//убирает из строки символы пробелы
void removeNonLetters(char* s);

//сокращает количество пробелов между словами данного предложения до одного
void removeExtraSpaces(char* s);

//возвращает значение 0, если слово не было считано, 
// в противном случае будет возвращено значение 1
int getWord(char* beginSearch, WordDescriptor* word);

//возвращает значение 0, если слово не было считано (с конца строки), 
// в противном случае будет возвращено значение 1
bool getWordReverse(char* rbegin, char* rend, WordDescriptor* word);

//перемещает цифры в начало слова в обратном порядке
void digitToStartReverse(WordDescriptor word);

//перемещает цифры в начало слова
void digitToStart(WordDescriptor word);

//перемещает цифры в начало слова в обратном порядке 
// для каждого слова в строке
void stringReverseDigitToStart(char* s);

//перемещает цифры в начало слова для каждого слова в строке
void stringDigitToStart(char* s);

//поиск по критерию
char* findCriteria(char* s, int (*f)(int));

//поиск по критерию с конца
char* findCriteriaReverse(char* rbegin, char* rend, int (*f)(int));

//заменяет числа соответствующим числом пробелов
void replaceSpaces(char* s);

//заменяет все вхождения слова w1 на слово w2
void replace(char* source, char* w1, char* w2);

//сравнивает два слова, возвращает 0 если слова равны,
//<0 если w2 больше, >0 если w1 больше
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//возвращает 'истина' если слова в строке упорядочены 
//в лексографическом порядке
int areWordsOrdered(char* s);

//получает все слова из строки
void getBagOfWords(BagOfWords* bag, char* s);

//получает все слова из строки в обратном порядке 
//возможно работает не правильно
void getReverseBagOfWords(BagOfWords* bag, char* s);

//выводит слова данной строки в обратном 
//порядке по одному в строке экрана
void reverseWordOrder(char* s);

//возвращает 'истина' если слово палиндром иначе - 'ложь'
bool isPalindromeWord(WordDescriptor w);

//возвращает количество слов палиндомов в строке
int countPalindrome(char* s);

//Получает строку, в которой чередуются слова первой и второй строки
void mixUpStrings(char* s, char* s1);

//меняет местами слова w1 и w2 
//ВАЖНО: w1 < w2 в строке "w1 ... w2"
void swapWords(WordDescriptor w1, WordDescriptor w2);

//Преобразовывает строку, изменив порядок следования слов на обратный
void reverseStrWordOrder(char* s);

//без понятия как это описать типа возвращает код соответствующий
//найдено ли слвово и типа вводит это слово
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
	char* s, WordDescriptor* w);

//Выводит слово данной строки, предшествующее первому из слов,
//содержащих букву "а".
void printWordBeforeFirstWordWithA(char* s);

//Определяет последнее из слов первой строки,
//которое есть во второй строке
WordDescriptor lastWordInFirstStringInSecondString
(char* s1, char* s2);

//переводит слово в строку
void wordDescriptorToString(WordDescriptor word, char* destination);

bool thereAreIdenticalWords(char* s);

int compareChar(const void* a, const void* b);


bool pairWordsMadeUpSameSetOfLetters(char* s);

char* stringWithoutCopyOfLastWord(char* s, char* destination);


WordDescriptor firstWordBeforeWWord(char* s1, char* s2);


void deletePaindromeWord(char* s);

void complementString(char* s1, char* s2);

bool allLettersInTheString(char* s, WordDescriptor w);

#endif
