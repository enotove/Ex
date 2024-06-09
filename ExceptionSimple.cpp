
#include <iostream>
#include <string>

class Bad_Length : public std::exception
{
public:
    const char* what() const override { return "Bad length!"; }
};

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length) throw Bad_Length();
    return str.length();
}

int main()
{
    int forbidden_length = 0;
    std::string word;
    std::cout << "Enter forbidden length: ";
    std::cin >> forbidden_length;
    std::cout << "Enter word: ";
    std::cin >> word;
    try
    {
        std::cout << "The length of word is equal to:  " << function(word, forbidden_length) << std::endl;
    }
    catch (const Bad_Length& ex) { std::cout << ex.what() << std::endl; }
    
}
