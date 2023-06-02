#include <string>
using namespace std;

#define MAX_SCORE_OF_LENGTH 60

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
		double samecnt = 0;
		double totalcnt = str1.length() + str2.length();

		int list1[26] = { 0 };
		int list2[26] = { 0 };
				
		for (int i = 0; i < str1.length(); i++)
		{
			list1[str1[i] - 'A'] += 1;
 		}

		for (int i = 0; i < str2.length(); i++)
		{
			list2[str2[i] - 'A'] += 1;
		}

		for (int i = 0; i < 26; i++)
		{
			if (list1[i] != 0 && list2[i] != 0) {
				samecnt += list1[i] + list2[i];
			}
		}

		if (samecnt == totalcnt) return 40;

		return ((samecnt/totalcnt) * 40);
	}

private:
	bool isValidLength(const std::string& str1, const std::string& str2)
	{
		return str1.length() >= str2.length() * 2 ||
			str2.length() >= str1.length() * 2;
	}
};
