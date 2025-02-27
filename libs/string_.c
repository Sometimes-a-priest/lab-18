#include "string_.h"

size_t strlen_(const char* begin) {
	char* end = begin;
	while (*end != '\0') {
		end++;
	}
	return end - begin;
}char* find(char* begin, char* end, int ch) {
	while (begin != end && *begin != ch) {
		begin++;
	}
	return begin;
}

char* findNonSpace(char* begin) {
	while (*begin != '\0' && isspace(*begin)) {
		begin++;
	}
	return begin;
}

char* findSpace(char* begin) {
	while (*begin != '\0' && !isspace(*begin)) {
		begin++;
	}
	return begin;
}

char* findNonSpaceReverse(char* rbegin, const char* rend) {
	while (rbegin > rend && isspace(*rbegin)) {
		rbegin--;
	}
	return rbegin;
}

char* findSpaceReverse(char* rbegin, const char* rend) {
	while (rbegin > rend && !isspace(*rbegin)) {
		rbegin--;
	}
	return rbegin;
}

int strcmp(const char* lhs, const char* rhs) {
	for (;*lhs == *rhs; lhs++, rhs++) {
		if (*lhs == '\0') {
			return 0;
		}
	}

	return *(const unsigned char*)lhs - *(const unsigned char*)rhs;
}

char* copy(const char* beginSource, const char* endSource,
	char* beginDestination) {

	memcpy(beginDestination, beginSource, 
		sizeof(char) * (endSource - beginSource));

	return beginDestination + (endSource - beginSource);
}

char* copyIf(char* beginSource, const char* endSource,
	char* beginDestination, int (*f)(int)) {

	while (beginSource < endSource) {
		if (f(*beginSource)) {
			memcpy(beginDestination, beginSource, sizeof(char));
			beginDestination++;
		}
		beginSource++;
	}

	return beginDestination;
}

char* copyIfReverse(char* rbeginSource, const char* rendSource,
	char* beginDestination, int (*f)(int)) {

	while (rendSource <= rbeginSource) {
		if (f(*rbeginSource)) {
			memcpy(beginDestination, rbeginSource, sizeof(char));
			beginDestination++;
		}
		rbeginSource--;
	}
	return beginDestination;
}

char* getEndOfString(char* s) {
	while (*s != '\0') {
		s++;
	}
	return s;
}

void removeNonLetters(char* s) {
	char* endSource = getEndOfString(s);
	char* destination = copyIf(s, endSource, s, isgraph);
	*destination = '\0';
}void  removeExtraSpaces(char* s) {	if (isspace(*s)) {s++;}	char* a = findNonSpace(s);	char* b = findSpace(a);	while (*s != '\0' && *a != '\0') {		s = copy(a, b + 1, s);		a = findNonSpace(b);		b = findSpace(a);	}}int getWord(char* beginSearch, WordDescriptor* word) {	word->begin = findNonSpace(beginSearch);
	if (*word->begin == '\0') {
		return 0;
	}
	word->end = findSpace(word->begin);
	return 1;}bool getWordReverse(char* rbegin, char* rend, WordDescriptor* word) {	word->end = findNonSpaceReverse(rbegin,rend);
	if (word->end == rend) {
		return 0;
	}
	word->begin = findSpaceReverse(word->end,rend);
	if (word->begin == rend) {
		return 0;
	}
	
	return 1;}void digitToStartReverse(WordDescriptor word) {
	char* endStringBuffer = copy(word.begin, word.end,_stringBuffer);

	char* recPosition = copyIfReverse
	(endStringBuffer - 1,_stringBuffer - 1,word.begin, isdigit);

	copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}void digitToStart(WordDescriptor word) {
	char* endStringBuffer = copy(word.begin, word.end, _stringBuffer);

	char* recPosition = copyIf
	(_stringBuffer - 1,endStringBuffer, word.begin, isdigit);

	copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}void stringReverseDigitToStart(char* s) {	char* beginSearch = s;
	WordDescriptor word;

	while (getWord(beginSearch, &word)) {

		digitToStartReverse(word);

		beginSearch = word.end;
	}}void stringDigitToStart(char* s) {	char* beginSearch = s;
	WordDescriptor word;

	while (getWord(beginSearch, &word)) {

		digitToStart(word);

		beginSearch = word.end;
	}}char* findCriteria(char* s,int (*f)(int)) {	while (*s != '\0' && !f(*s)) {		s++;	}	return s;}char* findCriteriaReverse(char* rbegin,char* rend, int (*f)(int)) {	while (rbegin > rend && !f(*rbegin)) {		rbegin--;	}	return rbegin;}void replaceSpaces(char* s) {	copy(s, getEndOfString(s), _stringBuffer);	char* num = findCriteria(_stringBuffer, isdigit);	char* str = copy(_stringBuffer, num, s);	char* copyBegin = num + 1;	while (*num != '\0') {				for (size_t i = 0;i < *num - '0';i++) {			*str = ' ';			str++;		}		num = findCriteria(num + 1, isdigit);		str = copy(copyBegin, num, str);		copyBegin = num + 1;	}}void replace(char* source, char* w1, char* w2) {

	size_t w1Size = strlen_(w1);
	size_t w2Size = strlen_(w2);

	WordDescriptor word1 = { w1, w1 + w1Size };
	WordDescriptor word2 = { w2, w2 + w2Size };
	WordDescriptor readWord;
	char* readPtr, *recPtr;	if (w1Size >= w2Size) {
		readPtr = source;
		recPtr = source;
	}
	else {
		copy(source, getEndOfString(source), _stringBuffer);
		readPtr = _stringBuffer;
		recPtr = source;
	}
	char* end = getEndOfString(readPtr);

	while (getWord(readPtr, &readWord)) {

		readPtr = readWord.end;
		getWord(recPtr, &readWord);
		recPtr = readWord.begin;

		if (!memcmp(readWord.begin, word1.begin,
			sizeof(char) * w1Size)) {
			recPtr = copy(word2.begin, word2.end, recPtr);
			*copy(readPtr, end, recPtr) = '\0';
		}
		else {
			recPtr = readWord.end;
		}
	}
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
	size_t w2Size = w2.end - w2.begin;
	return memcmp(w1.begin, w2.begin, sizeof(char) * w2Size);
}

