#include <string>
using namespace std;

#define MAX_SCORE_OF_LENGTH 60
#define MAX_SCORE_OF_ALPA 40
#define END_OF_ALPHABET 26

class Similarity
{
public:
	int checkLength(const string& str1, const string& str2)
	{
		if (str1.length() == str2.length())
			return MAX_SCORE_OF_LENGTH;

		if (isValidLength(str1, str2))
			return 0;

		int shorter = str1.length();
		int longer = str2.length();

		if (shorter > longer) swap(shorter, longer);

		double gap = longer - shorter;

		return ((1 - gap / shorter) * MAX_SCORE_OF_LENGTH);
	}

	int checkEqual(const string& str1, const string& str2)
	{
		double totalcnt = str1.length() + str2.length();

		int list1[END_OF_ALPHABET] = { 0 };
		int list2[END_OF_ALPHABET] = { 0 };
				
		countAlphabet(str1, list1);
		countAlphabet(str2, list2);

		double samecnt = countSameAlphabet(list1, list2);

		if (samecnt == totalcnt) return MAX_SCORE_OF_ALPA;

		return ((samecnt/totalcnt) * MAX_SCORE_OF_ALPA);
	}

	void countAlphabet(const string& str1, int *list)
	{
		for (int i = 0; i < str1.length(); i++)
		{
			list[str1[i] - 'A'] += 1;
		}
	}

	double countSameAlphabet(int *list1, int *list2)
	{
		double samecnt = 0;
		for (int i = 0; i < END_OF_ALPHABET; i++)
		{
			if (list1[i] != 0 && list2[i] != 0) {
				samecnt += list1[i] + list2[i];
			}
		}
		return samecnt;
	}

private:
	bool isValidLength(const std::string& str1, const std::string& str2)
	{
		return str1.length() >= str2.length() * 2 ||
			str2.length() >= str1.length() * 2;
	}

};
