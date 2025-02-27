#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

//тестами обозвал наборы данных

// no 1
int test_task1() {
	char c[] = "a b c";
	removeNonLetters(c);
	printf("%s\n", c);
}

//no 2
int test_task2_1() {
	char c[] = "  1  11  333  44    5";
	removeExtraSpaces(c);

	printf("%s\n", c);
}

//no 2
int test_task2_EmptyString() {
	char c[] = "";
	removeExtraSpaces(c);
	char s[] = " ";
	if (memcmp(c, s, sizeof(s)) == -1) {
		printf("Ok\n");
	}
	else {
		printf("error in test_task2_EmptyString\n");
	}
}

//no 2
int test_task2_OneElement() {
	char c[] = "a";
	removeExtraSpaces(c);

	printf("%s\n", c);
}

//no 2
int test_task2_OneElementSpace() {
	char c[] = " ";
	removeExtraSpaces(c);
	char s[] = " ";
	if (memcmp(c, s, sizeof(s)) == 0) {
		printf("Ok\n");
	}
	else {
		printf("error in test_task2_OneElementSpace\n");
	}
}

//no2 all tests
int all_test_task2() {
	test_task2_1();
	test_task2_EmptyString();
	test_task2_OneElement();
	test_task2_OneElementSpace();
}

//no 3
int test_task3_1() {
	char c[] = " a1b2c3 abc";
	stringReverseDigitToStart(c);
	printf("%s\n", c);
}

//no 3
int test_task3_OneWord() {
	char c[] = "a1b2c3";
	stringReverseDigitToStart(c);
	printf("%s\n", c);
}

//no 3
int test_task3_EmptyString() {
	char c[] = "";
	stringReverseDigitToStart(c);
	char s[] = "";
	if (memcmp(c, s, sizeof(s)) == 0) {
		printf("Ok\n");
	}
	else {
		printf("Error in test_task3_EmptyString\n");
	}
}

//no 3
int test_task3_OnlyDighits() {
	char c[] = " 321 123 ";
	stringReverseDigitToStart(c);
	printf("%s\n", c);
}

//no 3 all tests
int all_test_task3(){
	test_task3_1();
	test_task3_OneWord();
	test_task3_EmptyString();
	test_task3_OnlyDighits();
}

//no 3.1
int test_task3_1_1() {
	char c[] = " a1b2c3 abc";
	stringDigitToStart(c);
	printf("%s\n", c);
}

//no 3.1
int test_task3_1_OneWord() {
	char c[] = "a1b2c3";
	stringDigitToStart(c);
	printf("%s\n", c);
}

//no 3.1
int test_task3_1_EmptyString() {
	char c[] = "";
	stringDigitToStart(c);
	char s[] = "";
	if (memcmp(c, s, sizeof(s)) == 0) {
		printf("Ok\n");
	}
	else {
		printf("Error in test_task3_EmptyString\n");
	}
}

//no 3.1
int test_task3_1_OnlyDighits() {
	char c[] = " 321 123 ";
	stringDigitToStart(c);
	printf("%s\n", c);
}

//no 3.1 all tests
int all_test_task3_1_() {
	test_task3_1_1();
	test_task3_1_OneWord();
	test_task3_1_EmptyString();
	test_task3_1_OnlyDighits();
}

//no 4 all tests
int all_test_task4() {
	char c[50] = "a1b2c3d";
	replaceSpaces(c);
	printf("%s", c);
}

//no 5
int test_task5_w1_equivalen_w2() {
	char c[50] = "abcc asd abcc xxx";
	char w1[] = "abcc";
	char w2[] = "zzzz";
	replace(c, w1, w2);

	printf("%s\n", c);
}

//no 5
int test_task5_w1_bigger_then_w2() {
	char c[50] = "abcc asd abcc xxx";
	char w1[] = "abcc";
	char w2[] = "zzz";
	replace(c, w1, w2);

	printf("%s\n", c);
}

//no 5
int test_task5_w2_bigger_then_w1() {
	char c[50] = "abcc asd abcc xxx";
	char w1[] = "abcc";
	char w2[] = "zzzzz";
	replace(c, w1, w2);

	printf("%s\n", c);
}

//no 5 all tests
int all_test_task5(){
	test_task5_w1_equivalen_w2();
	test_task5_w1_bigger_then_w2();
	test_task5_w2_bigger_then_w1();
}

//no 6
int test_task6_1() {
	char s[] = "af bbbbb bfbbb bfbb cc ";
	printf("%d\n", areWordsOrdered(s));
}

//no 6
int test_task6_2() {
	char s[] = "a b c d e f g";
	printf("%d\n", areWordsOrdered(s));
}