int areWordsOrdered(char* s) {
	//WordDescriptor w1, w2;
	//getWord(s, &w1);
	//while (getWord(w1.end, &w2)) {
	//	if(areWordsEqual(w1, w2) > 0){
	//		return 0;
	//	}
	//	w1.begin = w2.begin;
	//	w1.end = w2.end;
	//}
	//return 1;

	WordDescriptor w1, w2;
	if (getWord(s, &w1) && getWord(w1.end, &w2)) {
		return (areWordsEqual(w1, w2) <= 0) ? areWordsOrdered(w1.end)
			: 0;
	}
	return 1;
}

void getBagOfWords(BagOfWords* bag, char* s) {
	//size_t i = 0;

	//while (getWord(s, bag->words + i)) {
	//	s = (bag->words+i)->end;
	//	i++;
	//}
	//bag->size = i;

	bag->size = 0;
	WordDescriptor* ptr = bag->words;
	while (getWord(s, ptr)) {
		s = ptr->end;
		ptr++;
		bag->size++;
	}
}

void getReverseBagOfWords(BagOfWords* bag, char* s) {
	bag->size = 0;
	char* end = getEndOfString(s); 
	WordDescriptor* ptr = bag->words;
	while (getWordReverse(end, s, ptr)) {
		end = ptr->begin;
		ptr++;
		bag->size++;
	}
	
}

void reverseWordOrder(char* s) {
	getBagOfWords(&_bag, s);

	char* copyBegin = _stringBuffer;
	WordDescriptor* ptr = _bag.words + _bag.size - 1;

	while (_bag.size) {
		copyBegin = copy(ptr->begin,ptr->end, copyBegin);
		*copyBegin = ' ';
		copyBegin++;
		ptr--;
		_bag.size--;
	}
	*copyBegin = '\0';
	printf("%s\n", _stringBuffer);
}

bool isPalindromeWord(WordDescriptor w) {

	while (w.end > w.begin) {
		if (*(w.begin) != *(w.end)) {
			return 0;
		}
		w.end--;
		w.begin++;
	}
	return 1;
}

int countPalindrome(char* s) {
	int x = 0;
	WordDescriptor w;

	while (getWord(s, &w)) {
		s = w.end;
		if (*w.end == '\0') { w.end--; }
		if (isprint(*w.end)) {
			w.end = findCriteria(w.begin, ispunct);
		}
		w.end--;
		x += isPalindromeWord(w);
	}

	return x;
}

