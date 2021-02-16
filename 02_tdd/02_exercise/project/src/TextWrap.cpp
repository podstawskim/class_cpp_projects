#include "TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {

}

std::string TextWrap::wrap(const char *line) const {

    std::stringstream tempWords(line);
    std::stringstream wrapped;
    std::string word;

    std::string count;
    size_t wordsCount = 0;

    while(tempWords >> count)
        ++wordsCount;

    std::stringstream words(line);
    if(wordsCount == 1)
    {
        if (count.size() > 1) {
            return count.substr(0, columns) + "\n" + count.substr(columns);
        }
    }

    if (words >> word) {
        wrapped << word;
        size_t space_left = columns - word.length();
        while (words >> word) {
            if (space_left < word.length() + 1) {
                wrapped << '\n' << word;
                space_left = columns - word.length();
            } else {
                wrapped << ' ' << word;
                space_left -= word.length() + 1;
            }
        }
    }
    return wrapped.str();
}





