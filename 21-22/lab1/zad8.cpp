#include <iostream>

class SanitizedString
{
private:
    std::string str;

public:
    SanitizedString(std::string ulaz)
    {
        str = ulaz;
        removeDuplicateWhitespace();
        removeNonAlphaChars();
    }

    void removeDuplicateWhitespace()
    {
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] == ' ' && str[i - 1] == ' ')
            {
                str.erase(str.begin() + i);
                i--;
            }
        }
    }

    void removeNonAlphaChars()
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (!(isalpha(str[i])) || str[i] == ' ')
            {
                str.erase(str.begin() + i);
                i--;
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const SanitizedString &str);
};

std::ostream &operator<<(std::ostream &os, const SanitizedString &str)
{
    os << str.str;
    return os;
}

int main(void)
{
    std::string ulaz;
    std::cout << "Upišite znakovni niz: ";
    std::getline(std::cin, ulaz);

    SanitizedString sanitized(ulaz);

    std::cout << "Početni string: " << ulaz << std::endl;
    std::cout << "Sanitizirani string: " << sanitized << std::endl;

    return 0;
}