void mixUpStrings(char* s1, char* s2) {
	WordDescriptor word1, word2;
	bool isW1Found, isW2Found;
	char* beginSearch1 = s1, *beginSearch2 = s2;
	char* copyBegin = _stringBuffer;

	while ((isW1Found = getWord(beginSearch1, &word1)),
		(isW2Found = getWord(beginSearch2, &word2)),
		isW1Found || isW2Found) {

		if (isW1Found) {
			copyBegin = copy(word1.begin, word1.end, copyBegin);
			*copyBegin = ' ';
			copyBegin++;
			beginSearch1 = word1.end;
		}

		if (isW2Found) {
			copyBegin = copy(word2.begin, word2.end, copyBegin);
			*copyBegin = ' ';
			copyBegin++;
			beginSearch2 = word2.end;
		}
	}
	*copyBegin = '\0';

	printf("%s\n", _stringBuffer);
}

void swapWords(WordDescriptor w1, WordDescriptor w2) {
	if (w1.begin == w2.begin) {return 0;}
	// w1
	char* oldW1 = copy(w1.begin,w1.end, _stringBuffer);

	// w2
	char* oldW2 = copy(w2.begin, w2.end, oldW1);

	//между w1 и w2
	char* between = copy(w1.end,w2.begin, oldW2);

	//после w2
	char* afterW2 = copy(w2.end, getEndOfString(w2.end), between);


	//w1 = w2
	w1.end = copy(oldW1, oldW2, w1.begin);

	//между
	w2.begin = copy(oldW2, between, w1.end);

	//w2 = w1 
	w2.end = copy(_stringBuffer, oldW1,w2.begin);

	//после w2
	*copy(between, afterW2, w2.end) = '\0';

	*_stringBuffer = '\0';
}

void reverseStrWordOrder(char* s) {

	getBagOfWords(&_bag, s);

	WordDescriptor* ptrEnd = _bag.words + _bag.size-1;
	WordDescriptor* ptrBegin = _bag.words;

	//while (ptrBegin < ptrEnd) {
	//	swapWords(*ptrBegin, *ptrEnd);
	//	getBagOfWords(&_bag, s);
	//	ptrEnd--;
	//	ptrBegin++;
	//}

	while (ptrBegin < ptrEnd) {
		swapWords(*ptrBegin, *ptrEnd);
		ptrBegin->end = findSpace(ptrBegin->begin);
		getBagOfWords(&_bag, ptrBegin->end);
		ptrEnd -=2;
	}
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
	char* s, WordDescriptor* w) {

	getBagOfWords(&_bag, s);

	if (_bag.size == 0) {
		return EMPTY_STRING;
	}

	WordDescriptor* ptrWord = _bag.words;
	char* ptrChar = ptrWord->begin;

	for (size_t i = 0; i < _bag.size;i++) {

		while (ptrChar < ptrWord->end) {
			if (*ptrChar == 'a' || *ptrChar == 'A') {
				if (i == 0) {
					return FIRST_WORD_WITH_A ;
				}
				else {
					ptrWord--;
					w->begin = ptrWord->begin;
					w->end = ptrWord->end;
					return WORD_FOUND;
				}
			}
			ptrChar++;
		}
		ptrWord++;
	}

	return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char* s) {

	WordDescriptor w;
	WordBeforeFirstWordWithAReturnCode x =
		getWordBeforeFirstWordWithA(s, &w);

	if (x == WORD_FOUND) {
		*copy(w.begin, w.end, _stringBuffer) = '\0';

		printf("%s\n", _stringBuffer);
		*_stringBuffer = '\0';
	}
	else {
		printf("There is no such word\n");
	}
}

WordDescriptor lastWordInFirstStringInSecondString
(char* s1, char* s2) {
	getBagOfWords(&_bag, s1);
	if (_bag.size == 0) {
		return (WordDescriptor) { '\0', '\0' };
	}
	getBagOfWords(&_bag2, s2);
	if (_bag2.size == 0) {
		return (WordDescriptor) { '\0', '\0' };
	}

	WordDescriptor* ptr1 = _bag.words + _bag.size - 1;
	WordDescriptor* ptr2 = _bag2.words;

	for (int j = _bag.size; j >= 0;j--) {
		
		for (size_t i = 0;i < _bag2.size;i++) {
			if (areWordsEqual(*ptr1, *ptr2) == 0) {
				return *ptr1;
			}
			ptr2++;
		}
		ptr2 = _bag2.words;
		ptr1--;
	}
	return (WordDescriptor) { '\0', '\0' };
}

void wordDescriptorToString(WordDescriptor word, char* destination) {
	*copy(word.begin, word.end, destination) = '\0';
}