//no 6
int test_task6_3() {
	char s[] = "g f e d c b a";
	printf("%d\n", areWordsOrdered(s));
}

//no 6
int test_task6_4() {
	char s[] = "aa ab ac";
	printf("%d\n", areWordsOrdered(s));
}

//no 6
int test_task6_5() {
	char s[] = "ae ab ac";
	printf("%d\n", areWordsOrdered(s));
}

//no 6
int test_task6_6() {
	char s[] = "aac aca caa";
	printf("%d\n", areWordsOrdered(s));
}

//no 6
int test_task6_7() {
	char s[] = "caaaa acaa aac";
	printf("%d\n", areWordsOrdered(s));
}

//no 6
int test_task6_8() {
	char s[] = "aaaa   bbb   cc e";
	printf("%d\n", areWordsOrdered(s));
}

//no 6 all tests
int all_test_task6() {
	test_task6_1();
	test_task6_2();
	test_task6_3();
	test_task6_4();
	test_task6_5();
	test_task6_6();
	test_task6_7();
	test_task6_8();
}

//no 7
int test_task7_1() {
	char c[] = "abc zzz xxx aaa";
	reverseWordOrder(c);
}

//no 7
int test_task7_2() {
	char c[] = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15";
	reverseWordOrder(c);
}

//no 7
int test_task7_3() {
	char c[] = "1";
	reverseWordOrder(c);
}

//no 7
int test_task7_4_emptyString() {
	char c[] = "";
	reverseWordOrder(c);
}

//no 7
int test_task7_5() {
	char c[] = "   1   2   3    4    5";
	reverseWordOrder(c);
}

//no 7 all tests
int test_task7() {
	test_task7_1();
	test_task7_2();
	test_task7_3();
	test_task7_4_emptyString;
	test_task7_5();
}

//no 8
int test_task8_1() {
	char c[] = "abba,   xzz,   xzx,  ";
	int x = countPalindrome(c);
	printf("%d\n", x);
}

//no 8
int test_task8_2() {
	char c[] = "abba, xzz, xzx,  aa, z.";
	int x = countPalindrome(c);
	printf("%d\n", x);
}

//no 8
int test_task8_3() {
	char c[] = "a";
	int x = countPalindrome(c);
	printf("%d\n", x);
}

//no 8
int test_task8_4() {
	char c[] = "a11a, 333";
	int x = countPalindrome(c);
	printf("%d\n", x);
}

//no 8
int test_task8_5_emptyString() {
	char c[] = "";
	int x = countPalindrome(c);
	printf("%d\n", x);
}

//no 8
int test_task8_6() {
	char c[] = "abba,";
	int x = countPalindrome(c);
	printf("%d\n", x);
}

//no 8 all tests
int test_task8() {
	test_task8_1();
	test_task8_2();
	test_task8_3();
	test_task8_4();
	test_task8_5_emptyString();
	test_task8_6();
}

//no 9
int test_task9_1() {
	char c[] = "1111 2222";
	char s[] = "3333 4444";
	mixUpStrings(c, s);
}

//no 9
int test_task9_2() {
	char c[] = "1111 2222 5555";
	char s[] = "3333 4444";
	mixUpStrings(c, s);
}

//no 9
int test_task9_3() {
	char c[] = "1111 2222 5555";
	char s[] = "3333 4444 6666 7777";
	mixUpStrings(c, s);
}

//no 9
int test_task9_4() {
	char c[] = "1111 2222 5555";
	char s[] = "";
	mixUpStrings(c, s);
}

//no 9
int test_task9_5() {
	char c[] = "";
	char s[] = "3333 4444 6666 7777";
	mixUpStrings(c, s);
}

//no 9 all tests
int test_task9() {
	test_task9_1();
	test_task9_2();
	test_task9_3();
	test_task9_4();
	test_task9_5();
}

//no 10
int test_task10_1() {
	char c[] = "1  22  333  4444  55555";
	reverseStrWordOrder(c);
	printf("%s\n", c);
}

//no 10
int test_task10_2() {
	char c[] = "55555 4444 333 22 1";
	reverseStrWordOrder(c);
	printf("%s\n", c);
}

//no 10
int test_task10_3() {
	char c[] = "1 2 3 4 5 6 7 8 9";
	reverseStrWordOrder(c);
	printf("%s\n", c);
}

//no 10 all tests
int test_task10() {
	test_task10_1();
	test_task10_2();
	test_task10_3();
}

//no 11
int test_task11_1() {
	char c[] = "xxx bcccA zzz";
	printWordBeforeFirstWordWithA(c);
}

