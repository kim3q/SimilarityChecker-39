#include "pch.h"
#include "..\Project14/similarity.cpp"
#include <string>

using namespace std;

TEST(TestCaseName, LengthSame) {
	int result = 0;
	string str1 = "";
	string str2 = "";
	
	result = Similarity().checkLength(str1, str2);
	EXPECT_EQ(60, result);
}

TEST(TestCaseName, LengthDouble) {
	int result = 0;
	string str1 = "ABC";
	string str2 = "ABCABC";

	result = Similarity().checkLength(str1, str2);
	EXPECT_EQ(0, result);
}

TEST(TestCaseName, LengthGap) {
	int result = 0;
	string str1 = "ABC";
	string str2 = "ABCAB";

	result = Similarity().checkLength(str1, str2);
	EXPECT_EQ(20, result);
}

TEST(TestCaseName, LengthGap1) {
	int result = 0;
	string str1 = "ABC";
	string str2 = "ABAB";

	result = Similarity().checkLength(str1, str2);
	EXPECT_EQ(40, result);
}

TEST(TestCaseName, CheckAlphabet) {
	int result = 0;
	string str1 = "ABC";
	string str2 = "CBA";

	result = Similarity().checkEqual(str1, str2);
	EXPECT_EQ(40, result);
}

TEST(TestCaseName, CheckAlphabet1) {
	int result = 0;
	string str1 = "A";
	string str2 = "CC";

	result = Similarity().checkEqual(str1, str2);
	EXPECT_EQ(0, result);
}

TEST(TestCaseName, CheckAlphabet2) {
	int result = 0;
	string str1 = "ABC";
	string str2 = "ABC";

	result = Similarity().checkEqual(str1, str2);
	EXPECT_EQ(40, result);
}

TEST(TestCaseName, CheckAlphabet3) {
	int result = 0;
	string str1 = "AA";
	string str2 = "AAE";

	result = Similarity().checkEqual(str1, str2);
	EXPECT_EQ(32, result);
}
