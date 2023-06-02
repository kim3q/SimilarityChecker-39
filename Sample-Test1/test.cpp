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