//no 11
int test_task11_2() {
	char c[] = "xxx bccac zzz";
	printWordBeforeFirstWordWithA(c);
}

//no 11
int test_task11_3() {
	char c[] = "accac zzz";
	printWordBeforeFirstWordWithA(c);
}

//no 11
int test_task11_4() {
	char c[] = "";
	printWordBeforeFirstWordWithA(c);
}

//no 11
int test_task11_5() {
	char c[] = "xxx bccc zzz";
	printWordBeforeFirstWordWithA(c);
}

//no 11 all tests
int test_task11() {
	test_task11_1();
	test_task11_2();
	test_task11_3();
	test_task11_4();
	test_task11_5();
}

//no 12
int test_task12_1() {
	char c[] = "aaa bbb ccc ddd eee fff";
	char s[] = "zzz xxx ccc vvv eee ccc";
	WordDescriptor w =
		lastWordInFirstStringInSecondString(c, s);
	
	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 12
int test_task12_2() {
	char c[] = "aaa bbb ccc ddd eee fff";
	char s[] = "zzz xxx aaa hhh jjj";
	WordDescriptor w =
		lastWordInFirstStringInSecondString(c, s);

	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 12
int test_task12_3() {
	char c[] = "aaa bbb jjj ccc ddd eee fff";
	char s[] = "zzz xxx aaa hhh jjj";
	WordDescriptor w =
		lastWordInFirstStringInSecondString(c, s);

	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 12 all tests
int test_task12() {
	test_task12_1();
	test_task12_2();
	test_task12_3();
}

//no 13
int test_task13_1() {
	char c[] = "aaa bbb ccc ddd aaa";
	bool x = thereAreIdenticalWords(c);
	printf("%d\n", x);
}

//no 13
int test_task13_2() {
	char c[] = "nnn aaa bbb ccc aaa lll";
	bool x = thereAreIdenticalWords(c);
	printf("%d\n", x);
}

//no 13
int test_task13_3() {
	char c[] = "nnn aaa bbb ccc lll";
	bool x = thereAreIdenticalWords(c);
	printf("%d\n", x);
}

//no 13
int test_task13_4_emptyString() {
	char c[] = "";
	bool x = thereAreIdenticalWords(c);
	printf("%d\n", x);
}

//no 13
int test_task13_5() {
	char c[] = "aaa";
	bool x = thereAreIdenticalWords(c);
	printf("%d\n", x);
}

//no 13 all tests
int test_task13() {
	test_task13_1();
	test_task13_2();
	test_task13_3();
	test_task13_4_emptyString();
	test_task13_5();
}

//on 14
int test_task14_1() {
	char c[] = "abc xxx cab qqq";
	bool x = pairWordsMadeUpSameSetOfLetters(c);
	printf("%d\n", x);
}

//no 14
int test_task14_2() {
	char c[] = "abc xxx";
	bool x = pairWordsMadeUpSameSetOfLetters(c);
	printf("%d\n", x);
}

//no 14
int test_task14_3() {
	char c[] = "abc";
	bool x = pairWordsMadeUpSameSetOfLetters(c);
	printf("%d\n", x);
}

//no 14
int test_task14_4_emptyString() {
	char c[] = "";
	bool x = pairWordsMadeUpSameSetOfLetters(c);
	printf("%d\n", x);
}

//no 14 all tests
int test_task14() {
	test_task14_1();
	test_task14_2();
	test_task14_3();
	test_task14_4_emptyString();
}

//no 15
int test_task15_1() {
	char c[] = "aaa bbb ccc aaa ddd eee aaa";
	stringWithoutCopyOfLastWord(c, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 15
int test_task15_2() {
	char c[] = "aaa";
	stringWithoutCopyOfLastWord(c, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 15
int test_task15_3_emptyString() {
	char c[] = "";
	stringWithoutCopyOfLastWord(c, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 15 all tests
int test_task15() {
	test_task15_1();
	test_task15_2();
	test_task15_3_emptyString();
}

//no 16
int test_task16_1() {
	char c[] = "aaa bbb ccc ddd";
	char c1[] = "eee fff bbb ggg";
	WordDescriptor w = firstWordBeforeWWord(c, c1);
	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 16
int test_task16_2_emptyString() {
	char c[] = "aaa bbb ccc ddd";
	char c1[] = "";
	WordDescriptor w = firstWordBeforeWWord(c, c1);
	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 16
int test_task16_3_emptyString() {
	char c[] = "aaa bbb ccc ddd";
	char c1[] = "";
	WordDescriptor w = firstWordBeforeWWord(c, c1);
	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 16
int test_task16_4_emptyString() {
	char c[] = "";
	char c1[] = "";
	WordDescriptor w = firstWordBeforeWWord(c, c1);
	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 15
int test_task16_5_NOIdenticalWords() {
	char c[] = "bbb ccc ddd";
	char c1[] = "eee fff bbb ggg";
	WordDescriptor w = firstWordBeforeWWord(c, c1);
	wordDescriptorToString(w, _stringBuffer);
	printf("%s\n", _stringBuffer);
}

//no 16 all tests
int test_task16() {
	test_task16_1();
	test_task16_2_emptyString();
	test_task16_3_emptyString();
	test_task16_4_emptyString();
	test_task16_5_NOIdenticalWords();
}

//no 17
int test_task17_1() {
	char c[] = "abc abba zcv asssa xcc";
	deletePaindromeWord(c);
	printf("%s\n", c);
}

//no 17
int test_task17_2() {
	char c[] = "abc abba";
	deletePaindromeWord(c);
	printf("%s\n", c);
}

//no 17
int test_task17_3() {
	char c[] = "abc";
	deletePaindromeWord(c);
	printf("%s\n", c);
}

//no 17
int test_task17_4() {
	char c[] = "abba";
	deletePaindromeWord(c);
	printf("%s\n", c);
}

//no 17
int test_task17_5_emptyString() {
	char c[] = "";
	deletePaindromeWord(c);
	printf("%s\n", c);
}

//no 17
int test_task17_6() {
	char c[] = "abc abba asssa xcc";
	deletePaindromeWord(c);
	printf("%s\n", c);
}

//no 17
int test_task17_7() {
	char c[] = "abba asssa";
	deletePaindromeWord(c);
	printf("%s\n", c);
}

//no 17 all tests
int test_task17() {
	test_task17_1();
	test_task17_2();
	test_task17_3();
	test_task17_4();
	test_task17_5_emptyString();
	test_task17_6();
	test_task17_7();
}

//no 18
int test_task18_1() {
	char c[MAX_STRING_SIZE] = "aaa bbb";
	char c1[MAX_STRING_SIZE] = "aaa bbb ccc xxx";
	complementString(c, c1);
	printf("%s\n", c);
}

//no 18
int test_task18_2() {
	char c[MAX_STRING_SIZE] = "aaa bbb ccc xxx";
	char c1[MAX_STRING_SIZE] = "aaa bbb";
	complementString(c, c1);
	printf("%s\n", c1);
}

//no 18
int test_task18_3() {
	char c[MAX_STRING_SIZE] = "aaa bbb";
	char c1[MAX_STRING_SIZE] = "aaa bbb";
	complementString(c, c1);
	printf("%s\n", c);
}

//no 18
int test_task18_4() {
	char c[MAX_STRING_SIZE] = "";
	char c1[MAX_STRING_SIZE] = "aaa bbb";
	complementString(c, c1);
	printf("%s\n", c);
}

//no 18 all tests
int test_task18() {
	test_task18_1();
	test_task18_2();
	test_task18_3();
	test_task18_4();
}

//no 19
int test_task19_1() {
	char c[] = "aaa bbb ccc ddd eee fff ggg";
	char x[] = " abc ";
	WordDescriptor w;
	getWord(x, &w);
	bool a = allLettersInTheString(c, w);
	printf("%d\n", a);
}

//no 19
int test_task19_2() {
	char c[] = "aaa bbb ddd eee fff ggg";
	char x[] = " abc";
	WordDescriptor w;
	getWord(x, &w);
	bool a = allLettersInTheString(c, w);
	printf("%d\n", a);
}

//no 19
int test_task19_3_emptyWord() {
	char c[] = "aaa bbb ccc ddd eee fff ggg";
	char x[] = "";
	WordDescriptor w;
	w.begin = x[0];
	w.end = x[0];
	bool a = allLettersInTheString(c, w);
	printf("%d\n", a);
}

//no 19
int test_task19_4_emptyString() {
	char c[] = "";
	char x[] = "abc";
	WordDescriptor w;
	getWord(x, &w);
	bool a = allLettersInTheString(c, w);
	printf("%d\n", a);
}

//no 19
int test_task19_5_allEmpty() {
	char c[] = "";
	char x[] = "";
	WordDescriptor w;
	w.begin = x[0];
	w.end = x[0];
	bool a = allLettersInTheString(c, w);
	printf("%d\n", a);
}

//no 19 all tests
int test_task19() {
	test_task19_1();
	test_task19_2();
	test_task19_3_emptyWord();
	test_task19_4_emptyString();
	test_task19_5_allEmpty();
}

//наборы данных вызывать здесь
int task() {

}