bool thereAreIdenticalWords(char* s) {
	getBagOfWords(&_bag, s);
	if (_bag.size == 0) {return 0;}

	WordDescriptor* ptr1 = _bag.words;
	WordDescriptor* ptr2 = ptr1 + 1;

	for (size_t i = 0;i < _bag.size - 1;i++) {
		for (size_t j = i+1;j < _bag.size;j++) {
			if (areWordsEqual(*ptr1, *ptr2) == 0) {
				return 1;
			}
			ptr2++;
		}
		ptr1++;
		ptr2 = ptr1 + 1;
	}
	return 0;
}

int compareChar(const void* a, const void* b) {
	return (*(char*)a - *(char*)b);
}

bool pairWordsMadeUpSameSetOfLetters(char* s) {
	*copy(s, getEndOfString(s), _stringBuffer) = '\0';

	getBagOfWords(&_bag, _stringBuffer);
	if (_bag.size < 2) { return 0; }

	WordDescriptor* ptr = _bag.words;
	char* ptr1 = ptr->begin;
	size_t size = ptr->end - ptr->begin;

	for (size_t i = 0; i < _bag.size;i++) {
		qsort(ptr1, size, sizeof(char), compareChar);
		ptr++;
		ptr1 = ptr->begin;
		size = ptr->end - ptr->begin;
	}

	return thereAreIdenticalWords(_stringBuffer);
}

char* stringWithoutCopyOfLastWord(char* s,char* destination) {
	getBagOfWords(&_bag, s);
	if (_bag.size < 2) {
		*destination = '\0';
		return destination;
	}
	WordDescriptor* LastWord = _bag.words + _bag.size - 1;
	WordDescriptor* ptr = _bag.words;
	char* copyBegin = destination;

	for (size_t i = 0; i < _bag.size - 1;i++) {
		if (areWordsEqual(*ptr, *LastWord) != 0) {
			copyBegin = copy(ptr->begin, ptr->end+1, copyBegin);
		}
		ptr++;
	}
	return copyBegin;
}

WordDescriptor firstWordBeforeWWord(char* s1, char* s2) {
	getBagOfWords(&_bag, s1);
	if (_bag.size < 1) { return (WordDescriptor) {'\0','\0' }; }
	getBagOfWords(&_bag2, s2);
	if (_bag2.size < 1) { return (WordDescriptor) { '\0', '\0' }; }

	WordDescriptor* ptr1 = _bag.words;
	WordDescriptor* ptr2 = _bag2.words;

	for (size_t i = 0; i < _bag.size;i++) {
		for (size_t j = 0; j < _bag2.size;j++) {
			if (areWordsEqual(*ptr1, *ptr2) == 0) {
				if (i == 0) {
					return (WordDescriptor) { '\0', '\0' };
				}
				ptr1--;
				return *ptr1;
			}
			ptr2++;
		}
		ptr1++;
		ptr2 = _bag2.words;
	}

	return (WordDescriptor) { '\0', '\0' };
}

void deletePaindromeWord(char* s) {

	WordDescriptor word;
	char* end = getEndOfString(s);

	while (getWord(s, &word)) {
		word.end--;
		if (isPalindromeWord(word)) {
			*copy(findNonSpace(word.end + 1), end, word.begin) = '\0';
			s = word.begin;
		}
		else {
			s = findSpace(word.end);
		}
	}
}

void complementString(char* s1, char* s2) {
	getBagOfWords(&_bag, s1);
	getBagOfWords(&_bag2, s2);

	bool flag = _bag.size >= _bag2.size;

	size_t nonExtraWordsCount = 
		((flag) ? _bag.size : _bag2.size) - abs(_bag.size - _bag2.size);

	char* smallerOneStringEnd = getEndOfString((flag) ? s2 : s1);
	char* extraWordBeggin =
		(((flag) ? _bag.words : _bag2.words) + nonExtraWordsCount)->begin;
	if (_bag.size && _bag2.size) { extraWordBeggin--; }

	*copy(extraWordBeggin, getEndOfString(extraWordBeggin),
		smallerOneStringEnd) = '\0';
}

bool allLettersInTheString(char* s, WordDescriptor w) {
	if (*s == '\0' || w.begin == '\0') {
		return 0;
	}
	char* end = w.end - 1;
	char* beggin = w.begin;
	int countLetters = w.end - w.begin;

	while (*s != '\0' && countLetters > 0) {
		for (size_t i = 0; i < countLetters;i++) {
			if (*s == *beggin) {
				countLetters--;
				beggin = end;
				end--;
			}
			beggin++;
		}
		s++;
		beggin = w.begin;
	}

	return countLetters == 0;
}