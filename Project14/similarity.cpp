#include <xstring>

class Similarity
{
public:
	int checkLength(const std::string& str1, const std::string& str2)
	{
		if (str1.length() == str2.length())
			return 60;

		if (isValidLength(str1, str2))
			return 0;

		int shorter = 0;
		double gap = 0;

		if (str1.length() > str2.length())
		{
			shorter = str2.length();
			gap = str1.length() - shorter;
		}
		else
		{
			shorter = str1.length();
			gap = str2.length() - shorter;
		}

		return ((1 - gap / shorter) * 60);
	}

private:
	bool isValidLength(const std::string& str1, const std::string& str2)
	{
		return str1.length() >= str2.length() * 2 ||
			str2.length() >= str1.length() * 2;
	}
};
