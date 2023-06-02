#include <string>
using namespace std;

#define MAX_SCORE_OF_LENGTH 60

class Similarity
{
public:
	int checkLength(const std::string& str1, const std::string& str2)
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

private:
	bool isValidLength(const std::string& str1, const std::string& str2)
	{
		return str1.length() >= str2.length() * 2 ||
			str2.length() >= str1.length() * 2;
	}
};
