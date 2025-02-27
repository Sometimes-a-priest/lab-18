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
	char* begin; // ������� ������ �����
	char* end; // ������� ������� �������, ����� ���������� ������� �����
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

//���������� ���������� �������� � ������
size_t strlen_(const char* begin);

//���������� ��������� �� ������ ������� � ����� ch
char* find(char* begin, char* end, int ch);

//���������� ��������� �� ������ ������, �������� �� ����������.
//���� ������ �� ������, ������������ ����� ������� ����-�������
char* findNonSpace(char* begin);

//���������� ��������� �� ������ ���������� ������
//��� �� ������ ���� - ������
char* findSpace(char* begin);

//���������� ��������� �� ������ ������ ������, �������� �� ���������� 
// ���� ������ �� ������, ������������ ����� rend
char* findNonSpaceReverse(char* rbegin, const char* rend);

//���������� ��������� �� ������ ���������� ������ ������ 
//���� ������ �� ������,������������ ����� rend
char* findSpaceReverse(char* rbegin, const char* rend);

//���������� �������� > 0 ���� lhs > rhs
//���� lhs == rhs - 0, ����� < 0 
int strcmp(const char* lhs, const char* rhs);

//���������� ��������� �� ��������� ��������� �������� ������ � destination
//���������� �� ������ beginDestination �������� ������, 
//������� � ������ beginSource �� endSource
char* copy(const char* beginSource, const char* endSource,
	char* beginDestination);

//���������� ��������� �� ��������� ��������� ��� ������ �������� � ������
//���������� �� ������ beginDestination �������� �� ��������� ������ 
//������� � beginSource ���������� endSource, 
//��������������� ������� - ��������� f
char* copyIf(char* beginSource, const char* endSource,
	char* beginDestination, int (*f)(int));

//���������� �������� beginDestination ���������� �� ������ beginDestination 
// �������� �� ��������� ������ ������� � rbeginSource ���������� rendSource,
// ��������������� ������� - ��������� f
char* copyIfReverse(char* rbeginSource, const char* rendSource,
	char* beginDestination, int (*f)(int));

//���������� ����� ������
char* getEndOfString(char* s);

//������� �� ������ ������� �������
void removeNonLetters(char* s);

//��������� ���������� �������� ����� ������� ������� ����������� �� ������
void removeExtraSpaces(char* s);

//���������� �������� 0, ���� ����� �� ���� �������, 
// � ��������� ������ ����� ���������� �������� 1
int getWord(char* beginSearch, WordDescriptor* word);

//���������� �������� 0, ���� ����� �� ���� ������� (� ����� ������), 
// � ��������� ������ ����� ���������� �������� 1
bool getWordReverse(char* rbegin, char* rend, WordDescriptor* word);

//���������� ����� � ������ ����� � �������� �������
void digitToStartReverse(WordDescriptor word);

//���������� ����� � ������ �����
void digitToStart(WordDescriptor word);

//���������� ����� � ������ ����� � �������� ������� 
// ��� ������� ����� � ������
void stringReverseDigitToStart(char* s);

//���������� ����� � ������ ����� ��� ������� ����� � ������
void stringDigitToStart(char* s);

//����� �� ��������
char* findCriteria(char* s, int (*f)(int));

//����� �� �������� � �����
char* findCriteriaReverse(char* rbegin, char* rend, int (*f)(int));

//�������� ����� ��������������� ������ ��������
void replaceSpaces(char* s);

//�������� ��� ��������� ����� w1 �� ����� w2
void replace(char* source, char* w1, char* w2);

//���������� ��� �����, ���������� 0 ���� ����� �����,
//<0 ���� w2 ������, >0 ���� w1 ������
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//���������� '������' ���� ����� � ������ ����������� 
//� ���������������� �������
int areWordsOrdered(char* s);

//�������� ��� ����� �� ������
void getBagOfWords(BagOfWords* bag, char* s);

//�������� ��� ����� �� ������ � �������� ������� 
//�������� �������� �� ���������
void getReverseBagOfWords(BagOfWords* bag, char* s);

//������� ����� ������ ������ � �������� 
//������� �� ������ � ������ ������
void reverseWordOrder(char* s);

//���������� '������' ���� ����� ��������� ����� - '����'
bool isPalindromeWord(WordDescriptor w);

//���������� ���������� ���� ���������� � ������
int countPalindrome(char* s);

//�������� ������, � ������� ���������� ����� ������ � ������ ������
void mixUpStrings(char* s, char* s1);

//������ ������� ����� w1 � w2 
//�����: w1 < w2 � ������ "w1 ... w2"
void swapWords(WordDescriptor w1, WordDescriptor w2);

//��������������� ������, ������� ������� ���������� ���� �� ��������
void reverseStrWordOrder(char* s);

//��� ������� ��� ��� ������� ���� ���������� ��� ���������������
//������� �� ������ � ���� ������ ��� �����
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
	char* s, WordDescriptor* w);

//������� ����� ������ ������, �������������� ������� �� ����,
//���������� ����� "�".
void printWordBeforeFirstWordWithA(char* s);

//���������� ��������� �� ���� ������ ������,
//������� ���� �� ������ ������
WordDescriptor lastWordInFirstStringInSecondString
(char* s1, char* s2);

//��������� ����� � ������
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
